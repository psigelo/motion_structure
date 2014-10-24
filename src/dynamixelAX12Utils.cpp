#include "dynamixelAX12Utils.hpp"


// Set postion to AX 12 - return error state
int ax_set_position (int fd, int id, int position)
{

	// Valid ID
	if (ax_verify_id (id) == 0) return INVAL_ID;

	// Packet to send
	char instructions[9] = {(char)0xff, (char)0xff, (char)id, (char)5, (char)AX_WRITE_DATA, (char)AX_GOAL_POSITION_L, (char)(position%256), (char)(position>>8), (char)0};
	// Packet to read
	char redst[6] = {0, 0, 0, 0, 0, 0};

	// Checksum
	instructions[8] = ax_checksum (instructions);

	// Comunication
	if (serial_io_flush (fd) == ERR_PORT) return ERR_READ;
	serial_send (fd, instructions, 9);
	serial_read (fd, redst, 6, DEF_TIMEOUT);

	//int i;
	//for (i =  0; i < 6; ++i)
	//	printf("%d\n", (uint8_t)redst[i]);
	return (redst[4] >= 0 && redst[5] != 0)? redst[4]: ERR_READ; // Verify errors


}

// Calculate cheksum for AX12 UART protocol
int ax_checksum (char *instructions)
{
	if (instructions == NULL || sizeof(instructions) < 6) return 0;
	int csum = 0;
	unsigned int i;
	for (i = 2; i < (sizeof(instructions)); ++i)
		 csum = csum + (uint8_t)instructions[i];

	return ~csum & 0x00ff; // Se conservan el byte menos significativos.
}

// Get position from AX 12
int ax_get_position (int fd, int id)
{
	// Valid ID
	if (ax_verify_id(id) == 0) return INVAL_ID;

	// Packet to send
	char instructions[8] = { (char)0xff, (char)0xff, (char)id, (char)4, (char)AX_READ_DATA, (char)AX_PRESENT_POSITION_L, (char)2, (char)0};
	// Packet to read
	char redst[8] = {0,0,0,0,0,0,0,0};

	// Checksum
	instructions[7] = ax_checksum(instructions);

	// Comunication
	if (serial_io_flush (fd) == ERR_PORT) return ERR_READ;
	serial_send (fd, instructions, 8);
	serial_read (fd, redst, 8, DEF_TIMEOUT);

	//int i;
	//for (i =  0; i < 8; ++i)
	//	printf("%d\n", (uint8_t)redst[i]);

	if (redst[7] == 0) return ERR_READ;
	if (redst[4] != 0 && redst[7] != 0) return -redst[4];
	// Verify error, return -(ERROR-FROM-AX12)

	return (int)((uint8_t)redst[6]*257 + (uint8_t)redst[5]);
}

// Enable motor torque - return error state
int ax_enable_torque (int fd, int id)
{
	// Valid ID
	if (ax_verify_id (id) == 0) return INVAL_ID;

	// Packet to send
	char instructions[8] = {(char)0xff, (char)0xff, (char)id, (char)4, (char)AX_WRITE_DATA, (char)AX_TORQUE_ENABLE, (char)1, (char)0};
	// Packet to read
	char redst[6] = {0, 0, 0, 0, 0, 0};

	// Checksum
	instructions[7] = ax_checksum (instructions);

	// Comunication
	if (serial_io_flush (fd) == ERR_PORT) return ERR_READ;
	serial_send (fd, instructions, 8);
	serial_read (fd, redst, 6, DEF_TIMEOUT);

	//int i
	//for (i =  0; i < 6; ++i)
	//	printf("%d\n", (uint8_t)redst[i]);

	return (redst[4] >= 0 && redst[5] != 0)? redst[4]: ERR_READ; // Verify error
}

// Turn off actuator - return error state
int ax_disable_torque (int fd, int id)
{
	// Valid ID
	if (ax_verify_id (id) == 0) return INVAL_ID;

	// Packet to send
	char instructions[8] = {(char)0xff, (char)0xff, (char)id, (char)4, (char)AX_WRITE_DATA, (char)AX_TORQUE_ENABLE, (char)0, (char)0};
	// Packet to read
	char redst[6] = {0, 0, 0, 0, 0, 0};

	// Checksum
	instructions[7] = ax_checksum (instructions);

	// Comunication
	if (serial_io_flush (fd) == ERR_PORT) return ERR_READ;
	serial_send (fd, instructions, 8);
	serial_read (fd, redst, 6, DEF_TIMEOUT);

	//int i
	//for (i =  0; i < 6; ++i)
	//	printf("%d\n", (uint8_t)redst[i]);

	return (redst[4] >= 0 && redst[5] != 0)? redst[4]: ERR_READ; // Verify error
}

// Turn on servo LED - return error state
int ax_led_turnon (int fd, int id)
{
	// Valid ID
	if (ax_verify_id (id) == 0) return INVAL_ID;

	// Packet to send
	char instructions[8] = {(char)0xff, (char)0xff, (char)id, (char)4, (char)AX_WRITE_DATA, (char)AX_LED, (char)1, (char)0};
	// Packet to read
	char redst[6] = {0, 0, 0, 0, 0, 0};

	// Checksum
	instructions[7] = ax_checksum (instructions);

	// Comunication
	if (serial_io_flush (fd) == ERR_PORT) return ERR_READ;
	serial_send (fd, instructions, 8);
	serial_read (fd, redst, 6, DEF_TIMEOUT);

	//int i
	//for (i =  0; i < 6; ++i)
	//	printf("%d\n", (uint8_t)redst[i]);

	return (redst[4] >= 0 && redst[5] != 0)? redst[4]: ERR_READ; // Verify error
}

// Turn off servo LED - return error state
int
ax_led_turnoff (int fd, int id)
{
	// Valid ID
	if (ax_verify_id (id) == 0) return INVAL_ID;

	// Packet to send
	char instructions[8] = {(char)0xff, (char)0xff, (char)id, (char)4, (char)AX_WRITE_DATA, (char)AX_LED, (char)0, (char)0};
	// Packet to read
	char redst[6] = {0, 0, 0, 0, 0, 0};

	// Checksum
	instructions[7] = ax_checksum (instructions);

	// Comunication
	if (serial_io_flush (fd) == ERR_PORT) return ERR_READ;
	serial_send (fd, instructions, 8);
	serial_read (fd, redst, 6, DEF_TIMEOUT);

	//int i
	//for (i =  0; i < 6; ++i)
	//	printf("%d\n", (uint8_t)redst[i]);

	return (redst[4] >= 0 && redst[5] != 0)? redst[4]: ERR_READ; // Verify error
}

// Verify id ranges
unsigned int
ax_verify_id (int ax_id)
{
	return (ax_id >= 1) && (ax_id <= 254); // 0 or 1
}






int ax_ping (int fd, int id){

	// Valid ID
	//if (ax_verify_id (id) == 0) return INVAL_ID;

	// Packet to send
	//char instructions[9] = {0xff, 0xff, id, 5, AX_WRITE_DATA, AX_GOAL_POSITION_L, (position%256), (position>>8), 0};

	char instructions[6] = {(char)0xff, (char)0xff, (char)id, (char)0x02 , (char)AX_PING, (char)0xFB};
	// Packet to read
	char redst[6] = {0, 0, 0, 0, 0, 0};
	serial_send (fd, instructions, 9);
	// Comunication
	if (serial_io_flush (fd) == ERR_PORT) return ERR_READ;

	serial_read (fd, redst, 6, DEF_TIMEOUT);

	int i;
	for (i =  0; i < 6; ++i)
		printf("%d\n", (uint8_t)redst[i]);
	
	return (redst[4] >= 0 && redst[5] != 0)? redst[4]: ERR_READ; // Verify errors


}
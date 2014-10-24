#ifndef AX12_DEF_H
#define AX12_DEF_H



extern "C" {
    #include "serial.h"
}
#include <stdio.h>
#include <stdint.h>

#define DEF_TIMEOUT 1000000
#define DEF_SERIAL_PORT "/dev/ttyUSB0"

/* Error serial port */
#define ERR_PORT -1

/* Error comunication */
#define ERR_READ -3
#define INVAL_ID -5

/* Funtion prototypes */
unsigned int ax_verify_id (int ax_id);
int ax_checksum (char *instructions);

int ax_set_position (int fd, int id, int position);
int ax_get_position (int fd, int id);

int ax_enable_torque (int fd, int id);
int ax_disable_torque (int fd, int id);

int ax_led_turnon (int fd, int id);
int ax_led_turnoff (int fd, int id);
int ax_ping (int fd, int id);


/* Definitions */

/* Default baudrate */
#define AX_DEF_BAUDRATE B1000000

/* The types of packets */
#define AX_PING (0x01)
#define AX_READ_DATA (0x02)
#define AX_WRITE_DATA (0x03)
#define AX_REG_WRITE (0x04)
#define AX_ACTION (0x05)
#define AX_RESET (0x06)
#define AX_SYNC_WIRTE 131

/* The types of errors */
#define AX_NO_ERROR 0
#define AX_ERR_IN_VOLT 1
#define AX_ERR_ANGL_LIM 2
#define AX_ERR_OVER_HE 4
#define AX_ERR_RANGE 8
#define AX_ERR_CHECKSUM 16
#define AX_ERR_OVERLOAD 32
#define AX_ERR_INSTRUCTION 64

/* Booleans */
#define AX_ENABLE 1
#define AX_DISABLE 0

/* Address */
typedef enum AX12_ADDRESS
	{
		AX_MODEL_NUMBER_L = 0x00,
		AX_MODEL_NUMBER_H,
		AX_FIRMWARE,
		AX_ID,
		AX_BAUD_RATE,
		AX_DELAY_TIME,
		AX_CW_ANGLE_LIMIT_L,
		AX_CW_ANGLE_LIMIT_H,
		AX_CCW_ANGLE_LIMIT_L,
		AX_CCW_ANGLE_LIMIT_H,
		AX_RESERVED_1,
		AX_HIGHEST_LIMIT_TEMP,
		AX_LOWEST_LIMIT_VOLTAGE,
		AX_HIGHEST_LIMIT_VOLTAGE,
		AX_MAX_TORQUE_L,
		AX_MAX_TORQUE_H,
		AX_STATUS_RETURN_LEVEL,
		AX_ALARM_LED,
		AX_ALARM_SHUTDOWN,
		AX_RESERVED_2,
		AX_DOWN_CALIBRATION_L,
		AX_DOWN_CALIBRATION_H,
		AX_UP_CALIBRATION_L,
		AX_UP_CALIBRATION_H,
		AX_TORQUE_ENABLE,
		AX_LED,
		AX_CW_COMPLIANCE_MARGIN,
		AX_CCW_COMPLIANCE_MARGIN,
		AX_CW_COMPLIANCE_SLOPE,
		AX_CCW_COMPLIANCE_SLOPE,
		AX_GOAL_POSITION_L,
		AX_GOAL_POSITION_H,
		AX_MOVING_SPEED_L,
		AX_MOVING_SPEED_H,
		AX_TORQUE_LIMIT_L,
		AX_TORQUE_LIMIT_H,
		AX_PRESENT_POSITION_L,
		AX_PRESENT_POSITION_H,
		AX_PRESENT_SPEED_L,
		AX_PRESENT_SPEED_H,
		AX_PRESENT_LOAD_L,
		AX_PRESENT_LOAD_H,
		AX_PRESENT_VOLTAGE,
		AX_PRESENT_TEMP,
		AX_PRESENT_REGINST,
		AX_RESERVED_3,
		AX_MOVING,
		AX_LOCK,
		AX_PUNCH_L,
		AX_PUNCH_H
	} AX_ADDRESS;
 
#endif


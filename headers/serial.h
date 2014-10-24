/******************************************************************/
/* serial.h    Dr. Juan Gonzalez Gomez.    January, 2009          */
/******************************************************************/
/* Modified	by	Pedro Espinoza (px2ec)		June, 2013	          */
/*----------------------------------------------------------------*/
/* Serial communications in Linux                                 */
/*----------------------------------------------------------------*/
/* GPL LICENSE                                                    */
/******************************************************************/

#ifndef SERIAL_H
#define SERIAL_H

#include <termios.h>

/*--------------------------*/
/* FUNCTION PROTOTYPES      */
/*--------------------------*/

int  serial_open(char *serial_name, speed_t baud);
void serial_send(int serial_fd, char *data, int size);
int  serial_read(int serial_fd, char *data, int size, int timeout_usec);
void serial_close(int fd);
int serial_io_flush(int serial_fd);
int serial_inputflush(int serial_fd);
int serial_outputflush(int serial_fd);

#endif  
#include "serial.h"


/* UNUSED BLOCK
#ifdef __USE_INACTIVE_
#ifdef _WIN32
bool AutoPortInit(char* portname, OUT HANDLE* hCom)
{
	// INCOMPLETE FUNCTION

	HANDLE hand;

	// Create a handle to port using the CreateFile macro
	hand = CreateFile(portname,					// port name
		GENERIC_READ | GENERIC_WRITE,			// Read and Write
		0,										// No Sharing
		NULL,									// No Security
		OPEN_EXISTING,							// Open existing port only
		0,										// Non Overlapped I/O
		NULL);									// Null for Comm Devices

	if (hand == INVALID_HANDLE_VALUE)
	{
		*hCom = NULL;
		return false;
	}
	else
	{
		*hCom = hand;
		return true;
	}
}

void CloseHandle(HANDLE hCom)
{
	//Closing the Serial Port
	CloseHandle(hCom);
}

#endif // _WIN32
#endif // __USE_INACTIVE_
UNUSED BLOCK */

#ifdef linux
int InitPort(char* portname, OUT int* outFd)
{
	int fd = open(portname, O_RDWR | O_NOCTTY | O_SYNC);
	*outFd = fd;

	tcdrain(fd);
	
	struct termios tty;
	if (tcgetattr(fd, &tty) < 0)
	{
		return false;
	}

	cfsetospeed(&tty, (speed_t)B115200);
	cfsetispeed(&tty, (speed_t)B115200);

	// Ignore Modem Controls
	tty.c_cflag |= (CLOCAL | CREAD); 
	tty.c_cflag &= ~CSSIZE;

	// 8 Bit characters
	tty.c_cflag |= CS8;

	// No Parity
	tty.c_cflag &= ~PARENB;

	// 1 Stop Bit
	tty.c_cflag &= ~CSTOPB;

	// No Flow Control
	tty.c_cflag &= ~CRTSCTS;
	
	// Non-Canonical Mode
	tty.c_iflag &= (~IGNBRK | BRKINT | ISTRIP | INLCR | IGNCR | ICRNL | IXON);
	tty.c_lflag &= (~ECHO | ECHONL | ICANON | ISIG | IEXTEN);
	tty.o_oflag &= ~OPOST;

	// Fetch bytes as they become available
	tty.c_cc[VMIN] = 1;
	tty.c_cc[VTIME] = 1;


	if (tcsetattr(fd, TCSANOW, &tty) != 0)
	{
		return false;
	}
	return true;
}

bool SetMincount(int fd, int mcount)
{
	struct termios tty;
	if (tcgetattr(fd, &tty) < 0)
	{
		return false;
	}

	tty.c_cc[VMIN] = mcount ? 1 : 0;
	tty.c_cc[VTIME] = 5;

	if (tcgetattr(fd, TCSANOW, &tty) < 0)
	{
		return false;
	}

	return true;
}

#endif // linux
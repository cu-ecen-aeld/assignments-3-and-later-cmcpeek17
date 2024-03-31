/* 1. Check the amount of inputs. If != 2 -> exit
 * 2. If the directory for the file is not created, then create it.
 * 3. Try creating the file. If the file could not be created then exit with a 1
 * */

#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <fcntl.h>

int main ( int argc, char* argv[] ) {

	int fd;

	openlog(NULL, 0, LOG_USER);
	if (argc != 3) {
		syslog(LOG_ERR, "wrong amount of inputs provided: %d", argc);
		return 1;
	}

	fd = creat (argv[1], 0664);
	if (fd == -1) {
		syslog(LOG_ERR, "file could not be created");
		return 1;
	}
	
	ssize_t write_size;
	syslog(LOG_ERR, "Writing %s to %s\n", argv[1], argv[2]);
	write_size = write( fd, argv[2], strlen(argv[2]));
	
	if (write_size == -1) {
		syslog(LOG_ERR, "file could not be written");
		return 1;
	}

	if (close(fd) == -1) {
		syslog(LOG_ERR, "file could not be closed");
		return 1;
	} else {
		return 0;
	}

}

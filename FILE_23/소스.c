#include <stdio.h>	
#include <stdlib.h>	
#include <io.h>	
#include <fcntl.h>

void main(int argc, char* argv[]) {
	int fdi, i, n, adr;
	unsigned char buf[16];

	if ((fdi = open(argv[0], O_RDONLY | O_BINARY)) == -1) {
		printf("File not found\n", argv[0]);
		exit(0);
	}

	adr = 0;
	while ((n = read(fdi, buf, 16)) != 0) {
		printf("%04x: ", 16 * adr++);
		for (i = 0; i < n; i++)
			printf("%02x ", buf[i]);
		for (i = 0; i < n; i++) {
			if (buf[i] < ' ' || '~' < buf[i])
				putchar('.');
			else
				putchar(buf[i]);
		}
		putchar('\n');
	}
	close(fdi);
}
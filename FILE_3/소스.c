#include <stdio.h>	
#include <conio.h>	
#include <stdlib.h>
void main(void) {
	char c;   FILE *fp1, *fp2;
	fp1 = fopen("a.txt", "r");
	if (fp1 == NULL) {
		printf("File of c2.c not opened ! \n");
		exit(0);
	}
	fp2 = fopen("cc2_2.c", "w");
	while ((c = getc(fp1)) != EOF)
		putc(c, fp2);
	fclose(fp2);
	fclose(fp1);
}
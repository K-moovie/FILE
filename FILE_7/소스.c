#include <stdio.h>	
#include <conio.h>	
#include <stdlib.h>

void main(void) {
	int i;		FILE *fp;
	fp = fopen("test.txt", "w");
	if (fp == NULL) {
		printf("파일을 open할 수 없습니다.\n");
		exit(0);
	}
	for (i = 1; i <= 1000; i++) {
		fprintf(fp, "%d ", i * 10);
		if (i % 10 == 0)
			fprintf(fp, "\n");
	}
	fclose(fp);
}
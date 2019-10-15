#include <stdio.h>	
#include <conio.h>	
#include <stdlib.h>

struct mydata {
	char name[10]; int clang, vb, tot;	float avg;
};

void main(void) {
	FILE *inp, *outp;
	struct mydata person;
	inp = fopen("input1.txt", "r");
	if (inp == NULL) {
		printf("Cannot open file\n");
		exit(0);
	}
	outp = fopen("bin1.dat", "wb");
	if (outp == NULL) {
		printf("Cannot open file\n");
		exit(0);
	}
	while (1) {
		fscanf(inp, "%s %d %d", person.name,
			&person.clang, &person.vb);
		if (feof(inp) != 0)
			break;
		person.tot = person.clang + person.vb;
		person.avg = person.tot / 2.0;
		fwrite(&person, sizeof(person), 1, outp);
	}
	fclose(inp);
	fclose(outp);
}
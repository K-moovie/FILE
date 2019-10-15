#include <stdio.h>	
#include <conio.h>	
#include <stdlib.h>

struct mydata {
	char name[10];
	int clang, vb, tot;	float avg;
};
void main(void) {
	FILE *inp, *outp;
	struct mydata person;
	inp = fopen("bin1.dat", "rb");
	outp = fopen("test.txt", "w");
	if (inp == NULL) {
		printf("Cannot open file\n"); exit(0);
	}
	if (outp == NULL) {
		printf("Cannot open file\n"); exit(0);
	}
	while (1) {
		fread(&person, sizeof(person), 1, inp);
		fwrite(&person, sizeof(person), 1, outp);
		if (feof(inp) != 0)
			break;
		printf("%s, %3d %3d %3d %6.2f\n",
			person.name, person.clang,
			person.vb, person.tot, person.avg);
	}
	fclose(inp);
	fclose(outp);
}
/* Replicate a file with caps. */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>	

FILE *gfopen(char *filename, char *mode);// 전위선언

int main(int argc, char* argv[]) {
	int c;
	printf("%s", argv[0]);
	printf("%s", argv[1]);
	printf("%s", argv[2]);
	FILE *fp, *tmp_fp;
	if (argc != 2) {
		fprintf(stderr, "\n%s%s%s\n\n%s\n\n",
			"Usage:  ", argv[0], "  filename",
			"The file will be doubled and some letters capitalized.");
		exit(1);
	}

	fp = gfopen(argv[1], "r+");
	tmp_fp = tmpfile();
	while ((c = getc(fp)) != EOF)
		putc(toupper(c), tmp_fp);
	rewind(tmp_fp);
	fprintf(fp, "---\n");
	while ((c = getc(tmp_fp)) != EOF)
		putc(c, fp);
	return 0;
}

FILE *gfopen(char *filename, char *mode) {
	FILE   *fp;
	if ((fp = fopen(filename, mode)) == NULL) {
		fprintf(stderr, "Cannot open %s - bye!\n", filename);
		exit(1);
	}
	return fp;
}
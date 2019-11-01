#pragma warning (disable: 4996)
#include <stdio.h>

int main(void) {
	int left = 0, right = 9, shift = 0;
	char d = '0', temp = '0', arr[10];
	FILE* data, * sort;
	data = fopen("data.txt", "r"); sort = fopen("sorteddata.txt", "w");

	for (int i = 0; i < 10; i++)
	{
		arr[i] = fgetc(data, d);
	}

	if (data == NULL) {
		printf("file open error");
		exit(0);
	}

	for (;;) {
		if (left < right) {
			for (int i = left; i < right; i++) {
				if (arr[i] > arr[i + 1])
				{
					temp = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = temp;
					shift = i;
				}
				else
					continue;
			}
			right = shift;

			for (int i = right; i > left; i--) {
				if (arr[i-1] > arr[i])
				{
					temp = arr[i-1];
					arr[i-1] = arr[i];
					arr[i] = temp;
					shift = i;
				}
				else
					continue;
			}
			left = shift;
		}

		else
		{
			for (int i = 0; i < 10; i++)
			{
				fputc(arr[i], sort);
			}
			printf("정렬 성공");
			break;
		}
	}
	fclose(data); fclose(sort);
	return 0;
}
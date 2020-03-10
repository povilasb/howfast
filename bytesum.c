#include <stdio.h>

const int BUFF_SIZE = 65535;

int main(int argc, char* argv[])
{
	if (argc < 2) {
		printf("Usage: ./bytesum $filename\n");
		return 1;
	}

	FILE* f = fopen(argv[1], "rb");
	if (f == NULL) {
		printf("Failed to open file for reading\n");
		return 1;
	}

	unsigned char data[BUFF_SIZE];
	unsigned int s = 0;

	while (1) {
		int bytes_read = fread(data, 1, BUFF_SIZE, f);
		if (bytes_read == 0) {
			break;
		}

		for (int i = 0; i < bytes_read; i++) {
			s = (s + data[i]) % 255;
		}
	}

	printf("Sum % 255 = %u\n", s);

	fclose(f);
	f = NULL;

	return 0;
}

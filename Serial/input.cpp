#include <stdio.h>

int main() {
	while (true) {
		unsigned int number = 0;
		FILE *serPort = fopen("/dev/ttyACM11", "w");
		while (true) {
			printf(">>> ");
			scanf("%x", &number);
			printf("%d\n", number);

			unsigned char writeBuffer[] = { number };
			printf("%d\n", writeBuffer[0]);
			fwrite(writeBuffer, sizeof(unsigned char), sizeof(writeBuffer), serPort);
		}
		fclose(serPort);
		return 0;
	}
}

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
	FILE *fp;
	uint32_t num;
	uint32_t a = 0;

	for (int i = 1; i < argc; i++) {
		fp = fopen(argv[i], "rb");
		if (!fp) {
			printf("error");
			return 1;
		}
		if (fread(&num, 1, 4, fp) < 4){
			printf("Too small");
			return 1;
		}
		fclose(fp);	
		printf(" %u(0x%08x)",ntohl(num), ntohl(num));
		if (i < argc -1){
			printf(" +");
		}
		uint32_t all = ntohl(num);
		a += all;
	}
	printf("= %u(0x%08x)", a, ntohl(ntohl(a)));
	return 0;
}


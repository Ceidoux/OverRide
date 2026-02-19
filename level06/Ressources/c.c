#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int u = argv[1][3] ^ 0x1337U;
	printf("argv[1][3] ^ 0x1337U : %d\n", u);

	int h = u + 0x5eeded;
	printf("u + 0x5eeded : %d\n", h);

	int len = strlen(argv[1]);

	printf("\n\n");

	for (int i = 0; i < len; i++)
	{
		if (argv[1][i] < ' ') // < 20     - all not printable char
		{
			printf("error, not printable char.");
			return 0;
		}	
		int c = argv[1][i] ^ h;
		printf("argv[1][i] ^ h : %d\n", c);

		int g = c % 0x539;
		printf("c %% 0x539 : %d\n", g);
		
		h += g;
		printf("h += g : %d\n\n", h);
	}

	printf("\n\n - end --\n\n");
	printf("\t%d\n", h);

	if (atoi(argv[2]) == h)
	{
		printf("success !");
	}

	return 1;
}
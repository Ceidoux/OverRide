#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int debug;

	if ((argc == 3 && (debug = (argv[2][0] != '-' || argv[2][1] != 'd')))
		&& (argc != 2 || strlen(argv[1]) < 6))
		return 1;

	int u = argv[1][3] ^ 0x1337U;
	if (!debug)
		printf("argv[1][3] ^ 0x1337U : %d\n", u);

	int h = u + 0x5eeded;
	if (!debug)
		printf("u + 0x5eeded : %d\n", h);

	int len = strlen(argv[1]);

	if (!debug)
		printf("\n\n");

	for (int i = 0; i < len; i++)
	{
		if (argv[1][i] < ' ') // < 20     - all not printable char
		{
			printf("error, not printable char.");
			return 0;
		}	
		int c = argv[1][i] ^ h;
		if (!debug)
			printf("argv[1][%d] ^ h : %d\n", i, c);

		int g = c % 0x539;
		if (!debug)
			printf("c %% 0x539 : %d\n", g);
		
		h += g;
		if (!debug)
			printf("h += g : %d\n\n", h);
	}

	printf("\nserialization of\t%s\t: %d\n", argv[1], h);
	
	
	if (debug)
		printf("\nto see step by step, use the program with `-d` as 2nd argument.\n");
	return 0;
}
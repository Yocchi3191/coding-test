#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		printf("Usage: %s string\n", argv[0]);
		exit(-1);
	}

	int currentChar, prevChar, count;
	prevChar = 0;

	while ((currentChar = *(argv[1])++))
	{
		if (currentChar == prevChar)
		{
			count++;
		}
		else
		{
			if (prevChar)
			{
				printf("Char: %c, Count: %d\n", prevChar, count);
			}
			prevChar = currentChar;
			count = 1;
		}
	}
	printf("Char: %c, Count: %d\n", prevChar, count);
}
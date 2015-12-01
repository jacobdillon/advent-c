#include <stdio.h>
#include <stdbool.h>

int main(int argc, char* argv[])
{
	int floor = 0, charCounter = 0;
	int ch;
	bool firstBasement = true;

	FILE *input = fopen("input", "r");

	while ((ch = fgetc(input)) != EOF)
	{
		if(ch == '(')
		{
			floor++;
			charCounter++;
		} else if(ch == ')') {
			floor--;
			charCounter++;
		}

		if(firstBasement && floor == -1)
		{
			printf("Santa entered the basement at position %d\n", charCounter);
			firstBasement = false;
		}
	}

	printf("Santa ended on floor %d\n", floor);

	fclose(input);
	return 0;
}

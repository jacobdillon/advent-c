#include <stdio.h>

int main(int argc, char* argv[])
{
	int floor = 0;
	int ch;

	FILE *input = fopen("input", "r");

	while ((ch = fgetc(input)) != EOF)
	{
		if(ch == '(') floor++;
		else if(ch == ')') floor--;
	}

	printf("Santa is on floor %d\n", floor);

	fclose(input);
	return 0;
}

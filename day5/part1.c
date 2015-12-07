#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isNice(char str[])
{
	int vowels = 0;
	int doubleLetter = 0;

	for(int i = 0; i < strlen(str) - 1; i++)
	{
		if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
			vowels++;

		if(str[i] == str[i + 1])
			doubleLetter++;

		if(str[i] == 'a' && str[i + 1] == 'b')
			return false;

		if(str[i] == 'c' && str[i + 1] == 'd')
			return false;

		if(str[i] == 'p' && str[i + 1] == 'q')
			return false;

		if(str[i] == 'x' && str[i + 1] == 'y')
			return false;
	}

	if(vowels >= 3 && doubleLetter >= 1)
		return true;
	else
		return false;
}

int main(int argc, char* argv[])
{
	int count = 0;
	char str[20];

	FILE *input = fopen("input", "r");

	while (fgets(str, sizeof str, input) != NULL)
		if(isNice(str)) count++;

	printf("There are %d nice strings\n", count);

	fclose(input);
	return 0;
}

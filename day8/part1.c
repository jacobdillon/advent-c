#include <stdio.h>
#include <string.h>

int getMemChar(char str[])
{
	int count = 0;

	for(int i = 0; i < strlen(str); i++)
	{
		if(str[i] == '\\' && (str[i + 1] == '\\' || str[i + 1] == '\"'))
		{
			count++;
			i++;
		} else if(str[i] == '\\' && str[i + 1] == 'x') {
			count++;
			i += 3;
		} else {
			count++;
		}
	}

	return count - 2;
}

int main(int argc, char* argv[])
{
	int strChar = 0, memChar = 0;
	char str[100];

	FILE *input = fopen("input", "r");

	while (fgets(str, sizeof str, input) != NULL)
	{
		str[strcspn(str, "\n")] = 0;
		strChar += strlen(str);
		memChar += getMemChar(str);

		printf("%s: strChar: %d memChar: %d\n", str, strlen(str), getMemChar(str));
	}

	printf("There are %d characters of code for string literals\n", strChar);
	printf("There are %d characters in memory for the values of the strings\n", memChar);
	printf("strChar - memChar is %d\n", strChar - memChar);

	fclose(input);
	return 0;
}

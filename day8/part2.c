#include <stdio.h>
#include <string.h>

int getEncodedChar(char str[])
{
	int count = 0;

	for(int i = 0; i < strlen(str); i++)
	{
		if(str[i] == '\"' && (i == 0 || i == strlen(str) - 1))
		{
			count += 3;
		} else if(str[i] == '\\' && str[i + 1] == 'x') {
			count += 2;
		} else if(str[i] == '\"') {
			count += 2;
		} else if(str[i] == '\\') {
			count += 2;
		} else {
			count++;
		}
	}

	return count;
}

int main(int argc, char* argv[])
{
	int strChar = 0, encodedChar = 0;
	char str[100];

	FILE *input = fopen("input", "r");

	while (fgets(str, sizeof str, input) != NULL)
	{
		str[strcspn(str, "\n")] = 0;
		strChar += strlen(str);
		encodedChar += getEncodedChar(str);

		printf("%s: strChar: %d encodedChar: %d\n", str, strlen(str), getEncodedChar(str));
	}

	printf("\nThere are %d characters after encoding in the strings\n", encodedChar);
	printf("There are %d characters of code for string literals\n", strChar);
	printf("encodedChar - strChar is %d\n", encodedChar - strChar);

	fclose(input);
	return 0;
}

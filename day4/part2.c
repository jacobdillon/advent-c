#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <openssl/md5.h>

#define NUMOFZEROS 6

bool headCmp(char *string, int headNum, char charToCmp)
{
	char tmpStr[256];

	strncpy(tmpStr, string, headNum);
	tmpStr[headNum] = 0;

	for(int i = 0; i < headNum; i++)
		if(tmpStr[i] != charToCmp)
			return false;

	return true;
}

int main(int argc, char* argv[])
{
	char key[25];
	char tmpStr[25];
	char intStr[10];
	long int i = 0;
	bool isBeginningZero = false;

	strcpy(key, argv[1]);

	do
	{
		sprintf(intStr, "%d", i);
		strcpy(tmpStr, key);
		strcat(tmpStr, intStr);

		unsigned char digest[MD5_DIGEST_LENGTH];
		MD5((unsigned char*)&tmpStr, strlen(tmpStr), (unsigned char*)&digest);

		char md5string[33];
		for(int j = 0; j < 16; j++)
			sprintf(&md5string[j*2], "%02x", (unsigned int)digest[j]);

		//printf("%s : %s\n", tmpStr, md5string);

		isBeginningZero = headCmp(md5string, NUMOFZEROS, '0');

		i++;
	} while(!isBeginningZero);

	printf("%s\n", intStr);

	return 0;
}

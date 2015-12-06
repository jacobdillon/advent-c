#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char* argv[])
{
	int lights[1000][1000] = {0};

	int x1, y1, x2, y2;
	long int counter = 0;

	char instruction[40];
	char command[10];
	char argument[5];

	FILE *input = fopen("input", "r");

	while(fgets(instruction, sizeof instruction, input) != NULL)
	{
		bool hasArgument = false;

		sscanf(instruction, "%s", command);

		if(strcmp(command, "turn") == 0)
		{
			sscanf(instruction, "%*s %s %d %*c %d %*s %d %*c %d", argument, &x1, &y1, &x2, &y2);
			hasArgument = true;
		} else {
			sscanf(instruction, "%*s %d %*c %d %*s %d %*c %d", &x1, &y1, &x2, &y2);
		}

		for(int x = 0; x < 1000; x++)
		{
			for(int y = 0; y < 1000; y++)
			{
				if(y >= y1 && y <= y2)
				{
					if(x >= x1 && x <= x2)
					{
						if(hasArgument)
						{
							if(strcmp(argument, "on") == 0)
							{
								lights[x][y]++;
							}
							else if(strcmp(argument, "off") == 0)
							{
								if(lights[x][y] != 0) lights[x][y]--;
							}
						}
						else
						{
							lights[x][y] += 2;
						}
					}
				}
			}
		}
	}

	for(int y = 0; y < 1000; y++)
		for(int x = 0; x < 1000; x++)
			counter += lights[x][y];

	printf("The total brightness is %li\n", counter);

	fclose(input);
	return 0;
}

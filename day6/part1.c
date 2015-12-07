#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char* argv[])
{
	bool lights[1000][1000] = {false};

	int x1, y1, x2, y2;
	int counter = 0;

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
		}
		else
		{
			sscanf(instruction, "%*s %d %*c %d %*s %d %*c %d", &x1, &y1, &x2, &y2);
		}

		for(int x = 0; x < 1000; x++)
		{
			for(int y = 0; y < 1000; y++)
			{
				if((y >= y1 && y <= y2) && (x >= x1 && x <= x2))
				{
					if(hasArgument)
					{
						if(strcmp(argument, "on") == 0) lights[x][y] = true;
						else if(strcmp(argument, "off") == 0) lights[x][y] = false;
					}
					else
					{
						if(lights[x][y] == true) lights[x][y] = false;
						else if(lights[x][y] == false) lights[x][y] = true;
					}
				}
			}
		}
	}

	for(int y = 0; y < 1000; y++)
		for(int x = 0; x < 1000; x++)
			if(lights[x][y] == true) counter++;

	printf("There are %d lights lit\n", counter);

	fclose(input);
	return 0;
}

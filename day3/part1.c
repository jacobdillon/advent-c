#include <stdio.h>
#include <uthash.h>

typedef struct {
	int x;
	int y;
} location;

typedef struct {
	location loc; // key
	int presents;
	UT_hash_handle hh; // makes this structure hashable
} house;

house *grid = NULL;

void visitHouse(location house_loc)
{
	house *h;

	HASH_FIND(hh, grid, &house_loc, sizeof(location), h);
	if(h == NULL)
	{
		h = (house *)malloc(sizeof(house));
		h->loc.x = house_loc.x;
		h->loc.y = house_loc.y;
		HASH_ADD(hh, grid, loc, sizeof(location), h);
	}
	h->presents++;
}

int main(int argc, char* argv[])
{
	int ch;
	location loc = {0, 0};

	visitHouse(loc);

	FILE *input = fopen("input", "r");

	while ((ch = fgetc(input)) != EOF)
	{
		switch(ch)
		{
			case '>':
				loc.x++;
				visitHouse(loc);
				break;
			case '<':
				loc.x--;
				visitHouse(loc);
				break;
			case '^':
				loc.y++;
				visitHouse(loc);
				break;
			case 'v':
				loc.y--;
				visitHouse(loc);
				break;
			default:
				break;
		}
	}

	printf("Santa delivered to %u houses\n", (unsigned int)HASH_COUNT(grid));

	fclose(input);
	return 0;
}

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

house *santa = NULL;

void visitHouse(location house_loc)
{
	house *h;

	HASH_FIND(hh, santa, &house_loc, sizeof(location), h);
	if(h == NULL)
	{
		h = (house *)malloc(sizeof(house));
		h->loc.x = house_loc.x;
		h->loc.y = house_loc.y;
		HASH_ADD(hh, santa, loc, sizeof(location), h);
	}
	h->presents++;
}

int main(int argc, char* argv[])
{
	int ch;
	int i = 0;
	location loc = {0, 0};
	location loc2 = {0, 0};

	visitHouse(loc);

	FILE *input = fopen("input", "r");

	while ((ch = fgetc(input)) != EOF)
	{
		switch(ch)
		{
			case '>':
				if(i % 2 != 0)
				{
					loc.x++;
					visitHouse(loc);
				} else {
					loc2.x++;
					visitHouse(loc2);
				}

				i++;
				break;

			case '<':
				if(i % 2 != 0)
				{
					loc.x--;
					visitHouse(loc);
				} else {
					loc2.x--;
					visitHouse(loc2);
				}

				i++;
				break;

			case '^':
				if(i % 2 != 0)
				{
					loc.y++;
					visitHouse(loc);
				} else {
					loc2.y++;
					visitHouse(loc2);
				}

				i++;
				break;

			case 'v':
				if(i % 2 != 0)
				{
					loc.y--;
					visitHouse(loc);
				} else {
					loc2.y--;
					visitHouse(loc2);
				}

				i++;
				break;
		}
	}

	printf("Santa delivered to %u houses\n", (unsigned int)HASH_COUNT(santa));

	fclose(input);
	return 0;
}

#include <stdio.h>

int min(int x, int y)
{
	if(x <= y) return x;
	else if(y >= x) return y;
}

int main(int argc, char* argv[])
{
	char tmpStr[30];
	int l, w, h;
	long total = 0;

	FILE *input = fopen("input", "r");

	while (fgets(tmpStr, sizeof tmpStr, input) != NULL)
	{
		sscanf(tmpStr, "%d %*c %d %*c %d", &l, &w, &h);
		total += (2 * l * w) + (2 * w * h) + (2 * h * l);
		total += min(l * w, min(w * h, h * l));
	}

	printf("The elves need %d square feet of wrapping paper\n", total);

	fclose(input);
	return 0;
}

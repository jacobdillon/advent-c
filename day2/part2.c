#include <stdio.h>

int min(int x, int y)
{
	if(x <= y) return x;
	else if(y >= x) return y;
}

int main(int argc, char* argv[])
{
	char tmpStr[30];
	int l, w, h, minSide, minPerimeter;
	long ribbon = 0;
	long paper = 0;

	FILE *input = fopen("input", "r");

	while (fgets(tmpStr, sizeof tmpStr, input) != NULL)
	{
		sscanf(tmpStr, "%d %*c %d %*c %d", &l, &w, &h);

		minSide = min(l * w, min(w * h, h * l));

		paper += (2 * l * w) + (2 * w * h) + (2 * h * l);
		paper += minSide;

		if(minSide == l * w)
			minPerimeter = l + l + w + w;
		else if(minSide == w * h)
			minPerimeter = w + w + h + h;
		else
			minPerimeter = h + h + l + l;

		ribbon += minPerimeter;
		ribbon += l * w * h;
	}

	printf("The elves need %d feet of ribbon\n", ribbon);
	printf("The elves need %d square feet of wrapping paper\n", paper);

	fclose(input);
	return 0;
}

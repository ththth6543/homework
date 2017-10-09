#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
	char **player = (char **)calloc(10, sizeof(char *));
	int i, j, d, k;

	for (k = 0; k < 10; k++)
	{
		printf("입력 : ");
		*(player + k) = (char *)calloc(6, sizeof(char));
		for (i = 0; i < 4; i++)
		{
			*(*(player + k) + i) = getchar();
			if (((*(*(player + k) + i)) == '\n') || (*(*(player + k) + i) == EOF))
				break;
		}
	}
	for (j=0; j<10; j++)
		printf("%s", *(player+j));

	for (d = 0; d < 10; d++)
		free(player+d);

	return 0;
}

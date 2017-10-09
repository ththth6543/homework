#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
	char **player;
	int i, j, d, c, num, num_word = 0;
	num = 0;

	while (num<5)
	{
		printf("입력 : ");
		i = 0;
		while (1)
		{
			*(*(player + i) + 1) = getchar();
			
			if ((c == '\n') || (c == EOF))
			{
				player[i] = '\0';
				break;
			}
			*(*(player + i)) = c;
		}
		player = (char *)calloc(strlen(player) + 1, sizeof(char));
		num++;
	}
	for (j = 0; j<10; j++)
		printf("%s", player + j);

	for (d = 0; d < 10; d++)
		free(player+d);

	return 0;
}

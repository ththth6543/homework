#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
	char **player;
	int i, j, d;
	i = 0;
	player = (char **)calloc(10, sizeof(char));
	
	while (i<5)
	{
		printf("입력 : ");
		while (1)
		{
			*(player + i) = (char *)calloc(strlen(player)+1, sizeof(char));
			
			*(*(player + i) + 1) = getchar();
			
			

			if ((*(*(player + i) + 1) == '\n') || (*(*(player + i) + 1) == EOF))
			{
				player[i] = '\0';
				break;
			}
		}
		
		i++;
	}
	for (j = 0; j<10; j++)
		printf("%s", player[j]);

	for (d = 0; d < 10; d++)
		free(player+d);

	return 0;
}

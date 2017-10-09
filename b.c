#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
	char **player = (char **)calloc(10, sizeof(char *));
	int i, j, d;
	i = 0;
	
	while (i<10)
	{
		printf("입력 : ");
		while (i<10)
		{
			*(player + i) = (char *)calloc(4, sizeof(char));
			
			*(*(player + i)) = getchar();
			
			

			if ((*(*(player + i)) == '\n') || (*(*(player + i)) == EOF))
			{
				*(player+i) = '\0';
				break;
			}
		}
		
		i++;
	}
	for (j = 0; j < 10; j++)
	{
		printf("%s", *(player)+j);
		//printf("%d", atoi( *(*(player + j))) );
	}

	for (d = 0; d < 10; d++)
		free(player+d);

	return 0;
}

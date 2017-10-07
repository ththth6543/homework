#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 50
#define L 10


int main(void)
{
	char *words_p[10];
	char **player; 
	player = &words_p;
	int i, j, d, c, num, num_word = 0;
	num = 0;

	while(num<5)
	{
		printf("입력 : ");
		i=0;
		while(1)
		{
			c = getchar();
			if ((c=='\n') || (c== EOF))
			{
				player[i] = '\0';
				break;
			}
			player[i++] = c;
		}
		words_p[num] = (char *) calloc(strlen(player)+1, sizeof(char));
		strcpy(words_p[num], player);
		num++;
	}
	for (j=0; j<10; j++)
		printf("%s", words_p[j]);

	for (d=0; d < 10; d++)
		free(words_p[d]);
	
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
	char **player = (char **)calloc(10, sizeof(char *));
	int i, j, d, k,sum, p;
	sum = 0;

	for (k = 0; k < 10; k++)
	{
		printf("%d번 프레임 점수를 입력하세요 : ",k+1);
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

	for(p = 0; p < 10; p++)
		if (p != 9)//1~9 프레임
		{
			if (strlen(*(player + p)) == 2) // 스트라이크
			{
				if (strlen(*(player + p + 1)) == 2) // 스트라이크
				{
					if (strlen(*(player + p + 2)) == 2) // 스트라이크
						sum += 30
					else if (*(*(player + p + 2) + 1) == '/') //스플릿
						sum += 20 + atoi(*(player + p + 2));
					else                                   // 그 외의 경우
						sum += 20 + atoi(*(player + p + 2)) / 10;
				}
				else // 스트라이크 외의 경우
				{
					if (*(*(player + p + 1) + 1) == '/') //스플릿
						sum += 10 + atoi(*(player + p + 1));
					else                         // (숫자,숫자)
						sum += 10 + atoi(*(player + p + 1)) / 10;
				}
			}
			else if (*(*(player + p) + 1) == '/') // 스플릿
			{
				if (strlen(*(player + p + 1)) == 2) // 스트라이크
					sum += 20;
				else if (*(*(player + p + 1) + 1) == '/') // 스플릿
					sum += 10 + atoi(*(player + p + 1));
				else                                  // 그 외
					sum += 10 + atoi(*(player + p + 1)) / 10;
			}
			else                            // (숫자,숫자)
				sum += (atoi(*(player + p)) / 10) + (atoi(*(player + p)) % 10);
		}
		else // 10 프레임
		{
			if (strlen(*(player + p)) == 2) // 스트라이크
		}



	printf("%d", strlen(*(player + 1)));
	printf("%c", *(*(player + 1) + 1));
	printf("%d\n", atoi(*(player + 1 + 1)) );
	if ( *(*(player + 1) + 1) == '/' )
		printf("1");

	for (d = 0; d < 10; d++)
		free(player+d);

	return 0;
}

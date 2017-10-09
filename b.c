#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
	char **player = (char **)calloc(10, sizeof(char *));
	int i, j, d, k,sum, p;
	sum = 0;
	FILE *score_board; // 파일 입출력

	score_board = fopens("score.txt", "w");
	
	if ((score_board = fopens("score.txt", "w")) == NULL)
		printf("오류 : 파일을 열 수 없습니다.\n"); // 오류메세지

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


	/*for (j=0; j<10; j++) 입력됬는지 확인용
		printf("%s", *(player+j)); */

	for(p = 0; p < 10; p++) // 점수 계산
		if (p != 9)//1~9 프레임
		{
			if (*(*(player + p)) == 'x') // 스트라이크
			{
				if (*(*(player + p + 1)) == 'x') // 스트라이크
				{
					if (*(*(player + p + 2)) == 'x') // 스트라이크
						sum += 30;
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
						sum += 10 + (atoi(*(player + p + 1)) / 10);
				}
			}
			else if (*(*(player + p) + 1) == '/') // 스플릿
			{
				if (*(*(player + p + 1)) == 'x') // 스트라이크
					sum += 20;
				else if (*(*(player + p + 1) + 1) == '/') // 스플릿
					sum += 10 + atoi(*(player + p + 1));
				else                                  // 그 외
					sum += 10 + (atoi(*(player + p + 1)) / 10);
			}
			else                            // (숫자,숫자)
				sum += (atoi(*(player + p)) / 10) + (atoi(*(player + p)) % 10);
		}
		else // 10 프레임
		{
			if (*(*(player + p)) == 'x') // 스트라이크
			{
				if (*(*(player + p) + 1) == 'x') // 스트라이크
				{
					if (*(*(player + p) + 2) == 'x') // 스트라이크
						sum += 30;
					else
						sum += 20 + atoi(*(player + p)); // 스트라이크 외의 경우
				}
			}
			else if (*(*(player + p) + 1) == '/') // 스플릿
			{
				if (*(*(player + p) + 2) == 'x') // 스트라이크
					sum += 20;
				else
					sum += 10 + (((int) *(*(player + p) + 2)) - 48);
					// 스트라이크 외의 경우
			}
		}
	for (j = 0; j < 10; j++)
		fprintf(score_board, "%s", *(player + j));
	
	fclose(score_board);

	printf("총 점수는 %d점 입니다.\n", sum);

	for (d = 0; d < 10; d++)
		free(player+d);

	return 0;
}

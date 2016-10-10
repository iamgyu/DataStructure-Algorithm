#include "KMP.h"
#include <stdlib.h>

// 최대 경계의 너비를 보관하는 테이블을 만드는 함수
void Preprocess(char* Pattern, int PatternSize, int* Border)
{
	int i = 0;
	int j = -1;

	Border[0] = -1;

	while(i < PatternSize)
	{
		while (j > -1 && Pattern[i] != Pattern[j])
			j = Border[j];
		i++;
		j++;

		Border[i] = j;
	}
}

// 검색을 담당하는 함수
int KMP(char* Text, int TextSize, int Start, char* Pattern, int PatternSize)
{
	int i = Start;
	int j = 0;
	int Position = -1;

	int* Border = (int*)calloc(PatternSize + 1, sizeof(int));

	Preprocess(Pattern, PatternSize, Border);

	while (i < TextSize)
	{
		while (j >= 0 && Text[i] != Pattern[j])
			j = Border[j];

		i++;
		j++;

		if (j == PatternSize)
		{
			Position = i - j;
			break;
		}
	}

	free(Border);
	return Position;
}
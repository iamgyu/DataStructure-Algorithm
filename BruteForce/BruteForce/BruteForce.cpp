#include "BruteForce.h"

int BruteForce(char* Text, int TextSize, int Start, char* Pattern, int PatternSize)
{
	int i = 0;
	int j = 0;

	for (i = Start; i <= TextSize - PatternSize; i++)		// Text를 Start 위치부터 TextSize - PatternSize까지 차례로 순회
	{
		for (j = 0; j < PatternSize; j++)
		{
			if (Text[i + j] != Pattern[j])
				break;
		}

		if (j >= PatternSize)
			return i;
	}

	return -1;

}
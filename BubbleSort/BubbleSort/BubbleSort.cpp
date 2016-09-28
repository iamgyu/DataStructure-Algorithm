#include <iostream>

void BubbleSort(int DataSet[], int Length)
{
	for (int i = 0; i < Length - 1; i++)			// 데이터 집합의 크기만큼 내부에 있는 for 루프를 실행
	{
		for (int j = 0; j < Length - (i + 1); j++)	// 바깥에 있는 for문이 한번 실행될 때마다 그 반복 횟수가 줄어듬
		{											// 외부에 있는 for 루프를 한번 실행할 때마다 정렬 대상으로 삼는 
			if (DataSet[j] > DataSet[j + 1])		// 데이터 집합의 크기가 줄어들기 때문
			{
				int temp = DataSet[j + 1];
				DataSet[j + 1] = DataSet[j];
				DataSet[j] = temp;
			}
		}
	}
}

int main()
{
	int DataSet[] = { 6, 4, 2, 3, 1, 5 };
	int Length = sizeof DataSet / sizeof DataSet[0];	// sizeof 연산자를 이용해 배열의 길이를 구한 후 Length 초기화
	
	BubbleSort(DataSet, Length);

	for (int i = 0; i < Length; i++)
		printf("%d ", DataSet[i]);						// 정렬 후의 데이터 집합 출력

	printf("\n");

	return 0;
}
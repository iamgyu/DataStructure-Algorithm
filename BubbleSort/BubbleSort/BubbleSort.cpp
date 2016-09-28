#include <iostream>

void BubbleSort(int DataSet[], int Length)
{
	for (int i = 0; i < Length - 1; i++)			// ������ ������ ũ�⸸ŭ ���ο� �ִ� for ������ ����
	{
		for (int j = 0; j < Length - (i + 1); j++)	// �ٱ��� �ִ� for���� �ѹ� ����� ������ �� �ݺ� Ƚ���� �پ��
		{											// �ܺο� �ִ� for ������ �ѹ� ������ ������ ���� ������� ��� 
			if (DataSet[j] > DataSet[j + 1])		// ������ ������ ũ�Ⱑ �پ��� ����
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
	int Length = sizeof DataSet / sizeof DataSet[0];	// sizeof �����ڸ� �̿��� �迭�� ���̸� ���� �� Length �ʱ�ȭ
	
	BubbleSort(DataSet, Length);

	for (int i = 0; i < Length; i++)
		printf("%d ", DataSet[i]);						// ���� ���� ������ ���� ���

	printf("\n");

	return 0;
}
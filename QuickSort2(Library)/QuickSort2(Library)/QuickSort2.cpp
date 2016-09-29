#include <iostream>
#include <stdlib.h>
#include <string.h>

/*
void qsort(){
	void *base,										// 데이터 집합 배열의 주소
	size_t num,										// 데이터 요소의 개수
	size_t width,									// 한 데이터 요소의 크기
	int(_cdecl* compare)(const void*, const void *)	// 비교 함수에 대한 포인터
};
*/

// 리턴값이
// < 0 이면, _elem1이 _elem2 보다 작다
//  0  이면, _elem1이 _elem2 와 같다
// > 0 이면, _elem1이 _elem2 보다 크다

int CompareScore(const void * _elem1, const void * _elem2)
{
	int* elem1 = (int*)_elem1;
	int* elem2 = (int*)_elem2;

	if (*elem1 > *elem2)
		return 1;
	else if (*elem1 < *elem2)
		return -1;
	else
		return 0;
}

int main()
{
	int DataSet[] = { 6, 4, 2, 3, 1, 5 };
	int Length = sizeof DataSet / sizeof DataSet[0];	

	qsort((void*)DataSet, Length, sizeof(int), CompareScore);

	for (int i = 0; i < Length; i++)
		printf("%d ", DataSet[i]);

	printf("\n");

	return 0;
}
#include <stdlib.h>
#include <stdio.h>
#include "Score.h"

/*
void *bsearch(
	const void *key,		// 찾고자 하는 목표 값 데이터의 주소
	const void *base,		// 데이터 집합 배열의 주소
	size_t num,				// 데이터 요소의 개수
	size_t width,			// 한 데이터 요소의 크기
	int (__cdecl *compare)(const void *, const void *)
							// 비교 함수에 대한 포인터
*/

int CompareScore(const void *_elem1, const void *_elem2)
{
	Score* elem1 = (Score*)_elem1;
	Score* elem2 = (Score*)_elem2;

	if (elem1->score > elem2->score)
		return 1;
	else if (elem1->score < elem2->score)
		return -1;
	else
		return 0;
}


int main()
{
	int Length = sizeof DataSet / sizeof DataSet[0];
	int i = 0;
	Score  target;
	Score* found = NULL;

	/*  점수의 오름차순으로 정렬 */
	qsort((void*)DataSet, Length, sizeof(Score), CompareScore);

	/*  671.78 점을 받은 학생 찾기 */
	target.number = 0;
	target.score = 671.78;

	found = bsearch(
		(void*)&target,
		(void*)DataSet,
		Length,
		sizeof(Score),
		CompareScore);

	printf("found: %d %f \n", found->number, found->score);

	return 0;
}
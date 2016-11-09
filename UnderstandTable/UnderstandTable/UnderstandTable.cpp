#include <stdio.h>
#pragma warning(disable:4996)

typedef struct _empInfo
{
	int empNum;	// 직원의 고유번호 -> Key
	int age;	// 직원의 나이 -> value
}EmpInfo;

int main(void)
{
	EmpInfo empInfoArr[1000];
	EmpInfo ei;
	int eNum;

	printf("사번과 나이 입력: ");
	scanf("%d %d", &(ei.empNum), &(ei.age));
	empInfoArr[ei.empNum] = ei;

	printf("확인하고픈 직원의 사번 입력: ");
	scanf("%d", &eNum);

	ei = empInfoArr[eNum];
	printf("사번 %d, 나이 %d \n", ei.empNum, ei.age);
	return 0;
}

// 절대 효율적인 테이블이 아님 단순히 테이블을 이해하기 위한 예제일 뿐
#include <stdio.h>
#pragma warning(disable:4996)

typedef struct _empInfo
{
	int empNum;	// ������ ������ȣ -> Key
	int age;	// ������ ���� -> value
}EmpInfo;

int main(void)
{
	EmpInfo empInfoArr[1000];
	EmpInfo ei;
	int eNum;

	printf("����� ���� �Է�: ");
	scanf("%d %d", &(ei.empNum), &(ei.age));
	empInfoArr[ei.empNum] = ei;

	printf("Ȯ���ϰ��� ������ ��� �Է�: ");
	scanf("%d", &eNum);

	ei = empInfoArr[eNum];
	printf("��� %d, ���� %d \n", ei.empNum, ei.age);
	return 0;
}

// ���� ȿ������ ���̺��� �ƴ� �ܼ��� ���̺��� �����ϱ� ���� ������ ��
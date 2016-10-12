#include "ArrayList.h"
#include <iostream>

void ListInit(List* plist)
{
	(plist->numOfData) = 0;
	(plist->curPosition) = -1;
}

void LInsert(List* plist, LData data)
{
	if (plist->numOfData >= LIST_LEN)
	{
		puts("������ �Ұ����մϴ�");
		return;
	}

	plist->arr[plist->numOfData] = data;
	(plist->numOfData)++;
}

int LFirst(List* plist, LData* pdata)
{
	if (plist->numOfData == 0)		// ����� �����Ͱ� �ϳ��� ���ٸ�
		return FALSE;

	(plist->curPosition) = 0;		// ���� ��ġ �ʱ�ȭ! ù ��° �������� ������ �ǹ�!
	*pdata = plist->arr[0];			// pdata�� ����Ű�� ������ ������ ����
	
	return TRUE;
}

int LNext(List* plist, LData* pdata)
{
	if (plist->curPosition >= (plist->numOfData) - 1)		// �� �̻� ������ �����Ͱ� ���ٸ�
		return FALSE;

	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}

LData LRemove(List* plist)
{
	int rpos = plist->curPosition;		// ������ �������� �ε��� �� ����
	int num = plist->numOfData;
	LData rdata = plist->arr[rpos];		// ������ �����͸� �ӽ÷� ����

	// ������ ���� �������� �̵��� �����ϴ� �ݺ���
	for (int i = rpos; i < num - 1; i++)
		plist->arr[i] = plist->arr[i + 1];

	(plist->numOfData)--;				// �������� �� ����
	(plist->curPosition)--;				// ������ġ�� �ϳ� �ǵ�����
	return rdata;						// ������ �������� ��ȯ
}

int LCount(List* plist)
{
	return plist->numOfData;
}
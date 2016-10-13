#include "CLinkedList.h"
#include <iostream>

void ListInit(List* plist)
{
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}

void LInsert(List* plist, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL)
	{
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
		plist->tail = newNode;				// LInsertFront 함수와의 유일한 차이점
	}

	(plist->numOfData)++;
}


void LInsertFront(List* plist, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL)
	{
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
	}

	(plist->numOfData)++;
}

int LFirst(List* plist, Data* pdata)
{
	if (plist->tail == NULL)			// 저장된 노드가 없다면
		return FALSE;

	plist->before = plist->tail;		// before가 꼬리를 가리키게 한다
	plist->cur = plist->tail->next;		// cur이 머리를 가리키게 한다
	
	*pdata = plist->cur->data;			// cur이 가리키는 노드의 데이터 반환
	return TRUE;
}

int LNext(List* plist, Data* pdata)
{
	if (plist->tail == NULL)			// 저장된 노드가 없다면
		return FALSE;

	plist->before = plist->cur;			// before가 다음 노드를 가리키게 한다
	plist->cur = plist->cur->next;		// cur이 다음 노드를 가리키게 한다

	*pdata = plist->cur->data;			// cur이 가리키는 노드의 데이터 반환
	return TRUE;
}

Data LRemove(List* plist)
{
	Node* rpos = plist->cur;
	Data rdata = rpos->data;

	if (rpos == plist->tail)			// 삭제할 노드를 tail이 가리킨다면
	{
		if (plist->tail == plist->tail->next)	// 그리고 마지막 노드라면
			plist->tail = NULL;
		else
			plist->tail = plist->before;
	}

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List* plist)
{
	return plist->numOfData;
}
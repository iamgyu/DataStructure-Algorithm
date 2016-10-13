#ifndef __C_LINKED_LIST_H
#define __C_LINKED_LIST_H

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node* next;
}Node;

typedef struct _CLL
{
	Node* tail;
	Node* cur;
	Node* before;
	int numOfData;
}CList;

typedef CList List;

void ListInit(List* plist);					// 초기화
void LInsert(List* plist, Data data);		// 꼬리에 노드를 추가
void LInsertFront(List* plist, Data data);	// 머리에 노드를 추가

int LFirst(List* plist, Data* pdata);		// 첫 데이터 참조
int LNext(List* plist, Data* pdata);		// 두 번째 이후 데이터 참조
Data LRemove(List* plist);					// 참조한 데이터 삭제
int LCount(List* plist);					// 저장된 데이터의 수 반환

#endif
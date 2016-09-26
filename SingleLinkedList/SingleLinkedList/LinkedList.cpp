#include "LinkedList.h"

// ��� ���� �Լ�
Node* SLL_CreateNode(ElementType NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData;	// �����͸� �����Ѵ�
	NewNode->NextNode = NULL;	// ���� ��忡 ���� �����ʹ� NULL�� �ʱ�ȭ�Ѵ�
	
	return NewNode;				// ����� �ּҸ� ��ȯ�Ѵ�
}

// ��� �Ҹ� �Լ�
void SLL_DestroyNode(Node* Node)
{	
	free(Node);
}

// ��� �߰� �Լ�
void SLL_AppendNode(Node** Head, Node* NewNode)
{
	// ��� ��尡 NULL�̶�� ���ο� ��尡 Head
	if ((*Head) == NULL)
	{
		*Head = NewNode;
	}
	else
	{
		// ������ ã�� NewNode�� ���� �Ѵ�
		Node* Tail = (*Head);
		while (Tail->NextNode != NULL)
		{
			Tail = Tail->NextNode;
		}

		Tail->NextNode = NewNode;
	}
}

// ��� ���� �Լ�
void SLL_InsertAfter(Node* Current, Node* NewNode)
{
	NewNode->NextNode = Current->NextNode;
	Current->NextNode = NewNode;
}

void SLL_InsertNewHead(Node** Head, Node* NewHead)
{
	if (*Head == NULL)
	{
		(*Head = NewHead);
	}
	else
	{
		NewHead->NextNode = (*Head);
		(*Head) = NewHead;
	}
}

// ��� ���� �Լ�
void SLL_RemoveNode(Node** Head, Node* Remove)
{
	if (*Head == Remove)
	{
		*Head = Remove->NextNode;
	}
	else
	{
		Node* Current = *Head;
		while (Current != NULL && Current->NextNode != Remove)
		{
			Current = Current->NextNode;
		}

		if (Current != NULL)
			Current->NextNode = Remove->NextNode;
	}
}

// ��� Ž�� �Լ�
Node* SLL_GetNodeAt(Node* Head, int Location)
{
	Node* Current = Head;

	while (Current != NULL && (--Location) >= 0)
	{
		Current = Current->NextNode;
	}

	return Current;
}

// ��� �� ���� �Լ�
int SLL_GetNodeCount(Node* Head)
{
	int Count = 0;
	Node* Current = Head;

	while (Current != NULL)
	{
		Current = Current->NextNode;
		Count++;
	}

	return Count;
}
#include "RedBlackTree.h"

extern RBTNode* Nil;

RBTNode* RBT_CreateNode(ElementType NewData)
{
	RBTNode* NewNode = (RBTNode*)malloc(sizeof(RBTNode));
	NewNode->Parent = NULL;
	NewNode->Left = NULL;
	NewNode->Right = NULL;
	NewNode->Data = NewData;
	NewNode->Color = RBTNode::BLACK;

	return NewNode;
}

void RBT_DestroyNode(RBTNode* Node)
{
	free(Node);
}

void RBT_DestroyTree(RBTNode* Tree)
{
	if (Tree->Right != Nil)
		RBT_DestroyTree(Tree->Right);

	if (Tree->Left != Nil)
		RBT_DestroyTree(Tree->Left);

	Tree->Left = Nil;
	Tree->Right = Nil;

	RBT_DestroyNode(Tree);
}

RBTNode* RBT_SearchNode(RBTNode* Tree, ElementType Target)
{
	if (Tree == Nil)
		return NULL;

	if (Tree->Data > Target)
		return RBT_SearchNode(Tree->Left, Target);
	else if (Tree->Data < Target)
		return RBT_SearchNode(Tree->Right, Target);
	else
		return Tree;
}

RBTNode* RBT_SearchMinNode(RBTNode* Tree)
{
	if (Tree == Nil)
		return Nil;

	if (Tree->Left == Nil)
		return Tree;
	else
		return RBT_SearchMinNode(Tree->Left);
}

void RBT_InsertNode(RBTNode** Tree, RBTNode* NewNode)
{
	RBT_InsertNodeHelper(Tree, NewNode);

	NewNode->Color = RBTNode::RED;
	NewNode->Left = Nil;
	NewNode->Right = Nil;

	RBT_RebuildAfterInsert(Tree, NewNode);
}

void RBT_InsertNodeHelper(RBTNode** Tree, RBTNode* NewNode)
{
	if ((*Tree) == NULL)
		(*Tree) = NewNode;

	if ((*Tree)->Data < NewNode->Data)
	{
		if ((*Tree)->Right == Nil)
		{
			(*Tree)->Right = NewNode;
			NewNode->Parent = (*Tree);
		}
		else
			RBT_InsertNodeHelper(&(*Tree)->Right, NewNode);
	}
	else if ((*Tree)->Data > NewNode->Data)
	{
		if ((*Tree)->Left == Nil)
		{
			(*Tree)->Left = NewNode;
			NewNode->Parent = (*Tree);
		}
		else
			RBT_InsertNodeHelper(&(*Tree)->Left, NewNode);
	}
}

void RBT_RotateRight(RBTNode** Root, RBTNode* Parent)
{
	RBTNode* LeftChild = Parent->Left;

	Parent->Left = LeftChild->Right;			// 왼쪽 자식 노드의 오른쪽 자식 노드를 부모 노드의 왼쪽 자식으로 등록

	if (LeftChild->Right != Nil)
		LeftChild->Right->Parent = Parent;

	LeftChild->Parent = Parent->Parent;

	if (Parent->Parent == NULL)					// 부모가 NULL 이라면 이 노드는 Root이다
		(*Root) = LeftChild;					// 이 경우에는 왼쪽 자식을 Root 노드로 만들어 회전시킨다
	else
	{
		if (Parent == Parent->Parent->Left)		// 왼쪽 자식 노드를 부모 노드가 있던 곳(할아버지의 자식 노드)에 위치시킨다
			Parent->Parent->Left = LeftChild;
		else
			Parent->Parent->Right = LeftChild;
	}

	LeftChild->Right = Parent;
	Parent->Parent = LeftChild;
}

void RBT_RotateLeft(RBTNode** Root, RBTNode* Parent)
{
	RBTNode* RightChild = Parent->Right;

	Parent->Right = RightChild->Left;			// 오른쪽 자식 노드의 왼쪽 자식 노드를 부모 노드의 오른쪽 자식으로 등록

	if (RightChild->Left != Nil)
		RightChild->Left->Parent = Parent;

	RightChild->Parent = Parent->Parent;

	if (Parent->Parent == NULL)					// 부모가 NULL 이라면 이 노드는 Root이다
		(*Root) = RightChild;					// 이 경우에는 왼쪽 자식을 Root 노드로 만들어 회전시킨다
	else
	{
		if (Parent == Parent->Parent->Left)		// 오른쪽 자식 노드를 부모 노드가 있던 곳(할아버지의 자식 노드)에 위치시킨다
			Parent->Parent->Left = RightChild;
		else
			Parent->Parent->Right = RightChild;
	}

	RightChild->Left = Parent;
	Parent->Parent = RightChild;
}

void RBT_RebuildAfterInsert(RBTNode** Root, RBTNode* X)
{
	while (X != (*Root) && X->Parent->Color == RBTNode::RED)
	{
		if (X->Parent == X->Parent->Parent->Left)
		{
			RBTNode* Uncle = X->Parent->Parent->Right;
			if (Uncle->Color == RBTNode::RED)
			{
				X->Parent->Color = RBTNode::BLACK;
				Uncle->Color = RBTNode::BLACK;
				X->Parent->Parent->Color = RBTNode::RED;

				X = X->Parent->Parent;
			}
			else
			{
				if (X == X->Parent->Right)
				{
					X = X->Parent;
					RBT_RotateLeft(Root, X);
				}

				X->Parent->Color = RBTNode::BLACK;
				X->Parent->Parent->Color = RBTNode::RED;

				RBT_RotateRight(Root, X->Parent->Parent);
			}
		}
		else
		{
			RBTNode* Uncle = X->Parent->Parent->Left;
			if (Uncle->Color == RBTNode::RED)
			{
				X->Parent->Color = RBTNode::BLACK;
				Uncle->Color = RBTNode::BLACK;
				X->Parent->Parent->Color = RBTNode::RED;

				X = X->Parent->Parent;
			}
			else
			{
				if (X == X->Parent->Left)
				{
					X = X->Parent;
					RBT_RotateRight(Root, X);
				}

				X->Parent->Color = RBTNode::BLACK;
				X->Parent->Parent->Color = RBTNode::RED;
				RBT_RotateLeft(Root, X->Parent->Parent);
			}
		}
	}

	(*Root)->Color = RBTNode::BLACK;
}

RBTNode* RBT_RemoveNode(RBTNode** Root, ElementType Data)
{
	RBTNode* Removed = NULL;
	RBTNode* Successor = NULL;
	RBTNode* Target = RBT_SearchNode((*Root), Data);

	if (Target == NULL)
		return NULL;

	if (Target->Left == Nil || Target->Right == Nil)
	{
		Removed = Target;
	}
	else
	{
		Removed = RBT_SearchMinNode(Target->Right);
		Target->Data = Removed->Data;
	}

	if (Removed->Left != Nil)
		Successor = Removed->Left;
	else
		Successor = Removed->Right;

	Successor->Parent = Removed->Parent;

	if (Removed->Parent == NULL)
		(*Root) = Successor;
	else
	{
		if (Removed == Removed->Parent->Left)
			Removed->Parent->Left = Successor;
		else
			Removed->Parent->Right = Successor;
	}

	if (Removed->Color == RBTNode::BLACK)
		RBT_RebuildAfterRemove(Root, Successor);

	return Removed;
}

void RBT_RebuildAfterRemove(RBTNode** Root, RBTNode* Successor)
{
	RBTNode* Sibling = NULL;

	while (Successor->Parent != NULL && Successor->Color == RBTNode::BLACK)
	{
		if (Successor == Successor->Parent->Left)
		{
			Sibling = Successor->Parent->Right;

			if (Sibling->Color == RBTNode::RED)
			{
				Sibling->Color = RBTNode::BLACK;
				Successor->Parent->Color = RBTNode::RED;
				RBT_RotateLeft(Root, Successor->Parent);


			}
			else
			{
				if (Sibling->Left->Color == RBTNode::BLACK && Sibling->Right->Color == RBTNode::BLACK)
				{
					Sibling->Color = RBTNode::RED;
					Successor = Successor->Parent;
				}
				else
				{
					if (Sibling->Left->Color == RBTNode::RED)
					{
						Sibling->Left->Color = RBTNode::BLACK;
						Sibling->Color = RBTNode::RED;

						RBT_RotateRight(Root, Sibling);
						Sibling = Successor->Parent->Right;
					}

					Sibling->Color = Successor->Parent->Color;
					Successor->Parent->Color = RBTNode::BLACK;
					Sibling->Right->Color = RBTNode::BLACK;
					RBT_RotateLeft(Root, Successor->Parent);
					Successor = (*Root);
				}
			}
		}
		else
		{
			Sibling = Successor->Parent->Left;

			if (Sibling->Color == RBTNode::RED)
			{
				Sibling->Color = RBTNode::BLACK;
				Successor->Parent->Color = RBTNode::RED;
				RBT_RotateRight(Root, Successor->Parent);
			}
			else
			{
				if (Sibling->Right->Color == RBTNode::BLACK && Sibling->Left->Color == RBTNode::BLACK)
				{
					Sibling->Color = RBTNode::RED;
					Successor = Successor->Parent;
				}
				else
				{
					if (Sibling->Right->Color == RBTNode::RED)
					{
						Sibling->Right->Color = RBTNode::BLACK;
						Sibling->Color = RBTNode::RED;

						RBT_RotateLeft(Root, Sibling);
						Sibling = Successor->Parent->Left;
					}

					Sibling->Color = Successor->Parent->Color;
					Successor->Parent->Color = RBTNode::BLACK;
					Sibling->Left->Color = RBTNode::BLACK;
					RBT_RotateRight(Root, Successor->Parent);
					Successor = (*Root);
				}
			}
		}
	}

	Successor->Color = RBTNode::BLACK;
}

void RBT_PrintTree(RBTNode* Node, int Depth, int BlackCount)
{
	char c = 'X';
	int v = -1;
	char cnt[100];

	if (Node == NULL || Node == Nil)
		return;

	if (Node->Color == RBTNode::BLACK)
		BlackCount++;

	if (Node->Parent != NULL)
	{
		v = Node->Parent->Data;

		if (Node->Parent->Left == Node)
			c = 'L';
		else
			c = 'R';
	}

	if (Node->Left == Nil && Node->Right == Nil)
		sprintf(cnt, "---------- %d", BlackCount);
	else
		sprintf(cnt, "");

	for (int i = 0; i < Depth; i++)
		printf(" ");

	printf(" %d %s [%c, %d] %s\n", Node->Data, (Node->Color == RBTNode::RED) ? "RED" : "BLACK", c, v, cnt);

	RBT_PrintTree(Node->Left, Depth + 1, BlackCount);
	RBT_PrintTree(Node->Right, Depth + 1, BlackCount);
}
#ifndef __C_QUEUE_H
#define __C_QUEUE_H

#define TRUE 1
#define FALSE 0

#define QUE_LEN 100
typedef int Data;

typedef struct _cQueue
{
	int front;				// �׸��� ���ؼ� F�� ǥ���ߴ� ���
	int rear;				// �׸��� ���ؼ� R�̶� ǥ���ߴ� ���
	Data queArr[QUE_LEN];
}CQUEUE;

typedef CQUEUE Queue;

void QueueInit(Queue* pq);
int QIsEmpty(Queue* pq);

void Enqueue(Queue* pq, Data data);
Data Dequeue(Queue* pq);
Data QPeek(Queue* pq);

#endif
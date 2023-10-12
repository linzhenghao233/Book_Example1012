#include <stdio.h> 
#include <stdlib.h>
#define MAXSIZE 100

typedef int datatype;
typedef struct {
	datatype data[MAXSIZE];
	int front;
	int rear;
}Sequeue;

//构造空队列
Sequeue* InitQueue() {
	Sequeue* q;

	q = (Sequeue*)malloc(sizeof(Sequeue));
	q->front = 0;
	q->rear = 0;

	return q;
}

//判断队空
int QueueEmpty(Sequeue* q) {
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}

//入队
int EnQueue(Sequeue* q, datatype x) {
	if ((q->rear + 1) % MAXSIZE == q->front) {
		printf("队列已满\n");

		return 0;
	}
	q->data[q->rear] = x;
	q->rear = (q->rear + 1) % MAXSIZE;

	return 1;
}

//出队
datatype DeQueue(Sequeue* q) {
	datatype x;

	if (q->front == q->rear) {
		printf("队列为空\n");

		return 0;
	}
	x = q->data[q->front];
	q->front = (q->front + 1) % MAXSIZE;

	return 1;
}

//打印
void Display(Sequeue* q) {
	int s;
	s = q->front;

	if (q->front == q->rear)
		printf("队列为空\n");
	else {
		while (s != q->rear) {
			printf("%d->", q->data[s]);
			s = (s + 1) % MAXSIZE;
		}
		puts("NULL");
	}
}

int main(void) {
	int a[6] = { 3, 7, 4, 12, 31, 15 }, i;
	Sequeue* p;
	p = InitQueue();
	for (i = 0; i < 6; i++) {
		EnQueue(p, a[i]);
	}
	printf("该队列为:");
	Display(p);
	EnQueue(p, 100);
	EnQueue(p, 200);
	printf("\n该队列为:");
	Display(p);
	DeQueue(p);
	DeQueue(p);
	printf("\n该队列为:");
	Display(p);

	return 0;
}
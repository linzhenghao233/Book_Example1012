#include <stdio.h> 
#include <stdlib.h>
#define MAXSIZE 100

typedef int datatype;
typedef struct {
	datatype data[MAXSIZE];
	int front;
	int rear;
}Sequeue;

//����ն���
Sequeue* InitQueue() {
	Sequeue* q;

	q = (Sequeue*)malloc(sizeof(Sequeue));
	q->front = 0;
	q->rear = 0;

	return q;
}

//�ж϶ӿ�
int QueueEmpty(Sequeue* q) {
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}

//���
int EnQueue(Sequeue* q, datatype x) {
	if ((q->rear + 1) % MAXSIZE == q->front) {
		printf("��������\n");

		return 0;
	}
	q->data[q->rear] = x;
	q->rear = (q->rear + 1) % MAXSIZE;

	return 1;
}

//����
datatype DeQueue(Sequeue* q) {
	datatype x;

	if (q->front == q->rear) {
		printf("����Ϊ��\n");

		return 0;
	}
	x = q->data[q->front];
	q->front = (q->front + 1) % MAXSIZE;

	return 1;
}

//��ӡ
void Display(Sequeue* q) {
	int s;
	s = q->front;

	if (q->front == q->rear)
		printf("����Ϊ��\n");
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
	printf("�ö���Ϊ:");
	Display(p);
	EnQueue(p, 100);
	EnQueue(p, 200);
	printf("\n�ö���Ϊ:");
	Display(p);
	DeQueue(p);
	DeQueue(p);
	printf("\n�ö���Ϊ:");
	Display(p);

	return 0;
}
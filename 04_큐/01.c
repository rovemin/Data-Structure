/* ����ť */

#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;    //ť�� ��� Ÿ��
typedef struct {        //ť Ÿ��
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
} QueueType;

void error(char* message)   //���� �Լ�
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_queue(QueueType* q)   //ť �ʱ�ȭ
{
    q->rear = -1;
    q->front = -1;
}

void queue_print(QueueType* q)  //ť�� ���
{
    for (int i=0; i<MAX_QUEUE_SIZE; i++) {
        if (i <= q->front || i> q->rear)
            printf("    | ");
        else
            printf("%d  | ", q->data[i]);
    }
    printf("\n");
}

int is_full(QueueType* q)   //ť�� �� ������ ����?
{
    if (q->rear == MAX_QUEUE_SIZE - 1)
        return 1;
    else
        return 0;
}

int is_empty(QueueType* q)  //ť�� ����°�?
{
    if (q->front == q->rear)
        return 1;
    else
        return 0;
}

void enqueue(QueueType* q, int item)  //ť�� ����
{
    if (is_full(q)) {
        error("ť�� ��ȭ�����Դϴ�.");
        return;
    }
    q->data[++(q->rear)] = item;
}

int dequeue(QueueType* q)   //ť���� ����
{
    if (is_empty(q)) {
        error("ť�� ��������Դϴ�.");
        return -1;
    }
    int item = q->data[++(q->front)];
    return item;
}

int main(void){
    int item = 0;
    QueueType q;    //ť ����

    init_queue(&q); //ť�� �ʱ�ȭ

    enqueue(&q, 10);    queue_print(&q);    //ť�� ����
    enqueue(&q, 20);    queue_print(&q);
    enqueue(&q, 30);    queue_print(&q);

    item = dequeue(&q); queue_print(&q);    //ť���� ����
    item = dequeue(&q); queue_print(&q);
    item = dequeue(&q); queue_print(&q);

    return 0;
}
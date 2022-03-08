/* ���� ���α׷� (������/�Һ���) */

//random number sequence�� ���� ������/�Һ���
//��Ȳ�� �ùķ��̼��ϴ� ���α׷�

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ===== ����ť �ڵ� ���� =====
#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct {    //ť Ÿ��
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

void error (char* message)  //���� �Լ�
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_queue(QueueType* q)   //�ʱ�ȭ
{
    q->front = q->rear = 0;
}

int is_empty(QueueType* q)  //���� ���� ����
{
    return (q->front == q->rear);
}

int is_full(QueueType* q)   //��ȭ ���� ����
{
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void queue_print(QueueType* q)  //ť�� ���
{
    printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
    if (!is_empty(q)) {
        int i = q->front;
        do {    //front+1, front+2, ... �̷��� �ִ� �� ������ ����
            i = (i + 1) % (MAX_QUEUE_SIZE);
            printf("%d | ", q->data[i]);
            if (i == q->rear)
                break;
        } while (i != q->front);
    }
    printf("\n");
}

void enqueue(QueueType* q, element item)    //���� �Լ�
{
    if (is_full(q))
        error("ť�� ��ȭ�����Դϴ�");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

element dequeue(QueueType* q)   //���� �Լ�
{
    if (is_empty(q))
        error("ť�� ��������Դϴ�.");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

int main(void) {
    QueueType queue;
    init_queue(&queue);

    srand(time(NULL));  //ù° random number ����

    for (int i=0; i<100; i++) {
        if (rand() % 5 == 0) {  //5�� ������ �������� (����)
            enqueue(&queue, rand() % 100);  //2�ڸ����� ����� ����
        }
        queue_print(&queue);

        if (rand() % 10 == 0) { //10���� ������ �������� (�Һ�)
            int data = dequeue(&queue); //ť���� ����
        }
        queue_print(&queue);
    }
    return 0;
}
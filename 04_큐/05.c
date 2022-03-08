/* ���� ���� �ùķ��̼� */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUEUE_SIZE 5
// ===== ����ť �ڵ� ���� =====
typedef struct {
    int id;
    int arrival_time;
    int service_time;
}element;
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
// ===== ����ť �ڵ� ���� =====

int main() {
    int minutes = 60;   //�� ���� �ð�
    int total_wait = 0; //��ü ���� ���ð� �հ�
    int total_customers = 0;    //������ ���� ��
    int service_time = 0;   //�� 1�� ���� �ð� (1~3��)
    int service_customer;   //���� ó������ �� ��ȣ
    element customer;   //ť�� ��� Ÿ��

    QueueType queue;    //ť�� ����
    init_queue(&queue); //ť �ʱ�ȭ

    srand(time(NULL));  //���� ������ �ʱ�ȭ
    for (int clock = 0; clock<minutes; clock++) {   //1�� ������ 1�ð� ���� ����
        //���� �����ߴ°� Ȯ���Ѵ�.
        //      �����ߴٸ� �� ��ȣ ����, ���� �ð� (1~3�� ����) �����Ͽ� ť�� �����Ѵ�.
        //���� ���� ���� ���� �ִٸ� 1�а� ���񽺸� �Ѵ�.
        //      ���ٸ� ť���� �� 1���� ������ ��� �ð��� ����ϰ�, ��ü ���ð��� ���Ѵ�.
        //      ���� �ð��� ������ ���´�.
        printf("����ð�=%d\n", clock);
        if ((rand() % 10) < 3) {    //0~9�� ���ڷ� ��ȯ, �� ���� ��Ȳ
            customer.id = total_customers++;
            customer.arrival_time = clock;
            customer.service_time = rand() % 3 + 1; //���񽺴� 1��~3�� ���̷� ����
            enqueue(&queue, customer);  //ť�� �� ����
            printf("�� %d�� %d�п� ���ɴϴ�. ����ó���ð�= %d��\n", 
                customer.id, customer.arrival_time, customer.service_time);
        }
        if (service_time > 0) { //���� ó�� ���� ���� �ִٸ� 1�а� ó��
            printf("�� %d ����ó�����Դϴ�. \n", service_customer);
            service_time--;
        }
        else {
            if (!is_empty(&queue)) {    //��� ���� ���� �ִٸ�
                customer = dequeue(&queue); //�� ���� ����
                service_customer = customer.id;
                service_time = customer.service_time;   //�� ���� �ð� ����
                printf("�� %d�� %d�п� ������ �����մϴ�. ���ð��� %d���̾����ϴ�.\n",
                    customer.id, clock, clock - customer.arrival_time);
                total_wait += clock - customer.arrival_time;    //��ü ���ð� ������Ʈ
            }
        }
    }
    printf("��ü ��� �ð�=%d�� \n", total_wait);
    return 0;
}
/* 원형큐 */

#include <stdio.h>
#include <stdlib.h>

// ===== 원형큐 코드 시작 =====
#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct {    //큐 타입
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

void error (char* message)  //오류 함수
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_queue(QueueType* q)   //초기화
{
    q->front = q->rear = 0;
}

int is_empty(QueueType* q)  //공백 상태 검출
{
    return (q->front == q->rear);
}

int is_full(QueueType* q)   //포화 상태 검출
{
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void queue_print(QueueType* q)  //큐의 출력
{
    printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
    if (!is_empty(q)) {
        int i = q->front;
        do {    //front+1, front+2, ... 이렇게 최대 한 바퀴를 돈다
            i = (i + 1) % (MAX_QUEUE_SIZE);
            printf("%d | ", q->data[i]);
            if (i == q->rear)
                break;
        } while (i != q->front);
    }
    printf("\n");
}

void enqueue(QueueType* q, element item)    //삽입 함수
{
    if (is_full(q))
        error("큐가 포화상태입니다");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

element dequeue(QueueType* q)   //삭제 함수
{
    if (is_empty(q))
        error("큐가 공백상태입니다.");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

int main(void) {
    QueueType queue;
    int element;

    init_queue(&queue);

    printf("--데이터 추가 단계--\n");
    while (!is_full(&queue)) {
        printf("정수를 입력하시오: ");
        scanf_s("%d", &element);
        enqueue(&queue, element);
        queue_print(&queue);
    }
    printf("큐는 포화상태입니다.\n\n");

    printf("--데이터 삭제 단계--\n");
    while (!is_empty(&queue)) {
        element = dequeue(&queue);
        printf("꺼내진 정수: %d \n", element);
        queue_print(&queue);
    }
    printf("큐는 공백상태입니다.\n");
    return 0;
}
/* 연결 리스트로 구현한 큐 */

#include <stdio.h>
#include <stdlib.h>

typedef int element;        //요소 타입
typedef struct QueueNode {  //노드 타입
    element data;
    struct QueueNode* link;
} QueueNode;

typedef struct {    //큐
    QueueNode* front, * rear;
} LinkedQueueType;

//큐 초기화 함수
void init(LinkedQueueType* q) {
    q->front = q->rear = NULL;
}

int is_empty(LinkedQueueType* q) {
    return (q->front == NULL);
}

//삽입 함수
void enqueue(LinkedQueueType* q, element data) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->data = data;
    temp->link = NULL;
    if (is_empty(q)) {
        q->front = temp;
        q->rear = temp;
    }
    else {
        q->rear->link = temp;
        q->rear = temp;
    }
}

//삭제 함수
element dequeue(LinkedQueueType* q) {
    QueueNode* temp = q->front;
    element data;
    if (is_empty(q)) {
        fprintf(stderr, "스택이 비어있음\n");
        exit(1);
    }
    else {
        data = temp->data;          //데이터를 꺼낸다
        q->front = q->front->link;  //front는 다음 노드로 이동
        if (q->front == NULL)       //공백 상태
            q->rear = NULL;
        free(temp);
        return data;
    }
}

void print_queue(LinkedQueueType* q) {
    QueueNode* p;
    for (p = q->front; p != NULL; p = p->link)
        printf("%d->", p->data);
    printf("NULL\n");
}

int main() {
    LinkedQueueType queue;
    init(&queue);

    enqueue(&queue, 1); print_queue(&queue);
    enqueue(&queue, 2); print_queue(&queue);
    enqueue(&queue, 3); print_queue(&queue);

    dequeue(&queue);    print_queue(&queue);
    dequeue(&queue);    print_queue(&queue);
    dequeue(&queue);    print_queue(&queue);

    return 0;
}
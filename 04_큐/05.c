/* 은행 업무 시뮬레이션 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUEUE_SIZE 5
// ===== 원형큐 코드 시작 =====
typedef struct {
    int id;
    int arrival_time;
    int service_time;
}element;
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
// ===== 원형큐 코드 종료 =====

int main() {
    int minutes = 60;   //총 영업 시간
    int total_wait = 0; //전체 고객의 대기시간 합계
    int total_customers = 0;    //서비스한 고객의 수
    int service_time = 0;   //고객 1명 서비스 시간 (1~3분)
    int service_customer;   //현재 처리중인 고객 번호
    element customer;   //큐의 요소 타입

    QueueType queue;    //큐의 생성
    init_queue(&queue); //큐 초기화

    srand(time(NULL));  //난수 시퀸스 초기화
    for (int clock = 0; clock<minutes; clock++) {   //1분 단위로 1시간 동안 수행
        //고객이 도착했는가 확인한다.
        //      도착했다면 고객 번호 지정, 서비스 시간 (1~3분 랜덤) 세팅하여 큐에 삽입한다.
        //현재 서비스 중인 고객이 있다면 1분간 서비스를 한다.
        //      없다면 큐에서 고객 1명을 꺼내어 대기 시간을 출력하고, 전체 대기시간에 더한다.
        //      서비스 시간을 세팅해 놓는다.
        printf("현재시각=%d\n", clock);
        if ((rand() % 10) < 3) {    //0~9의 숫자로 변환, 고객 도착 상황
            customer.id = total_customers++;
            customer.arrival_time = clock;
            customer.service_time = rand() % 3 + 1; //서비스는 1분~3분 사이로 지정
            enqueue(&queue, customer);  //큐에 고객 삽입
            printf("고객 %d이 %d분에 들어옵니다. 업무처리시간= %d분\n", 
                customer.id, customer.arrival_time, customer.service_time);
        }
        if (service_time > 0) { //현재 처리 중인 고객이 있다면 1분간 처리
            printf("고객 %d 업무처리중입니다. \n", service_customer);
            service_time--;
        }
        else {
            if (!is_empty(&queue)) {    //대기 중인 고객이 있다면
                customer = dequeue(&queue); //고객 서비스 시작
                service_customer = customer.id;
                service_time = customer.service_time;   //고객 서비스 시간 세팅
                printf("고객 %d이 %d분에 업무를 시작합니다. 대기시간은 %d분이었습니다.\n",
                    customer.id, clock, clock - customer.arrival_time);
                total_wait += clock - customer.arrival_time;    //전체 대기시간 업데이트
            }
        }
    }
    printf("전체 대기 시간=%d분 \n", total_wait);
    return 0;
}
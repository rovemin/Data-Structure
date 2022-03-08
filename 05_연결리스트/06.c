/* Lab4: 리스트를 역순으로 만드는 연산 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;

typedef struct ListNode {   //노드 타입
    element data;
    struct ListNode* link;
} ListNode;

//오류 처리 함수
void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

//리스트 맨 앞에 삽입
ListNode* insert_first(ListNode* head, element value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));  //노드 생성
    p->data = value;    //노드에 값 대입
    p->link = head;     //리스트의 맨 앞에 삽입
    head = p;           //헤드 포인터 변경
    return head;
}

//리스트 출력
void print_list(ListNode* head) {
    for (ListNode* p = head; p != NULL; p = p->link)
        printf("%d->", p->data);
    printf("NULL \n");
}

//리스트를 역순으로 만드는 연산
ListNode* reverse(ListNode* head) {
    //순회 포인터로 p, q, r을 사용
    ListNode* p, * q, * r;

    p = head;   //p는 역순으로 만들 리스트
    q = NULL;   //q는 역순으로 만들 노드
    while(p != NULL) {
        r = q;  //r은 역순으로 된 리스트
                //r은 q, q는 p를 차례로 따라간다
        q = p;
        p = p->link;
        q->link = r;    //q의 링크 방향을 바꾼다
    }
    return q;
}

int main() {
    ListNode* head = NULL;

    printf("head 리스트 생성 과정 \n");
    head = insert_first(head, 40);
    print_list(head);
    head = insert_first(head, 30);
    print_list(head);
    head = insert_first(head, 20);
    print_list(head);
    head = insert_first(head, 10);
    print_list(head);

    printf("\n역순으로 된 리스트\n");
    head = reverse(head);
    print_list(head);
    return 0;
}
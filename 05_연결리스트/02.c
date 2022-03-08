/* 단순 연결 리스트 */

#include <stdio.h>
#include <stdlib.h>

//노드의 정의
typedef int element;
typedef struct ListNode {   //노드 타입을 구조체로 정의한다.
    element data;
    struct ListNode* link;
} ListNode;

//삽입 연산
ListNode* insert_first(ListNode* head, int value){
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}

//삽입 연산
//노드 pre 뒤에 새로운 노드 삽입
ListNode* insert(ListNode* head, ListNode* pre, element value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = pre->link;
    pre->link = p;
    return head;
}

//삭제 연산
ListNode* delete_first(ListNode* head) {
    ListNode* removed;
    if (head == NULL) return NULL;
    removed = head;
    head = removed->link;
    free(removed);
    return head;
}

//삭제 연산
//pre가 가리키는 노드의 다음 노드 삭제
ListNode* delete(ListNode* head, ListNode* pre) {
    ListNode* removed;
    removed = pre->link;
    pre->link = removed->link;
    free(removed);
    return head;
}

//head가 가리키는 리스트 전체 출력
void print_list(ListNode* head) {
    for (ListNode* p = head; p != NULL; p = p->link)
        printf("%d->", p->data);
    printf("NULL \n");
}

int main() {
    ListNode* head = NULL;

    for (int i=0; i<5; i++) {
        head = insert_first(head, i);
        print_list(head);
    }

    for (int i=0; i<5; i++) {
        head = delete_first(head);
        print_list(head);
    }

    return 0;
}
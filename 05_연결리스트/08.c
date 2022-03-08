/* 원형 연결 리스트 프로그램 */

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {   //노드 타입
    element data;
    struct ListNode* link;
} ListNode;

ListNode* insert_first(ListNode* head, element data) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    if (head == NULL) {
        head = node;
        node->link = head;
    }
    else {
        node->link = head->link;
        head->link = node;
    }
    return head;
}

ListNode* insert_last(ListNode* head, element data) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    if (head == NULL) {
        head = node;
        node->link = head;
    }
    else {
        node->link = head->link;
        head->link = node;
        head = node;
    }
    return head;
}

//리스트 출력
void print_list(ListNode* head) {
    ListNode* p;

    if (head == NULL) return;
    p = head->link; //첫째 노드
    do {
        printf("%d->", p->data);
        p = p->link;
    } while (p != head);
    printf("%d->", p->data);    //마지막 노드 출력
}

int main() {
    ListNode* head = NULL;

    head = insert_last(head, 20);
    head = insert_last(head, 30);
    head = insert_last(head, 40);
    head = insert_first(head, 10);
    print_list(head);
    return 0;
}
/* 멀티 플레이어 게임 - 연결 리스트의 응용: 원형 큐의 구현 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//노드의 데이터 타입, element는 크기가 100인 문자 배열의 이름
typedef char element[100];
typedef struct ListNode {   //노드 타입
    element data;
    struct ListNode* link;
} ListNode;

ListNode* insert_first(ListNode* head, element data) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    strcpy(node->data, data);
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

//원형 연결 리스트 테스트 프로그램
int main(void) {
    ListNode* head = NULL;

    head = insert_first(head, "KIM");
    head = insert_first(head, "PARK");
    head = insert_first(head, "CHOI");

    ListNode* p = head;
    
    for (int i=0; i<10; i++) {
        printf("현재 차례=%s \n", p->data);
        p = p->link;
    }
    return 0;
}
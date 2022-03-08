/* Lab2: 특정한 값을 탐색하는 함수 */

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

//리스트에서 특정 값 탐색
ListNode* search_list(ListNode* head, element x) {
    ListNode* p = head;
    while (p != NULL) {
        if (p->data == x) return p;
        p = p->link;
    }
    return NULL;    //탐색 실패
}

int main() {
    ListNode* head = NULL;
    head = insert_first(head, 10);
    print_list(head);
    head = insert_first(head, 20);
    print_list(head);
    head = insert_first(head, 30);
    print_list(head);
    if (search_list(head, 10) != NULL)
        printf("리스트에서 10을 찾았습니다. \n");
    else
        printf("리스트에서 10을 찾지 못했습니다. \n");
    return 0;
}
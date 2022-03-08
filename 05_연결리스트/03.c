/* Lab1: 단어들을 저장하고 있는 연결리스트 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
} element;

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
        printf("%s->", p->data.name);
    printf("NULL \n");
}

//테스트 프로그램
int main() {
    ListNode* head = NULL;
    element data;

    strcpy(data.name, "APPLE");
    head = insert_first(head, data);
    print_list(head);

    strcpy(data.name, "KIWI");
    head = insert_first(head, data);
    print_list(head);

    strcpy(data.name, "BANANA");
    head = insert_first(head, data);
    print_list(head);

    return 0;
}
/* Lab3: 2개의 리스트를 합하는 함수 */

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

//두 리스트를 합하는 함수
ListNode* concat_list(ListNode* head1, ListNode* head2) {
    if (head1 == NULL) return head2;
    else if (head2 == NULL) return head1;
    else {
        ListNode* p;
        p = head1;
        while (p->link != NULL)
            p = p->link;
        p->link = head2;
        return head1;
    }
}

int main() {
    ListNode* head1 = NULL;
    ListNode* head2 = NULL;

    printf("head1 리스트 생성 과정 \n");
    head1 = insert_first(head1, 30);
    print_list(head1);
    head1 = insert_first(head1, 20);
    print_list(head1);
    head1 = insert_first(head1, 10);
    print_list(head1);

    printf("\nhead2 리스트 생성 과정 \n");
    head2 = insert_first(head2, 60);
    print_list(head2);
    head2 = insert_first(head2, 50);
    print_list(head2);
    head2 = insert_first(head2, 40);
    print_list(head2);

    printf("\n합해진 리스트 head1 \n");
    head1 = concat_list(head1, head2);
    print_list(head1);

    return 0;
}
/* Lab2: Ư���� ���� Ž���ϴ� �Լ� */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;

typedef struct ListNode {   //��� Ÿ��
    element data;
    struct ListNode* link;
} ListNode;

//���� ó�� �Լ�
void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

//����Ʈ �� �տ� ����
ListNode* insert_first(ListNode* head, element value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));  //��� ����
    p->data = value;    //��忡 �� ����
    p->link = head;     //����Ʈ�� �� �տ� ����
    head = p;           //��� ������ ����
    return head;
}

//����Ʈ ���
void print_list(ListNode* head) {
    for (ListNode* p = head; p != NULL; p = p->link)
        printf("%d->", p->data);
    printf("NULL \n");
}

//����Ʈ���� Ư�� �� Ž��
ListNode* search_list(ListNode* head, element x) {
    ListNode* p = head;
    while (p != NULL) {
        if (p->data == x) return p;
        p = p->link;
    }
    return NULL;    //Ž�� ����
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
        printf("����Ʈ���� 10�� ã�ҽ��ϴ�. \n");
    else
        printf("����Ʈ���� 10�� ã�� ���߽��ϴ�. \n");
    return 0;
}
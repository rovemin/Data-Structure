/* Lab1: �ܾ���� �����ϰ� �ִ� ���Ḯ��Ʈ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
} element;

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
        printf("%s->", p->data.name);
    printf("NULL \n");
}

//�׽�Ʈ ���α׷�
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
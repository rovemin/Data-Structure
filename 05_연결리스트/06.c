/* Lab4: ����Ʈ�� �������� ����� ���� */

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

//����Ʈ�� �������� ����� ����
ListNode* reverse(ListNode* head) {
    //��ȸ �����ͷ� p, q, r�� ���
    ListNode* p, * q, * r;

    p = head;   //p�� �������� ���� ����Ʈ
    q = NULL;   //q�� �������� ���� ���
    while(p != NULL) {
        r = q;  //r�� �������� �� ����Ʈ
                //r�� q, q�� p�� ���ʷ� ���󰣴�
        q = p;
        p = p->link;
        q->link = r;    //q�� ��ũ ������ �ٲ۴�
    }
    return q;
}

int main() {
    ListNode* head = NULL;

    printf("head ����Ʈ ���� ���� \n");
    head = insert_first(head, 40);
    print_list(head);
    head = insert_first(head, 30);
    print_list(head);
    head = insert_first(head, 20);
    print_list(head);
    head = insert_first(head, 10);
    print_list(head);

    printf("\n�������� �� ����Ʈ\n");
    head = reverse(head);
    print_list(head);
    return 0;
}
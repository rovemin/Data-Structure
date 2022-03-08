/* ������ ���� Ʈ���� ���� */

#include <stdio.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left, * right;
    int is_thread;  //���� ������ ��ũ�� �������̸� TRUE;
} TreeNode;

TreeNode* find_successor(TreeNode* p) {
    //q�� p�� ������ ������
    TreeNode* q = p->right;
    //���� ������ �����Ͱ� NULL�̰ų� �������̸� ������ �����͸� ��ȯ
    if (q == NULL || p->is_thread == 1)
        return q;
    //���� ������ �ڽ��̸� �ٽ� ���� ���� ���� �̵�
    while (q->left != NULL) q = q->left;
    return q;
}

void thread_inorder(TreeNode* t) {
    TreeNode* q;
    q = t;
    while(q->left) q = q->left; //���� ���� ���� ����
    do {
        printf("%d ", q->data); //������ ���
        q = find_successor(q);  //�ļ��� �Լ� ���
    } while (q);                //NULL�� �ƴϸ�
}

TreeNode n1 = {1, NULL, NULL, 1};
TreeNode n4 = {4, NULL, NULL, 1};
TreeNode n7 = {7, &n1, &n4, 0};
TreeNode n16 = {16, NULL, NULL, 1};
TreeNode n25 = {25, NULL, NULL, 0};
TreeNode n8 = {8, &n16, &n25, 0};
TreeNode n5 = {5, &n7, &n8, 0};

TreeNode* root = &n5;

int main(void) {
    //������ ����
    n1.right = &n7;
    n4.right = &n5;
    n16.right = &n8;

    //���� ��ȸ
    printf("���� ��ȸ=");
    thread_inorder(root);
    printf("\n");
    return 0;
}
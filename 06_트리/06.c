/* ���� Ʈ�� ���� : ��� ���� ���� */

#include <stdio.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left, * right;
} TreeNode;

int get_node_count(TreeNode* node) {
    int count = 0;
    if (node != NULL)
        count = 1 + get_node_count(node->left) + get_node_count(node->right);
    return count;
    
}

int main(void) {
    TreeNode n4 = {1, NULL, NULL};
    TreeNode n5 = {1, NULL, NULL};
    TreeNode n2 = {3, &n4, &n5};
    TreeNode n6 = {1, NULL, NULL};
    TreeNode n3 = {2, &n6, NULL};
    TreeNode n1 = {6, &n2, &n3};
    TreeNode* node = &n1;

    printf("����� ���� = %d\n", get_node_count(&n1));
}
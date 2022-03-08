/* 스레드 이진 트리의 구현 */

#include <stdio.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left, * right;
    int is_thread;  //만약 오른쪽 링크가 스레드이면 TRUE;
} TreeNode;

TreeNode* find_successor(TreeNode* p) {
    //q는 p의 오른쪽 포인터
    TreeNode* q = p->right;
    //만약 오른쪽 포인터가 NULL이거나 스레드이면 오른쪽 포인터를 반환
    if (q == NULL || p->is_thread == 1)
        return q;
    //만약 오른쪽 자식이면 다시 가장 왼쪽 노드로 이동
    while (q->left != NULL) q = q->left;
    return q;
}

void thread_inorder(TreeNode* t) {
    TreeNode* q;
    q = t;
    while(q->left) q = q->left; //가장 왼쪽 노드로 간다
    do {
        printf("%d ", q->data); //데이터 출력
        q = find_successor(q);  //후속자 함수 출력
    } while (q);                //NULL이 아니면
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
    //스레드 설정
    n1.right = &n7;
    n4.right = &n5;
    n16.right = &n8;

    //중위 순회
    printf("중위 순회=");
    thread_inorder(root);
    printf("\n");
    return 0;
}
// �迭�� �̿��� ������ ���� ������ �����ϴ� ���

#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100  // ������ �ִ� ũ��

typedef int element;            // �������� �ڷ���
element stack[MAX_STACK_SIZE];  // 1���� �迭
int top = -1;

// ������ ��� �ִ� �������� Ȯ���ϴ� �Լ�
int isEmpty() {
    return (top == -1);
}

// ������ ���� �� �������� Ȯ���ϴ� �Լ�
int isFull() {
    return (top == (MAX_STACK_SIZE - 1));
}

// ���� �Լ�
void push(element item) {
    if (isFull()) {
        printf("������ ���� á���ϴ�.\n");
        return;
    }
    else
        stack[++top] = item;
}

// ���� �Լ�
element pop() {
    if (isEmpty()) {
        printf("������ ��� �ֽ��ϴ�.\n");
        exit(1);    // ���� �߻� �� ���� ����
    }
    else
        return stack[top--];
}

// ��ũ �Լ�
element peek() {
    if (isEmpty()) {
        printf("������ ��� �ֽ��ϴ�.\n");
        exit(1);    // ���� �߻� �� ���� ����
    }
    else
        return stack[top];
}


int main(void) {
    push(10);
    push(7);
    push(6);
    push(5);
    printf("%d\n", pop());
    printf("%d\n", peek());
    printf("%d\n", pop());
    printf("%d\n", pop());
    push(3);
    printf("%d\n", pop());

    return 0;
}

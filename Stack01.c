// 배열을 이용한 스택을 전역 변수로 구현하는 방법

#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100  // 스택의 최대 크기

typedef int element;            // 데이터의 자료형
element stack[MAX_STACK_SIZE];  // 1차원 배열
int top = -1;

// 스택이 비어 있는 상태인지 확인하는 함수
int isEmpty() {
    return (top == -1);
}

// 스택이 가득 찬 상태인지 확인하는 함수
int isFull() {
    return (top == (MAX_STACK_SIZE - 1));
}

// 삽입 함수
void push(element item) {
    if (isFull()) {
        printf("스택이 가득 찼습니다.\n");
        return;
    }
    else
        stack[++top] = item;
}

// 삭제 함수
element pop() {
    if (isEmpty()) {
        printf("스택이 비어 있습니다.\n");
        exit(1);    // 에러 발생 시 강제 종료
    }
    else
        return stack[top--];
}

// 피크 함수
element peek() {
    if (isEmpty()) {
        printf("스택이 비어 있습니다.\n");
        exit(1);    // 에러 발생 시 강제 종료
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

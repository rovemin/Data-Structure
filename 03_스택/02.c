/* 스택의 요소가 구조체인 경우 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100  //스택의 최대 크기
#define MAX_STRING 100      //문자열의 최대 크기
typedef struct {            //스택 요소 (학생 정보)
    int student_no;             //학생 번호
    char name[MAX_STRING];      //학생 이름
    char address[MAX_STRING];   //학생 주소
} element;

element stack[MAX_STACK_SIZE];  //스택: 1차원 배열
int top = -1;

//공백 상태 검출 함수
int is_empty() {
    return (top == -1);
}

//포화 상태 검출 함수
int is_full() {
    return (top == (MAX_STACK_SIZE - 1));
}

//삽입 함수
void push(element item) {
    if (is_full()) {
        fprintf (stderr, "스택 포화 에러\n");
        return;
    }
    else stack[++top] = item;
}

//삭제 함수
element pop() {
    if (is_empty()) {
        fprintf (stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return stack[top--];
}

//피크 함수
element peek() {
    if (is_empty()) {
        fprintf (stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return stack[top];
}

int main(void) {
    element ie = {12345678, "김이화", "서울"};
    element oe;

    push(ie);
    oe = pop();

    printf("학번: %d\n", oe.student_no);
    printf("이름: %s\n", oe.name);
    printf("주소: %s\n", oe.address);
    return 0;
}
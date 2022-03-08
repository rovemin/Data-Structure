/* 포인터의 활용 예제 (2) */

#include <stdio.h>

void swap(int* p, int* q) {     //주소를 포인터 변수에 저장한다
    int temp;
    temp = *p;      //temp 변수에 p가 가리키는 변수의 값을 저장
    *p = *q;        //p가 가리키는 곳에 q가 가리키는 변수의 값을 저장
    *q = temp;      //q가 가리키는 곳에 temp 값을 저장
}

int main() {
    int a=10, b=20;
    printf("(1) a = %d, b = %d\n", a, b);
    swap(&a, &b);   //변수 a와 b의 주소를 보낸다
    printf("(2) a = %d, b = %d\n", a, b);
    return 0;
}

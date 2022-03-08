/* 포인터의 활용 예제 (1) */

#include <stdio.h>

int main() {
    int a, b;
    printf("양의 정수 2개를 입력하시오: ");
    scanf("%d%d", &a, &b);              //a와 b의 주소를 보냄
    printf("a = %d, b = %d\n", a, b);   //a와 b의 값을 보냄
    return 0;
}
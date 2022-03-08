/* 포인터의 활용 예제 (3) */

#include <stdio.h>

//두 수의 합과 곱을 계산하는 함수
void getSumAndProduct (int a, int b, int *sum_ptr, int *prod_ptr) {
    *sum_ptr = a + b;   //sum_ptr 포인터가 가리키는 곳에 합을 저장
    *prod_ptr = a * b;  //prod_ptr 포인터가 가리키는 곳에 곱을 저장
}

int main() {
    int x=10, y=20;
    int sum, prod;

    getSumAndProduct(x, y, &sum, &prod);    //x, y 값을 보냄    //sum, prod는 주소를 보냄
    printf("합계 = %d, 곱 = %d\n", sum, prod);
    return 0;
}

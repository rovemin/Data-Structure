/* 배열 접근 방법 : 포인터 q */

#include <stdio.h>

int main() {
    int A[5] = {10, 20, 30, 40, 50};
    int* p = A;
    int* q = p;     //q는 p가 가리키고 있는 원소를 가리킴
    for (int i=0; i<5; i++) {
        printf("%d ", *q);
        q++;        //배열의 다음 원소를 가리킴
    }
    return 0;
}

/* int * p[4]; */

#include <stdio.h>

int main(){
    int* p[4];  //정수 포인터 4개를 저장하는 배열
    int a=1, b=2, c=3, d=4;

    p[0] = &a;  p[1] = &b;
    p[2] = &c;  p[3] = &d;

    for (int i=0; i<4; i++) {
        printf("%d  ", *p[i]);
    }

    return 0;
}
/* 포인터의 이동 예제 */

#include <stdio.h>

int main() {
    int A=2, B=3, C=6, D=7, E=9;
    int * p=&A, * q=&B, * r=&C, * s=&D, * t=&E, * u;

    u=p;    //임시 포인터 u는 p가 가리키는 변수를 함께 가리킨다.
    p=q;    //p는 q가 가리키는 변수를 가리키게 된다.
    q=u;

    u=t;
    t=s;
    s=r;
    r=u;

    printf("%d %d %d %d %d\n", *q, *p, *s, *t, *r);
    return 0;
}

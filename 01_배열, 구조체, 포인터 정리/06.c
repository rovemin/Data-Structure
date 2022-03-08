/* 다항식 표현 방법 #2 */

#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 101
struct {
    float coef;
    int expon;
} terms[MAX_TERMS] = {{8,3}, {7,1}, {1,0}, {10,3}, {3,2}, {1,0}};
int avail = 6;  //전역 변수, terms[] 배열의 비어있는 첫째 요소의 인덱스

//정수 2개를 비교하여 크기 정보를 반환
char compare(int a, int b) {
    if (a > b) return '>';
    else if (a == b) return '=';
    else return '<';
}

//새로운 항을 다항식에 추가
void attach(float coef, int expon) {
    if (avail >= MAX_TERMS) {
        fprintf(stderr, "항의 개수가 너무 많음\n");
        exit(1);
    }
    else {
        terms[avail].coef = coef;
        terms[avail++].expon = expon;
    }
}

//C = A + B
poly_add2(int As, int Ae, int Bs, int Be, int* Cs, int* Ce) {
    float tempcoef;
    *Cs = avail;
    while (As <= Ae && Bs <= Be) 
        switch (compare(terms[As].expon, terms[Bs].expon)) {
            case '>': //A의 차수 > B의 차수
                attach(terms[As].coef, terms[As].expon);
                As++;           break;
            case '=': //A의 차수 == B의 차수
                tempcoef = terms[As].coef + terms[As].coef;
                if (tempcoef)
                    attach(tempcoef, terms[As].expon);
                As++; Bs++;     break;
            case '<': ///A의 차수 < B의 차수
                attach(terms[Bs].coef, terms[Bs].expon);
                Bs++;           break;
        }
    
    //A의 나머지 항들을 이동함
    for (; As <= Ae; As++)
        attach(terms[As].coef, terms[As].expon);
    //B의 나머지 항들을 이동함
    for (; Bs <= Be; Bs++)
        attach(terms[Bs].coef, terms[Bs].expon);
    *Ce = avail -1;
}

void print_poly(int s, int e) {
    for (int i=s; i<e; i++)
        printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon);
    printf("%3.1fx^%d\n", terms[e].coef, terms[e].expon);
}

int main(void) {
    int As=0, Ae=2, Bs=3, Be=5, Cs, Ce;
    poly_add2(As, Ae, Bs, Be, &Cs, &Ce);
    print_poly(As, Ae);
    print_poly(Bs, Be);
    printf("--------------------\n");
    print_poly(Cs, Ce);

    return 0;
}

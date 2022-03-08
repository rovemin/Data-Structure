/* 다항식 표현 방법 #1 */
#include <stdio.h>
#define MAX_DEGREE 101 //다항식의 최대 차수 +1
typedef struct {
    int degree;
    float coef[MAX_DEGREE];
} polynomial; //다항식 구조체 선언

//다항식 A와 B를 더한 결과를 반환한다.
polynomial poly_add1(polynomial A, polynomial B) {
    polynomial C;                       //결과 다항식
    int Apos = 0, Bpos = 0, Cpos = 0;   //배열 인덱스 변수
    int degree_a = A.degree;
    int degree_b = B.degree;
    C.degree = (A.degree > B.degree) ? A.degree : B.degree; //결과 다항식 차수
    while (Apos <= A.degree && Bpos <= B.degree) {
        if (degree_a > degree_b) {          //A항 > B항
            C.coef[Cpos++] = A.coef[Apos++];
            degree_a--;
        }
        else if (degree_a == degree_b){     //A항 == B항
            C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
            degree_a--; degree_b--;
        }
        else {                              //B항 > A항
            C.coef[Cpos++] = B.coef[Bpos++];
            degree_b--;
        }
    }
    return C;
}

void print_poly(polynomial p) {
    int i;
    for (i=p.degree; i>0; i--)
        printf("%3.1fx^%d + ", p.coef[p.degree-i], i);
    printf("%3.1f \n", p.coef[p.degree]);
}

int main(void) {
    polynomial a = {5, {3, 6, 0, 0, 0, 10}};
    polynomial b = {4, {7, 0, 5, 0, 1}};
    polynomial c;

    print_poly(a);
    print_poly(b);
    c = poly_add1(a, b);    //다항식의 덧셈
    printf("-------------------\n");
    print_poly(c);
    return 0;
}
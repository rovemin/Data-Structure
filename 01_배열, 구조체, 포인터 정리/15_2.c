/* 2차원 배열을 가리키는 배열에 대한 포인터 */
/* 개념: int (*p)[4];  */

#include <stdio.h>

int main() {
    int (*p)[4];    //4열짜리 1행을 가리킬 수 있는 포인터
    int A[3][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    int B[3][4] = {{10,20,30,40}, {50,60,70,80}};

    p = A;      //4열짜리 2차원 배열
    for (int i=0; i<3; i++) {
        for (int j=0; j<4; j++)
            printf("%4d", p[i][j]);     //*(*(p+i)+j) 와 같음
        printf("\n");
    }

    printf("\n");

    p = B;      //4열짜리 2차원 배열
    for (int i=0; i<2; i++) {
        for (int j=0; j<4; j++)
            printf("%4d", *(*(p+i)+j)); //p[i][j]와 같음
        printf("\n");
    }

    return 0;
}
/* 2차원 배열의 동적 할당 */
/* 5x7 행렬의 할당 예제 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main() {
    int(*p)[7]; //p는 7열짜리 1행을 가리키는 포인터
    int i, j;
    p = (int(*)[7])malloc(sizeof(int) * 5 * 7); //5행7열 배열로 사용할 예정
    if (p==NULL) {  //할당 오류 점검
        fprintf(stderr, "메모리가 부족해서 할당할 수 없습니다.\n");
        exit(1);
    }

    for (i=0; i<5; i++)     //배열에 데이터를 채움
        for (j=0; j<7; j++)
            p[i][j] = i * 10 + j;

    for (i=0; i<5; i++) {   //배열 출력
        for (j=0; j<7; j++)
            printf("%4d", p[i][j]);
        printf("\n");
    }

    return 0;
}
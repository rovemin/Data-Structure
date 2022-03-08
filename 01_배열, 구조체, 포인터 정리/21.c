/* 1차원 배열의 동적 할당 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define SIZE 10

int main() {
    int* p;     //할당받은 배열을 가리킬 포인터
    p = (int*)malloc(SIZE * sizeof(int));   //배열 할당
    if (p==NULL) {  //할당 오류 점검
        fprintf(stderr, "메모리가 부족해서 할당할 수 없습니다.\n");
        exit(1);
    }

    for (int i=0; i<SIZE; i++)  //할당받은 곳에 데이터 채움
        p[i] = i;
    for (int i=0; i<SIZE; i++)  //채운 데이터의 출력
        printf("%d ", p[i]);

    free(p);    //할당받은 메모리 반납

    return 0;
}
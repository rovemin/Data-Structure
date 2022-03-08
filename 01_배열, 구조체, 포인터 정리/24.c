/* 구조체 배열의 동적 할당 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct {    //2차원 평면 상의 점(x, y)을 나타내는 구조체 선언
    int x, y;
} point;

int main() {
    point* p;
    p = (point*)malloc(sizeof(point) * 5);  //크기가 5인 점 배열 할당
    if (p == NULL) {    //할당 오류 점검
        fprintf(stderr, "할당 오류");
        exit(1);
    }

    for (int i=0; i<5; i++) {   //점 5개 정의
        p[i].x = i; //(p+i)->x = i 와 동일
        p[i].y = i * 10;
    }

    for (int i=0; i<5; i++) {   //점 5개 출력
        printf("(%d, %d)\n", p[i].x, p[i].y);
    }
    printf("\n");
    free(p);    //할당받은 배열 반환

    return 0;
}
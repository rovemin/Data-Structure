/* 구조체의 동적 할당 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {    //2차원 평면 상의 점(x, y)을 나타내는 구조체 선언
    int x, y;
} point;

int main() {
    point* p;
    p = (point*)malloc(sizeof(point));
    if (p==NULL) {  //할당 오류 점검
        fprintf(stderr, "메모리가 부족해서 할당할 수 없습니다.\n");
        exit(1);
    }

    p->x = 10;  //점의 x좌표 저장
    p->y = 20;  //점의 y좌표 저장
    printf("(%d, %d)\n", p->x, p->y);
    free(p);

    return 0;
}

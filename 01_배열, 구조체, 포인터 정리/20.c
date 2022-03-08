/* 동적 메모리 할당 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main() {
    int* pi;
    pi = (int*)malloc(sizeof(int)); //동적 메모리 할당
    if (pi == NULL) {   //제대로 되었는지 확인
        fprintf(stderr, "틀림");
         exit(1);   //강제 종료
    }
    *pi = 10;   //동적 메모리의 사용
    printf("%d\n", *pi);
    free(pi);   //동적 메모리 반납
    return 0;
}
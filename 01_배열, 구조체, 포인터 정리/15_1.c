/* 2���� �迭�� ����Ű�� �迭�� ���� ������ */
/* ����: int (*p)[4] = A;  */

#include <stdio.h>

int main() {
    int A[3][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    int(*p)[4] = A;

    printf("*** �迭 A\n");
    for (int i=0; i<3; i++) {
        for (int j=0; j<4; j++)
            printf("%3d", A[i][j]);
        printf("\n");
    }

    printf("\n*** p�� ����Ű�� �迭\n");
    for (int i=0; i<3; i++) {
        for (int j=0; j<4; j++)
            printf("%3d", p[i][j]);
        printf("\n");
    }

    return 0;
}
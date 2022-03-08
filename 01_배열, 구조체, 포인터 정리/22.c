/* 2���� �迭�� ���� �Ҵ� */
/* 5x7 ����� �Ҵ� ���� */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main() {
    int(*p)[7]; //p�� 7��¥�� 1���� ����Ű�� ������
    int i, j;
    p = (int(*)[7])malloc(sizeof(int) * 5 * 7); //5��7�� �迭�� ����� ����
    if (p==NULL) {  //�Ҵ� ���� ����
        fprintf(stderr, "�޸𸮰� �����ؼ� �Ҵ��� �� �����ϴ�.\n");
        exit(1);
    }

    for (i=0; i<5; i++)     //�迭�� �����͸� ä��
        for (j=0; j<7; j++)
            p[i][j] = i * 10 + j;

    for (i=0; i<5; i++) {   //�迭 ���
        for (j=0; j<7; j++)
            printf("%4d", p[i][j]);
        printf("\n");
    }

    return 0;
}
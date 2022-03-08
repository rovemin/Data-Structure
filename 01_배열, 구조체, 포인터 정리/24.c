/* ����ü �迭�� ���� �Ҵ� */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct {    //2���� ��� ���� ��(x, y)�� ��Ÿ���� ����ü ����
    int x, y;
} point;

int main() {
    point* p;
    p = (point*)malloc(sizeof(point) * 5);  //ũ�Ⱑ 5�� �� �迭 �Ҵ�
    if (p == NULL) {    //�Ҵ� ���� ����
        fprintf(stderr, "�Ҵ� ����");
        exit(1);
    }

    for (int i=0; i<5; i++) {   //�� 5�� ����
        p[i].x = i; //(p+i)->x = i �� ����
        p[i].y = i * 10;
    }

    for (int i=0; i<5; i++) {   //�� 5�� ���
        printf("(%d, %d)\n", p[i].x, p[i].y);
    }
    printf("\n");
    free(p);    //�Ҵ���� �迭 ��ȯ

    return 0;
}
/* 1���� �迭�� ���� �Ҵ� */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define SIZE 10

int main() {
    int* p;     //�Ҵ���� �迭�� ����ų ������
    p = (int*)malloc(SIZE * sizeof(int));   //�迭 �Ҵ�
    if (p==NULL) {  //�Ҵ� ���� ����
        fprintf(stderr, "�޸𸮰� �����ؼ� �Ҵ��� �� �����ϴ�.\n");
        exit(1);
    }

    for (int i=0; i<SIZE; i++)  //�Ҵ���� ���� ������ ä��
        p[i] = i;
    for (int i=0; i<SIZE; i++)  //ä�� �������� ���
        printf("%d ", p[i]);

    free(p);    //�Ҵ���� �޸� �ݳ�

    return 0;
}
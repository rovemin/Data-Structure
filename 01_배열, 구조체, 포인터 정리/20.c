/* ���� �޸� �Ҵ� */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main() {
    int* pi;
    pi = (int*)malloc(sizeof(int)); //���� �޸� �Ҵ�
    if (pi == NULL) {   //����� �Ǿ����� Ȯ��
        fprintf(stderr, "Ʋ��");
         exit(1);   //���� ����
    }
    *pi = 10;   //���� �޸��� ���
    printf("%d\n", *pi);
    free(pi);   //���� �޸� �ݳ�
    return 0;
}
/* �������� Ȱ�� ���� (2) */

#include <stdio.h>

void swap(int* p, int* q) {     //�ּҸ� ������ ������ �����Ѵ�
    int temp;
    temp = *p;      //temp ������ p�� ����Ű�� ������ ���� ����
    *p = *q;        //p�� ����Ű�� ���� q�� ����Ű�� ������ ���� ����
    *q = temp;      //q�� ����Ű�� ���� temp ���� ����
}

int main() {
    int a=10, b=20;
    printf("(1) a = %d, b = %d\n", a, b);
    swap(&a, &b);   //���� a�� b�� �ּҸ� ������
    printf("(2) a = %d, b = %d\n", a, b);
    return 0;
}

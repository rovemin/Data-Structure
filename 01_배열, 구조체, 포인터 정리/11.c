/* �������� Ȱ�� ���� (3) */

#include <stdio.h>

//�� ���� �հ� ���� ����ϴ� �Լ�
void getSumAndProduct (int a, int b, int *sum_ptr, int *prod_ptr) {
    *sum_ptr = a + b;   //sum_ptr �����Ͱ� ����Ű�� ���� ���� ����
    *prod_ptr = a * b;  //prod_ptr �����Ͱ� ����Ű�� ���� ���� ����
}

int main() {
    int x=10, y=20;
    int sum, prod;

    getSumAndProduct(x, y, &sum, &prod);    //x, y ���� ����    //sum, prod�� �ּҸ� ����
    printf("�հ� = %d, �� = %d\n", sum, prod);
    return 0;
}

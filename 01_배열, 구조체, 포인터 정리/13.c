/* �迭 ���� ��� : ������ q */

#include <stdio.h>

int main() {
    int A[5] = {10, 20, 30, 40, 50};
    int* p = A;
    int* q = p;     //q�� p�� ����Ű�� �ִ� ���Ҹ� ����Ŵ
    for (int i=0; i<5; i++) {
        printf("%d ", *q);
        q++;        //�迭�� ���� ���Ҹ� ����Ŵ
    }
    return 0;
}

/* �������� �̵� ���� */

#include <stdio.h>

int main() {
    int A=2, B=3, C=6, D=7, E=9;
    int * p=&A, * q=&B, * r=&C, * s=&D, * t=&E, * u;

    u=p;    //�ӽ� ������ u�� p�� ����Ű�� ������ �Բ� ����Ų��.
    p=q;    //p�� q�� ����Ű�� ������ ����Ű�� �ȴ�.
    q=u;

    u=t;
    t=s;
    s=r;
    r=u;

    printf("%d %d %d %d %d\n", *q, *p, *s, *t, *r);
    return 0;
}

/* ����ü�� ���� �Ҵ� */

#include <stdio.h>
#include <stdlib.h>

typedef struct {    //2���� ��� ���� ��(x, y)�� ��Ÿ���� ����ü ����
    int x, y;
} point;

int main() {
    point* p;
    p = (point*)malloc(sizeof(point));
    if (p==NULL) {  //�Ҵ� ���� ����
        fprintf(stderr, "�޸𸮰� �����ؼ� �Ҵ��� �� �����ϴ�.\n");
        exit(1);
    }

    p->x = 10;  //���� x��ǥ ����
    p->y = 20;  //���� y��ǥ ����
    printf("(%d, %d)\n", p->x, p->y);
    free(p);

    return 0;
}

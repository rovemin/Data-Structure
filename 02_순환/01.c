/* 10���� -> 2���� ��ȯ ��� �Լ� */

#include <stdio.h>

void printbinary(int n) {
	int a, b;
	if (n == 1) printf("%d", n);
	else {
		a = n / 2;
		b = n % 2;
		printbinary(a);
		printf("%1d", b);
	}
}

int main(void) {
	int n;
	printf("���� �Է� : ");
	scanf("%d", &n);
	printf("%d�� ������\n", n);
	printbinary(n);
	printf("\n");
	return 0;
}
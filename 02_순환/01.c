/* 10진수 -> 2진수 변환 재귀 함수 */

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
	printf("정수 입력 : ");
	scanf("%d", &n);
	printf("%d의 이진수\n", n);
	printbinary(n);
	printf("\n");
	return 0;
}
/* �ִ� ���ϴ� ���α׷� */

#include <stdio.h>

int main() {
	int A[10] = { 3, 5, 7, 4, 1, 6, 0, 9, 8, 2 };
	int max = A[0];
	for (int i = 1; i < 10; i++)
		if (A[i] > max)
			max = A[i];
	printf("�ִ� = %d\n", max);
	return 0;
}
/* 최댓값 구하는 프로그램 */

#include <stdio.h>

int main() {
	int A[10] = { 3, 5, 7, 4, 1, 6, 0, 9, 8, 2 };
	int max = A[0];
	for (int i = 1; i < 10; i++)
		if (A[i] > max)
			max = A[i];
	printf("최댓값 = %d\n", max);
	return 0;
}

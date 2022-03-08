/* binary search algorithm */

#include <stdio.h>

int BS(int A[], int key, int low, int high)
{
	int mid;
	if (high < low) return -1;
	else {
		mid = (high + low) / 2;
		if (A[mid] > key)
			return BS(A, key, low, mid - 1);
		else if (A[mid] < key)
			return BS(A, key, mid + 1, high);
		else
			return mid;
	}
}

int main() {
	int A[] = { 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85 };
	int result;
	result = BS(A, 38, 0, 15);
	if (result >= 0) printf("result = %d\n", result);
	else printf("그런 숫자는 없습니다!\n");
}
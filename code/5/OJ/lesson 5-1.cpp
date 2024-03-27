#include <stdio.h>

int main() {
	int a[100];
	int x = 0;

	scanf("%d", &x);
	for (int i = 0; i < x; i++) {
		scanf("%d", &a[i]);
	}
//	for (int i = 0; i < x; i++) {
//		printf("%d", a[i]);
//	}
	int count = 0;
	for (int i = 0; i < x; i++) {
		if (a[i] == 2) {
			
			count++;
		}
	}
	printf("%d", count);
}

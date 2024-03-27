#include <stdio.h>

int change(int num) {
	num = num / 2;
	return num;
}

int main() {
	int i = 0;
	scanf("%d", &i);
	printf("%d", change(i));
}

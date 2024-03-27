#include <stdio.h>

int main() {
	int x = 0;
	for (int i = 1; i <= 40; i++) {
		for (int j = 1; j <= 40; j++) {
			for (int k = 1; k <= 40; k++) {
				for (int p = 1; p <= 40; p++) {
					int res = i * 10 + j * 5 + k * 2 + p * 1;
					int count = i + j + k + p;
					if(res == 100 && count == 40){
						x++;
					}
				}
			}
		}
	}
	printf("%d", x);
}

#include<stdio.h>

int main(){
	int i = 0;
	char j = '\0';
	float k = 0.0;
	float res = 0.0;
	scanf("%d %c %f", &i, &j, &k);
	res = i + (int)j + k;
	printf("%.2f", res);
}

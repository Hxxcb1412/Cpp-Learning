#include<stdio.h>

int main(){
	int x = 0;
	scanf("%d", &x);
	if(x >= 65 && x <=122){
		printf("%c", x);
	}else{
		return 0;
	}
}

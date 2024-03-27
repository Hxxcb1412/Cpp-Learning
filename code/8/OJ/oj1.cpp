#include <stdio.h>

struct {
	char s_num[10];
	char s_name[10];
	char s_sex[10];
} student;

int main() {
	char number, name, sex;
	scanf("%s %s %s", student.s_num, student.s_name, student.s_sex);
	printf("%s %s %s", student.s_num, student.s_name, student.s_sex);
}

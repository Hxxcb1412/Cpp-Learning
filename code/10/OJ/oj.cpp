/***
  Description
  初始化顺序表（顺序表中元素为整型），里边的元素是1,2,3，然后通过scanf读取一个元素（假如插入的是6），
  插入到第2个位置，打印输出顺序表，每个元素占3个空格，格式为1  6  2  3，
  然后scanf读取一个整型数，是删除的位置（假如输入为1），然后输出顺序表  6  2  3，假如输入的位置不合法，输出false字符串。
  提醒，Language一定要选为C++。

  Input
  第一次输入插入的元素值，第二次输入删除的位置

  Output
  假如插入的元素为6，那么输出为
  1  6  2  3
  假如删除的位置为1，那么输出为
  6  2  3
 */
#include <stdio.h>
#define MaxSize 10
typedef int ElemType;
int num1 = 0;
int num2 = 0;
bool res;
typedef struct {
	ElemType data[MaxSize];
	int len;
} SqList;

bool InsertList(SqList &L, int pos, int element) {
	//是否合法
	if (pos < 1 || pos > L.len + 1) {
		return false;
	}
	//是否存满
	if (L.len == MaxSize) {
		return false;
	}
	for (int i = L.len; i >= pos; i--) {
		L.data[i] = L.data[i - 1];
	}
	L.data[pos - 1] = element;
	L.len++;
	return true;
}

int PrintList(SqList L) {
	for (int i = 0; i < L.len; i++) {
		printf("%3d", L.data[i]);
	}
	printf("\n");
}

bool DeleteList(SqList &L, int pos) {
	//是否合法
	if (pos < 1 || pos > L.len) {
		return false;
	}
	int del = 0;
	del = L.data[pos - 1];
	for (int i = pos - 1; i < L.len; i++) {
		L.data[i] = L.data[i + 1];
	}
	L.len--;
	return true;
}

int main() {
	SqList L;
//	printf("请输入插入的数字：");
	scanf("%d", &num1);

	L.data[0] = 1;
	L.data[1] = 2;
	L.data[2] = 3;
	L.len = 3;
	res = InsertList(L, 2, num1);
	if (res) {
		PrintList(L);
	} else {
		printf("false");
	}
	
//	printf("请输入删除的位置：");
	scanf("%d", &num2);
	res = DeleteList(L, num2);
	if(res){
		PrintList(L);
	}else{
		printf("false");
	}
}



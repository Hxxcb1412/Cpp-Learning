#include <stdio.h>

#define MaxSize 5
typedef int ElemType;// 让顺序表存储其他类型元素时，可以快速完成代码修改

typedef struct {
	ElemType data[MaxSize];
	int length;
} SqList;

// 顺序表的插入，因为L会改变，因此我们这里要用引用，pos是插入的位置
bool ListInsert(SqList &L, int pos, ElemType element) {
	// 判断i是否合法
	if (pos < 1 || pos > L.length + 1) {
		//TODO
		return false;	// 插入失败返回false
	}

	// 如果存储空间满了，不能插入
	if (L.length == MaxSize) {
		//TODO
		return false;
	}
	// 把后面的元素依次往后移动，空出位置，来放要插入的元素
	for (int j = L.length; j >= pos; j--) {
		L.data[j] = L.data[j - 1];
	}

	L.data[pos - 1] = element;	//放入要插入的元素
	L.length ++;	// 顺序表长度要加1

	return true;	// 插入成功返回true
}

// 打印顺序表
void PrintList(SqList L) {
	for (int i = 0; i < L.length; i++) {
		//TODO
		printf("%3d", L.data[i]);	// 为了打印到同一行
	}
	printf("\n");
}

// 删除顺序表中的元素，pos是要删除的元素的位置，del是为了获取被删除的元素的值
bool ListDelete(SqList &L, int pos, ElemType &del) {
	// 判断删除的元素的位置是否合法
	if (pos < 1 || pos > L.length) {
		//TODO
		return false;	// 一旦走到return函数就结束了
	}
	del = L.data[pos - 1];	// 首先保存要删除元素的值
	for (int j = pos - 1; j <= L.length - 1; j++) {	// 往前移动元素
		//TODO
		L.data[j] = L.data[j + 1];
	}
	L.length --;	// 顺序表长度减1
	return true;
}

//查找某个元素的位置，找到了就会返回对应位置，没找到就返回0
int LocateElem(SqList L, ElemType element) {
	for (int i = 0; i < L.length; i++) {
		//TODO
		if (element == L.data[i]) {
			//TODO
			return i + 1;	// 因为i是数组的下标，加1以后才是顺序表的下标
		}
	}
	return 0;
}

// 顺序表的初始化及插入操作实战
int main() {
	SqList L;	//定义一个顺序表，变量L
	bool ret;	//ret用来装函数的返回值
	L.data[0] = 1;
	L.data[1] = 2;
	L.data[2] = 3;
	L.length = 3;
	PrintList(L);
	ret = ListInsert(L, 2, 60);
	if (ret) {
		//TODO
		printf("Insert sqlist successful！\n");
		PrintList(L);
	} else {
		printf("Insert sqlist failed！\n");
	}
	printf("------------------------------\n");
	ElemType del;	//删除的元素存入del中
	ret = ListDelete(L, 1, del);
	if (ret) {
		//TODO
		printf("Delete sqlist successful！\n");
		printf("del element = %d\n", del);
		PrintList(L);	// 顺序表打印
	} else {
		printf("Delete sqlist failed！\n");
	}

	int pos;	// 存储元素位置
	pos = LocateElem(L, 3);
	if (pos) {
		//TODO
		printf("Find this element！\n");
		printf("element pos = %d\n", pos);
	} else {
		printf("Don't find this element！\n");
	}
	return 0;
}

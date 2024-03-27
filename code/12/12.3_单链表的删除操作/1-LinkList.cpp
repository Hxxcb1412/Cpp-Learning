#include <stdio.h>
#include <stdlib.h>
typedef int EleType;
typedef struct LNode {
	EleType data;	// 数据域
	struct LNode *next;
} LNode, *LinkList;

//LNode*是结构体指针，和LinkList完全等价的
//输入3,4,5,6,7,9999
void list_head_insert(LinkList &L) {
	L = (LinkList)malloc(sizeof(LNode));//申请头结点空间，头指针指向头结点
	L->next = NULL;
	EleType x;
	scanf("%d", &x);
	LNode *s;	//用来指向申请的新结点
	while (x != 9999) {
		s = (LinkList)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;	//s的next指向原本链表的第一个结点
		L->next = s;	//头结点的next，指向新结点
		scanf("%d", &x);
	}
}

//尾插法来新建链表
void list_tail_insert(LNode* &L) {
	L = (LinkList)malloc(sizeof(LNode));//申请头结点空间，头指针指向头结点
	L->next = NULL;
	EleType x;
	scanf("%d", &x);
	LNode *s, *r = L;	//s是用来指向申请的新结点，r始终指向链表尾部
	while (x != 9999) {
		s = (LinkList)malloc(sizeof(LNode));	//为新结点申请空间
		s->data = x;
		r->next = s;	//新结点给尾节点的next指针
		r = s;	//r要指向新的尾部
		scanf("%d", &x);
	}
	r->next = NULL;	//让尾结点的next为NULL
}

void print_list(LNode *L) {
	L = L->next;
	while (L != NULL) {
		printf("%3d", L->data);
		L = L->next;
	}
	printf("\n");
}

// 按位置查找
LinkList GetElem(LNode* L, int pos) {
	int i = 0;
	if (pos < 0) {
		return NULL;
	}
	if (pos == 0) {
		return L;
	}
	while (i < pos && L) {
		L = L->next;
		i++;
	}
	return L;
}

// 按值查找
LNode* LocateElem(LinkList L, int num) {
	L = L->next;
	while (L) {
		if (num == L->data) {	//如果找到对应的值，就返回那个结点的地址
			return L;
		}
		L = L->next;
	}
	return NULL;
}

bool ListDelete(LinkList L, int i) {
	LinkList p = GetElem(L, i - 1);	//拿到要删除结点的前一个结点
	if(p==NULL){
		return false;
	}else{
		LinkList q = p->next;	//拿到要删除的结点指针
		p->next = q->next;	//断链
		free(q);
		return true;
	}
}


int main() {
	LinkList L, search;	//L是链表头指针，是结构体指针类型
//	list_head_insert(L);
	list_tail_insert(L);
	print_list(L);

//	search = GetElem(L, 2);	// 按位置查找
//	if (search != NULL) {
//		printf("Succeeded in searching by serial number\n");
//		printf("%d\n", search->data);
//	}
//	search = LocateElem(L, 3);	// 按值查找
//	if(search != NULL){
//		printf("Search by valuue succeeded\n");
//		printf("%d\n", search->data);
//	}
	ListDelete(L, 2);
	print_list(L);
	return 0;
}

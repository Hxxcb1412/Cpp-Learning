#include <stdio.h>
#include <stdlib.h>
typedef int EleType;
typedef struct LNode {
	EleType data;
	struct LNode *next;
}*LinkList, Lnode;

void list_head_insert(LinkList &L) {
	L = (LinkList)malloc(sizeof(EleType));
	LNode* s;
	EleType x;
	scanf("%d", &x);
	L->next = NULL;
	while (x != 9999) {
		s = (LinkList)malloc(sizeof(EleType));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}
}

void list_tail_insert(LinkList &L){
	L = (LinkList)malloc(sizeof(EleType));
	LNode* s, *r = L;
	EleType x;
	scanf("%d", &x);
	L->next = NULL;
	while (x != 9999) {
		s = (LinkList)malloc(sizeof(EleType));
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d", &x);
	}
	r->next = NULL;
}

//打印链表中每个结点的值
void PrintList(LinkList L) {
	L = L->next;
	while (L != NULL) {
		printf("%d", L->data); //打印当前结点数据
		L = L->next; //指向下一个结点
		if (L != NULL) {
			printf(" ");
		}
	}
	printf("\n");
}

int main() {
	LinkList L;
	list_head_insert(L);
	PrintList(L);
	list_tail_insert(L);
	PrintList(L);
}


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

//找链表中间结点，并设置好L2链表
void find_middle(LinkList L, LinkList &L2) {
	L2 = (LinkList)malloc(sizeof(LNode));	//第二条链表的头结点
	LinkList pcur, ppre;	//双指针法
	ppre = pcur = L->next;
	while (pcur) {
		pcur = pcur->next;
		if (pcur == NULL) {	//为了防止pcur为NULL
			break;
		}
		pcur = pcur->next;
		if (pcur == NULL) {	//为了使得偶数个，ppre依然指向a1,a2,到a6中的a3
			break;
		}
		ppre = ppre->next;
	}
	L2->next = ppre->next;	//由L2头结点指向后面一半链表
	ppre->next = NULL;	//前一半链表的最后一个结点，next要为NULL
}

void reverse(LinkList L2) {
	LinkList r, s, t;
	r = L2->next;
	if (L2->next == NULL) {
		return;	//链表为空
	}
	s = r->next;
	if (s == NULL) {
		return;	//链表为空
	}
	t = s->next;
	while (t) {
		s->next = r;	//原地逆置
		//以下三句是三个指针同时走一步
		r = s;
		s = t;
		t = t->next;
	}
	s->next = r;
	L2->next->next = NULL;	//逆置后，链表第一个结点的next要为NULL
	L2->next = s;	//s是链表第一个结点，L2指向它
}

void merge(LinkList L, LinkList L2) {
	LinkList pcur, p, q;
	pcur = L->next;	//pcur始终指向组合后链表的链表尾
	p = pcur->next;	//p用来遍历L1链表
	q = L2->next;	//q指向L2第一个结点，q用来遍历L2链表
	while (p != NULL && q != NULL) {
		pcur->next = q;
		q = q->next;	//用来指向下一个
		pcur = pcur->next;
		pcur->next = p;
		p = p->next;//用来指向下一个
		pcur = pcur->next;
	}
	//任何一个链表都可能剩余一个结点，放进来即可
	if(p!=NULL){
		pcur->next=p;
	}
	if(q!=NULL){
		pcur->next=q;
	}
}

int main() {
	LinkList L;	//L是链表头指针，是结构体指针类型
	list_tail_insert(L);
	print_list(L);

	LinkList L2 = NULL;
	find_middle(L, L2);	//只有一个结点时，L2中是没有结点的
	printf("---------------------------\n");
	print_list(L);
	print_list(L2);
	printf("---------------------------\n");
	reverse(L2);
	print_list(L2);
	printf("---------------------------\n");
	merge(L, L2);
	free(L2);
	print_list(L);
	return 0;
}

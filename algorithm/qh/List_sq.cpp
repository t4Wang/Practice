/* 线性表 */
// 初始化线性表
InitList(L &l);
// 销毁线性表
DestroyList(L &l);
// 将L重置为空表 
ClearList(L &l);
// 判断是否为空 
ListEmpty(L);
// 返回元素个数
ListLength(L);
// 用e获取第i个元素 
GetElem(L l, int i, ElemType &e);
// 返回第一个与e满足关系compare的数据元素的位置，若不存在返回0
LocateElem(L, e, compare());
// 用pre_e返回cur_e的前驱
PriorElem(L, cur_e, &pre_e);
// 用next_e返回cur_e的后继
NextElem(L, cur_e, &next_e);
// 第i个元素之前插入新的元素e，L的长度加1
ListInsert(&L, i, e);
// 删除第i个元素
ListDelete(&L, i, &e);
// 依次对每个元素调用函数visit()
ListTraverse(L, visit());

#define LIST_INIT_SIZE 100	// 初始分配量
#define LISTINCREMENT 10	// 增量
#define OVERFLOW 1
#define OK 1

typedef int Status;
typedef int ElemType;
typedef struct {
	ElemType *elem; // 存储空间基址
	int length;		// 当前长度
	int listsize;	// 当前存储容量（最大元素个数）
}SqList;

Status InitList(L &l) {
	l = malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem) exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;	// 初始存储长度
	return OK;
}

Status DestroyList(L &l) {
	free(l); l = null;
	return OK;
}

Status ClearList(L &l) {
	free(l);
	l = malloc(LIST_INIT_SIZE * sizeof(ElemType));
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;	// 初始存储长度
	return OK;	
}

Status ListEmpty(L &l) {
	if (l == null || l.length == 0) return true;
	else return false;
}

Status ListLength(L &l) {
	return l.length;
}

Status GetElem(L l, int i, ElemType &e) {
	e = l[i];
	return OK;
}
Status LocateElem(L l, ElemType e, bool compare()) {
	for (int i = 0; i < l.length; i++) {
		if (compare(e, l)) {
			return i;
		}
	}
	return l.length;
}

Status PriorElem(L, cur_e, &pre_e) {
	if (cur_e == l[0]) return null;
	for (int i = 1; i < l.length; i++) {
		if (l[i] == cur_e) {
			pre_e = l[i - 1];
			return OK;
		}
	}
	return null;
}

Status NextElem(L, cur_e, &pre_e) {
	// if (cur_e == l[0]) return null;
	for (int i = 0; i < l.length - 1; i++) {
		if (l[i] == cur_e) {
			pre_e = l[i + 1];
			return OK;
		}
	}
	return null;
}

//  第i个元素之前插入新的元素e，L的长度加1
Status ListInsert(&L, i, e) {
	ElemType* head = l.head;
	ElemType* temp = head;
	int i = 0;
	while (head != null) {
		
	}
}
Status ListDelete(&L, i, &e) {
}
Status ListTraverse(L, visit()) {
}



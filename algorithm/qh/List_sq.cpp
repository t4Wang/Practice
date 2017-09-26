/* ���Ա� */
// ��ʼ�����Ա�
InitList(L &l);
// �������Ա�
DestroyList(L &l);
// ��L����Ϊ�ձ� 
ClearList(L &l);
// �ж��Ƿ�Ϊ�� 
ListEmpty(L);
// ����Ԫ�ظ���
ListLength(L);
// ��e��ȡ��i��Ԫ�� 
GetElem(L l, int i, ElemType &e);
// ���ص�һ����e�����ϵcompare������Ԫ�ص�λ�ã��������ڷ���0
LocateElem(L, e, compare());
// ��pre_e����cur_e��ǰ��
PriorElem(L, cur_e, &pre_e);
// ��next_e����cur_e�ĺ��
NextElem(L, cur_e, &next_e);
// ��i��Ԫ��֮ǰ�����µ�Ԫ��e��L�ĳ��ȼ�1
ListInsert(&L, i, e);
// ɾ����i��Ԫ��
ListDelete(&L, i, &e);
// ���ζ�ÿ��Ԫ�ص��ú���visit()
ListTraverse(L, visit());

#define LIST_INIT_SIZE 100	// ��ʼ������
#define LISTINCREMENT 10	// ����
#define OVERFLOW 1
#define OK 1

typedef int Status;
typedef int ElemType;
typedef struct {
	ElemType *elem; // �洢�ռ��ַ
	int length;		// ��ǰ����
	int listsize;	// ��ǰ�洢���������Ԫ�ظ�����
}SqList;

Status InitList(L &l) {
	l = malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem) exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;	// ��ʼ�洢����
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
	L.listsize = LIST_INIT_SIZE;	// ��ʼ�洢����
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

//  ��i��Ԫ��֮ǰ�����µ�Ԫ��e��L�ĳ��ȼ�1
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



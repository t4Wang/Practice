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

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

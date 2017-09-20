/* 三元组 */
typedef int ElemType;
typedef ElemType* Triplet;
typedef Status int;

static const int OK = 0;
static const int ERROR = 1;

Status InitTriplet(Triplet &T, ElemType v1, ElemType v2, ElemType v3);
// 三元组销毁
Status DestroyTriplet(Triplet &T);
// 用e返回T的第i个元素
Status Get(Triplet T, int i, ElemType &e);
// 改变T的第i个元素为e
Status Put(Triplet &T, int i, ElemType e);
// 是否按升序排列
Status IsAscending(Triplet T);
// 是否按降序排列
Status IsDescending(Triplet T);
// 用e返回T的三个元素中最大的值
Status Max(Triplet &T, ElemType &e);
// 用e返回T的三个元素中最小的值
Status Min(Triplet T, ElemType &e);

Status InitTriplet(Triplet &T, ElemType v1, ElemType v2, ElemType v3) {
	T = (ElemType *) malloc(3 * sizeof(ElemType));
	if(!T) exit(OVERFLOW); // 分配存储空间失败
	T[0] = v1; T[1] = v2; T[2] = v3;
	return OK;
}

Status DestroyTriplet(Triplet &T) {
	free(T); T = null;
	return OK;
}

Status Get(Triplet T, int i, ElemType &e) {
	if (i < 1 || i > 3) return ERROR;
	e = T[i - 1];
	return OK;
}

Status Put(Triplet &T, int i, ElemType e) {
	if (i < 1 || i > 3) return ERROR;
	T[i - 1] = e;
	return OK;
}

Status IsAscending(Triplet T) {
	return (T[0] <= T[1] && T[1] <= T[2]);
}

Status IsDescending(Triplet T) {
	return (T[0] >= T[1] && T[1] >= T[2]);
}

Status Max(Triplet &T, ElemType &e) {
	e = T[0] > T[1] ? T[0] : T[1];
	e = e > T[2] ? e :T[2];
	return OK;
}

Status Max(Triplet &T, ElemType &e) {
	e = T[0] < T[1] ? T[0] : T[1];
	e = e < T[2] ? e :T[2];
	return OK;
}

// template<typename T>
// class Triplet {
// public:
// 	initTriplet(const T &t1, const T &t2, const T &t3)
// 	get()
// 	using Status=int;
// }
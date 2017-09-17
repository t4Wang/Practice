/* 三元组 */
typedef int ElemType;
typedef ElemType* Triplet;
typedef Status int;

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

// template<typename T>
// class Triplet {
// public:
// 	initTriplet(const T &t1, const T &t2, const T &t3)
// 	get()
// 	using Status=int;
// }
/*
 * 在大小为N的集合里查找第k个大的数
 *
 * 思路：建立k大小的集合，排序，
 * 将剩下的数与k位置的数比对，
 * 若大于k，放入合适的位置，k位的数据被挤出，
 * 否则该数被丢弃
 *
 * detail：集合为数组，
 */
#include <iostream>
#include <cstring>
using namespace std;

void sort(int a[], int b[], int k);
void sort(int a[], int size);
void merge(int a1[], int size1, int a2[], int size2);
void insert(int b[], int size, int a);
void array_assign(int a[], int b[], int k);

int main() {
	int a[] = {1,2,3,4,5,6,7,8,9,0};
	int b[5];
	int k = 5;
	int n = 10;

	// 1.排序出k大小的数组b
	sort(a, b, k);
	// 2.将a数组排序后k位置后的数比对k位置的数
	// 比较大小
	for (int i = k; i < n; i++) {
		if (a[i] > b[k - 1]) {
			insert(b, k, a[i]);
		}
	}
	// 获取到真正的数了
	cout << b[k];

	return 0;
}
//
void sort(int a[], int b[], int k) {
	array_assign(a, b, k);
	// 排序，前k个元素
	sort(b, k);
}
void array_assign(int a[], int b[], int k) {
	memcpy(b, a, k);
}

// 倒序排列
void sort(int a[], int size) {
	// 如果只有一个元素，则它是有序的
	//if (size == 1) return;
	// 如果有两个以上元素，分别排序
	//else {
	//
	//}
	// 如果长度为2，排序
	// 归并排序，
	// 拆分到基本情况后合并
	int a1[size / 2];
	memcpy(a1, a, (size / 2) * sizeof (int) );
	int a2[size - size / 2];
	memcpy(a2, a + size / 2, (size - size / 2) * sizeof (int) );
	if (size > 1) {
		sort(a1, size / 2);
		sort(a2, size - size / 2);
	}
	merge(a1, size / 2, a2, size - size / 2);
}

void merge(int a1[], int size1, int a2[], int size2) {
    int size = size1 + size2;
    int b[size];
    int i = 0, j = 0, k = 0;
    for (; k < size && i < size1 && j < size2; k++) {
        if (a1[i] > a2[j]) {
            b[k] = a1[i];
            i++;
        } else {
            b[k] = a2[j];
            j++;
        }
    }
    if (k != size) {
        while (i < size1) {
            b[k] = a1[i];
            i++;
            k++;
        }
        while (j < size2) {
            b[k] = a2[j];
            j++;
            k++;
        }
    }

}
// 将元素插入倒序排列的数组，多余的元素忽略
void insert(int b[], int size, int a) {
	// int i = size - 1;
	// 选取合适的插入位置
	// for (; b[i] < a; i--) {}
	// 将i以后的元素后移
	int i = size - 1;
	for (; a > b[i] && i > 1; i--) { b[i] = b[i - 1]; }
	if (a > b[i])
		b[i] = a;
}





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
int main() {
	int a[] = {1,2,3,4,5,6,7,8,9,0};
	int b[5];
	int k = 5;
	int n = 10;
	
	// 1.排序出k大小的数组b
	sort(a, n, k);
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
	// 排序，前k个元素
	sort(a, k);
	array_assign(a, b, k);
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
	if (size > 2) {
		if (a[i]
	}
	
}
// 将元素插入倒序排列的数组，多余的元素忽略
void insert(int b[], int size, int a) {
	int i = size - 1;
	// 选取合适的插入位置
	for (; b[i] < a; i--) {}
	// 将i以后的元素后移
	for (int j = k - 2; j > i; j--) { b[j + 1] = b[j]; }
}





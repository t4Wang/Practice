/*
 * �ڴ�СΪN�ļ�������ҵ�k�������
 *
 * ˼·������k��С�ļ��ϣ�����
 * ��ʣ�µ�����kλ�õ����ȶԣ�
 * ������k��������ʵ�λ�ã�kλ�����ݱ�������
 * �������������
 *
 * detail������Ϊ���飬
 */
#include <iostream>
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

	// 1.�����k��С������b
	sort(a, b, k);
	// 2.��a���������kλ�ú�����ȶ�kλ�õ���
	// �Ƚϴ�С
	for (int i = k; i < n; i++) {
		if (a[i] > b[k - 1]) {
			insert(b, k, a[i]);
		}
	}
	// ��ȡ������������
	cout << b[k];

	return 0;
}
//
void sort(int a[], int b[], int k) {
	// ����ǰk��Ԫ��
	sort(a, k);
	array_assign(a, b, k);
}
// ��������
void sort(int a[], int size) {
	// ���ֻ��һ��Ԫ�أ������������
	//if (size == 1) return;
	// �������������Ԫ�أ��ֱ�����
	//else {
	//
	//}
	// �������Ϊ2������
	// �鲢����
	// ��ֵ����������ϲ�
	int a1[size / 2] = a;
	int a2[size - size / 2] = a + size / 2;
	if (size > 1) {
		sort(a1, size / 2);
		sort(a2, size - size / 2);
	}
	merge(a1, size / 2, a2, size - size / 2);
}

void merge(int a1[], size1, int a2[], size2) {
    int size = size1 + size2
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
// ��Ԫ�ز��뵹�����е����飬�����Ԫ�غ���
void insert(int b[], int size, int a) {
	int i = size - 1;
	// ѡȡ���ʵĲ���λ��
	for (; b[i] < a; i--) {}
	// ��i�Ժ��Ԫ�غ���
	for (int j = k - 2; j > i; j--) { b[j + 1] = b[j]; }
}





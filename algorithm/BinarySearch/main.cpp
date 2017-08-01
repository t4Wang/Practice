/*
    ���ֲ��ҷ�

    �ݹ��ѭ������
*/
#include <iostream>
using namespace std;

/*
    ѭ��
*/
const int SIZE = 20;
/**
    @param a: ��������, key: ���Ҵ�
*/
int search_loop(int a[], int key) {
    int hi = SIZE - 1;
    int lo = 0;
    int mid;

    // �������ݣ���ѯ�ؼ���
    while (lo <= hi) {
        mid = (hi + lo) / 2;
        if (key == a[mid]) return mid;
        else if (key < a[mid]) hi = mid - 1;
        else if (key > a[mid]) lo = mid + 1;
    }
    return -1;
}

/*
    �ݹ�
*/
int search_recursion(int a[], int key, int lo, int hi) {
    if (lo > hi) return -1;
    int mid = (lo + hi) / 2;
    if (a[mid] == key) return mid;
    else if (a[mid] > key) return search_recursion(a, key, lo, mid - 1);
    else if (a[mid] < key) return search_recursion(a, key, mid + 1, hi);
}

int main()
{
    int a[SIZE];
    for (int i = 0; i < SIZE; i++) {
        a[i] = 2 * i + 1;
    }
    int result = search_recursion(a, 3, 0, SIZE - 1);

    cout << result << endl;



    return 0;
}

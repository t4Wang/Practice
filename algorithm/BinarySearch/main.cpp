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
    int mid = (hi + lo) / 2;

    // �������ݣ���ѯ�ؼ���
    while (lo <= mid) {
        if (key == a[mid]) return mid;
        else if (key < a[mid]) hi = mid - 1;
        else if (key > a[mid]) lo = mid + 1;
    }
    return -1;
}

int main()
{
    int a[SIZE];
    for (int i = 0; i < SIZE; i++) {
        a[i] = 2 * i + 1;
    }


    return 0;
}

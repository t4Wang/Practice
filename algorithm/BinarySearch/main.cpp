/*
    二分查找法

    递归和循环方法
*/
#include <iostream>
using namespace std;

/*
    循环
*/
const int SIZE = 20;
/**
    @param a: 有序序列, key: 查找词
*/
int search_loop(int a[], int key) {
    int hi = SIZE - 1;
    int lo = 0;
    int mid;

    // 遍历数据，查询关键词
    while (lo <= hi) {
        mid = (hi + lo) / 2;
        if (key == a[mid]) return mid;
        else if (key < a[mid]) hi = mid - 1;
        else if (key > a[mid]) lo = mid + 1;
    }
    return -1;
}

/*
    递归
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

/*
创建一个list容器，放置6个整型数值[0, 1, 30, 20, 10, 0]

1. 从后向前打印出容器内的元素

2. 向list容器后面添加两个元素，并对容器内的值求和并打印

3. 打印链表的中间元素

4. 找到不为0的元素，复制到一个vector中并打印vector元素
*/
#include <algorithm>
#include <list>
#include <iostream>
using namespace std;

int main () {
	// 1.
	list<int> l = {0, 1, 30, 20, 10, 0};
	for (auto iterator = l.crbegin(); iterator != l.crend(); ++iterator) {
		cout << *iterator << endl;
	}
	// 2.
	l.push_back(1);
	l.push_back(2);
	int sum = accumulate(l.cbegin(), l.cend(), 0);
	cout << sum << endl;

	// 3.
	// 		4种思路，
	//			1，从头和尾同时遍历，看相遇，
	// 			2，从头开始遍历，用两个指针分别记录当前的末尾元素和中间元素，末尾指针后移2个元素，中间指针后移一个元素
	//			3，截取从头到中间的list，然后取这个新list的最后一个元素
	// 			4，遍历，到中间时停止，获取该元素
	auto iter = l.cbegin()
	for (int i = 0; i < l.size() / 2; ++i, ++iter);
	cout << *iter << endl;

	// 4.
	
}

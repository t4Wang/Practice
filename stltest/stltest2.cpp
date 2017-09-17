/*
一个整数集 , 该整数集可以有重复元素, 初始为空集合 。可以指定如下指令：
1. add x 将x加入整数集
2. del x 删除整数集中所有与x相等的元素
3. ask x 对整数集中元素x的情况询问
下面为指令解释，并要求进行如下输出:
1. add 输出操作后集合中x的个数
2. del 输出操作前集合中x的个数
3. ask 先输出0或1表示x是否曾被加入集合（0表示不曾加入），再输出当前集合中x的个数，中间用空格格开。
提示
请使用STL中的 set 和multiset 来完成该题

输入
第一行是一个整数n，表示命令数。0<=n<=100000。
后面n行命令。
输出
共n行，每行按要求输出。


样例输入
7            //第一行是整数,表示为命令数目
add 1
add 1
ask 1
ask 2
del 2
del 1
ask 1       
样例输出
1
2
1 2
0 0
0
2
1 0
*/

#include <iostream>
#include <set>
using namespace std;

int main() {
	multiset<int> dataSet;
	set<int> records;	// 存储曾经插入过的记录
	// 接受输入
	int n = 0;	// 命令数
	cin >> n;
	if (0 > n || 100000 < n) return 0;

	string instruction;
	int data;
	// 循环执行命令
	for(int i = 0; i < n; i++) {
		// 接收指令
		cin >> instruction >> data;
		// 处理指令
		if ("add" == instruction) {
			// 添加元素
			dataSet.insert(data);
			records.insert(data);
			// 输出操作后集合中x的个数
			cout << dataSet.count(data) << endl;
		} else if ("del" == instruction) {
			// 输出操作前集合中x的个数
			cout << dataSet.count(data) << endl;
			// 删除元素
			set<int>::iterator pitem = dataSet.find(data);
			while (pitem != dataSet.end()) {
				dataSet.erase(pitem);
				pitem = dataSet.find(data);
			}
		} else if ("ask" == instruction) {
			// 查询元素
			// 输出0或1表示x是否曾被加入集合（0表示不曾加入）
			// 输出当前集合中x的个数，中间用空格格开。
			set<int>::iterator pitem = records.find(data);
			set<int>::size_type size = dataSet.count(data);
			if (pitem == records.end()) {
				cout << 0 << " " << 0 << endl;
			} else {
				cout << 1 << " " << size << endl;
			}
		}
	}
}
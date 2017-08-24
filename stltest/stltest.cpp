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
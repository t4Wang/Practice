/*
为Date类实现如下成员：

1. 构造器，可以初始化年、月、日。

2. 大于、小于、等于（> 、< 、==）操作符重载，进行日期比较。

3. print() 打印出类似 2015-10-1 这样的格式。


然后创建两个全局函数：

1. 第1个函数 CreatePoints生成10个随机的Date，并以数组形式返回；

2. 第2个函数 Sort 对第1个函数CreatePoints生成的结果，将其按照从小到大进行排序。


最后在main函数中调用CreatePoints，并调用print将结果打印出来。然后调用Sort函数对前面结果处理后，并再次调用print将结果打印出来。


    class Date
    {
        int year;
        int month;
        int day;
    };
*/
#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

class Date {
friend bool operator==(const Date&, const Date&);
friend bool operator>(const Date&, const Date&);
friend bool operator<(const Date&, const Date&);
friend ostream& operator<<(ostream&, const Date&);
public:
	Date(int y = 1999, int m = 1, int d = 1):year(y), month(m), day(d) {}
	void print();
	Date &operator=(const Date&);
private:
	int year;
	int month;
	int day;
};

void Date::print() {
	cout << *this << endl;
}
/*
 * 用于print函数使用
 */
ostream& operator<<(ostream &os, const Date &rd) {
	os << rd.year << "-" << rd.month << "-" << rd.day;
}
/*
 * 用于随机生成日期时的赋值
 */
inline Date&
Date::operator=(const Date &rd) {
	year = rd.year;
	month = rd.month;
	day = rd.day;
	return *this;
}

inline bool
operator==(const Date &ld, const Date &rd) {
	if (ld.year == rd.year 
		&& ld.month == rd.month
		&& ld.day == rd.day) return true;
	return false;
}

inline bool
operator<(const Date &ld, const Date &rd) {
	if (ld.year < rd.year)
		return true;
	else if (ld.year == rd.year && ld.month < rd.month)
		return true;
	else if (ld.year == rd.year && ld.month == rd.month && ld.day < rd.day)
		return true;
	return false;
}

inline bool
operator>(const Date &ld, const Date &rd) {
	if (ld.year > rd.year)
		return true;
	else if (ld.year == rd.year && ld.month > rd.month)
		return true;
	else if (ld.year == rd.year && ld.month == rd.month && ld.day > rd.day)
		return true;
	return false;
}

/*
 * 用于随机生成和排序的数组
 */
Date dates[10];
/*
 * 生成10个随机日期
 */
Date* CreatePoints() {
	for (auto iter = begin(dates); iter != end(dates); ++iter) {
		int year = rand() % 1000 + 1500;
		int month = rand() % 12 + 1;

		int maxDay = 28;
		switch (month) {
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				maxDay = 31;
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				maxDay = 30;
				break;
			case 2:
				if ((year % 4 == 0 && year % 100 != 0)
						|| year % 400 == 0) 
					maxDay = 29;
				break;
		}
		int day = rand() % maxDay + 1;

		Date d(year, month, day);
		*iter = d;
	}

	return dates;
}

/*
 *	按从小到大的顺序排列日期数组
 */
Date* Sort() {
	sort(begin(dates), end(dates));
	return dates;
}

#endif

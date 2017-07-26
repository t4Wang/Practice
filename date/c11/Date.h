/*
 * filename: Date.h
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
    int getYear() const { return year; }
    int getMonth() const { return month; }
    int getDay() const { return day; }
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
 *    按从小到大的顺序排列日期数组
 */
Date* Sort() {
    sort(begin(dates), end(dates));
    return dates;
}
 
#endif

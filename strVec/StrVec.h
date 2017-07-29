#include <string>
using namespace std;

class StrVec {
public:
	// allocator成员进行默认初始化
	StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(const StrVec&);
	StrVec &operator=(const StrVec&);
	~StrVec();
	void push_back(const string&);							// 拷贝元素
	size_t size() const { return first_free - elements; }	// 返回实际元素大小
	size_t capacity() const { return cap - elements; }		// 返回总容量
	string *begin() const { return elements; }				// 返回初始元素地址
	string *end() const {return first_free; }				// 返回元素末尾位置

private:
	static std::allocator<string> alloc;					// 分配元素
	// 被添加元素的函数所使用
	void chk_n_alloc() { if (size() == capacity()) reallocate(); }
	// 工具函数，被拷贝构造函数，赋值运算符和析构函数所使用
	std::pair<string*, string*> alloc_n_copy
		(const string*, const string*);
	void free();			// 销毁元素，释放内存
	void reallocate();		// 获取更多内存并拷贝已有元素
	string *elements;		// 指向数组首元素
	string *first_free;		// 指向数组第一个空闲元素
	string *cap;			// 指向数组尾后位置
}

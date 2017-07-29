#incldue <string>
using namespace std;

// 拷贝构造函数
StrVec::StrVec(const StrVec &s) {
	// 销毁当前元素内存，保存新内存？
	// 调用alloc_n_copy分配空间以容纳与s中一样多的元素
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

void StrVec::push_back(const string &s) {
	chk_n_alloc();
	// 在first_free指向的元素中构造s的副本
	alloc.construct(first_free++, s);
}

// 分配内存空间，并将元素拷贝到
pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e) {
	// 分配空间保存给定范围中的元素
	auto data = alloc.allocate(e - b);
	// 初始化并返回一个pair，该pair由data和uninitialized_copy的返回值构成
	return { data, uninitialized_copy(b, e, data) };
}

// 销毁元素，释放内存
void StrVec::free() {
	// 不能传递给deallocate一个空指针，如果elements为0，函数什么也不做
	if (elements) {
		// 逆序销毁旧元素
		for (auto p = first_free; p != elements; /* 空 */)
			alloc.destroy(--p);

		alloc.deallocate(elements, cap = elements);	// 释放空间
	}
}

void StrVec::reallocate() {

}

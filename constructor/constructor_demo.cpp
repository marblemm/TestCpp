#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <string>

class MyClass
{
public:
	MyClass(const char* str = nullptr);  // 默认带参构造函数 // 默认构造函数指不带参数或者所有参数都有缺省值的构造函数
	~MyClass(void);  // 默认析构函数
	MyClass(const MyClass&);  // 默认拷贝构造函数
	MyClass& operator =(const MyClass&);  // 默认重载赋值运算符函数
	MyClass* operator &();  // 默认重载取址运算符函数
	MyClass const* operator &() const;  // 默认重载取址运算符const函数
	MyClass(MyClass&&);  // 默认移动构造函数
	MyClass& operator =(MyClass&&);  // 默认重载移动赋值操作符函数

private:
	char* m_pData;
};

// 默认带参构造函数
MyClass::MyClass(const char* str)
{
	if (!str)
	{
		m_pData = nullptr;
	}
	else
	{
		this->m_pData = new char[strlen(str) + 1];
		strcpy(this->m_pData, str);
	}
	std::cout << "默认带参构造函数" << " this addr: " << this << std::endl;
}

// 默认析构函数
MyClass::~MyClass(void)
{
	if (this->m_pData)
	{
		delete[] this->m_pData;
		this->m_pData = nullptr;
	}
	std::cout << "默认析构函数" << " this addr: " << this << std::endl;
}

// 默认拷贝构造函数
MyClass::MyClass(const MyClass& m)
{
	if (!m.m_pData)
	{
		this->m_pData = nullptr;
	}
	else
	{
		this->m_pData = new char[strlen(m.m_pData) + 1];
		strcpy(this->m_pData, m.m_pData);
	}
	std::cout << "默认拷贝构造函数" << " this addr: " << this << std::endl;
}

// 默认重载赋值运算符函数
MyClass& MyClass::operator =(const MyClass& m)
{
	if (this == &m) {
		return *this;
	}

	delete[] this->m_pData;
	if (!m.m_pData)
	{
		this->m_pData = nullptr;
	}
	else
	{
		this->m_pData = new char[strlen(m.m_pData) + 1];
		strcpy(this->m_pData, m.m_pData);
	}

	std::cout << "默认重载赋值运算符函数" << " this addr: " << this << std::endl;
	return *this;
}

// 默认重载取址运算符函数
MyClass* MyClass::operator &()
{
	std::cout << "默认重载取址运算符函数" << " this addr: " << this << std::endl;
	return this;
}

// 默认重载取址运算符const函数
MyClass const* MyClass::operator &() const
{
	std::cout << "默认重载取址运算符const函数" << " this addr: " << this << std::endl;
	return this;
}

// 默认移动构造函数
MyClass::MyClass(MyClass&& m) :
	m_pData(std::move(m.m_pData))
{
	std::cout << "默认移动构造函数" << std::endl;
	m.m_pData = nullptr;
}

// 默认重载移动赋值操作符函数
MyClass& MyClass::operator =(MyClass&& m)
{
	if (this == &m) {
		return *this;
	}

	this->m_pData = nullptr;
	this->m_pData = std::move(m.m_pData);
	m.m_pData = nullptr;
	std::cout << "默认重载移动赋值操作符函数" << " this addr: " << this << std::endl;
	return *this;
}

void funA(MyClass a)
{
	std::cout << "调用funA函数" << " param addr: " << &a << std::endl;
}

void mytest1(void)
{
	std::cout << "mytest1 >>>>" << std::endl;
	MyClass myclass1; // 等价于 MyClass myclass1 = MyClass(); // 调用默认带参构造函数
	myclass1 = MyClass(); // MyClass()为右值，需要右值引用 // 先调用默认带参构造函数，然后调用默认重载取址运算符函数，最后调用默认重载移动赋值操作符函数
	std::cout << "<<<<< mytest1" << std::endl;
	// 析构两次 1: myclass1 = MyClass()中的MyClass() 2: MyClass myclass1
}

void mytest2(void)
{
	std::cout << "mytest2 >>>>" << std::endl;
	MyClass myclass1; // 等价于 MyClass myclass1 = MyClass(); // 调用默认带参构造函数
	MyClass myclass2(myclass1);  // 调用默认拷贝构造函数
	myclass2 = myclass1; // myclass2为左值，所以此操作为赋值操作，会调用默认重载取址运算符const函数，然后调用默认重载赋值运算符函数
	funA(myclass1); // 参数传值会导致赋值操作，会调用默认拷贝构造函数，然后funA函数调用默认重载取址运算符函数取得参数
	funA(std::move(myclass1)); // funA函数的参数现为右值，会调用默认移动构造函数，然后funA函数调用默认重载取址运算符函数取得参数
	// 在移动构造函数中对于基本类型所谓移动只是把其值拷贝，对于如string这类类成员来说才会真正的所谓资源移动
	std::cout << "<<<<< mytest2" << std::endl;
}

void mytest3(void)
{
	std::cout << "mytest3 >>>>" << std::endl;
	funA(MyClass()); // 会调用默认带参构造函数，生成该类的对象，然后funA函数调用默认重载取址运算符函数取得参数
	std::cout << "<<<<< mytest3" << std::endl;
	// 析构一次 1: funA(MyClass())中的MyClass()形成的对象，是在funA函数结束调用的时候，调用默认析构函数
}

void mytest(void)
{
	std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;

	mytest1();
	mytest2();
	mytest3();

	std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;
}

int main(int argc, char* argv[], char* envp[])
{
	mytest();

	system("pause");
	return 0;
}


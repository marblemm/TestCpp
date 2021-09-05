#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <string>

class MyClass
{
public:
	MyClass(const char* str = nullptr);  // Ĭ�ϴ��ι��캯�� // Ĭ�Ϲ��캯��ָ���������������в�������ȱʡֵ�Ĺ��캯��
	~MyClass(void);  // Ĭ����������
	MyClass(const MyClass&);  // Ĭ�Ͽ������캯��
	MyClass& operator =(const MyClass&);  // Ĭ�����ظ�ֵ���������
	MyClass* operator &();  // Ĭ������ȡַ���������
	MyClass const* operator &() const;  // Ĭ������ȡַ�����const����
	MyClass(MyClass&&);  // Ĭ���ƶ����캯��
	MyClass& operator =(MyClass&&);  // Ĭ�������ƶ���ֵ����������

private:
	char* m_pData;
};

// Ĭ�ϴ��ι��캯��
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
	std::cout << "Ĭ�ϴ��ι��캯��" << " this addr: " << this << std::endl;
}

// Ĭ����������
MyClass::~MyClass(void)
{
	if (this->m_pData)
	{
		delete[] this->m_pData;
		this->m_pData = nullptr;
	}
	std::cout << "Ĭ����������" << " this addr: " << this << std::endl;
}

// Ĭ�Ͽ������캯��
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
	std::cout << "Ĭ�Ͽ������캯��" << " this addr: " << this << std::endl;
}

// Ĭ�����ظ�ֵ���������
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

	std::cout << "Ĭ�����ظ�ֵ���������" << " this addr: " << this << std::endl;
	return *this;
}

// Ĭ������ȡַ���������
MyClass* MyClass::operator &()
{
	std::cout << "Ĭ������ȡַ���������" << " this addr: " << this << std::endl;
	return this;
}

// Ĭ������ȡַ�����const����
MyClass const* MyClass::operator &() const
{
	std::cout << "Ĭ������ȡַ�����const����" << " this addr: " << this << std::endl;
	return this;
}

// Ĭ���ƶ����캯��
MyClass::MyClass(MyClass&& m) :
	m_pData(std::move(m.m_pData))
{
	std::cout << "Ĭ���ƶ����캯��" << std::endl;
	m.m_pData = nullptr;
}

// Ĭ�������ƶ���ֵ����������
MyClass& MyClass::operator =(MyClass&& m)
{
	if (this == &m) {
		return *this;
	}

	this->m_pData = nullptr;
	this->m_pData = std::move(m.m_pData);
	m.m_pData = nullptr;
	std::cout << "Ĭ�������ƶ���ֵ����������" << " this addr: " << this << std::endl;
	return *this;
}

void funA(MyClass a)
{
	std::cout << "����funA����" << " param addr: " << &a << std::endl;
}

void mytest1(void)
{
	std::cout << "mytest1 >>>>" << std::endl;
	MyClass myclass1; // �ȼ��� MyClass myclass1 = MyClass(); // ����Ĭ�ϴ��ι��캯��
	myclass1 = MyClass(); // MyClass()Ϊ��ֵ����Ҫ��ֵ���� // �ȵ���Ĭ�ϴ��ι��캯����Ȼ�����Ĭ������ȡַ�����������������Ĭ�������ƶ���ֵ����������
	std::cout << "<<<<< mytest1" << std::endl;
	// �������� 1: myclass1 = MyClass()�е�MyClass() 2: MyClass myclass1
}

void mytest2(void)
{
	std::cout << "mytest2 >>>>" << std::endl;
	MyClass myclass1; // �ȼ��� MyClass myclass1 = MyClass(); // ����Ĭ�ϴ��ι��캯��
	MyClass myclass2(myclass1);  // ����Ĭ�Ͽ������캯��
	myclass2 = myclass1; // myclass2Ϊ��ֵ�����Դ˲���Ϊ��ֵ�����������Ĭ������ȡַ�����const������Ȼ�����Ĭ�����ظ�ֵ���������
	funA(myclass1); // ������ֵ�ᵼ�¸�ֵ�����������Ĭ�Ͽ������캯����Ȼ��funA��������Ĭ������ȡַ���������ȡ�ò���
	funA(std::move(myclass1)); // funA�����Ĳ�����Ϊ��ֵ�������Ĭ���ƶ����캯����Ȼ��funA��������Ĭ������ȡַ���������ȡ�ò���
	// ���ƶ����캯���ж��ڻ���������ν�ƶ�ֻ�ǰ���ֵ������������string�������Ա��˵�Ż���������ν��Դ�ƶ�
	std::cout << "<<<<< mytest2" << std::endl;
}

void mytest3(void)
{
	std::cout << "mytest3 >>>>" << std::endl;
	funA(MyClass()); // �����Ĭ�ϴ��ι��캯�������ɸ���Ķ���Ȼ��funA��������Ĭ������ȡַ���������ȡ�ò���
	std::cout << "<<<<< mytest3" << std::endl;
	// ����һ�� 1: funA(MyClass())�е�MyClass()�γɵĶ�������funA�����������õ�ʱ�򣬵���Ĭ����������
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


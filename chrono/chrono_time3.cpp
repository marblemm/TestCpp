#include<iostream>
#include<vector>
#include<string>
#include<ctime>//��ʱ���ʽ������ת�����ַ���
#include<chrono>
using namespace std::chrono;
using namespace std;
int main()
{
	//��ȡϵͳ�ĵ�ǰʱ��
	auto t = system_clock::now();
	//����ȡ��ʱ��ת����time_t����
	auto tNow = system_clock::to_time_t(t);

	//ctime()������time_t���͵�ʱ��ת�����ַ�����ʽ,����ַ����Դ����з�
	string str_time = std::ctime(&tNow);

	cout << str_time;

	return 0;
}
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std;
using namespace std::chrono;
int g_count = 0;
std::mutex mymutex;

void mythread()
{
	for (int i = 0; i < 1000000; i++)
	{
		std::unique_lock<std::mutex> u1(mymutex);
		g_count++;
	}
}


int main()
{
	std::thread t1(mythread);
	std::thread t2(mythread);
	auto start = steady_clock::now();
	t1.join();
	t2.join();
	auto end = steady_clock::now();
	auto tt = duration_cast<milliseconds>(end - start);
	cout << "������ʱ=" << tt.count() << "����" << endl;
	cout << "��������½��Ӧ����200 0000�Σ�ʵ����" << g_count << endl;
	return 0;
}

/*
�����
������ʱ=349����
��������½��Ӧ����200 0000�Σ�ʵ����2000000
*/
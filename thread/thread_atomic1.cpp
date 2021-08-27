#include <iostream>
#include <thread>

using namespace std;
#include <chrono>
using namespace std::chrono;
int g_count = 0;

void mythread()
{
	for (int i = 0; i < 1000000; i++)
	{
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
	cout << "程序用时=" << tt.count() << "毫秒" << endl;
	cout << "正常情况下结果应该是200 0000次，实际是" << g_count << endl;
	return 0;
}

/*
结果：
程序用时=16毫秒
正常情况下结果应该是200 0000次，实际是1303733
*/
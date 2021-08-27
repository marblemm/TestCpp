#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>

using namespace std;
using namespace std::chrono;
std::atomic<int> g_count = 0; //封装了一个类型为int的 对象（值）

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
程序用时=51毫秒
正常情况下结果应该是200 0000次，实际是2000000
*/
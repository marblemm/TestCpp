#include <iostream>
#include <deque>
#include <thread>
#include <mutex>
using namespace std;
#include <chrono>
using namespace std::chrono;

std::deque<int> q;
std::mutex mu;

void function_1()
{
	int count = 10;
	while (count > 0)
	{
		std::unique_lock<std::mutex> locker(mu);
		q.push_front(count);
		locker.unlock();
		std::this_thread::sleep_for(std::chrono::seconds(1));
		count--;
	}
}

void function_2()
{
	int data = 0;
	while (data != 1)
	{
		std::unique_lock<std::mutex> locker(mu);
		if (!q.empty())
		{
			data = q.back();
			q.pop_back();
			locker.unlock();
			std::cout << "t2 got a value from t1: " << data << std::endl;
		}
		else {
			locker.unlock();
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
		}
	}
}
int main()
{
	std::thread t1(function_1);
	std::thread t2(function_2);
	auto start = steady_clock::now();

	t1.join();
	t2.join();

	auto end = steady_clock::now();
	auto tt = duration_cast<milliseconds>(end - start);
	cout << "程序用时=" << tt.count() << "毫秒" << endl;
	return 0;
}

//输出结果
//t2 got a value from t1: 10
//t2 got a value from t1: 9
//t2 got a value from t1: 8
//t2 got a value from t1: 7
//t2 got a value from t1: 6
//t2 got a value from t1: 5
//t2 got a value from t1: 4
//t2 got a value from t1: 3
//t2 got a value from t1: 2
//t2 got a value from t1: 1
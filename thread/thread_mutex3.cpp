#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>​
std::mutex g_mutex;

void func()
{
	std::lock_guard<std::mutex> lock(g_mutex);   //加锁
	std::cout << "entry func test thread ID is : " << std::this_thread::get_id() << std::endl;
	std::this_thread::sleep_for(std::chrono::microseconds(1000));
	std::cout << "leave func test thread ID is : " << std::this_thread::get_id() << std::endl;
	//退出作用域后，lock_guard对象析构就自动解锁
}

int main()
{
	std::thread t1(func);
	std::thread t2(func);
	std::thread t3(func);
	std::thread t4(func);
	std::thread t5(func);

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	return 0;
}
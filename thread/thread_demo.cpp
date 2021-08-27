#include <iostream>
#include <deque>
#include <thread>
#include <mutex>​
void threadfunc()
{
	std::cout << "detach thread func" << std::endl;
}
int main()
{
	std::thread t1(threadfunc);
	std::thread t2(std::move(t1));

	t2.join();
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));//睡眠1000毫秒
		break;
	}
	return 0;
}
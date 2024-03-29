#include <iostream>
#include <memory> // shared_ptr
#include <mutex>  // mutex

// version 2:
// with problems below fixed:
// 1. thread is safe now
// 2. memory doesn't leak

class Singleton
{
public:
	~Singleton()
	{
		std::cout << "destructor called!" << std::endl;
	}
	Singleton(Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	static std::shared_ptr<Singleton> get_instance()
	{
		// "double checked lock"
		if (m_instance_ptr == nullptr)
		{
			std::lock_guard<std::mutex> lk(m_mutex);
			if (m_instance_ptr == nullptr)
			{
				m_instance_ptr = std::shared_ptr<Singleton>(new Singleton);
			}
		}
		return m_instance_ptr;
	}


private:
	Singleton()
	{
		std::cout << "constructor called!" << std::endl;
	}
	static std::shared_ptr<Singleton> m_instance_ptr;
	static std::mutex m_mutex;
};

// initialization static variables out of class
std::shared_ptr<Singleton>  Singleton::m_instance_ptr = nullptr;
std::mutex Singleton::m_mutex;

int main()
{
	std::shared_ptr<Singleton> instance = Singleton::get_instance();
	std::shared_ptr<Singleton> instance2 = Singleton::get_instance();
	return 0;
}

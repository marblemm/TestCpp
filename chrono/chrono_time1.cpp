#include <ctime>
#include <iostream>
using namespace std;

int main()
{

	clock_t start = clock();
	// do something...
	clock_t end = clock();
	cout << "������" << (double)(end - start) / CLOCKS_PER_SEC << "��" << endl;
}

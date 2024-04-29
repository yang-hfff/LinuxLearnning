#include <vector>
#include <iostream>
#include <chrono>

using namespace std;

int main()
{			
	while (1)
	{
		cout << "请输入开辟空间的大小:";
		uint32_t n = 0;
		cin >> n;

		//new
		auto start = std::chrono::high_resolution_clock::now();
		double* a = new double[n];
		auto stop = std::chrono::high_resolution_clock::now();
		auto timeout1 = std::chrono::duration_cast<std::chrono::duration<double, ratio<1, 1000>>>(stop - start);
		cout << "new开辟空间耗时：" << timeout1.count() << "ms" << endl;
		delete[] a;

		//vector
		start = std::chrono::high_resolution_clock::now();
		vector<double> b(n);
		stop = std::chrono::high_resolution_clock::now();
		auto timeout2 = std::chrono::duration_cast<std::chrono::duration<double, ratio<1, 1000>>>(stop - start);
		cout << "vector开辟空间耗时：" << timeout2.count() << "ms" << endl;

		//unique_ptr
		start = std::chrono::high_resolution_clock::now();
		unique_ptr<double[]> c = unique_ptr<double[]>(new double[n]);
		stop = std::chrono::high_resolution_clock::now();
		auto timeout3 = std::chrono::duration_cast<std::chrono::duration<double, ratio<1, 1000>>>(stop - start);
		cout << "unique_ptr开辟空间耗时：" << timeout3.count() << "ms\n" << endl;
	}

    return 0;
}
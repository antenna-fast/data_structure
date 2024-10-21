// selection sort
//「选择排序 selection sort」的工作原理非常简单：
// 开启一个循环，每轮从未排序区间选择最小的元素，将其放到已排序区间的末尾。
// ref: https://www.hello-algo.com/chapter_sorting/selection_sort/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	std::vector<int> a{3, 2, 5, 1, 8, 0};
	
	// from small to big
	for (size_t i = 0; i < a.size()-1; i++)
	{
		for(int j=i+1; j<a.size(); j++)
		{
			if(a.at(i) > a.at(j) )
			{
				// swap a[i] and the following one
				int tmp = a.at(i);
				a.at(i) = a.at(j);
				a.at(j) = tmp;
			}
		}
	}
	

	for(int i=0; i<a.size(); i++)
	{
		cout << a.at(i) << endl;
	}

	return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	std::vector<int> a{3,2,5,1,8,0};
	
	// we want to from small to big
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

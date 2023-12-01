#include <iostream>


using namespace std;

// f(n) = 1+2+...n
int add(int n)
{
    if(n==0)
    {
        return 0;
    }
    else
    {
        return n+add(n-1);
    }
}

int main()
{
    cout << add(100) << endl;
}

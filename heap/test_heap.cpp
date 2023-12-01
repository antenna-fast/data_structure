// 「堆 heap」是一种满足特定条件的完全二叉树


#include <iostream>

using namespace std;

int main(int argc, char** argv) 
{
    if(argc != 1)
    {
        std::cout << " argc not match, Usage: " << std::endl;
        return -1;
    }

    std::cout << "running: " << argv[0] << std::endl;
    
    return 0;
}

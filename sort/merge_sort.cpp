#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
    if(argc != 1) {
        std::cout << " argc not match, Usage: " << std::endl;
        return -1;
    }

    std::cout << "running: " << argv[0] << std::endl;
    
    // std::vector<int> a{3,2,5,1,8,0};
    std::vector<int> a{3,2};

    // split vector
    int len_vec = a.size();
    
    // find mid
    int mid_idx = len_vec / 2 - 1;
    
    vector<int> left_vec, right_vec; 
    for (size_t i = 0; i <= mid_idx; i++)
    {
        left_vec.push_back(a[i]);
    }

    for (size_t i = mid_idx; i < len_vec; i++)
    {
        right_vec.push_back(a[i]);
    }
    
    // merge vector

    return 0;
}
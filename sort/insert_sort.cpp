// ref: https://www.hello-algo.com/chapter_sorting/insertion_sort/#1143

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
    if(argc != 1) {
        std::cout << " argc not match, Usage: " << std::endl;
        return -1;
    }

    std::cout << "running: " << argv[0] << std::endl;
    
    std::vector<int> a{3,4,5,1,8,0,9};
    // std::vector<int> a{5,4};
    // std::vector<int> a{4, 5};
	
    for (size_t i = 1; i < a.size(); i++)  // pick unsorted element one-by-one
    {
        int tmp = a[i];

        // get insert index
        int insert_idx = i;  // init insert index
        while (insert_idx>0)
        {
            if(a[insert_idx-1] > tmp)
            {
                insert_idx-=1;
            }
            else
            {
                break;
            }
        }
        
        cout << "insert_idx: " << insert_idx << endl;

        // perform move: [insert_idx, i-1] to [insert_idx+1, i]
        for (size_t j = i; j > insert_idx; j--)
        {
            a[j] = a[j-1];
        }
        
        // insert
        a[insert_idx] = tmp;
    }
    
    for (size_t i = 0; i < a.size(); i++)
    {
        cout << a[i] << endl;
    }
    

    return 0;
}
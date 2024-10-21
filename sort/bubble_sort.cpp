// ref: https://www.hello-algo.com/chapter_sorting/bubble_sort/

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
    if(argc != 1) {
        std::cout << " argc not match, Usage: " << std::endl;
        return -1;
    }

    std::cout << "running: " << argv[0] << std::endl;
    
    vector<int> a{5,4,2,3,8,7,9,0};

    // easy to understand version
    for (size_t i = a.size(); i > 1; i--)  // [ size(), 2 ] 
    {
        for (size_t j = 1; j < i; j++)  // [ 1, size()-1 ]
        {
            if(a.at(j) < a.at(j-1))
            {
                // swap
                int tmp = a.at(j);
                a.at(j) = a.at(j-1);
                a.at(j-1) = tmp;
            }
        }
    }
    

    // for (size_t l = a.size()-1; l > 0; l--)
    // {
    //     for (size_t i = 0; i < l; i++)  // let the biggest on lie at least
    //     {
    //         if(a.at(i) > a.at(i+1))
    //         {
    //             int tmp = a.at(i);
    //             a.at(i) = a.at(i+1);
    //             a.at(i+1) = tmp;
    //         }
    //     }
    // }


    for (size_t i = 0; i < a.size(); i++)
    {
        cout << a.at(i) << endl;
    }
    
    return 0;
}
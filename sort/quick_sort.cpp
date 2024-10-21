// Author: Yaohua Liu
// date: 2023-12-05

// ref: https://blog.csdn.net/dongdong7_77/article/details/108458561

#include <iostream>
#include <vector>

using namespace std;


void quick_sort(vector<int> &a, int left, int right)
{
    int tmp = a.at(left);
    // int left = 0;
    // int right = a.size()-1;

    int ori_left = left; 
    int ori_right = right; 

    int mid = 0;

    while (left < right)
    {
        // search from right to left to find < 6 one
        while (left < right)
        {
            if(a.at(right) < tmp)  // found
            {
                break;
            }
            else
            {
                right --;
            }
        }
        // std::cout << "right: " << right << endl;
    
        // search from left to right to find > 6 one
        while (left < right)
        {
            if(a.at(left) > tmp)  // found
            {
                break;
            }
            else
            {
                left ++;
            }
        }
        // std::cout << "left: " << left << endl;

        // swap them
        if(left != right)
        {
            int gt_buf = a.at(left);
            a.at(left) = a.at(right);
            a.at(right) = gt_buf;
        }
        else if(left == right)  // after above two while loop, the left finally must can == right
        {
            if(a.at(left) < tmp)  // need to swap
            {
                int lt_buf = a.at(left);
                a.at(left) = tmp;
                a.at(0) = lt_buf;
                break;
            }
            else
            {
                break;
            }
        }
    }

    mid = left;
    std::cout << "mid: " << mid << endl;

    // if(mid < ori_right)
    // {
    //     quick_sort(a, mid+1, ori_right);
    // }

    // if(mid > ori_left)
    // {
    //     quick_sort(a, ori_left, mid-1);
    // }

}

void display(vector<int> &a)
{
    for (size_t i = 0; i < a.size(); i++)
    {
        std::cout << a.at(i) << ", " ;
    }
    std::cout << endl;
}


int main(int argc, char** argv) 
{
    if(argc != 1)
    {
        std::cout << " argc not match, Usage: " << std::endl;
        return -1;
    }

    std::cout << "running: " << argv[0] << std::endl;
    
    std::vector<int> a{6,4,10,5,1,8,0,9,-1};
    
    display(a);
    
    quick_sort(a, 0, a.size()-1);
    display(a);

    quick_sort(a, 0, 5-1);
    display(a);

    quick_sort(a, 2, 5-1);
    display(a);

    return 0;
}
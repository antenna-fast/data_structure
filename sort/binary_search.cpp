#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int binary_search_1d(int query, vector<int> gallery){
    uint start = 0;
    uint end = gallery.size() - 1;
    uint mid;
    int ret = -1;  // not found flag
    while (start <= end)
    {
        mid = start + (end - start) / 2;  // to avoid overflow
        if(gallery[mid] < query){
            start = mid + 1;
        }
        else if (gallery[mid] > query)
        {
            end = mid - 1;
        }
        else{
            ret = mid;
            break;
        }
    }
    return ret;
}

uint binary_search_nn_1d(int query, vector<int> gallery){
    uint start = 0;
    uint end = gallery.size() - 1;
    uint mid;
    uint ret;

    float min_dist = std::numeric_limits<float>::max();  // inti with maximum

    while (start <= end)
    {
        mid = start + (end - start) / 2;  // to avoid overflow
        if(gallery[mid] < query){
            start = mid + 1;
            int dist_tmp = query - gallery[mid];
            if(dist_tmp < min_dist){
                min_dist = dist_tmp;
                ret = mid;
            }
        }
        else if (gallery[mid] > query)
        {
            end = mid - 1;
            int dist_tmp = gallery[mid] - query;
            if(dist_tmp < min_dist){
                min_dist = dist_tmp;
                ret = mid;
            }
        }
        else{
            ret = mid;
            break;
        }
    }
    return ret;
}

int main(int argc, char** argv){
    std::cout << "running: " << argv[0] << std::endl;

    vector<int> gallery;
    for (size_t i = 0; i < 50000000; i++)
    {
        gallery.push_back(i);
    }

    int query = gallery.size() + 1000;
    // int query = numeric_limits<int>::max();
    // int query = 2147483647;
    
    // int query = 0;
    
    // search
    // int ret = binary_search_1d(query, gallery);
    int ret = binary_search_nn_1d(query, gallery);
    
    // if(ret){
        cout << "query found in gallery: " << ret << endl;
    // }
    // else{
    //     cout << "query nor found." << endl;
    // }

    return 0;
}
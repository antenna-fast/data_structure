// Author: Yaohua Liu
// date: 2023-12-01

// graph basic using adjencent matrix 
// ref: https://www.hello-algo.com/chapter_graph/graph_operations/ 

#include <iostream>
#include <vector>

using namespace std;

class GraphAdjMat
{
private:
    vector<int> vert;
    vector<vector<int>> adjMat;

public:

    int size()
    {
        return vert.size();
    }

    void addVert(int val)
    {
        // modify vertex array
        vert.push_back(val);

        // add a row to adjencent matrix
        adjMat.push_back(vector<int>(10, 0));
        // add a col to adjencent matrix
        for(vector<int> & r : adjMat)
        {
            r.push_back(0);
        }        
    }

    void delVert(int idx)
    {
        int num = size();
        if(idx >= num)
        {
            cout << "Idx overflow!" << endl;
            return;
        }

        vert.erase(vert.begin() + idx);

        adjMat.pop_back();
        for(vector<int> r : adjMat)
        {
            r.erase(r.begin() + idx);
        }
    } 

    void addEdge(int i, int j)
    {
        int num = size();
        if(i==j || i<0 || j<0 || i>=num || j >= num)
        {
            cout << "idx overflow: i: " << i << ", j: " << j << ", totle: " << num << endl;
            return;
        }
        adjMat[i][j] = 1;
        adjMat[j][i] = 1;
    }

    void delEdge(int i, int j)
    {
        int num = size();
        if(i==j || i<0 || j<0 || i>=num || j >= num)
        {
            cout << "idx overflow: i: " << i << ", j: " << j << ", totle: " << num << endl;
            return;
        }
        adjMat[i][j] = 0;
        adjMat[j][i] = 0;
    }

    void displayGraph()
    {
        int num = size();
        for (size_t i = 0; i < num; i++)
        {
            for (size_t j = 0; j < num; j++)
            {
                cout << adjMat[i][j] << " ";
            }
            cout << " " << endl;
        }
    }
};


int main(int argc, char** argv) 
{
    if(argc != 1)
    {
        std::cout << " argc not match, Usage: " << std::endl;
        return -1;
    }

    std::cout << "running: " << argv[0] << std::endl;
    
    GraphAdjMat *g = new GraphAdjMat;

    for (size_t i = 0; i < 3; i++)
    {
        g->addVert(i);
    }
    
    g->addEdge(1, 2);
    g->displayGraph();

    g->delEdge(1, 2);
    g->displayGraph();

    g->delVert(1);
    g->displayGraph();

    return 0;
}
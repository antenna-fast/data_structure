// Author: Yaohua Liu
// date: 2023-12-01

// graph basic using linked 
// ref: https://www.hello-algo.com/chapter_graph/graph_operations/ 
// ref: http://data.biancheng.net/view/203.html

// TODO: fix it

#include <iostream>
#include <vector>

using namespace std;

typedef struct Node
{
    int val;
    int adjIdx;
    Node* next;

    Node(int val, int adjIdx) : val(val), adjIdx(adjIdx), next(nullptr) {}
} Node;

class GrapgLinked
{
private:
    vector<Node*> vert;

public:
    int size()
    {
        return vert.size();
    }

    void addVert(int val)
    {
        Node* newVert = new Node(val, -1);
        vert.push_back(newVert);
    }

    void delVert(int idx)
    {
        if(idx < 0 || idx >= size())
        {
            cout << "idx illegal" << endl;
            return;
        }
        vert.erase(vert.begin() + idx);
    }

    void addEdge(int i, int j)
    {
        if(i<0 || i>=size() || j<0 || j>= size() || i==j)
        {
            cout << "i, j illegal" << endl;
            return;
        }

        // insert from i to j 
        Node* tmp = vert.at(i)->next;
        while (tmp)  // iter to check if already inserted edge link from i to j
        {
            if(tmp->adjIdx == j)
            {
                cout << "i-j " << i << ", " << j << " link already exist" << endl;
                return;
            }

            cout << "tmp: " << tmp->adjIdx << endl;
        }
        
        Node* newNode = new Node(-1, j);  // init node to record adjIdx
        // insert new node to linked-list's head
        tmp = newNode;

        // insert from j to i
        Node* &tmp2 = vert.at(j)->next;
        while (tmp2)
        {
            if(tmp2->adjIdx == i)
            {
                cout << "i-j " << i << ", " << j << " already exist" << endl;;
                return;
            }
            tmp2 = tmp2->next;
        }
        Node* newNode2 = new Node(-1, i);
        tmp2 = newNode2;
        // vert.at(j)->next = newNode2;
    }

    void delEdge(int i, int j)
    {

    }

    void displayGraph()
    {
        for (size_t i = 0; i < size(); i++)
        {
            cout << "vert: " << vert.at(i)->val << endl;
            Node* tmp = vert.at(i)->next;
            cout << "   edge: ";
            while (tmp)
            {
                cout << tmp->adjIdx << " ";
                tmp = tmp->next;
            }
            cout << endl;
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
    
    GrapgLinked *g = new GrapgLinked;

    for (size_t i = 0; i < 5; i++)
    {
        g->addVert(i);
    }
    
    g->addEdge(0, 1);
    // g->addEdge(0, 1);
    g->addEdge(0, 2);
    g->addEdge(0, 3);
    // g->addEdge(2, 3);

    g->displayGraph();

    return 0;
}
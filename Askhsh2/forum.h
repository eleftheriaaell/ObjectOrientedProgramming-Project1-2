#include "tree.h"

using namespace std;

class forum{
public:
    forum(string ft);
    ~forum();
    void print_sorted();
    
private:
    string ftitle;
    thread *T;
    int cnt;
    tree **Tr;
    tree *Tree;
};

#include "thread.h"
#include "post_list.h"

class tree{
public:
    tree(thread &thr);
    tree();
    tree(tree* T);
    ~tree();
    void print_tree();
    void traversal(tree* Tree);

private:
    string creator;
    p_list* ppost;
    tree* left;
    tree* right;
    void create_tree(string s, thread &thr);
    void deallocate();
    void merge(tree* node);
};



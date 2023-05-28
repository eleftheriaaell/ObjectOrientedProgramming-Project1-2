#include "thread.h"

class forum{
public:
    forum(string ft);
    ~forum();
    void printt();
    void choose(string s);
    void ppost(int);
    
private:
    string ftitle;
    thread *T;
    int cnt;
};

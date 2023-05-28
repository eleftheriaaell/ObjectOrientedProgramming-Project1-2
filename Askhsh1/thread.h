#include "post.h"

class thread{
public:
    thread();
    ~thread();
    void tprint();
    void name();
    void pprint();
    int check(string s);
    int p_check(int n);

private:
    string subject;
    string tcreator;            //requested fields
    date tdate;
    post *P;
    int cnt;                    //number of random posts included in thread
    void choose_t();
    void choose_tt();
    void t_date();
};
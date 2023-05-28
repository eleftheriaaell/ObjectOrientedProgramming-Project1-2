#include "post.h"

class thread{
public:
    thread();
    ~thread();
    int counter();
    string c_list();
    post& repost();

private:
    string subject;
    string tcreator;           
    date tdate;
    post *P;
    int cnt;                
    void choose_t();
    void choose_tt();
    void t_date();
    void tprint();
};
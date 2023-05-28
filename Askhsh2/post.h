#include <iostream>
#include <string>
#include <cstdlib>
#include "date.h"

using namespace std;

class post{
public:
    post();
    post(post &P);
    post(post *P);
    ~post();
    string name();
    void p_name();
    
private:
    int id;
    string title;                   
    string creator;
    date pdate;
    string text;
    void random();                 
    void p_date();
    void print();
    void copy(post &P);
};
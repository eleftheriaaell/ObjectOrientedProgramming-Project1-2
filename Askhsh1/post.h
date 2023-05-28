#include <iostream>
#include <string>
#include <cstdlib>
#include "date.h"

using namespace std;

class post{
public:
    post();
    ~post();
    void print();
    int check(int n);
    
private:
    int id;
    string title;                   //requested fields
    string creator;
    date pdate;
    string text;
    void random();                 
    void p_date();
};
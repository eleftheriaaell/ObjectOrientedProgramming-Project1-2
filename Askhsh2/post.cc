#include "post.h"
#include "post_array.h"

post::post(){
    random();
    p_date();
    print();
}

post::post(post &P){
    copy(P);                //copying post
}

post::post(post *P){
    id=P->id;
    creator=P->creator;
    title=P->title;
    pdate=P->pdate;
    text=P->text;
}                          //copying post for merge

post::~post(){
    cout<<"Post number: "<<id<<" is about to be destroyed."<<endl;
}

void post::random(){
    string P[10], C[10], Tx[10];
    
    create(P);
    cr_create(C);
    txt(Tx);
    
    int k=rand()%10;
    static int i=1;

    id=i;
    title=P[k];
    creator=C[k];
    text=Tx[k];

    i++;
}                                       //creating post

void post::p_date(){
    pdate.day=29;
    pdate.month=11;
    pdate.year=2019;
}                                       //date creation

void post::print(){
    cout<<"Post:"<<endl;
    cout<<"ID: "<<id<<endl;
    cout<<"Title of Post: "<<title<<endl;
    cout<<"Creator of Post: "<<creator<<endl;
    cout<<"Text: "<<text<<endl;
    cout<<"Creation Date of Post: "<<pdate.day<<"/"<<pdate.month<<"/"<<pdate.year<<endl;
    cout<<endl;
}                                      //printing post info                                     

string post::name(){
    return creator;
}                                      //returning post creator

void post::copy(post &P){
    id=P.id;
    creator=P.creator;
    title=P.title;
    pdate=P.pdate;
    text=P.text;
}                                       //called by destructor for copying post

void post::p_name(){
    cout<<"Post "<<id<<": "<<title<<endl;
}                                      //printing post id and title
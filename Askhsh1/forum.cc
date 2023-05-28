#include "forum.h"
#include "thread_array.h"
#include "post_array.h"

forum::forum(string ft){
    cnt=rand()%5+1;             //random !=0 number of threads
    T=new thread[cnt];          //creation of threads array
    ftitle=ft;
    cout<<"Forum with title: "<<ftitle<<" has just been created!"<<endl;
}

forum::~forum(){
    cout<<"Forum with title: "<<ftitle<<" is about to be destroyed."<<endl;
    delete []T;                 //deallocating array of threads
}

void forum::printt(){    
    cout<<endl;

    cout<<"Threads:"<<endl;
    for(int i=0; i<cnt; i++){
        cout<<i+1<<". ";                
        T[i].name();            //printing thread name through thread::name    
    }
    cout<<endl;
}                               //printing threads of current forum

void forum::choose(string s){
    int i;
    for(i=0; i<5; i++){
        if(T[i].check(s)){      //check for subject existance through thread::check
            cout<<"Chosen Thread: "<<s<<endl;
            cout<<endl;
            break;
        }
    }
    T[i].tprint();              //printing chosen thread
    T[i].pprint();              //printing posts of chosen thread
}

void forum::ppost(int n){
    for(int i=0; i<cnt; i++){
        if(T[i].p_check(n)==1)
            break;
    }
}                               //for random post printing
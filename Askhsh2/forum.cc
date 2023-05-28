#include "forum.h"
#include "thread_array.h"
#include "post_array.h"

forum::forum(string ft){
    cnt=rand()%5+1;                 //random !=0 number of threads
    T=new thread[cnt];              //creation of threads array
    Tr=new tree*[cnt];              //creation of tree array
    ftitle=ft;
    cout<<"Forum with title: "<<ftitle<<" has just been created!"<<endl<<endl;
    cout<<endl;
}

forum::~forum(){
    cout<<endl<<"Forum with title: "<<ftitle<<" is about to be destroyed."<<endl<<endl;
    delete []T;                    //deallocating array of threads
    delete []Tr;                   //deallocating array of trees
}

void forum::print_sorted(){
    Tree=new tree(T[0]);           //creating final tree
    
    Tr[0]=new tree(T[0]);
    for(int i=1; i<cnt; i++){
        Tr[i]=new tree(T[i]);
        Tree->traversal(Tr[i]);   //merging trees
    }
    
    cout<<"TREE"<<":"<<endl<<endl;
    Tree->print_tree();          //printing final tree through tree::print_tree

    cout<<"Posts of tree are about to be destroyed:"<<endl;
    cout<<"-------------------------------------------"<<endl;
    for(int i=0; i<cnt; i++)
        delete Tr[i];            //deallocating array of trees

    delete Tree;                 //deallocating final tree
    cout<<"-------------------------------------------"<<endl;
}
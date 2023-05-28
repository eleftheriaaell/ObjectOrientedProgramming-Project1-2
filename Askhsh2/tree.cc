#include "tree.h"

tree::tree(thread &thr){
    ppost=NULL;
    
    if(thr.counter())     //checking for !=0 counter of posts
        for(int i=0; i<thr.counter(); i++){
            create_tree(thr.c_list(), thr);     //creating tree 
        }
}

tree::tree(){}

tree::tree(tree* T){
    creator=T->creator;
    left=NULL;
    right=NULL;
   
    ppost=new p_list();
    ppost->posts=new post(T->ppost->posts);
    
    p_list* temp=T->ppost->next;
    p_list* temp2=ppost;

    while (temp!=NULL){
        temp2->next=new p_list();
        temp2->next->posts=new post(temp->posts);
        temp2->next->next=NULL;
        temp=temp->next;
        temp2=temp2->next;
    }  
}                           //constructor used for merge

tree::~tree(){
    deallocate();   
}                          //deallocating tree

void tree::create_tree(string s, thread &thr){
    if(ppost == NULL){
        left=NULL;
        right=NULL;
        creator=s;

        ppost=new p_list();  
        ppost->next=NULL;
        ppost->posts=new post(thr.repost());
    }                                            //for non existing creator

    else if(creator == s){
        p_list* temp=ppost;

        while(temp->next != NULL)
            temp=temp->next;
        
        p_list* node=new p_list;
        node->next=NULL;
        node->posts=new post(thr.repost());
        temp->next=node;
    }                                            //for existing creator
       
    else if(creator < s){
        if(right == NULL){
            right=new tree();
            right->ppost=NULL;

            right->create_tree(s, thr); 
        }
        
        else
            right->create_tree(s, thr);
    }                                           //for sorted creators
       

    else if(creator > s){
        if(left == NULL){
            left=new tree();
            left->ppost=NULL;

            left->create_tree(s, thr); 
        }
        
        else
            left->create_tree(s, thr);
    }                                          //for sorted creators
}

void tree::traversal(tree* Tree){
    if(Tree == NULL)
        return;

    if(Tree->left != NULL) 
        traversal(Tree->left);
        
    if(Tree->right != NULL)
        traversal(Tree->right);
     
    merge(Tree);
}                                            //travelling through tree and separately merging nodes

void tree::merge(tree* node){
    if(creator == node->creator){
        p_list* temp=ppost;
        p_list* temp2=node->ppost;

        while(temp->next != NULL)
            temp=temp->next;
        
        while(temp2 != NULL){
            temp->next=new p_list();
            temp->next->posts=new post(temp2->posts);
            
            temp->next->next=NULL;
            temp2=temp2->next;
            temp=temp->next;
        }
       
        return;
    }                                  //for existing creator
       
    else if(creator < node->creator){
        if(right == NULL){
            right=new tree(node);
        }
        
        else
            right->merge(node);
    }                                //for sorted creators
       

    else if(creator > node->creator){
        if(left == NULL){
            left=new tree(node);
        }
        
        else 
            left->merge(node);
    }                               //for sorted creators
}

void tree::deallocate(){
    
    delete left;
    delete right;
    
    p_list* temp=ppost;
    while(ppost != NULL){
        temp=ppost->next;
        delete ppost->posts;
        delete ppost;
        ppost=temp;
    }
}                               //deallocating posts and nodes

void tree::print_tree(){
    if(this == NULL)
        return;
    
    left->print_tree();

    cout<<creator<<":"<<endl;
    p_list* temp=ppost;
    while(temp != NULL){
        temp->posts->p_name();
        temp=temp->next;
    }
    
    cout<<endl;

    right->print_tree();
}                              //printing tree
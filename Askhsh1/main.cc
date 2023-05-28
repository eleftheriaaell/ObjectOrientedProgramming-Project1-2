#include "forum.h"

int main(){
    forum obj("Αντικειμενοστραφής Προγραμματισμός");    //forum creation
    obj.printt();                                      
    
    obj.choose("Κανόνες και Χρήσιμες Πληροφορίες");     //thread selection
    
    cout<<"List of Random Posts:"<<endl<<endl;
    int j=rand()%4+1;                                   //number of random posts
    for(int i=0; i<j; i++)
        obj.ppost(rand()%10);                           //random post selection

    return 0;
}
#include "thread.h"
#include "thread_array.h"

thread::thread(){
    cnt=rand()%10+1;                //random !=0 number of posts
    P=new post[cnt];                //creation of posts array
    static int i=0;
    if(i==0){
        choose_tt();
        t_date();
        i++;
    }
    else{
        choose_t();
        t_date();
    }
    cout<<"Thread with subject: "<<subject<<" has just been created!"<<endl;
    cout<<endl;
    tprint();
}

thread::~thread(){
    cout<<endl<<"Thread with subject: "<<subject<<" is about to be destroyed."<<endl;
    delete []P;                     //deallocating array of posts
}

void thread::choose_tt(){
    subject="Κανόνες και Χρήσιμες Πληροφορίες";
    tcreator="avicci";
}                                  //creating standard thread of "Κανόνες και Χρήσιμες Πληροφορίες"

void thread::choose_t(){
    string T[5], C[5];
    
    createt(T);
    t_create(C);

    int i=rand()%5;

    subject=T[i];
    tcreator=C[i];
}                                  //creating random threads

void thread::t_date(){
    tdate.day=29;
    tdate.month=11;
    tdate.year=2019;
}                                  //creating creation date

void thread::tprint(){
    cout<<"Thread: "<<endl;
    cout<<"Subject: "<<subject<<endl;
    cout<<"Creator: "<<tcreator<<endl;
    cout<<"Creation Date of Thread: "<<tdate.day<<"/"<<tdate.month<<"/"<<tdate.year<<endl;
    cout<<endl;
}                                  //printing thread

int thread::counter(){
    return cnt;
}                                  //returning counter of posts

string thread::c_list(){
    static int i=0;
    if(i>=cnt)
        i=0;
    return P[i++].name();          //returning name of post through post::name
}

post& thread::repost(){
    static int i=0;
    if(i>=cnt)
        i=0;
    return P[i++];                 //returning whole post;
}
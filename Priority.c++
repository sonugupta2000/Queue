#include <iostream>
using namespace std;
#define MAX 100
typedef struct nodetype{
    int info;
    struct nodetype *next;
}node;
void enqueue_prior(node **front,int item){
    node *ptr,*loc,*temp;
    ptr=(node*)malloc(sizeof(node));
    ptr->info=item;
    if (*front==NULL){
        *front=ptr;
        ptr->next=NULL;
    }
    else{
        loc=*front;
        temp=NULL;
        while((loc!=NULL) && (loc->info<=item)){
            temp=loc;
            loc=loc->next;
        }
        if (loc==*front){
            ptr->next=*front;
            *front=ptr;
        }
        else{
            ptr->next=temp->next;
            temp->next=ptr;
        }
    }
}
void dequeue_prior(node **front){
    node *ptr;
    if (*front==NULL){
        cout<<"Queue is empty"<<endl;
        return;
    }
    else{
    ptr=*front;
    cout<<"deleted item "<<ptr->info<<endl;
    *front=ptr->next;
    }
    free(ptr);
}
void display(node *front,node *rear){
    if (front==NULL){
        cout<<"Queue is empty"<<endl;
        return;
    }
    else{
        while(front!=rear){
            cout<<front->info<<endl;
            front=front->next; 
        }
        cout<<rear->info<<endl;
    }
    }
int main(){
    node queue[MAX];
    node *front,*rear;
    front=NULL;
    rear=NULL;;
    int choice,item;
    while(1){
        cout<<"Welcome to Priority Queue program"<<endl;
        cout<<"Enter your choice"<<endl;
        cout<<"1.Enqueue"<<endl;
        cout<<"2.Dequeue"<<endl;
        cout<<"3.Display"<<endl;
        cout<<"3.Exit"<<endl;
        cin>>choice;
        switch(choice){
        case 1:
            cout<<"Enter item"<<endl;
            cin>>item;
            enqueue_prior(&front,item);
            break;
        case 2:
            dequeue_prior(&front);
            break;
        case 3:
            display(front,rear);
            break;
        default:
            exit(1);
        }
    }
return 0;
}

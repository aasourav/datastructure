#include <iostream>
#include <cstdlib>
#define N 0
using namespace std;
struct doubleList{
	int n;
	struct doubleList *next;
	struct doubleList *prev;
};

typedef struct doubleList node;
node *head=N, *tail=N;
node* newN(int a){
	node *temp= (node *)malloc(sizeof(node));
	temp->n=a;
	temp->next=N;
	temp->prev=N;
	
	return temp;
}
void setTail(int a){
	node *newNode=newN(a);
	if(head==N){
		head=newNode;
		tail=newNode;
		return;
	}
	
	tail->next=newNode;
	newNode->prev=tail;
	tail=newNode;
	
}
void setHead(int a){
	node *newNode = newN(a);
	
	if(head==N){
		head=newNode;
		tail=newNode;
		return;
	}
	head->prev=newNode;
	newNode->next=head;
	head=newNode;
}

void setMiddle(int a,int pos){
	int i=1;
	
	node *newNode = newN(a);
	if(head==N){
		head=newNode;
		tail=newNode;
		return ;
	}
	node *temp;
	temp=head;
	while(i<pos-1 && temp->next!=N){
		temp=temp->next;
		i++;
	}
	
	newNode->next=temp->next;
	newNode->prev=temp;
	
	if(temp->next)
		temp->next->prev=newNode;
	temp->next=newNode;
}


void PrintF(){
	node *list=head;
	if(head==N){
		cout<<"list empty\n";
		return;
	}
	while(1){
		cout<<list->n<<" ";
		if(list->next==N){
			cout<<"\n";
			break;
		}
		else
			list=list->next;
	}
}
void  PrintB(){
	node *list=tail;
	if(head==N){
		cout<<"list empty\n";
		return;
	}
	while(1){
		cout<<list->n<<" ";
		if(list->prev==N){
		cout<<"\n";
		break;
	}
	else
		list=list->prev;
	}

}
int main(){
	setHead(1);
	setTail(2);
	setMiddle(3,2);
	PrintF();
	PrintB();
	
	free(head);
	free(tail);
	return 0;
}

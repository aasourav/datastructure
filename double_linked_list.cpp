#include <iostream>
#include <cstdlib>
#define N 0
using namespace std;
struct linkedlist{
	int v;
	struct linkedlist *next;
	struct linkedlist *prev;
};
typedef struct linkedlist node;
node *head= N, *tail=N;
node* newV(int a){
	node* temp= (node *)malloc(sizeof(node));
	temp->v=a;
	temp->next=N;
	temp->prev=N;
	
	return temp;
}
void intail(int a){
	node* newvalue= newV(a);
	if(head==N){
		head=newvalue;
		tail=newvalue;
		return;
	}
	tail->next=newvalue;
	newvalue->prev=tail;
	tail->next=newvalue;
}
void inhead(int a){
	node* newvalue=newV(a);
	if(head==N){
		head=newvalue;
		tail=newvalue;
		return;
	}
	newvalue->next=head;
	head->prev=newvalue;
	head=newvalue;
}
void inmid(int a,int pos){
	node *newvalue = newV(a);
	if(head==N){
		head=newvalue;
		tail=newvalue;
		return;
	}
	
	int i=1;
	node *temp= head;
	while(i<pos-1 && temp->next!=N){
		temp=temp->next;
		i++;
	}
	newvalue->next=temp->next;
	newvalue->prev=temp;
	
	if(temp->next)
		temp->next->prev=newvalue;
	
	temp->next=newvalue;
}
void printF(){
	node *temp=head;
	while(1){
		if(head==N || tail==N){
			break;
		}
		cout<<temp->v<<" ";
		
		if(temp->next==N){
			cout<<"\n";
			break;
		}
		else
			temp=temp->next;
	}
}
void printB(){
	node *temp=tail;
	while(1){
		if(head==N || tail==N){
			break;
		}
		cout<<temp->v<<" ";
		
		if(temp->prev==N){
			cout<<"\n";
			break;
		}
		else
			temp=temp->prev;
	}
}
int main(){
	intail(11);
	inhead(12);
	inmid(105,2);
	inmid(106,3);
	printF();
	printB();
	
	free(head);
	free(tail);
	return 0;
}

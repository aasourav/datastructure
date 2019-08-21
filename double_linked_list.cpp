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

void delete_by_position(int pos){
	node *temp=head;
	if(pos==1){
		head=head->next;
		head->prev=N;
		return;
	}
	int i=1;
	int ck=0;
	while(1){
		if(i==pos){
			if(temp->next==N){
				temp->prev->next=N;
				break;
			}
			temp->prev->next=temp->next;
			temp->next->prev=temp->prev;
			ck=1;
			break;
		}
		else if(temp->next==N)
		break;
		else
			temp=temp->next;
		++i;
	}
}
void delete_by_value(int a){
	node *temp=head;
	int ck=0;
	if(head->v==a){
		head=head->next;
		head->prev=N;
		return;
	}
	while(1){
		if(a==temp->v){
			if(temp->next==N){
				temp->prev->next=N;
				break;
			}
			temp->prev->next=temp->next;
			temp->next->prev=temp->prev;
			ck=1;
			break;
		}
		else if(temp->next==N)
		break;
		else
			temp=temp->next;
	}
}
int main(){
	intail(11);
	inhead(12);
	inmid(105,2);
	inmid(106,3);
	printF();
	delete_by_position(3);
	delete_by_value(12);
	printF();
	printB();
	free(head);
	free(tail);
	return 0;
}

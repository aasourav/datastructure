/* insert many element, insert element at first, insert elemet
at last , insert element at middle, search an element , delete an element using
linked list */

#include <iostream>
#include <cstdlib>
#define N 0
using namespace std;
struct linked_list{
	int n;
	struct linked_list *next;
};
typedef struct linked_list node;
node *head=N, *last=N;

//finding size
int sz(node *list){
	if(list->next==N)
		return 1;
	return (1+sz(list->next));
}

//printing list
void print(node *list){
	cout<<list->n<<" ";
	if(list->next==N){
		cout<<"Size: "<<sz(head)<<"\n";
		return;
	}
	else
		print(list->next);
}
//insert element at last
void Last(int a){
	node *value;
	value=(node *)malloc(sizeof(node));
	value->n=a;
	value->next=N;
	
	if(head==N){
		head=value;
		last=value;
	}
	else{
		last->next=value;
		last=(node *)malloc(sizeof(node));
		last=value;
	}
}

//inserting element
void create(){
	cout<<"input a value(-99 for exit): ";
	int a;
	cin>>a;
	if(a==-99)
		return;
	else{
		Last(a);
		create();
	}
}

//insert an element at first
void First(int a){
	node *first;
	first=(node *)malloc(sizeof(node));
	first->n=a;
	first->next=head;
	head=first;
	print(head);
}

//insert an element at mid
void Mid(int point, int value){
	node *mid;
	mid=head;
	int ck=0;
	
	while(1){
		if(mid->n==point){
			node *temp = (node *)malloc(sizeof(node));
			temp->n=value;
			temp->next=mid->next;
			mid->next=temp;
			
			ck=1;
			break;
		}
		else if(mid->next==N)
			break;
		else
			mid=mid->next;
	}
	
	if(ck==1){
		print(head);
	}
	else
		cout<<"Key not found\n";
}

//search a value
void Search(int value){
	node *list = head;
	int ck=0;
	while(1){
		if(list->n==value){
			ck=1;
			cout<<" Found\n";
			break;
		}
		else if(list->next==N)
			break;
		else
			list=list->next;
	}
	if(ck==0)
		cout<<" Not Found\n";
}

//deleting a value;
void Delete(int value){
	node *temp=head,*previous=N;
	int ck=0;
	while(1){
		if(temp->n==value){
			if(previous==N){
				head=temp->next;
			}
			else{
				previous->next=temp->next;
			}
			ck=1;
			cout<<"Deleted\n";
			print(head);
			
			break;
		}
		else if(temp->next==N)
			break;
		else{
			previous=temp;
			temp=temp->next;
		}
			
	}
	if(ck==0)
		cout<<"Value Not Found\n";
}
int main(){
	int search=135;
	create();
	cout<<"\n\n";
	cout<<"After create List: \n";
	print(head);
	cout<<"After Added a value at first: \n";
	First(120);
	cout<<"After Added a value at Middle: \n";
	Mid(120,121);
	Last(135);
	cout<<"After Added a valued at Last:\n";
	print(head);
	cout<<"Searching: "<<search<<" ";
	Search(search);
	cout<<"After Delete a value:\n";
	Delete(121);
	
	
	free(head);
	return 0;
}

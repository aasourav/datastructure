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
void create(node *list){
	int a;
	cout<<"enter a value -99999 for exit";
	cin>>a;
	
	if(a==-99999){
		list->next=N;
	}
		
	else{
		list->n=a;
		list->next= (node *)malloc(sizeof(node));
		create(list->next);
	}
}
void print(node *list){
	if(list->next==N){
		cout<<"node adress: "<<list->next<<"\n";
		return ;	
	}
	
	else{
		cout<<list->n<<" ";
		print(list->next);
	}
}
int sizelist(node *list){
	if(list->next==N)
		return 0;
	else
		return(1+sizelist(list->next));
}
int main(){
	head=(node *)malloc(sizeof(node));
	create(head);
	print(head);
	cout<<"\n"<<sizelist(head);
	
}

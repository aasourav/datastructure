#include <iostream>
#include <cstdlib>
#define N 0
using namespace std;
struct linked{
	int v;
	struct linked *next;
};
typedef struct linked node;
node *head=N,*last;
int size(node *lis){
	if(lis->next==N)
		return 0;
	return (1+size(lis->next));
}
void print(node *lis){
	
	if(lis->next==N){
		cout<<"size: "<<size(head)<<"\n";
		return;
	}
	cout<<lis->v<<" ";
	print(lis->next);
}
void create(node *lis){
	int a;
	cin>>a;
	if(a==-99){
		lis->next=N;
	}
	else{
		lis->v=a;
		lis->next=(node *)malloc(sizeof(node));
		create(lis->next);
	}
}
int main(){
	head=(node *)malloc(sizeof(node));
	create(head);
	print(head);
	free(head);
	return 0;
}

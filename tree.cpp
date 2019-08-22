#include <iostream>
#include <cstdlib>
#define N 0
using namespace std;
struct tree{
	int v;
	struct tree *left;
	struct tree *right;
};
typedef struct tree node;
node *root=N;
node *create(int a){
	node *temp= (node *)malloc(sizeof(node));
	temp->v=a;
	temp->left=N;
	temp->right=N;
	
	return temp;
}
void addnode(int a){
	node *newvalue=create(a);
	if(root==N){
		root=newvalue;
		return;
	}
	node *temp=root;
	while(1){
		if(a<temp->v){
			if(temp->left==N){
				temp->left=newvalue;
				break;
			}
			else
				temp=temp->left;
		}
		else{
			if(temp->right==N){
				temp->right=newvalue;
				break;
			}
			else
				temp=temp->right;
		}
	}
}

void preorder(node *temp){
	//root-left-right;
	if(temp==N)
		return;
	cout<<temp->v<<" ";
	preorder(temp->left);
	preorder(temp->right);
}
void inorder(node *temp){
	//left-root-right;
	if(temp==N){
		return;
	}
	inorder(temp->left);
	cout<<temp->v<<" ";
	inorder(temp->right);
}
void postorder(node *temp){
	//left-right-root;
	if(temp==N)
		return;
	postorder(temp->left);
	postorder(temp->right);
	cout<<temp->v<<" ";
}
int max(node *temp){
	
	int a;
	while(1){
		if(temp==N)
			break;
		a=temp->v;
		temp=temp->right;
	}
	
	return a;
	
}
int min(node *temp){
	
	int a;
	while(1){
		if(temp==N)
			break;
		a=temp->v;
		temp=temp->left;
	}
	
	return a;
	
}
int main(){
	addnode(45);
	addnode(54);	
	addnode(40);
	addnode(49);
	addnode(38);
	addnode(70);
	addnode(30);
	addnode(39);
	addnode(41);
	addnode(45);
	addnode(44);
	preorder(root);
	cout<<endl;
	inorder(root);
	cout<<endl;
	postorder(root);
	cout<<endl;
	cout<<"Mximum value: "<<max(root);
	cout<<endl;
	cout<<"Minimum value: "<<min(root);
	free(root);
	return 0;
}

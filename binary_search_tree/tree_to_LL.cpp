#include<iostream>
using namespace std;
void khushi(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

}

class Node{
public:
	int data;
	Node* left;
	Node* right;

	Node(int data){
		this->data=data;
		left=right=NULL;
	}
};

Node* insert(Node *root, int data){
	if(root==NULL){
		return new Node(data);
	}
	//
	if(data<root->data){
		root->left=insert(root->left,data);
	}
	else{
		root->right=insert(root->right,data);
	}
    
     return root;

}

//BST to linkedlist
class LinkedList{
public:
	Node* head;
	Node* tail;
} ;

LinkedList tree_to_LL(Node* root){
	LinkedList l;
	if(root==NULL){
		l.head=l.tail;
		return l;
	}
	//case 1 when both subtrees are null
	if(root->left==NULL && root->right==NULL){
		l.head=l.tail=root;
		return l;
	}
	// case 2 when right subt is null and left subt is not null
	else if(root->left!=NULL && root->right==NULL){
		LinkedList leftLL=tree_to_LL(root->left);
		leftLL.tail->right=root;
		l.head=leftLL.head;
		l.tail=root;

	}
	// case 3 when left subt is null and right subt is not null
	else if(root->left==NULL && root->right!=NULL){
		LinkedList rightLL=tree_to_LL(root->right);
		root->right=rightLL.head;
		l.head=root;
		l.tail=rightLL.tail;

	}
	// case 4 when both  subtrees right and left are not null
	else{
		LinkedList rightLL=tree_to_LL(root->right);
		LinkedList leftLL=tree_to_LL(root->left);

		leftLL.tail->right=root;
		root->right=rightLL.head;

		l.head=leftLL.head;
		l.tail=rightLL.tail;
	}
	return l;
}

void printInOrder(Node *root){
	if(root==NULL){
		return;
	}
	printInOrder(root->left);
	cout<<root->data<<" ";
	printInOrder(root->right);
}

int main(){
	khushi();
	Node *root=NULL;
	int arr[]={8,3,10,1,6,14,4,7,13};
	for(int x:arr){
		root=insert(root,x);
	}
	// printInOrder(root);
	// flattenTree(root)<<endl;
	LinkedList l= tree_to_LL(root);
	Node * temp=l.head;
	while(temp!=NULL){
		cout<<temp->data<<"--> ";
		temp=temp->right;
		//temp=temp->next;
	}

	return 0;
}
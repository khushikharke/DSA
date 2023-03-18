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

// next inorder successor 
Node *inorder_succ(Node *root,Node *target){
	if(target->right!=NULL){
		// if right subtree exists and traverse in left extreme and that is temp;
		Node *temp=target->right;
		while(temp->left!=NULL){
			temp=temp->left;
		}
		return temp;
	}


	// if right subT does not exist
	Node *temp=root;
	Node *succ=NULL;
	while(temp!=NULL){
		if(temp->data>target->data){
			succ=temp;
			temp=temp->left;
		}

		else if(temp->data < target->data){
			temp=temp->right;
		}
		//target->data== temp->data
		else{
			break;
		}

	}
	return succ;

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
	root=insert(root,8);
	root=insert(root,3);
	root=insert(root,10);
	root=insert(root,1);
	root=insert(root,6);
	root=insert(root,14);
	root=insert(root,4);
	root=insert(root,7);
	root=insert(root,13);
	

	Node *t1=root->left->right->right;
	Node *t2=root->right;
	cout<<"Inorder successor of 7 is "<< inorder_succ(root,t1) ->data<<endl;
	cout<<"Inorder successor of 10 is"<< inorder_succ(root,t2)->data<<endl;
	
	return 0;
}

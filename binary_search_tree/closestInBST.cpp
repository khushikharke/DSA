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

int findClosest(Node* root,int target){
    int closest;
	int diff= INT_MAX;
	Node* temp=root;

	while(temp!=NULL){
		int curr_diff=abs(temp->data -target);
        if(curr_diff==0){
        	return temp->data;
        }
        if(curr_diff<diff){
        	diff=curr_diff;
        	closest=temp->data;
        }

        // right or left

        if(temp->data<target){
        	temp=temp->right;
        }
        else{
        	temp=temp->left;
        }
	}
	return closest;
	
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
	cout<< findClosest(root,17)<<endl;
	return 0;
}
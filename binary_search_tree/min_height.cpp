#include<iostream>
#include<vector>
#include<algorithm>
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
//code for min height bst
Node *sortedArr(vector<int> &arr, int s,int e){
	if(s>e){
		return NULL;
	}
	int mid=(s+e)/2;
	Node *root=new Node(arr[mid]);

	root->left=sortedArr(arr,s,mid-1);
	root->right=sortedArr(arr,mid+1,e);

	return root;
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
	vector<int>arr{8,3,10,1,6,14,4,7,13};
	int n=arr.size();
	for(int x: arr){
		root=insert(root,x); 
	}
	printInOrder( root);
	sortedArr(arr,0,n-1);


	return 0;
}


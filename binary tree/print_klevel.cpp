#include<iostream>
#include<queue>

using namespace std;
void khushi(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}
class node{
public:
	int data;
	node*left;
	node*right;

	node(int d){
		data=d;
		left=NULL;
		right=NULL;

	}
};
//input 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
//preorder
node *buildTree(){
	int d;
	cin>>d;
	if(d==-1){
		return NULL;
	}
	node*n=new node(d);
	n->left = buildTree();
	n->right = buildTree();
	return n;

}

void levelPrint(node *root){
	queue<node *>q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		node *temp=q.front();
		if(temp==NULL){
			cout<<endl;
			q.pop();
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			q.pop();
			cout<<temp->data<<" ";
			if(temp->left){
				q.push(temp->left);

			}
			if(temp->right){
				q.push(temp->right); 
			}
		}
	}
	return ;
}


void printAtk(node *root,int k){
	if(root==NULL){
		return;
	}
	if(k==0){
		cout<<root->data<<" ";
	}
	printAtk(root->left,k-1);
	printAtk(root->right,k-1);
	return;
}


int printNodeAtDistanceK(node *root, node *target,int k){
//base case


	if(root==NULL){
		return -1;
	}
	//reached target or not 
	if(root==target){
		printAtk(target,k);
		return 0;
	}

	//other case target in either left or right
	int DistL=printNodeAtDistanceK(root->left,target,k);
	if(DistL!=-1){

		//2 cases 
		//print current node
		if(DistL+1==k){
			cout<<root->data<<" ";
		}

		//print some nodes in right subtree
        else{
        	printAtk(root->right,k-2-DistL);
        }		
        return 1+DistL;

	}

	int DistR=printNodeAtDistanceK(root->right,target,k);
	if(DistR!=-1){
		//2 cases
		if(DistR+1==k){
			cout<<root->data<<" ";
		}
		else{
			printAtk(root->left,k-2-DistR);
		}
		return 1+DistR;
	}
	return -1;
}












int main(){
	khushi();
	node *root=new node(1);
	root->left=new node(2);
	root->right=new node(3);
	root->left->left=new node(4);
	root->left->right=new node(5);
	root->right->right=new node(6);
	root->left->right->left=new node(7);
	root->left->right->right=new node(8);
	root->left->right->right->left=new node(9);
	root->left->right->right->right=new node(10);
	// target node is 5 and root node is 1;
	node *target=root->left->right;
	int k=2;
	printNodeAtDistanceK(root,target,k);
	cout<<endl;
	
	return 0;
}
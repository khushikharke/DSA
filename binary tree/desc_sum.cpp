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
int replace(node *root){
	//base
	if(root ==NULL){
		return 0;
	}
	if(root->left==NULL and root->right ==NULL){
		return root->data;
	}
	int SL=replace(root->left);
	int SR=replace(root->right);

	//recursive case
	int temp=root->data;
	root->data=SL+SR;

	return temp+root->data;



}

int main(){
	khushi();
	node *root=buildTree();
	// node *root= levelPrint();
	levelPrint(root);
	cout<<endl;
	replace(root);
	levelPrint(root);
	return 0;
}
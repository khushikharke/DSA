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

class Pair{
public:
	int includ;
	int exclude;
};

Pair maxSubsetSum(node *root){
	Pair p;
	if(root==NULL){
		p.includ=p.exclude=0;
		return p;
	}

	//rec case
	Pair Left=maxSubsetSum(root->left);
	Pair Right=maxSubsetSum(root->right);
	p.includ = root->data + Left.exclude + Right.exclude;
	p.exclude = max(Left.includ, Left.exclude) + max(Right.includ,Right.exclude);

	return p;
}





int main(){
	khushi();
	node *root=buildTree();
	// node *root= levelPrint();
	levelPrint(root);
	cout<<endl;
	Pair p = maxSubsetSum(root);
	cout << "Max Sum : "<< max(p.includ,p.exclude)<<endl; 
	return 0;
}






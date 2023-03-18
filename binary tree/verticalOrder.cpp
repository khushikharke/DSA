#include<iostream>
#include<queue>
#include<map>
#include<bitset>

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

void traverse(node *root,int d,map<int,vector<int> > &m){
	if(root==NULL){
		return ;
	}
	m[d].push_back(root->data);
	traverse(root->left,d-1,m);
	traverse(root->right,d+1,m);

}

void verticalPrint(node *root){
	map<int ,vector<int> > m;
	int d=0;
	//for root
	traverse(root,d,m);
	//-1 ->(....)
	//0-> (.....)
	//keys are sorted in map so iterating now 
	for(auto p:m){
		int dist=p.first;
		vector<int >nodes=p.second;

		for(auto node:nodes){
			cout<<node<<" ";
		}
		cout<<endl;

	}
	return;
}



int main(){
	khushi();
	node* root=new node(1);
	root->left=new node(2);
	root->right=new node(3);
	root->left->left=new node(4);
	root->left->right=new node(5);
	root->right->left=new node(6);
	root->right->right=new node(7);
	root->right->left->right=new node(8);
	root->right->right->right=new node(9);

	verticalPrint(root);

	return 0;

}






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


//sec= h2-h1<=1,left ==T ,right ==T
pair<int,bool> isHeightbal(node *root){
     pair<int,bool> p,Left,Right;
     if(root==NULL){
     	p.first=0;
     	p.second=true;
     	return p;
     }
     Left=isHeightbal(root->left);
     Right=isHeightbal(root->right);

     int H=max(Left.first,Right.first)+1;
     if((abs(Left.first - Right.first)<=1) and Left.second and Right.second){
     	return make_pair(H,true);
     }
     return make_pair(H,false);


}
int height(node *root){
	if(root==NULL){
		return 0;
	}
	int h1=height(root->left);
	int h2=height(root->right);
	return 1+max(h1,h2);
}
//left is bal,right is bal, diff b/w h of left and right should not be more than 1;





int main(){
	khushi();
	node *root=new node(1);
	root->left=new node(2);
	root->right=new node(3);
	root->left->left=new node(4);
	root->left->right=new node(5);
	root->right->right=new node (6);
	root->left->right->left=new node(7);
	root->left->right->right=new node(8);
	// root->left->right->right->left=new node(9);
	// root->left->right->right->right = new node(10);

	pair<int,bool> p = isHeightbal(root);
	// node *root= levelPrint();
	if(p.second){
		cout<<"Yes, its a balanced height tree";

	}
	else{
		cout<<"Not a height bal tree";
	}

	return 0;
}










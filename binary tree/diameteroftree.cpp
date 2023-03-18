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

int height(node *root){
	if(root==NULL){
		return 0;
	}
	int h1=height(root->left);
	int h2=height(root->right);
	return 1+ max(h1,h2);
}

// diameter optimised 
class HDpair{
public:
	int height;
	int diameter;

};

HDpair optdiameter(node *root){
	HDpair p; 
	if(root==NULL){
		p.height=p.diameter=0;
		return p;
	}
	//otherwise
	HDpair Left = optdiameter(root->left);
	HDpair Right = optdiameter(root->right);

	p.height = max(Left.height,Right.height) +  1;
	int D1 =Left.height+Right.height;
	int D2 = Left.diameter;
	int D3 = Right.diameter;

	p.diameter=max(D1,max(D2,D3));
	return p;
}

int diameter(node *root){
	//base case
	if(root==NULL){
		return 0;
	}
	//rec
	int D1=height(root->left) + height(root->right);
	int D2=diameter(root->left);   
	int D3=diameter(root->right);

	return max(D1,max(D2,D3));
}

int main(){
	khushi();

	node *root=buildTree();
	levelPrint(root);
	cout<<"Diameter is "<<diameter(root)<<endl;
	cout<<"OPT diameter is "<<optdiameter(root).diameter<<endl;  

	return 0;
}
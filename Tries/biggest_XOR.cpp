#include<iostream>
#include<unordered_map>
#include<cstring>
#include<vector>
using namespace std;

void khushi(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w", stdout);
}
class node {
public:
	node *left;//0
	node *right;//1
};

class trie{
	node *root;
public:
	trie(){
		root=new node();
	}
	void insert(int n ){
		node *temp=root;
		// n is no. of bits of the number in the trie
		for(int i=31;i>=0;i--){
			int bit =(n>>i) & 1; 
			if(bit==0){
				if(temp->left ==NULL){
					temp->left = new node();
				}
				temp=temp->left;
			}

			else{
				if(temp->right == NULL){
					temp->right=new node();
				}
				temp=temp->right;
			}
		}

	}
	int max_xor_helper(int value ){
		// 25 , what no. it needs to be xor 
		int current_ans=0;
		node *temp=root;
		for(int j =31;j>=0;j--){
			int bit = (value>>j)&1;

			if(bit ==0 ){
				// find the no. with bit 1 
				if(temp->right!=NULL){
					temp=temp->right;
					current_ans+= (1<<j);
					// (1<<j)==2^j

				}
				else{
						temp=temp->left;
						//current_ans+=()
				}
			}
			else{
				// if bit is one look for 0 bit 

				if(temp->left != NULL){
					temp=temp->left;
					current_ans+=(1<<j);
				}
				else{
					temp=temp->right;
				}

			} 

 			
		}

		return current_ans;
	}
	int max_xor(int *input , int n ){
		pa
	}
};

int main(){
	khushi();
	int input[]={3,10,5,25,9,2};
	int n =sizeof(input)/sizeof(int);

	trie t ;
	cout<<t.max_xor(input, n)<<endl;

	return 0;
}







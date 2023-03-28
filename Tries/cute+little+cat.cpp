#include<iostream>
#include<unordered_map>
#include<cstring>
#include<vector>
using namespace std;

void khushi(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w", stdout);
}
//Build a Prefix Tree - Trie
class Node{
public:
	char data;
	unordered_map<char,Node*> children;
	bool isTerminal;

	Node(char d){
		data = d;
		isTerminal = false;
	}
};

class Trie{
public:
	Node* root;

	Trie(){
		root = new Node('\0');
	}

	//later
	void  insert(string word){

		Node* temp = root;

		for(char ch : word){

			if(temp->children.count(ch)==0){
				Node *n = new Node(ch);
				temp->children[ch] = n;
			}
			temp = temp->children[ch];
		}

		temp->isTerminal = true;

	}
};

void search_helper(Trie t, string document, int i, unordered_map<string , bool> &m){
	Node *temp=t.root;
	for(int j =i;j<document.length();j++){
		char ch =document[j];
		if(temp->children.count(ch)==0){
			return ;

		}
		temp=temp->children[ch];
		if(temp->isTerminal){
			// storing history of every branch of trie 
			string out =document.substr(i,j-i+1);
			m[out]=true;
		}
	}
	return ;
}

void docSearch(string document, vector<string> words){
	// first trie insert doc 
	Trie t;
	for(auto w : words){
		t.insert(w);
	}
	// search uses helper function

	unordered_map<string , bool> m;

	for(int i=0;i<document.length();i++){
		search_helper(t,document, i , m);

	}
	 // check words marked as true in hashmap 
	for(auto w : words){
		if(m[w]){
			cout<<w<<"True"<<endl;
		}
		else {
			cout<<w<<"False"<<endl;
		}
	}

}
 
int main(){
	khushi();
	string document = "little cute cat loves to code in c++ , java and python";
	 vector<string> words{"cute cat","ttle","cat","quick","big"};
	// vector<string> words;
	// string temp;
	// cin >> temp;
	// words.push_back(temp);

	docSearch(document,words);
	return 0;






}








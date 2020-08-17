#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
const int lt=100005;
ll mod=1000000007;

struct Trie{
	map <char,Trie*> n;
	bool eow;
	Trie(){
		for(char i='a';i<='z';i++) n[i] = NULL;
		eow = false;
	}
};

void insertTrie(Trie* root, string s){
	for(int i=0;i<sz(s);i++){
		if(root->n[s[i]]==NULL)
			root->n[s[i]] = new Trie();
		root = root->n[s[i]];
	}
	root->eow = true;
}

bool searchTrie(Trie* root, string s){
	int i=0;
	while(i<sz(s) && root->n[s[i]]!=NULL){
		root = root->n[s[i]];
		i++;
	}
	if(root->eow==true && i==sz(s))
		return true;
	else
		return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin >> n;
	Trie* root = new Trie();
	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		insertTrie(root,s);
	}

	ll k;
	cin >> k;
	for(int i=0;i<k;i++){
		string s;
		cin >> s;
		cout << searchTrie(root,s) << endl;
	}
	return 0;
}
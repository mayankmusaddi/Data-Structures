#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
const int lt=100005;
ll mod=1000000007;

void printv(vector <ll> a){
	for(int i=0;i<a.size();i++)
		cout << a[i] << " ";
	cout << endl;
}

vector <ll> adj[100005];
vector <ll> adjr[100005];
vector <bool> visited(100005,0);
stack <ll> finish;

ll dfsf(ll node)
{
	visited[node]=1;
	for (int i=0;i<sz(adj[node]);i++)
	{
		int v= adj[node][i];
		adjr[v].pb(node);
		if(!visited[v])
			dfsf(v);
	}
	finish.push(node);
}

ll dfs(ll node)
{
	visited[node]=1;
	for (int i=0;i<sz(adjr[node]);i++)
	{
		int v= adjr[node][i];
		if(!visited[v])
			dfs(v);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m;
	cin >> n >> m;
	for(int i=0;i<m;i++)
	{
		ll u,v;
		cin >> u >> v;
		adj[u].pb(v);
	}
	for(int i=1;i<=n;i++){
		if(!visited[i])
			dfsf(i);
	}

	fill(visited.begin(),visited.end(),0);

	int nc = 0;
	while(!finish.empty()){
		int u = finish.top();
		finish.pop();
		if(!visited[u]){
			dfs(u);
			nc++;
		}
	}

	cout << nc << endl;
	return 0;
}
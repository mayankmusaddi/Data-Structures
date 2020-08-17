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
vector <bool> visited(100005,false);

ll dfs(ll node)
{
	cout << node << " ";
	visited[node]=1;
	for (int i=0;i<sz(adj[node]);i++)
	{
		int v= adj[node][i];
		if(!visited[v])
			dfs(v);
	}
}

ll bfs(ll node){
	queue<ll> q;
	q.push(node);
	visited[node] = 1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		cout << u << " ";

		for(int i=0;i<sz(adj[u]);i++){
			int v = adj[u][i];
			if(!visited[v]){
				q.push(v);
				visited[v] = 1;
			}
		}
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
		adj[v].pb(u);
	}

	dfs(1);
	cout << endl;
	fill(visited.begin(),visited.end(),0);
	bfs(1);
	cout << endl;
	return 0;
}
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

vector <ll> toposort(ll n){
	vector <ll> indeg(n+1,0);
	for(int i=1;i<=n;i++){
		for(int j=0;j<sz(adj[i]);j++){
			int v = adj[i][j];
			indeg[v]++;
		}
	}

	queue <ll> q;
	for(int i=1;i<=n;i++)
		if(indeg[i]==0)
			q.push(i);

	vector <ll> ts;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		ts.pb(u);
		for(int i=0;i<sz(adj[u]);i++){
			int v = adj[u][i];
			indeg[v]--;
			if(indeg[v]==0)
				q.push(v);
		}
	}
	return ts;
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
	vector <ll> ts = toposort(n);
	printv(ts);
	return 0;
}
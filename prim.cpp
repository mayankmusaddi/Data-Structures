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

vector <pair<ll,ll> > adj[100005];
vector <bool> visited(100005,0);
vector <ll> prim(ll n){
	vector <ll> d(n+1, LLONG_MAX);
	d[1] = 0;
	priority_queue <pair<ll,ll> , vector <pair<ll,ll> >, greater <pair<ll,ll> > > q;
	q.push(mp(0,1));

	while(!q.empty()){
		pair<ll,ll> p = q.top();
		q.pop();
		ll u = p.second;
		if(visited[u])
			continue;
		visited[u] = 1;

		for(int i=0;i<sz(adj[u]);i++){
			pair<ll,ll> vw = adj[u][i];
			ll v = vw.first;
			ll w = vw.second;
			if(visited[v])
				continue;
			if(w < d[v]){
				d[v] = w;
				q.push(mp(w,v));
			}
		}
	}
	return d;
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
		ll u,v,w;
		cin >> u >> v >> w;
		adj[u].pb(mp(v,w));
		adj[v].pb(mp(u,w));
	}

	vector <ll> sp = prim(n);
	printv(sp);

	return 0;
}
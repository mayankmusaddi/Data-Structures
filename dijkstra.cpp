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
vector <ll> dijkstra(ll n,ll s){
	vector <ll> d(n+1, LLONG_MAX);
	d[s] = 0;
	priority_queue <pair<ll,ll> , vector <pair<ll,ll> >, greater <pair<ll,ll> > > q;
	q.push(mp(0,s));
	while(!q.empty()){
		pair<ll,ll> p = q.top();
		q.pop();
		ll u = p.second;

		for(int i=0;i<sz(adj[u]);i++){
			pair<ll,ll> vw = adj[u][i];
			ll v = vw.first;
			ll w = vw.second;
			if(d[u]+w < d[v]){
				d[v] = d[u]+w;
				q.push(mp(d[v],v));
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
	}
	ll s;
	cin >> s;

	vector <ll> sp = dijkstra(n,s);
	printv(sp);

	return 0;
}
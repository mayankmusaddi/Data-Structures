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

vector <pair<ll,pair<ll,ll> > > edge;

vector <ll> bf(ll n,ll m,ll s){
	vector <ll> d(n+1,LLONG_MAX);
	d[s] = 0;
	for(int i=1;i<n;i++){
		for(int j=0;j<m;j++){
			ll w = edge[j].first;
			ll u = edge[j].second.first;
			ll v = edge[j].second.second;
			if(d[u]!=LLONG_MAX && d[u]+w < d[v])
				d[v] = d[u]+w;
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
		edge.pb(mp(w,mp(u,v)));
	}
	ll s;
	cin >> s;
	
	vector <ll> sp = bf(n,m,s);
	printv(sp);
	return 0;
}
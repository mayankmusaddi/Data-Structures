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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m;
	cin >> n >> m;
	vector <vector <ll> > w(n+1,vector <ll> (n+1,LLONG_MAX));
	for(int i=0;i<m;i++)
	{
		ll u,v,wt;
		cin >> u >> v >> wt;
		w[u][v] = wt;
	}
	vector <vector <ll> > d(w);
	for(int i=1;i<=n;i++)
		d[i][i] = 0;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(d[i][j]==LLONG_MAX)
				cout << "N ";
			else
			cout << d[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(d[i][k]!=LLONG_MAX && d[k][j]!=LLONG_MAX && d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k]+d[k][j];
			}
		}
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(d[i][j]==LLONG_MAX)
				cout << "N ";
			else
			cout << d[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
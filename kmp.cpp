#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
const int lt=100005;
ll mod=1000000007;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string a;
	cin >> a;

	vector <ll> lps;

	lps.pb(0);
	int i=1;
	int len=0;
	while(i<sz(a)){
		if(a[i]==a[len]){
			len++;
			lps.pb(len);
			i++;
		}
		else{
			if(len!=0)
				len = lps[len-1];
			else{
				lps.pb(0);
				i++;
			}
		}
	}

	for(int i=0;i<sz(lps);i++)
		cout << lps[i] << " " ;
	cout << endl;
	return 0;
}
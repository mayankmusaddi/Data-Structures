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

vector <ll> bubblesort(vector <ll> &a){
	for(int i=1;i<a.size();i++)
		for(int j=0;j<a.size()-i;j++)
			if(a[j]>a[j+1])
				swap(a[j],a[j+1]);
	return a;
}

vector <ll> insertionsort(vector <ll> &a){
	for(int i=2;i<a.size();i++){
		ll key = a[i];
		int j = i-1;
		while(j>=0 && a[j]>key){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
	}
	return a;
}

vector <ll> selectionsort(vector <ll> &a){
	for(int i=a.size()-1;i>0;i--){
		int sm = i;
		for(int j=0;j<i;j++){
			if(a[j]>a[sm])
				sm = j;
		}
		swap(a[i],a[sm]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin >> n;
	vector <ll> a;
	for(int i=0;i<n;i++){
		ll k;
		cin >> k;
		a.pb(k);
	}
	printv(a);

	// insertionsort(a);
	// bubblesort(a);
	selectionsort(a);

	printv(a);
	return 0;
}
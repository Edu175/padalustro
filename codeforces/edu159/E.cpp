#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e6+5;

int tr[MAXN][26],qidx=0;

ll c[MAXN];

ll add(ll x, char c){
	int &res=tr[x][c-'a'];
	if(res!=-1)return res;
	return res=++qidx;
}


int main(){FIN;
	mset(tr,-1);
	ll n; cin>>n;
	vector<string> a(n);
	ll res=0;
	fore(i,0,n){
		cin>>a[i];
		res+=SZ(a[i])*n;
		ll x=0;
		fore(j,0,SZ(a[i]))x=add(x,a[i][j]),c[x]++;
	}
	//cout<<res<<"\n";
	ll men=0;
	fore(i,0,n){
		ll x=0;
		string s=a[i];
		reverse(ALL(s));
		//cout<<i<<" "<<s<<": ";
		for(auto j:s){
			x=tr[x][j-'a'];
			if(x==-1)break;
			//cout<<j<<","<<x<<" ";
			men+=c[x];
		}
		//cout<<"\n";
	}
	res-=men;
	cout<<res*2<<"\n";
	return 0;
}

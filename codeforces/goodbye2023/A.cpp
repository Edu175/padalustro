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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		ll flag=1;
		vector<ll>a(n);
		ll m=2023;
		fore(i,0,n){
			cin>>a[i];
			if(m%a[i])flag=0;
			m/=a[i];
		}
		if(!flag)cout<<"NO\n";
		else {
			cout<<"YES\n"<<m<<" ";
			fore(i,0,k-1)cout<<"1 ";
			cout<<"\n";
		}
	}
	return 0;
}

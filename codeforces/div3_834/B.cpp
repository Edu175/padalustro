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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll m,s; cin>>m>>s;
		ll a[m];
		ll n=0;
		fore(i,0,m)cin>>a[i],n=max(n,a[i]);
		ll oc[n+1];
		mset(oc,0);
		fore(i,0,m)oc[a[i]]++;
		ll flag=1,sum=0;
		fore(i,0,n+1){
			if(oc[i]==0)sum+=i;
		}
		while(sum<s){
			n++;
			sum+=n;
		}
		if(sum==s)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
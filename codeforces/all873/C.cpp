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
const ll MOD=1e9+7;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[n],b[n];
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		sort(a,a+n); sort(b,b+n);
		ll res=1;
		//imp(a); imp(b);
		fore(i,0,n){
			ll lwb=lower_bound(b,b+n,a[i])-b;
			//cout<<i<<": "<<lwb<<"\n";
			res=res*max(lwb-i,(ll)0)%MOD;
		}
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
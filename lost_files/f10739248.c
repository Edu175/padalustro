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

vector<ll> a={0,1,2,3,4};
ll k=5;
ll f(ll x){
	if(x<k)return a[x];
	ll res=0;
	fore(i,1,k+1){
		res-=f(x-i);
	}
	return res;
}

int main(){FIN;
	while(1){
		ll q; cin>>q;
		cout<<f(q)<<endl<<endl;
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home

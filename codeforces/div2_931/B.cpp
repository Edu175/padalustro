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
const ll MAXV=1e6;
vector<ll>cs={1, 3, 6, 10, 15};
int main(){FIN;
	vector<ll>dp(MAXV,MAXV); dp[0]=0;
	fore(i,1,MAXV)for(auto c:cs){
		if(i-c>=0)dp[i]=min(dp[i],dp[i-c]+1);
	}
	fore(i,0,1100)cout<<dp[i]<<" ";;cout<<"\n";
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll res=0;
		while(n){
			ll c=*(upper_bound(ALL(cs),n)-1);
			ll q=n/c;
			res+=q;
			n-=q*c;
		}
		cout<<res<<"\n";
	}
	return 0;
}
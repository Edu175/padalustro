#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;


int main(){FIN;
	ll t; cin>>t;ll te=t;
	while(t--){
		cout<<"Case #"<<te-t<<": ";
		ll n,k; cin>>n>>k;
		ll sq=0;
		ll sum=0;
		bool flag=1;
		vector<ll> a(n);
		fore(i,0,n){
			cin>>a[i];
			sum+=a[i];
			sq+=(a[i]*a[i]);
			if(a[i]!=0)flag=0;
		}
		if (sum)cout<<(sq/sum-sum)/2<<"\n";
		else if(flag)cout<<1<<"\n";
		else cout<<"IMPOSSIBLE\n";
	}
	return 0;
}

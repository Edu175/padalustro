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
	ll t; cin>>t;
	while(t--){
		string s;cin>>s;
		string r,d;
		vector<char>v(27);
		for(auto i:s)v[i-'a']++;
		fore(i,0,27){
			if(v[i]==2)r+='a'+i;
			if(v[i]==1)d+='a'+i;
		}
		cout<<r<<r<<d<<"\n";
	}
	 return 0;
}

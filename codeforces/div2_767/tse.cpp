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
ll pali(string s){
	fore(i,0,SZ(s)/2){
		if(s[i]!=s[SZ(s)-i-1]){
			return 0;
		}
	}
	return 1;
}
int main(){FIN;
	string s; cin>>s;
	cout<<pali(s);
	return 0;
}
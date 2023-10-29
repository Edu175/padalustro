#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,edu=b;i<edu;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin,x.end
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto lol:v)cout<<lol<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
const ll MAXN=1e4+5;
string pag[MAXN];
map<string,ll> id;
vector<ll>g[MAXN];
ll n;
ll dp[MAXN],vis[MAXN][MAXN],vis1[MAXN][MAXN];
ll tot(ll x, ll s){
	vis1[x][s]=1;
	ll &res=dp[x];
	if(res>=0)return res;
	res=0;
	for(auto i:g[x]){
		if(!vis1[i][s]){
			if(s==15)cout<<i<<"\n";
			res+=1+tot(i,s);
		}
	}
	return res;
}
ll dfs(ll x,ll s){//O(N)
	ll res=0;
	vis[x][s]=1;
	for(auto i:g[x]){
		if(!vis[i][s])res=res+(pag[i]==pag[s])+dfs(i,s);
	}
	return res;
}

void celdas(vector <string> &c, vector <int> &celdasTotal, vector <int> &celdasMismaHoja) {
	n=SZ(c);
	vector<pair<string,ll>>edges;
    fore(i,0,n){
    	string a,pg, s=c[i];
    	ll r=0;
    	bool e=0;
    	fore(j,0,SZ(s)){
    		if(e){
    			if(s[j]=='='){
					r=j+1;
					break;
				}
				pg.pb(s[j]);
    		}
    		if(s[j]=='!')e=1;
    		a+=s[j];
    	}
    	id[a]=i;
    	//cout<<"id["<<a<<"]="<<i<<"\n";
    	pag[i]=pg;
    	s.pb('+');
    	string t;
    	fore(k,r,SZ(s)){
    		if(s[k]=='*'||s[k]=='+'||s[k]=='-'){
    			if(t[0]<'0'||t[0]>'9'){
    				edges.pb({t,i});
    			}
				t.clear();
			}
			else t+=s[k];
    	}
    }
    //cout<<"\n";
    for(auto i:edges){
    	g[id[i.fst]].pb(i.snd);
    	cout<<id[i.fst]<<" "<<i.snd<<"\n";
    }
    /*fore(i,0,n){
		cout<<i<<": ";
		imp(g[i]);
	}*/
	mset(dp,-1);
    fore(i,0,n){//O(N)
    	celdasTotal.pb(tot(i,i));
    	celdasMismaHoja.pb(dfs(i,i));
    }
}

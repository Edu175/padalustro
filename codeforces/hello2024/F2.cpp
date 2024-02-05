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
const ll INF=1e18;

struct STreemin{
	int n; vector<ll>t;
	STree(int n):n(n),t(2*n+5,INF){}
	void upd(int p, ll v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=min(t[p],t[p^1]);
	}
	ll query(int l, int r){
		ll res=INF;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=min(res,t[l++]);
			if(r&1)res=min(res,t[--r]);
		}
		return res;
	}
};
STreemin cs;

struct node{
	ll l,r,s,f,res;
	node(ll p, ll a, ll b):l(p),r(p+1),s(max((ll)0,a-b)),f(max((ll)0,b-a)),c(c),res(min(a,b)){}
	node():s(0),f(0),res(0){}
	//void prnt(){cout<<s<<","<<f<<","<<c<<"("<<res<<") ";}
};
node NEUT;
node oper(node a, node b){
	//a.prnt(); b.prnt();
	ll cap=cs.query();
	a.s=min(a.s,cap);
	b.f=min(b.f,cap);
	node c(a.s,b.f);
	c.s+=b.s;
	c.f+=a.f;
	c.res+=a.res+b.res;
	//cout<<"= "; c.prnt(); cout<<"\n";
	return c;
}

struct STree{
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void upd(int p, node v){
		for(p+=n,t[p]=v;p>1;p>>=1)p^=p&1,t[p>>1]=oper(t[p],t[p^1]);
	}
	node query(int l, int r){
		node izq=NEUT,der=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)izq=oper(izq,t[l++]);
			if(r&1)der=oper(t[--r],der);
		}
		return oper(izq,der);
	}
};

int main(){FIN;
	ll n,q; cin>>n>>q;
	vector<ll>a(n),b(n),c(n);
	fore(i,0,n)cin>>a[i];
	fore(i,0,n)cin>>b[i];
	fore(i,0,n-1)cin>>c[i];
	STree st(n);
	fore(i,0,n)st.upd(i,node(i,a[i],b[i])),cs.upd(i,c[i]);
	while(q--){
		ll p,x,y,z; cin>>p>>x>>y>>z; p--;
		st.upd(p,node(p,x,y));
		cout<<st.query(0,n).res<<"\n";
	}
	return 0;
}


#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const int MAXN=105;
ll INF=5;
int n;
bool g[MAXN][MAXN];
ll val[MAXN];
bool is[MAXN];
int no[MAXN];
//int m,k; // my set, available set
set<pair<ll,int>>my,dis;
ll r=0;
ll rnd[MAXN];
void ch(int i){
	if(is[i]){
		r-=val[i];
		fore(j,0,n)if(g[i][j]){
			no[j]--;
			if(!no[j]&&!is[j])dis.insert({(rnd[j]=rand()),j});
		}
		my.erase({rnd[i],i});
		if(!no[i])dis.insert({(rnd[i]=rand()),i});
	}
	else {
		r+=val[i];
		fore(j,0,n)if(g[i][j]){
			no[j]++;
			if(no[j]==1&&!is[j])dis.erase({rnd[j],j});
		}
		if(!no[i])dis.erase({rnd[i],i});
		my.insert({(rnd[i]=rand()),i});
	}
	is[i]^=1;
}
double t=1e9; //temperature, 1e9 or 1e5
ll SA(){
	srand(175);
	vector<int>per;
	fore(i,0,n)per.pb(i);
	fore(i,0,n)dis.insert({(rnd[i]=rand()),i});
	for(auto i:per)if((rand()&1)&&((!is[i]&&!no[i])||is[i]))ch(i);
//	cout<<m<<" "<<k<<"\n";
//	fore(i,0,n)cout<<is[i]<<" ";;cout<<"\n";
//	fore(i,0,n)cout<<no[i]<<" ";;cout<<"\n";
//	cout<<endl;
	ll best=r;
	while(clock()<=1.99*CLOCKS_PER_SEC){ //time limit 2sec
		ll old=r;
		int i=rand()%(SZ(my)+SZ(dis));
		if(i<SZ(my)){
			i=my.begin()->snd;
//			int cnt=0;
//			fore(j,0,n)if(is[j]){
//				if(cnt==i){i=j;break;}
//				cnt++;
//			}
			assert(is[i]);
		}
		else {
			i=dis.begin()->snd;
//			int cnt=0;
//			fore(j,0,n)if(!is[j]&&!no[j]){
//				if(cnt==i){i=j;break;}
//				cnt++;
//			}
			assert(!is[i]&&!no[i]);
		}
		ch(i);
		best=min(best,r);
		if(! (r<old||exp((old-r)/t)*RAND_MAX>=rand()) )ch(i);
		t*=0.99999;
	}
//	cout<<m<<" "<<k<<"\n";
//	fore(i,0,n)cout<<is[i]<<" ";;cout<<"\n";
//	fore(i,0,n)cout<<no[i]<<" ";;cout<<"\n";
//	cout<<endl;
//	cout<<r<<"\n";
	cerr<<t<<"\n";
	return best;
}
vector<int> kmppre(string& t){ // r[i]: longest border of t[0,i)
	vector<int> r(t.size()+1);r[0]=-1;
	int j=-1;
	fore(i,0,t.size()){
		while(j>=0&&t[i]!=t[j])j=r[j];
		r[i+1]=++j;
	}
	return r;
}
bool is_sub(string &a, string &b){ // <=
	auto c=b+"$"+a;
	auto r=kmppre(c);
	fore(i,SZ(b),SZ(r))if(r[i]==SZ(b))return 1;
	return 0;
}

int main(){FIN;
	cin>>n;
	vector<string> s(n);
	vector<ll>a(n);
	fore(i,0,n)cin>>s[i];
	fore(i,0,n)cin>>a[i];
	map<string,ll>mp;
	fore(i,0,n)mp[s[i]]=max(mp[s[i]],a[i]);
	vector<string>s_;
	vector<ll>a_;
	for(auto i:mp)s_.pb(i.fst),a_.pb(i.snd);
	a=a_;s=s_;
	n=SZ(s);
//	imp(s);
//	imp(a);
	fore(i,0,n)val[i]=-a[i],INF+=a[i];
	fore(i,0,n)fore(j,0,n)if(i!=j&&is_sub(s[i],s[j]))g[i][j]=g[j][i]=1;
//	fore(i,0,n){
//		fore(j,0,n)cout<<g[i][j];
//		cout<<"\n";
//	}
	ll res=SA();
	res=-res;
	cout<<res<<"\n";
	return 0;
}
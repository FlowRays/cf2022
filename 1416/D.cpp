/*
    1.dsu fake node for merge
    2.subtree maximum using segment tree (https://www.geeksforgeeks.org/euler-tour-subtree-sum-using-segment-tree/)
*/

#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fore(i, l, r) for (int i = int(l); i <= int(r); ++i)
#define sz(a) int((a).size())
#define endl "\n"
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define pb push_back
#define vi vector<int>

using namespace std;
using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
const int N = 5e5+10; // 包含dsu的fake node在内
const int M = 3e5+10;
const int Q = 5e5+10;

pii e[M],que[Q],t[N*4]; // 线段树4倍空间
vi adj[N];
int tin[N],tout[N],timer;
int par[N],arr[N];
bool del[M];
int n,m,q;

int getPar(int x){
    if(x == par[x]) return x;
    return par[x] = getPar(par[x]);
}

void uni(int a,int b){
    a = getPar(a);
    b = getPar(b);
    if(a == b) return;
    ++n;
    par[n] = n;
    par[a] = n;
    par[b] = n;
    adj[n].pb(a);
    adj[n].pb(b);
}

void dfs(int v){
    tin[v] = ++timer;
    for(auto to: adj[v]) dfs(to);
    tout[v] = timer;
}

void upd(int v,int tl,int tr,int p,pii x){
    if(tl == tr){
        t[v] = x;
        return;
    }
    int mid = tl+tr >> 1;
    int c1 = v*2, c2 = v*2+1;
    if(p<=mid) upd(c1,tl,mid,p,x);
    else upd(c2,mid+1,tr,p,x);
    t[v] = max(t[c1],t[c2]);
}

pii segMax(int v,int tl,int tr,int l,int r){
    if(l>r || tl>r || tr<l) return make_pair(0,0);
    if(l<=tl && tr<=r) return t[v];
    int mid = tl+tr >> 1;
    int c1 = v*2, c2 = v*2+1;
    return max(segMax(c1,tl,mid,l,r),segMax(c2,mid+1,tr,l,r));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>q;
    fore(i,1,n) cin>>arr[i];
    fore(i,1,m){
        int u,v;
        cin>>u>>v;
        e[i] = {u,v};
    }
    fore(i,1,q){
        int a,b;
        cin>>a>>b;
        que[i] = {a,b};
        if(a == 2) del[b] = true;
    }
    fore(i,1,n) par[i] = i;
    fore(i,1,m){
        if(!del[i]) uni(e[i].first,e[i].second);
    }
    for(int i=q;i>=1;--i){
        int tp = que[i].first;
        if(tp == 2){
            int id = que[i].second;
            uni(e[id].first,e[id].second);
        }
        else que[i].second = getPar(que[i].second);
    }
    fore(i,1,n){
        if(getPar(i) == i) dfs(i);
    }
    fore(i,1,n) upd(1,1,n,tin[i],make_pair(arr[i],tin[i]));
    fore(i,1,q){
        int tp = que[i].first;
        if(tp == 1){
            int v = que[i].second;
            pii res = segMax(1,1,n,tin[v],tout[v]);
            if(res.first == 0) cout<<0<<endl;
            else{
                cout<<res.first<<endl;
                upd(1,1,n,res.second,make_pair(0,0));
            }
        }
    }

    return 0;
}
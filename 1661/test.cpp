#include <bits/stdc++.h>

#define forn(i, n) for (ll i = 0; i < ll(n); i++)
#define fore(i, l, r) for (ll i = ll(l); i <= ll(r); ++i)
#define sz(a) ll((a).size())
#define endl "\n"
#define pii pair<ll,ll>
#define all(x) x.begin(),x.end()
#define pb push_back
#define vi vector<ll>

using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll inf = 0x3f3f3f3f;
const ll mod = 1e9+7;
const ll N = 1e5+10;

ll n,m;
ll b[N];
struct Node{
    ll l,r;
    ll sum, tag;
}tr[N*4];

void pushup(Node &u, Node &l, Node &r){
    u.sum = l.sum + r.sum;
}

void pushup(ll u){
    pushup(tr[u],tr[u<<1],tr[u<<1 | 1]);
}

void pushdown(Node &u, Node &l, Node &r){
    if(u.tag){
        l.tag += u.tag, l.sum += u.tag * (l.r-l.l+1);
        r.tag += u.tag, r.sum += u.tag * (r.r-r.l+1);
        u.tag = 0;             
    }
}

void pushdown(ll u){
    pushdown(tr[u],tr[u<<1],tr[u<<1 | 1]);
}

void build(ll u,ll l,ll r){
    if(l == r) tr[u] = {l,r,b[r],0};
    else{
        tr[u] = {l,r};
        ll mid = l+r >> 1;
        build(u<<1,l,mid), build(u<<1 | 1, mid+1, r);
        pushup(u);
    }
}

Node query(ll u,ll l,ll r){
    if(tr[u].l >= l && tr[u].r <= r) return tr[u];
    ll mid = tr[u].l + tr[u].r >> 1;
    pushdown(u);      
    if(r <= mid) return query(u<<1,l,r);
    else if(l>mid) return query(u<<1 | 1,l,r);
    else{
        auto left = query(u<<1,l,r);
        auto right = query(u<<1 | 1,l,r);
        Node res;
        pushup(res,left,right);
        return res;
    }
}

void modify(ll u,ll l,ll r,ll v){
    if(l <= tr[u].l && tr[u].r <= r){
        tr[u].sum += (tr[u].r-tr[u].l+1)*v;
        tr[u].tag += v;
        return;
    }
    ll mid = tr[u].l + tr[u].r >> 1;
    pushdown(u);
    if(l<=mid) modify(u<<1,l,r,v);
    if(r>mid) modify(u<<1 | 1, l,r, v);
    pushup(u);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    fore(i,1,n) cin>>b[i];
    build(1,1,n);
    while(m--){
        char op;
        cin>>op;
        if(op == 'C'){
            ll l,r,d;
            cin>>l>>r>>d;
            modify(1,l,r,d);
        }
        else{
            ll l,r;
            cin>>l>>r;
            cout<<query(1,l,r).sum<<endl;
        }
    }

    return 0;
}

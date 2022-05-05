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
const ll N = 3e5+10;

ll n,k;
ll a[N],b[N];
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
    if(l == r) tr[u] = {l,r,a[r],0};
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
    cin>>n>>k;
    fore(i,1,n) cin>>b[i],a[i]=0;
    build(1,1,n);
    ll ans = b[1];
    modify(1,1,k,b[1]);
    if(1+k<=n) modify(1,1+k,1+k,-k*b[1]);
    ll s = query(1,1,n).sum;
    if(s<b[n]){
        ll t = (b[n]-s+k-1)/k;
        ans += t;
        modify(1,n-k+1,n,t);
    }
    // cout<<ans<<endl;
    for(ll i=n-1;i>=2;--i){
        s = query(1,1,i).sum;
        if(s>=b[i]) continue;
        ll t = min(i,k);
        ll d = (b[i]-s+t-1)/t;
        ans += d;
        // cout<<i<<" "<<d<<endl;
        modify(1,i-t+1,i,d);
    }
    cout<<ans<<endl;

    return 0;
}
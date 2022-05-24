#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fore(i, l, r) for (int i = int(l); i <= int(r); ++i)
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
const int N = 1e5+10;

void solve(){
    int n;
    cin>>n;
    vi a(n),b(n);
    forn(i,n) cin>>a[i];
    forn(i,n) cin>>b[i];
    auto a_ = a, b_ = b;
    sort(all(a_));
    sort(all(b_));
    vector<pii> pa(n),pb(n);
    forn(i,n){
        int l = lower_bound(all(a_),a[i])-a_.begin();
        int r = lower_bound(all(a_),a[i]+1)-a_.begin()-1;
        pa[i] = {l,r};
    }
    forn(i,n){
        int l = lower_bound(all(b_),b[i])-b_.begin();
        int r = lower_bound(all(b_),b[i]+1)-b_.begin()-1;
        pb[i] = {l,r};
    }
    vector<bool> vis(n,false);
    vi seq(n);
    forn(i,n){
        int l = max(pa[i].first,pb[i].first);
        int r = min(pa[i].second,pb[i].second);
        bool ok = false;
        fore(j,l,r){
            if(!vis[j]){
                vis[j] = true;
                ok = true;
                seq[i] = j;
                break;
            }
        }
        if(!ok){
            cout<<-1<<endl;
            return;
        }
    }
    vector<pii> ans;
    forn(i,n){
        int idx;
        forn(j,n){
            if(seq[j] == i) {
                idx = j;
                break;
            }
        }
        if(idx != i) {
            swap(seq[idx],seq[i]);
            ans.pb({i+1,idx+1});
        }
    }
    cout<<ans.size()<<endl;
    for(auto [x,y]: ans){
        cout<<x<<" "<<y<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}
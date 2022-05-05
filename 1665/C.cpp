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
    vector<int> cnt(n+1,0);
    forn(i,n-1){
        int x;
        cin>>x;
        cnt[x]++;
    }
    cnt[0]++;
    vector<int> v;
    forn(i,n+1)
        if(cnt[i]) v.pb(cnt[i]);
    sort(all(v),greater<int>());
    int ans = v.size();
    vector<int> a;
    forn(i,v.size()){
        // cout<<v[i]<<" ";
        int t = ans-i;
        if(v[i]>t) a.pb(v[i]-t);
    }
    // cout<<endl;
    while(true){
        if(a.size()==0) break;
        sort(all(a),greater<int>());
        // forn(i,a.size()) cout<<" "<<a[i]<<" ";
        // cout<<endl;
        a[0]--;
        forn(i,a.size()) a[i]--;
        bool ok = true;
        forn(i,a.size()){
            if(a[i]>0){
                ok = false;
                break;
            }
        }
        ans++;
        if(ok) break;
    }
    cout<<ans<<endl;
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
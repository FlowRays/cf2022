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
    int n,k;
    cin>>n>>k;
    vi a(n);
    map<int,int> mp;
    forn(i,n) cin>>a[i],mp[a[i]]++;
    int cnt = 0;
    int fill = 0;
    int mex = 0;
    forn(i,n){
        if(!mp.count(i)){
            if(k>0 && n-cnt>fill){
                k--;
                fill++;
                mp[i] = 1;
            }
            else{
                mex = i;
                break;
            }
        }
        else cnt += mp[i];
        if(n-cnt <= fill){
            cout<<0<<endl;
            return;
        }
    }
    vi v;
    for(auto [x,y]: mp){
        if(x>mex){
            v.pb(y);
        }
    }
    sort(all(v));
    int p = 0;
    int ans = v.size();
    while(fill>0 && p<v.size()){
        if(fill>=v[p]){
            fill -= v[p];
            ans--;
        }
        else break;
        p++;
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
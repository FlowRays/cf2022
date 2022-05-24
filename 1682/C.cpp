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
    map<int,int> mp;
    forn(i,n){
        int x;
        cin>>x;
        mp[x]++;
    }
    vi a;
    for(auto [x,y]: mp){
        if(y>=2){
            a.pb(x);
            a.pb(x);
        }
        else{
            a.pb(x);
        }
    }
    int ans = a.size();
    cout<<(ans%2==1 ? ans/2+1 : ans/2)<<endl;
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
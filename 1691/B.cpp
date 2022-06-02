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
    vi s(n);
    forn(i,n) cin>>s[i];
    vi ans;
    forn(i,n){
        int x = s[i];
        int j = i+1;
        while(j<n && s[j]==x) j++;
        int cnt = j-i;
        if(cnt == 1){
            cout<<-1<<endl;
            return;
        }
        forn(k,cnt-1){
            // cout<<i+2+k<<" ";
            ans.pb(i+2+k);
        }
        ans.pb(i+1);
        // cout<<i+1<<" ";
        i = j-1;
    }
    forn(i,n) cout<<ans[i]<<" \n"[i==n-1];
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
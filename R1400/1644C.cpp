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
    int n,x;
    cin>>n>>x;
    vi a(n),s(n+1);
    forn(i,n) cin>>a[i];
    forn(i,n) s[i+1] = s[i]+a[i];
    int maxv = 0,maxlen = 0;
    vi v(n+1,-1e9);
    fore(i,1,n){
        fore(j,i,n){
            v[i] = max(v[i],s[j]-s[j-i]);
            if(s[j]-s[j-i]>=maxv){
                maxv = s[j]-s[j-i];
                maxlen = i;
            }
        }
    }
    int pre = maxv;
    cout<<maxv<<" ";
    fore(k,1,n){
        if(k<=maxlen){
            cout<<maxv+k*x<<" ";
            pre = maxv+k*x;
        }
        else{
            int ans = 0;
            fore(j,k,n){
                ans = max(ans,v[j]+k*x);
            }
            ans = max(ans,pre);
            cout<<ans<<" ";
            pre = ans;
        }
    }
    cout<<endl;
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
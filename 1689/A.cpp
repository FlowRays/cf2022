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
    int n,m,k;
    cin>>n>>m>>k;
    string a,b;
    cin>>a>>b;
    string c;
    sort(all(a));
    sort(all(b));
    vi v,s;
    s.pb(0);
    int t = 0;
    for(int i=0,j=0;i<n && j<m;t++){
        if(t>=k && s[t]-s[t-k]==k){
            c.pb(a[i++]);
            v.pb(0);
            s.pb(s.back()+v.back());
            continue;
        }
        else if(t>=k && s[t]-s[t-k]==0){
            c.pb(b[j++]);
            v.pb(1);
            s.pb(s.back()+v.back());
            continue;
        }
        if(a[i]<=b[j]){
            c.pb(a[i++]);
            v.pb(0);
            s.pb(s.back()+v.back());
        }
        else{
            c.pb(b[j++]);
            v.pb(1);
            s.pb(s.back()+v.back());
        }
    }
    cout<<c<<endl;
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
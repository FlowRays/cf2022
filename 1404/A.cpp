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
    string s;
    cin>>s;
    forn(i,k){
        vector<char> v;
        for(int j=i;j<n;j+=k){
            if(s[j] == '?') continue;
            v.pb(s[j]);
        }
        if(v.size()>=1){
            sort(all(v));
            v.erase(unique(all(v)),v.end());
            if(v.size()>1){
                cout<<"NO"<<endl;
                return;
            }
            for(int j=i;j<n;j+=k){
                s[j] = v[0];
            }            
        }
    }
    vi cnt0(n+1),cnt1(n+1);
    forn(i,n) cnt0[i+1] = cnt0[i]+(s[i]=='0'), cnt1[i+1] = cnt1[i]+(s[i]=='1');
    int c0 = cnt0[k], c1 = cnt1[k];
    if(c0>k/2 || c1>k/2){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
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
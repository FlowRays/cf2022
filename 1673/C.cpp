#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fore(i, l, r) for (int i = int(l); i <= int(r); ++i)
#define sz(a) int((a).size())
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
const int N = 4e4+10;

int f[N];
int rec[N];
int cnt;
int ans[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    fore(i,1,N-1){
        bool ok = true;
        int t = i;
        vi v;
        while(t){
            v.pb(t%10);
            t /= 10;
        }
        forn(j,v.size()){
            if(v[j] != v[v.size()-1-j]){
                ok = false;
                break;
            }
        }
        f[i] = (ok ? 1 : 0);
        if(f[i]) rec[++cnt] = i;
    }    
    ans[0] = 1;
    fore(i,1,cnt){
        fore(j,rec[i],N-1){
            ans[j] = (ans[j]+ans[j-rec[i]])%mod;
        }
    }
    int tt;
    cin>>tt;
    while(tt--){
        int x;
        cin>>x;
        cout<<ans[x]<<endl;
    }

    return 0;
}
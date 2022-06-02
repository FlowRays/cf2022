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

class dsu {
public:
    vi p;
    int n;
    
    dsu(int _n): n(_n) {
        p.resize(n);
        iota(all(p),0);
    }

    inline int find(int x){
        return (x == p[x] ? x : (p[x] = find(p[x])));
    }

    inline bool merge(int x,int y){
        x = find(x), y = find(y);
        if(x != y){
            p[x] = y;
            return true;
        }
        return false;
    }
};

void solve(){
    int n;
    cin>>n;
    vi c(n),l(n),r(n);
    vector<pii> ev;
    forn(i,n){
        cin>>c[i]>>l[i]>>r[i];
        ev.emplace_back(l[i],~i); // ~i = -i-1;
        ev.emplace_back(r[i],i);
    }
    sort(all(ev));
    vector<set<pii>> s(2);
    dsu d(n);
    int ans = n;
    for(auto &e: ev){
        int id = e.second;
        if(id<0){
            id = ~id;
            s[c[id]].emplace(r[id],id);
            int q = c[id]^1;
            if(s[q].size()){
                while(s[q].size()>=2){
                    ans -= d.merge(id,s[q].begin()->second);
                    s[q].erase(s[q].begin());
                }
                ans -= d.merge(id,s[q].begin()->second);
                // 不能全部删掉
            }
        }
        else{
            s[c[id]].erase({r[id],id}); // 表示已经到达seg终点，从set中去除
        }
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
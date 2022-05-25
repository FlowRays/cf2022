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
    vector<pii> p(n);
    forn(i,n) p[i] = {a[i],b[i]};
    sort(all(a));
    sort(all(b));
    vector<pii> ans;
    bool ok = true;
    forn(i,n){
        fore(j,i,n-1){
            if(p[j] == make_pair(a[i],b[i])){
                swap(p[i],p[j]);
                if(i != j){
                    ans.emplace_back(i,j);
                }
                break;
            }
        }
        if(p[i] != make_pair(a[i],b[i])){
            ok = false;
            break;
        }
    }
    if(!ok) cout<<-1<<endl;
    else{
        cout<<ans.size()<<endl;
        for(auto [x,y]: ans){
            cout<<x+1<<" "<<y+1<<endl;
        }
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
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
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m));
    forn(i,n){
        forn(j,m){
            cin>>a[i][j];
        }
    }
    auto b = a;
    vector<int> diff(n);
    vector<vector<int>> rec(n);
    forn(i,n){
        sort(all(b[i]));
        int cnt = 0;
        forn(j,m){
            if(a[i][j] != b[i][j]){
                cnt++;
                rec[i].pb(j);
            }
        }
        diff[i] = cnt;
    }
    bool ok = true;
    bool has = false;
    int p = -1, q = -1;
    forn(i,n){
        if(!has && diff[i]==2){
            has = true;
            p = rec[i][0], q = rec[i][1];
        }
        if(diff[i]!=0 && diff[i]!=2){
            ok = false;
            break;
        }
    }
    if(!ok){
        cout<<-1<<endl;
        return;
    }
    if(has){
        forn(i,n){
            if(diff[i]==0 && a[i][p]!=a[i][q]){
                ok = false;
                break;
            }
            if(diff[i]==2 && (rec[i][0]!=p || rec[i][1]!=q)){
                ok = false;
                break;
            }
        }
        if(ok) cout<<p+1<<" "<<q+1<<endl;
        else cout<<-1<<endl;
    }   
    else{
        cout<<1<<" "<<1<<endl;
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
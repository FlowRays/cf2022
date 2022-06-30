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
    vector<vector<int>> A(n),B(n);
    set<int> p;
    forn(i,n){
        vi a(m);
        forn(j,m) cin>>a[j];
        A[i] = a;
        auto b = a;
        sort(all(b));
        B[i] = b;
        forn(j,m){
            if(a[j] != b[j]){
                p.insert(j+1);
            }
        }
    }
    if(p.size()>=3){
        cout<<-1<<endl;
    }
    else if(p.size()==0){
        cout<<1<<" "<<1<<endl;
    }
    else{
        int t1 = *p.begin(), t2 = *p.rbegin(); 
        // cout<<t1<<" "<<t2<<endl;
        bool ok = true;
        forn(i,n){
            swap(A[i][t1-1],A[i][t2-1]);
            ok &= A[i]==B[i];
        }
        if(ok) cout<<t1<<" "<<t2<<endl;
        else cout<<-1<<endl;
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
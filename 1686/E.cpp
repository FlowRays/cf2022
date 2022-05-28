// (())()
// ())((()))(
// ())((()))(()
// 12个数
// 1 -1 -1 1 1 1 -1 -1 -1 1 1 -1
// 1 0  -1 0 1 2 1   0 -1 0 1  0

// 1 2  3  2 1 0 1   2  3 2 1  0

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
    n *= 2;
    string s;
    cin>>s;
    vi a(n);
    forn(i,n){
        a[i] = (s[i]=='(' ? 1 : -1);
    }
    vi b(n+1);
    fore(i,1,n){
        b[i] = b[i-1]+a[i-1];
    }
    if(*min_element(all(b))>=0){
        cout<<0<<endl;
        return;
    }
    int l, r;
    fore(i,1,n){
        if(b[i]<0){
            l = i;
            break;
        }
    }
    for(int i=n;i>=1;--i){
        if(b[i]<0){
            r = i;
            break;
        }
    }
    int L = 0, R = r;
    fore(i,0,l){
        if(b[i]>b[L]){
            L = i;
        }
    }
    L++;
    for(int i=r;i<=n;++i){
        if(b[i]>b[R]){
            R = i;
        }
    }
    bool ok = true;
    fore(i,L,R){
        if(b[L-1]+b[R]-b[i-1]<0){
            ok = false;
            break;
        }
    }
    if(ok){
        cout<<1<<endl;
        cout<<L<<" "<<R<<endl;
    }
    else{
        cout<<2<<endl;
        int p = 1;
        fore(i,1,n){
            if(b[i]>b[p]){
                p = i;
            }
        }
        cout<<1<<" "<<p<<endl;
        cout<<p+1<<" "<<n<<endl;
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
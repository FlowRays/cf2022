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
    ll n;
    cin>>n;
    ll t = n/4;
    bool found = false;
    ll mi, mx;
    for(ll x=0;x<=min(t,2ll);++x){
        if((n+2*x)%6==0){
            found = true;
            mi = (n+2*x)/6;
            break;
        }
    }
    if(!found){
        cout<<-1<<endl;
        return;
    }
    found = false;
    for(ll x=t;x>=max(0ll,t-2);x--){
        if((n+2*x)%6==0){
            found = true;
            mx = (n+2*x)/6;
            break;
        }
    }
    if(!found){
        cout<<-1<<endl;
        return;
    }
    cout<<mi<<" "<<mx<<endl;
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
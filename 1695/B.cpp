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
    vi a(n);
    forn(i,n) cin>>a[i];
    if(n%2==0){
        int mi = *min_element(all(a));
        int p = 0;
        forn(i,n){
            if(a[i] == mi){
                p = i;
                break;
            }
        }
        if(p%2==0) cout<<"Joe"<<endl;
        else cout<<"Mike"<<endl;
    }
    else{
        cout<<"Mike"<<endl;
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
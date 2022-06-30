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

int sq(int x){
    if(x<0) return -1;
    int t = sqrt(x);
    for(int i=t-1;i<=t+1;++i){
        if(i>=0 && i*i == x){
            return i;
        }
    }
    return -1;
}

void solve(){
    int x;
    cin>>x;
    for(int n=1;n==1 || n*n-(n/2)*(n/2)<=x;++n){
        int k = sq(n*n-x);
        if(k<0) continue;
        int l = 1, r = n;
        while(l<r){
            int mid = l+r+1 >> 1;
            if(n/mid>=k) l = mid;
            else r = mid-1;
        }
        if(n/l == k){
            cout<<n<<" "<<l<<endl;
            return;
        }
    }
    cout<<-1<<endl;
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
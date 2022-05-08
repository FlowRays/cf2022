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
const int N = 2e5+10;

int dp[N];
int tot;

void solve(){
    int n;
    cin>>n;
    cout<<lower_bound(dp+1,dp+tot,n)-dp<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a[3] = {0};
    int i = 1;
    while(true){
        forn(j,3){
            if(a[j]<=a[(j+1)%3] && a[j]<=a[(j+2)%3]){
                a[j]++;
                dp[i] = dp[i-1]+(a[(j+1)%3]+a[(j+2)%3])*2;
                break;
            }
        }
        if(dp[i]>1e9) break;
        i++;
    }
    tot = i;
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}
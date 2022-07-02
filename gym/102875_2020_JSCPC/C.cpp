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
const int N = 1e5+10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vi a(n+1);
    int tot = 0;
    int base = 1;
    int cnt = 0;
    while(tot<n){
        tot += base;
        base *= 2;
        cnt++;
    }
    fore(i,1,cnt){
        int t = 1<<(cnt-i);
        int ad = 1<<(cnt-i+1);
        while(t<=n){
            a[t] = i;
            t += ad;
        }
    }
    fore(i,1,n) cout<<a[i]<<" \n"[i==n];

    return 0;
}
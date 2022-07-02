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
    int n,q;
    cin>>n>>q;
    vi a(n+1);
    fore(i,1,n){
        int x;
        cin>>x;
        a[i] = i-x;
    }
    vi L(q);
    vector<vector<int>> R(n+1);
    forn(i,q){
        int x,y;
        cin>>x>>y;
        int l = x+1, r = n-y;
        L[i] = l;
        R[r].pb(i);
    }
    int global = 0;
    vector<int> BIT(n+1);
    vector<int> ans(q);
    fore(i,1,n){
        if(a[i]>=0){
            // [l,r] max l: global-BIT[0:l]>=a[i]
            int l = 0, r = i;
            while(l<r){
                int mid = l+r+1 >> 1;
                int v = global;
                for(int j=mid;j>=1;j -= j&-j){
                    v -= BIT[j];
                }
                if(v>=a[i]) l=mid;
                else r=mid-1;
            }
            for(int j=l+1;j<=n;j += j&-j){
                BIT[j]++;
            }
            global++;
        }
        for(auto t: R[i]){
            ans[t] = global;
            int l = L[t];
            for(int j=l;j>=1;j -= j&-j){
                ans[t] -= BIT[j];
            }
        }
    }
    forn(i,q) cout<<ans[i]<<endl;

    return 0;
}
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
    vi a(n);
    forn(i,n) cin>>a[i];
    vi R(n); // 包含点i的区间中右端点的最大值
    forn(i,n) R[i] = i;
    forn(i,m){
        int l,r;
        cin>>l>>r;
        l--,r--;
        R[l] = max(R[l],r); // R[i]: max Rj of [i,Rj]
    }
    fore(i,1,n-1){
        R[i] = max(R[i],R[i-1]); // R[i]: max Rj of [0-i,Rj] 
    }
    vi f(n); // 以i为ANS的左端点时右端点的最小值
    forn(i,n) f[i] = i;
    bool ok = true;
    int maxL = n-1, minR = 0; 
    map<int,vi> p; // 一个值出现的所有位置
    forn(i,n) p[a[i]].pb(i);
    for(auto [x,p]: p){
        int m = p.size();
        forn(i,m-1){
            int u = p[i], v = p[i+1];
            if(R[u] >= v){ // 存在某个区间同时包含了两个相同的值
                maxL = min(maxL,v); // L不可能在v的右侧
                minR = max(minR,u); // R不可能在u的左侧
                ok = false;
            }
        }
        for(int i=0,j=0;i<m;++i){
            while(j+1<m && p[j+1]<=R[p[i]]) j++;
            // 对于每个i，令j移动到最远的距离，使得存在同时包含p[i]和p[j]的区间
            if(i<j){
                int u = p[i], v = p[j];
                // f[i]: 以i为左端点，满足要求的右端点
                // 因为存在某个区间同时包含p[i],p[j]，所以当ANS的左端点为p[i]+1时，必须让p[j]包含在ANS的区间中，至少为p[j]
                f[u+1] = max(f[u+1],v); // 对每个x都要满足要求
            }
        }
    }
    fore(i,1,n-1) f[i] = max(f[i-1],f[i]);
    if(ok){
        cout<<0<<endl;
        return;
    }
    int ans = n;
    for(int l=0;l<=maxL;++l){
        ans = min(ans,max(minR,f[l])-l+1);
    }
    cout<<ans<<endl;
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
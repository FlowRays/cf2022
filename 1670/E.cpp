// 首先可以证明出ans>=2^p，因为在[1,2^(p+1)-1]这些数中，必然存在某一条链上的前缀在p-bit上为0，而遇到下一个数的p-bit上为1
// 因此xor>=2^p，所以最大值至少是2^p
// 可以试图构造出一种方式来确保答案是2^p
// 令任意一个点为根，取值为2^p，将其相连的一条边和一个结点看为一组，分别是x+2^p和x（x为[1,2^p-1]任意值）
// 可以保证数量刚好与结点和边的数量对应上

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
    int p;
    cin>>p;
    int n = 1<<p;
    map<pii,int> mp;
    vector<vector<int>> e(n+1);
    forn(i,n-1){
        int u,v;
        cin>>u>>v;
        mp[{u,v}] = i+1;
        mp[{v,u}] = i+1;
        e[u].pb(v);
        e[v].pb(u);
    }
    vector<int> node(n+1),edge(n);
    vector<int> st(n+1,0);
    vector<int> d(n+1,0);
    queue<int> q;
    q.push(1);
    st[1] = 1;
    node[1] = n;
    int cnt = 1;
    while(q.size()){
        int t = q.front();
        q.pop();
        for(auto v: e[t]){
            if(!st[v]){
                if(d[t]%2==0){
                    node[v] = cnt;
                    edge[mp[{t,v}]] = cnt+n;
                }
                else{
                    node[v] = cnt+n;
                    edge[mp[{t,v}]] = cnt;
                }
                d[v] = d[t]+1;
                q.push(v);
                st[v] = 1;
                cnt++;
            }
        }
    }
    cout<<1<<endl;
    fore(i,1,n) cout<<node[i]<<" \n"[i==n];
    fore(i,1,n-1) cout<<edge[i]<<" \n"[i==n-1];
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

/*
1
2
1 2
2 3
3 4
*/
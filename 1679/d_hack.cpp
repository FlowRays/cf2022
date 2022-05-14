#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5;
int val[N];

int n,m,k;
vector<vector<int>> adj;
vector<int> deg;
vector<int> dp;
vector<pair<int,int>> edges;

void init(){
    adj.clear();
    adj.resize(n+1);
    deg.clear();
    deg.resize(n+1);
    dp.clear();
    dp.resize(n+1);
}

bool check(int x){
    init();
    for(auto [u,v] : edges){
        if(val[u] > x || val[v] > x) continue;
        adj[u].push_back(v);
        deg[v]++;
    }

    vector<int> num;
    queue<int> q;
    for(int i = 1;i <= n;i++){
        if(deg[i]==0) q.push(i);
    }

    while(!q.empty()){
        int u = q.front(); q.pop();
        num.push_back(u);
        for(auto v : adj[u]){
            dp[v] = max(dp[v],dp[u]+1);
            deg[v]--;
            if(deg[v]==0) q.push(v);
        }
    }

    if(num.size() < n) return true;
    if(*max_element(dp.begin(),dp.end()) >= k-1) return true;
    return false;
}

signed main(){
    fastio
    cin >> n >> m >> k;

    int mx = 0;
    for(int i = 1;i <= n;i++){
        cin >> val[i];
        mx = max(mx,val[i]);
    }

    for(int i = 0;i < m;i++){
        int u,v;
        cin >> u >> v;
        edges.push_back({u,v});
    }

    if(k==1){
        cout << mx << "\n";
        return 0;
    }

    int l = 0, r = 1e9+7;

    while(l < r){
        int mid = l+r>>1;
        if(check(mid)) r = mid;
        else l = mid+1;
    }

    if(r==1e9+7) cout << -1 << '\n';
    else cout << r << "\n";
}
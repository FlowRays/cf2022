#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fore(i, l, r) for (int i = int(l); i <= int(r); ++i)
#define sz(a) int((a).size())
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define pb push_back
#define vi vector<int>

using namespace std;
using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
const int N = 1e6+10;

int pv[N],vis[N];
vector<int> e[N];
vector<int> choice[2];

void dfs(int s,int x){
    vis[s] = 1;
    choice[x].pb(s);
    for(auto v: e[s]){
        if(!vis[v]){
            dfs(v,x^1);
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    if(n%2){
        cout<<"Second"<<endl;
        for(int i=1;i<=2*n;++i){
            int x;
            cin>>x;
            if(pv[x]){
                e[pv[x]].pb(i);
                e[i].pb(pv[x]);
            }
            else pv[x] = i;
        }
        for(int i=1;i<=n;++i){
            e[i].pb(i+n);
            e[i+n].pb(i);
        }
        for(int i=1;i<=2*n;++i){
            if(!vis[i]) dfs(i,0);
        }
        ll sum = 0;
        for(auto x: choice[0]) sum += x;
        if(sum%(2*n) != 0) swap(choice[0],choice[1]);
        for(auto x: choice[0]) cout<<x<<" ";
        cout<<endl;
        int res;
        cin>>res;
    }
    else{
        cout<<"First"<<endl;
        forn(i,2*n) cout<<(i%n)+1<<" ";
        cout<<endl;
        int res;
        cin>>res;
    }

    return 0;
}
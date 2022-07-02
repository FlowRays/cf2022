#include <bits/stdc++.h>

#define forn(i, n) for (ll i = 0; i < ll(n); i++)
#define fore(i, l, r) for (ll i = ll(l); i <= ll(r); ++i)
#define sz(a) ll((a).size())
#define endl "\n"
#define pii pair<ll,ll>
#define all(x) x.begin(),x.end()
#define pb push_back
#define vi vector<ll>

using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll inf = 0x3f3f3f3f;
const ll mod = 1e9+7;
const ll N = 500+10;

ll n,m,xs,ys,xt,yt;
ll a[N][N],b[N][N],c[N][N],w[N][N];
ll vis[N][N][2];
ll ti[N][N][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>xs>>ys>>xt>>yt;
    fore(i,1,n){
        fore(j,1,m){
            cin>>a[i][j];
        }
    }
    fore(i,1,n){
        fore(j,1,m){
            cin>>b[i][j];
        }
    }
    fore(i,1,n){
        fore(j,1,m-1){
            cin>>c[i][j];
        }
    }
    fore(i,1,n-1){
        fore(j,1,m){
            cin>>w[i][j];
        }
    }
    queue<tuple<ll,ll,ll>> q;
    q.push({0,xs,ys});
    ll ans = 1e18;
    while(q.size()){
        auto [t,x,y] = q.front();
        q.pop();
        if(x == xt && y == yt) ans = min(ans,t);
        int k = t / (a[x][y] + b[x][y]);
        if(t>=k*(a[x][y] + b[x][y]) && t<(k+1)*a[x][y]+k*b[x][y]){
            if(!vis[x][y][0]){
                vis[x][y][0] = 1;
                ti[x][y][0] = t;
            }
            else{
                if(t>ti[x][y][0]) continue;
            }
            if(x>1) q.push({t+w[x-1][y],x-1,y});
            if(x<n) q.push({t+w[x][y],x+1,y});
        }
        else{
            if(!vis[x][y][1]){
                vis[x][y][1] = 1;
                ti[x][y][1] = t;
            }
            else{
                if(t>ti[x][y][1]) continue;
            }
            if(y>1) q.push({t+c[x][y-1],x,y-1});
            if(y<m) q.push({t+c[x][y],x,y+1});
        }
    }
    cout<<ans<<endl;

    return 0;
}




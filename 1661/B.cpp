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
const int mod = 32768;
const int N = 1e5+10;

int dist[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(dist,-1,sizeof dist);
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while(q.size()){
        int t = q.front(); q.pop();
        int x = (t-1+mod)%mod;
        if(dist[x] == -1){
            q.push(x);
            dist[x] = dist[t]+1;
        }
        if(t%2==0){
            x = t/2;
            if(dist[x] == -1){
                q.push(x);
                dist[x] = dist[t]+1;
            }
            x = (t+mod)/2;
            if(dist[x] == -1){
                q.push(x);
                dist[x] = dist[t]+1;
            }
        }
    }
    int n;
    cin>>n;
    vi a(n);
    forn(i,n) cin>>a[i];
    forn(i,n) cout<<dist[a[i]]<<(i==n-1 ? '\n' : ' ');

    return 0;
}
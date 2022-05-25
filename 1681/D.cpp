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
    ll n,v;
    cin>>n>>v;
    queue<ll> q;
    map<ll,int> dist;
    dist[v] = 0;
    q.push(v);
    while(q.size()){
        ll k = q.front();
        q.pop();
        string s = to_string(k);
        if(s.size() == n){
            cout<<dist[k]<<endl;
            return 0;
        }
        for(auto x: s){
            if(x>'1'){
                ll w = k*(x-'0');
                if(!dist.contains(w)){ // c++20
                    dist[w] = dist[k]+1;
                    q.push(w);
                }
            }
        }
    }
    cout<<-1<<endl;

    return 0;
}
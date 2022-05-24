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

inline ll get(ll x){
    ll res = 0;
    while(x){
        res++;
        x /= 10;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,x;
    cin>>n>>x;
    queue<ll> q;
    map<ll,ll> dis;
    q.push(x);
    dis[x] = 0;
    while(q.size()){
        ll t = q.front();
        q.pop();
        set<int> st;
        ll val = t;
        while(val){
            if(val%10 != 1){
                st.insert(val%10);
            }
            val /= 10;
        }
        for(auto f: st) {
            if(dis.count(f*t) == 0) {
                q.push(f*t);
                dis[f*t] = dis[t]+1;
                if(get(f*t) == n) {
                    cout<<dis[f*t]<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<-1<<endl;

    return 0;
}
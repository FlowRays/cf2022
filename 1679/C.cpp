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

template <typename T>
class fenwick{
public:
    vector<T> fenw;
    int n;
    
    fenwick(int _n) : n(_n) {
        fenw.resize(n);
    }
    
    void modify(int x, T v) {
        while (x < n) {
            fenw[x] += v;
            x |= (x + 1);
        }
    }

    T get(int x) {
        T v{};
        while (x >= 0) {
            v += fenw[x];
            x = (x & (x + 1)) - 1;
        }
        return v;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    fenwick<int> r(n+1),c(n+1);
    fenwick<int> r1(n+1),c1(n+1);
    while(q--){
        int op;
        cin>>op;
        if(op == 1){
            int x,y;
            cin>>x>>y;
            r.modify(x,1);
            c.modify(y,1);
            int t1 = r1.get(x)-r1.get(x-1);
            int t2 = c1.get(y)-c1.get(y-1);
            if(t1 == 0) r1.modify(x,1);
            if(t2 == 0) c1.modify(y,1);
        }
        else if(op == 2){
            int x,y;
            cin>>x>>y;
            r.modify(x,-1);
            c.modify(y,-1);     
            int t1 = r.get(x)-r.get(x-1);
            int t2 = c.get(y)-c.get(y-1);
            // int t3 = r1.get(x)-r1.get(x-1);
            // int t4 = c1.get(y)-c1.get(y-1);
            if(t1 == 0) r1.modify(x,-1);
            if(t2 == 0) c1.modify(y,-1);                   
        }
        else{
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            int s1 = r1.get(x2) - r1.get(x1-1);
            int s2 = c1.get(y2) - c1.get(y1-1);
            cout<<((s1==x2-x1+1 || s2==y2-y1+1) ? "YES" : "NO")<<endl;
        }
    }

    return 0;
}
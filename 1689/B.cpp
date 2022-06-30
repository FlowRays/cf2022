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
    int n;
    cin>>n;
    vi a(n),b(n);
    forn(i,n) cin>>a[i];
    priority_queue<int,vector<int>,greater<int>> q;
    forn(i,n) q.push(i+1);
    forn(i,n){
        if(q.size() == 2){
            int t1 = q.top(); q.pop();
            int t2 = q.top();
            if(a[i] == t1 || a[i+1] == t2) b[i] = t2, b[i+1] = t1;
            else b[i] = t1, b[i+1] = t2;
            break;
        }
        if(q.top() != a[i]){
            b[i] = q.top();
            q.pop();
        }
        else{
            q.pop();
            if(q.empty()){
                cout<<-1<<endl;
                return;
            }
            b[i] = q.top();
            q.pop();
            q.push(a[i]);
        }
    }
    forn(i,n) cout<<b[i]<<" \n"[i==n-1];
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
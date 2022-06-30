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
    string s;
    cin>>s;
    int n = s.size();
    vi pi(n),vis(n);
    fore(i,1,n-1){
        int j = pi[i-1];
        while(j && s[i]!=s[j]) j = pi[j-1];
        if(s[i]==s[j]) j++;
        pi[i] = j;
        if(i != n-1) vis[j]=1;
    }
    int p = pi[n-1];
    while(p){
        if(vis[p]){
            cout<<s.substr(0,p)<<endl;
            return 0;
        }
        p = pi[p-1];
    }
    cout<<"Just a legend"<<endl;

    return 0;
}
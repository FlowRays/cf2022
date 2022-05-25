// link cut tree 维护动态树
// 思路明确了就可以看做是lct模板题了

#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int maxn = 5e5 + 5, INF = 0x3f3f3f3f;
vector<PII> g[maxn];

struct Node{
    int s[2], p, sz, sz2;
    bool rev;
}tr[maxn];
int stk[maxn];

void pushup(int u){
    tr[u].sz = tr[tr[u].s[0]].sz + 1 + tr[tr[u].s[1]].sz + tr[u].sz2;
}

void pushrev(int u){
    swap(tr[u].s[0], tr[u].s[1]);
    tr[u].rev ^= 1;
}

void pushdown(int u){
    if (tr[u].rev){
        pushrev(tr[u].s[0]), pushrev(tr[u].s[1]);
        tr[u].rev = 0;
    }
}

bool isroot(int x){
    return tr[tr[x].p].s[0] != x && tr[tr[x].p].s[1] != x;
}

void rotate(int x){
    int y = tr[x].p, z = tr[y].p;
    int k = tr[y].s[1] == x;
    if (!isroot(y)) tr[z].s[tr[z].s[1] == y] = x;
    tr[x].p = z;
    tr[y].s[k] = tr[x].s[k ^ 1], tr[tr[x].s[k ^ 1]].p = y;
    tr[x].s[k ^ 1] = y, tr[y].p = x;
    pushup(y), pushup(x);
}

void splay(int x){
    int top = 0, r = x;
    stk[++top] = r;
    while(!isroot(r)) stk[++top] = r = tr[r].p;
    while(top) pushdown(stk[top--]);
    while(!isroot(x)){
        int y = tr[x].p, z = tr[y].p;
        if (!isroot(y))
            if ((tr[y].s[1] == x) ^ (tr[z].s[1] == y)) rotate(x);
            else rotate(y);
        rotate(x);
    }
}

void access(int x){
    int z = x;
    for(int y = 0; x; y = x, x = tr[x].p){
        splay(x);
        tr[x].sz2 += tr[tr[x].s[1]].sz - tr[y].sz;
        tr[x].s[1] = y, pushup(x);
    }
    splay(z);
}

void makeroot(int x){
    access(x);
    pushrev(x);
}

int findroot(int x){
    access(x);
    while(tr[x].s[0]) x = tr[x].s[0];
    splay(x);
    return x;
}

void link(int x, int y){
    makeroot(x);
    access(y);
    tr[x].p = y; 
    tr[y].sz2 += tr[x].sz;
    pushup(y);
}

void cut(int x, int y){
    makeroot(x);
    if (findroot(y) == x && tr[y].p == x && !tr[y].s[0]){
        tr[x].s[1] = tr[y].p = 0;
        pushup(x);
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) tr[i].sz = 1;
    for(int i = 0; i < n - 1; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[w].push_back({u, v});
        link(u, v);
    }
    LL ans = 0;
    for(int x = 1; x <= n; x++){
        for(auto [u, v] : g[x]) cut(u, v);
        for(auto [u, v] : g[x]){
            makeroot(u), makeroot(v);
            ans += 1LL * tr[u].sz * tr[v].sz;
        }
        for(auto [u, v] : g[x]) link(u, v); 
    }
    cout << ans << '\n';

}
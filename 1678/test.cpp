#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxm=1e5+5;
struct Node{
    int lc,rc,cnt;
}a[maxm*40];
int r[maxm],cnt;
int b[maxm];
int xx[maxm];
void init(){
    cnt=0;
}
void pushup(int k){
    a[k].cnt=a[a[k].lc].cnt+a[a[k].rc].cnt;
}
int build(int l,int r){
    int k=cnt++;
    a[k].cnt=0;
    if(l!=r){
        int mid=(l+r)/2;
        a[k].lc=build(l,mid);
        a[k].rc=build(mid+1,r);
    }
    return k;
}
int update(int x,int val,int l,int r,int last){
    int k=cnt++;
    a[k]=a[last];
    if(l==r){
        a[k].cnt+=val;
        return k;
    }
    int mid=(l+r)/2;
    if(x<=mid)a[k].lc=update(x,val,l,mid,a[last].lc);
    else a[k].rc=update(x,val,mid+1,r,a[last].rc);
    pushup(k);
    return k;
}
int ask(int st,int ed,int l,int r,int x,int y){//区间求和
    if(st<=l&&ed>=r){
        return a[y].cnt-a[x].cnt;
    }
    int mid=(l+r)/2;
    int ans=0;
    if(st<=mid)ans+=ask(st,ed,l,mid,a[x].lc,a[y].lc);
    if(ed>=mid+1)ans+=ask(st,ed,mid+1,r,a[x].rc,a[y].rc);
    return ans;
}
int main(){
    int T;
    scanf("%d",&T);
    int cas=1;
    while(T--){
        init();
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%d",&b[i]);
            xx[i]=b[i];
        }
        sort(xx+1,xx+1+n);
        int num=unique(xx+1,xx+1+n)-xx-1;
        r[0]=build(1,num);
        for(int i=1;i<=n;i++){
            int p=lower_bound(xx+1,xx+1+num,b[i])-xx;
            r[i]=update(p,1,1,num,r[i-1]);
        }
        printf("Case %d:\n",cas++);
        for(int i=1;i<=m;i++){
            int a,b,k;
            scanf("%d%d%d",&a,&b,&k);
            a++,b++;
            int p=lower_bound(xx+1,xx+1+num,k)-xx;
            if(xx[p]!=k)p--;
            if(p>0)printf("%d\n",ask(1,p,1,num,r[a-1],r[b]));
            else puts("0");
        }
    }
    return 0;
}

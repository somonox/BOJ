#include<cstdio>
#include<vector>
#include<algorithm>
#define pi pair<int,int>
#define mp make_pair
using namespace std;
int n,i,j,m;
pi p[100000];
int q[100000];
vector<pi> v;
bool comp(const pi &a,int b){
    return a.first<b;
}
int main(){
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d %d",&p[i].first,&p[i].second);
    sort(p,p+n);
    for(i=0;i<n;i++){
        if(v.empty()||v.back().first<p[i].second){
            q[i]=v.size()?v[v.size()-1].second:-1;
            v.push_back(mp(p[i].second,i));
            m=i;
        }else{
            j=lower_bound(v.begin(),v.end(),p[i].second,comp)-v.begin();
            q[i]=j?v[j-1].second:-1;
            v[j]=mp(p[i].second,i);
        }
    }
    printf("%d\n",n-v.size());
    while(m>-1){
        p[m].first=-1;
        m=q[m];
    }
    for(i=0;i<n;i++)if(p[i].first>-1)printf("%d\n",p[i].first);
}
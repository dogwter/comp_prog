#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int k,m,n; cin>>k>>m>>n;
    vector<pair<int,long long>>p(k);
    vector<int>c(m);
    vector<long long>g;
    for(int i=0;i<k;i++)cin>>p[i].first>>p[i].second;
    for(int i=0;i<m;i++)cin>>c[i];
    sort(p.begin(),p.end());
    sort(c.begin(),c.end());
    int l = 0, r = 0; 
    long long tasty = 0;
    while(l<k&&p[l].first<c[0]){
        tasty+=p[l].second;
        l++;
    }
    g.push_back(tasty);
    for(int i=0;i<m-1;i++){ //process each nhoj chunk
        long long tt = 0; //total taste within the whole chunk
        tasty = 0;
        while(l<k&&p[l].first<=c[i])l++;
        if(l==k)break;
        else{
            if(p[l].first<c[i+1]){
                tt+=p[l].second;
                r=l;
                while(r+1<k&&p[r+1].first<c[i+1]){
                    r++;
                    tt+=p[r].second;
                }
                long long temp=p[l].second;
                int right = l+1;
                for(int j=l;j<=r;j++){
                    while(right<=r&&(p[right].first-p[j].first)*2<c[i+1]-c[i]){
                        temp+=p[right].second;
                        right++;
                    }
                    tasty = max(tasty,temp);
                    temp-=p[j].second;
                }
                g.push_back(tasty);
                g.push_back(tt-tasty);
            }
        }
    }
    tasty = 0; l = k-1;
    while(l>=0&&p[l].first>c[m-1]){
        tasty+=p[l].second;
        l--;
    }
    g.push_back(tasty);
    sort(g.begin(),g.end(),greater<long long>());
    tasty = 0;
    for(int i=0;i<min((int)g.size(),n);i++)tasty+=g[i];
    cout<<tasty<<"\n";
}  
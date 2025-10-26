#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int n, l; cin>>n>>l;
    vector<tuple<int,int,int>>cow;
    vector<pair<int,int>>rw(n);
    int total = 0, t = 0;
    for(int i=0,a,b,c;i<n;i++){
        cin>>a>>b>>c;
        cow.push_back({b,a,c});
        total += a;
    }
    sort(cow.begin(),cow.end());
    int idx = 0;
    for(int i=0;i<n;i++){
        if(get<2>(cow[i])==-1){
            rw[i].second=get<1>(cow[idx]);
            idx++;
        }
    }
    idx=n-1;
    for(int i=n-1;i>=0;i--){
        if(get<2>(cow[i])!=-1){
            rw[i].second=get<1>(cow[idx]);
            idx--;
        }
    }
    for(int i=0;i<n;i++)get<1>(cow[i])=rw[i].second;
    for(int i=0;i<n;i++){
        if(get<2>(cow[i])==1)rw[i].first=l-get<0>(cow[i]);
        else rw[i].first=get<0>(cow[i]);
    }
    sort(rw.begin(),rw.end());
    idx = 0;
    while(total>0){
        total-=rw[idx].second*2;
        t = rw[idx].first;
        idx++;
    }
    queue<int>q;
    int ans = 0;
    for(int i=0;i<n;i++){
        if(get<2>(cow[i])==1)q.push(get<0>(cow[i]));
        else{
            while(!q.empty()&&get<0>(cow[i])-q.front()>2*t)q.pop();
            ans+=q.size();
        }
    }
    cout<<ans;
}  
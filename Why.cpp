#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int c, n; cin>>c>>n;
    vector<int>t(c);
    for(int i=0;i<c;i++)cin>>t[i];
    vector<pair<int,int>>cow(n);
    for(int i=0;i<n;i++)cin>>cow[i].first>>cow[i].second;
    sort(cow.begin(),cow.end());
    sort(t.begin(),t.end());
    priority_queue<int,vector<int>,greater<int>>pq;
    int ans = 0, idx = 0;
    for(int i:t){
        while(idx<n){
            if(cow[idx].first<=i){
                pq.push(cow[idx].second);
                idx++;
            }
            else break;
        }
        while(!pq.empty()){
            int j = pq.top();
            if(j<i)pq.pop();
            else break;
        }
        if(!pq.empty()){
            ans++; pq.pop();
        }
    }
    cout<<ans;
}  
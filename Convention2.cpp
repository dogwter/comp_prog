#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<int>eat(n);
    vector<pair<int,int>>cow(n);
    for(int i=0;i<n;i++){
        cin>>cow[i].first>>eat[i];
        cow[i].second = -i;
    }
    sort(cow.begin(), cow.end());
    priority_queue<pair<int,int>>pq;
    int time = cow[0].first;
    int wait = 0, idx = 0;
    while(idx<n&&cow[idx].first<=time){
        pq.push({cow[idx].second,cow[idx].first});
        idx++;
    }
    while(!pq.empty()||idx<n){
        if(pq.empty()){
            pq.push({cow[idx].second,cow[idx].first});
            time = cow[idx].first;
            idx++;
            while(idx<n&&cow[idx].first<=time){
                pq.push({cow[idx].second,cow[idx].first});
                idx++;
            }
        } else {
            auto c = pq.top(); pq.pop();
            wait = max(wait,time-c.second);
            time += eat[-c.first];
            
            while(idx<n&&cow[idx].first<=time){
                pq.push({cow[idx].second,cow[idx].first});
                idx++;
            }
        }
    }
    cout<<wait;
} 
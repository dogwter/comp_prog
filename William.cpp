#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<int>num(n);
    for(int i=0;i<n;i++)cin>>num[i];
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<n;i++){
        pq.push(num[i]);
        if(i%2==1)pq.pop();
    }
    int ans = 0;
    while(!pq.empty()){
        ans+=pq.top(); pq.pop();
    }
    cout<<ans;
}  
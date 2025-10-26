#include <bits/stdc++.h>
using namespace std;


bool dance(int s, int t, vector<int>&a){
    int nt = 0;
    priority_queue<int, vector<int>, greater<int>>pq;
    for(int i=0;i<a.size();i++){
        if(pq.size()<s)pq.push(a[i]);
        else{
            int temp = pq.top(); pq.pop();
            pq.push(temp+a[i]);
        }
    }
    while(!pq.empty()){
        nt=pq.top(); pq.pop();
    }
    if(nt>t)return false;
    return true;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int n, t; cin>>n>>t;
    vector<int>cows(n);
    for(int i=0;i<n;i++) cin>>cows[i];
    int lo=1, hi = n;
    while(lo<=hi){
        if(dance((lo+hi)/2,t,cows)) hi = (lo+hi)/2-1;
        else lo = (lo+hi)/2+1;
    }
    cout<<lo;
}
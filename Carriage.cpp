#include <bits/stdc++.h>
using namespace std;

bool move(vector<int>&a, vector<int>&d, int z){
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>,greater<>>pq;
    for(int i=0;i<a.size();i++){
        if(a[i]>0&&d[i]!=0)pq.push({max(0,i-d[i]),min((int)a.size()-1,i+d[i]),a[i]});
    }
    for(int i=0;i<a.size();i++){
        int j=0;
        if(d[i]==0)j=a[i];
        if(j>z)return false;
        while(j<z&&!pq.empty()){
            auto k = pq.top(); 
            if(get<0>(k)>i)break;
            else if(get<1>(k)<i) return false; 
            pq.pop();
            int temp = z-j;
            j+=min(get<2>(k),temp);
            if(get<2>(k)>temp)pq.push({get<0>(k),get<1>(k),get<2>(k)-temp});
        }
    }
    if(!pq.empty())return false;
    return true;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int n, hi=0; cin>>n;
    vector<int>a(n);
    vector<int>d(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        hi=max(hi,a[i]);
    }
    for(int i=0;i<n;i++)cin>>d[i];
    int lo =1;
    while(lo<=hi){
        if(move(a,d,(lo+hi)/2))hi=(lo+hi)/2-1;
        else lo = (lo+hi)/2+1;
    }
    cout<<lo;
}
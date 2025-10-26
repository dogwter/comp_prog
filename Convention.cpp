#include <bits/stdc++.h>
using namespace std;

bool bus(int c, int m, int t, vector<int>&a){
    int b = 1, idx = 0; 
    for(int i=0;i<a.size();i++){
        if(i-idx==c||a[i]-a[idx]>t){
            b++; idx = i;
        }
    }
    if(b>m)return false;
    return true;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int n, m, c; cin>>n>>m>>c;
    vector<int>cow(n);
    for(int i=0;i<n;i++)cin>>cow[i];
    sort(cow.begin(), cow.end());
    int lo = 0, hi=0;
    for(int i=0;i+c-1<n;i++)hi=max(hi,cow[i+c-1]-cow[i]);
    while(lo<=hi){
        if(bus(c,m,(lo+hi)/2,cow)) hi=(lo+hi)/2-1;
        else lo=(lo+hi)/2+1;
    }
    cout<<lo;
}
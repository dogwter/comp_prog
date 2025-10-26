#include <bits/stdc++.h>
using namespace std;

bool d(int r, int k, vector<int> &h){
    int ans = 1, idx = 0;
    for(int i=0;i<h.size();i++){
        if(h[i]-h[idx]>2*r){
            idx = i; ans++;
        }
    }
    if(ans>k)return false;
    return true;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin>>n>>k;
    vector<int>hay(n);
    for(int i=0;i<n;i++)cin>>hay[i];
    sort(hay.begin(),hay.end());
    int lo = 0, hi = (hay[n-1]-hay[0]+1)/2;
    while(lo<=hi){
        if(d((lo+hi)/2, k, hay)) hi = (lo+hi)/2-1;
        else lo = (lo+hi)/2+1;
    }
    cout << lo;
}
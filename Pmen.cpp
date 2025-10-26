#include <bits/stdc++.h>
using namespace std;

bool eat(vector<int>&a, vector<int>&p, int time){
    int idx = 0; // up to where has been eaten
    for(int i:p){
        if(a[idx]<i){ // this is its leftmost, must eat
            if(i-a[idx]>time)return false;
            int l_idx = i-a[idx];
            while(idx<a.size()&&a[idx]<i)idx++;
            if(idx==a.size())return true;
            while(idx<a.size()){
                if(max(a[idx]-i,l_idx)+min(a[idx]-i,l_idx)*2<=time)idx++;
                else break;
            }
            if(idx==a.size())return true;
        } else { // asterisks are to the packman's right, eat as much as possible
            while(idx<a.size()&&a[idx]-i<=time)idx++;
            if(idx==a.size())return true;
        }
    }
    return false; // if after processing everything, still not all have been eaten
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<int>a, p; 
    for(int i=0;i<n;i++){
        char c; cin>>c;
        if(c=='*')a.push_back(i);
        else if(c=='P')p.push_back(i);
    }

    int lo=1, hi = n*2;
    while(lo<=hi){
        if(eat(a,p,(lo+hi)/2)) hi = (lo+hi)/2-1;
        else lo = (lo+hi)/2+1;
    }
    cout<<lo;
}
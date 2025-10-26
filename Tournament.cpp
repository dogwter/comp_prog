#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    for(int i=0;i<t;i++){
        int n,m,idx = 0,ans=-1; cin>>n>>m;
        vector<pair<int,int>>a(n);
        for(int j=0;j<n;j++){
            cin>>a[j].first;
            a[j].second = j;
        }
        sort(a.begin(),a.end());
        for(int j=0;j<n;j++){
            if(m>=a[j].first){
                m-=a[j].first;
                idx++;
            } else {
                if(a[j].second==idx)ans=a[j].first;
            }
        }
        if(idx==n)cout<<1<<"\n";
        else if(idx==0)cout<<n+1<<"\n";
        else if(ans!=-1){
            m+=a[idx-1].first;
            if(m>=ans)cout<<n-idx<<"\n";
            else cout<<n-idx+1<<"\n";
        } else cout<<n-idx<<"\n";
    }
} 
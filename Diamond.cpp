#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin>>n>>k;
    vector<int>dia(n);
    vector<int>c1(n);
    vector<int>c2(n);
    for(int i=0;i<n;i++)cin>>dia[i];
    sort(dia.begin(), dia.end());
    int j = 0;
    for(int i=0;i<n;i++){
        while(dia[j]-dia[i]<=k && j<n)j++;
        c1[i]=j;
    }
    c2[n-1]=0;
    for(int i=n-2;i>=0;i--)c2[i] = max(c2[i+1],c1[i+1]-(i+1));
    c2.push_back(0);
    int ans =0;
    for(int i=0;i<n;i++)ans=max(ans,c1[i]-i+c2[c1[i]-1]);
    cout<<ans;
}
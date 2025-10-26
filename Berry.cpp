#include <bits/stdc++.h>
using namespace std;

int mod = 1;

bool m_cmp(int &a, int &b){
    return a%mod>b%mod;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin>>n>>k;
    vector<int>b(n);
    int j = 0;
    for(int i=0;i<n;i++){
        cin>>b[i];
        j = max(j,b[i]);
    }
    int ans = 0;
    for(int i=1;i<=j;i++){
        int full = 0;
        int temp = 0;
        mod=i;
        for(int t: b) full+=t/i;
        if(full>=k){
            ans = max(k/2*i,ans);
        } else if(full>=k/2){
            sort(b.begin(),b.end(),m_cmp);
            full-=k/2;
            temp = full*i;
            for(int l=0;l<k/2-full;l++) temp += b[l]%i;
            ans = max(temp,ans);
        }
    }
    cout<<ans;
} 
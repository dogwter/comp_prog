#include <bits/stdc++.h>
using namespace std;

int a[100001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    for(int i=0;i<t;i++){
        int n; cin>>n;
        long long ans = 0;
        map<int,int>good;
        a[0]=0;
        good[0]++;
        for(int j=1;j<=n;j++){
            char c; cin>>c;
            a[j]=(int)(c-'0');
            a[j]+=a[j-1];
            good[a[j]-j]++;
        }
        for(auto x:good){
            ans+=(x.second)*((long long)(x.second-1))/2;
        }
        cout<<ans<<"\n";
    }
}

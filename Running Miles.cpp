#include <bits/stdc++.h>
using namespace std;

long long b[3][100001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    for(int i=0;i<t;i++){
        int n; cin>>n;
        long long ans = 0;
        for(int j=1;j<=n;j++){ // putting vals in
            cin>>b[0][j];
            b[1][j]=b[0][j]-j;
            b[2][j]=b[0][j]+j;
        }
        long long idx = b[2][1];
        for(int j=2,k;j<n;j++){ // process L to R
            k = max(b[2][j],idx);
            b[2][j]=idx;
            idx=k;
        }
        idx = b[1][n];
        for(int j=n-1,k;j>1;j--){ // getting ans while process R to L
            k=max(b[1][j],idx);
            b[1][j]=idx;
            idx=k;
            ans = max(ans,b[0][j]+b[1][j]+b[2][j]);
        }
        cout<<ans<<"\n";
    }
}

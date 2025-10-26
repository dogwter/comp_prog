#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int fj[3][100001];
    int ans = 0;
	int n; cin>>n;
    for(int i=1;i<=n;i++){
        char c; cin>>c;
        if(c=='S')fj[0][i]++;
        else if(c=='P')fj[1][i]++; 
        else fj[2][i]++; 
        for(int j=0;j<3;j++)fj[j][i]+=fj[j][i-1];
    }
    for(int i=1;i<=n;i++){
        int temp = max(max(fj[0][i],fj[1][i]),fj[2][i]);
        if(temp==fj[0][i])temp+=max(fj[1][n]-fj[1][i],fj[2][n]-fj[2][i]);
        else if(temp==fj[1][i])temp+=max(fj[0][n]-fj[0][i],fj[2][n]-fj[2][i]);
        else temp+=max(fj[1][n]-fj[1][i],fj[0][n]-fj[0][i]);
        if(temp>ans)ans=temp;
    }
    cout<<ans<<"\n";
}

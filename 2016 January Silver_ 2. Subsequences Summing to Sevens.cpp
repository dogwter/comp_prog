#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
    long long cows[50001];
    int idx[2][7]; //the first and last occurences 
    for(int i=0;i<7;i++)idx[0][i]=-1;
    idx[0][0]=0; idx[0][1]=0;
    for(int i=1;i<=n;i++){
        cin>>cows[i];
        cows[i]+=cows[i-1];
        cows[i]%=7;
        if(idx[0][cows[i]]==-1){idx[0][cows[i]]=i; idx[1][cows[i]]=i;}
        else idx[1][cows[i]]=i;
    }
    int group = 0;
    for(int i=0;i<7;i++){
        if(idx[1][i]-idx[0][i]>group)group=idx[1][i]-idx[0][i];
    }
    cout<<group<<"\n";
}

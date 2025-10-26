#include <bits/stdc++.h>
using namespace std;

int salt[100000];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>salt[i];
        if(i>0&&salt[i-1]-salt[i]>m)salt[i]=salt[i-1]-m;
    }
    for(int i=n-1;i>0;i--){
        if(salt[i]-salt[i-1]>m)salt[i-1]=salt[i]-m;
    }
    for(int i=0;i<n;i++){
        cout<<salt[i]<<" ";
    }
}

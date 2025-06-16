#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
	int n, k; cin >> n >> k;
    int cows[101];
    int c[101];
    int l = 1;
    for(int i=1;i<=n;i++){
        cows[i]=i; c[i] = -1;
    }
    int a1,a2,b1,b2; cin>>a1>>a2>>b1>>b2;
    for(int i=a1;i<=(a1+a2)/2;i++) swap(cows[i], cows[a1+a2-i]);
    for(int i=b1;i<=(b1+b2)/2;i++) swap(cows[i], cows[b1+b2-i]);
    for(int i=1;i<=n;i++){
        if(c[i]==-1){
        int mod = 1;
        int idx = i;
        while(cows[idx]!=i){
            idx = cows[idx];
            mod++;
        }
        c[i]=mod; c[idx]=mod;
        l = lcm(l,mod);
        }
    }
    k=k%l;
    for(int i=1;i<=n;i++)cows[i]=i;
    for(int i=0;i<k;i++){
        for(int i=a1;i<=(a1+a2)/2;i++) swap(cows[i], cows[a1+a2-i]);
        for(int i=b1;i<=(b1+b2)/2;i++) swap(cows[i], cows[b1+b2-i]);
    }
    for(int i=1;i<=n;i++)cout<<cows[i]<<"\n";
}

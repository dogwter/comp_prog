#include <bits/stdc++.h>
using namespace std;

bool repay(long long n, long long k, long long m, long long x){
    long long g = 0;
    while(g<n&&k>0){
        long long cur = (n-g)/x;
        if(cur<m) return n-g<=m*k;
        long long days = min((n-cur*x-g)/cur+1,k);
        g+=cur*days;
        k-=days;
    }
    return g>=n;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    long long n, k, m; cin>>n>>k>>m;
    long long lo = 1, hi = 1e12;
    while(lo<=hi){
        if(repay(n,k,m,(lo+hi)/2))lo=(lo+hi)/2+1;
        else hi=(lo+hi)/2-1;
    }
    cout<<hi;
}
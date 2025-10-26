#include <bits/stdc++.h>
using namespace std;

long long bridge(long long n, long long l_number){ //given number of v in the loop, calculates the max # of edges
    return n + min(n-2*l_number,l_number*(l_number-1)/2-l_number);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int q; cin>>q;
    for(int i=0;i<q;i++){
        long long n; cin>>n;
        if(n<6)cout<<n-1<<"\n";
        else{
            long long lo = 2, hi = n/2;
            while(lo<=hi){
                if(bridge(n,(lo+hi)/2)<bridge(n,(lo+hi)/2+1)) lo = (lo+hi)/2+1;
                else hi = (lo+hi)/2-1; // downward slope
            }
            cout<<bridge(n,lo)<<"\n";
        }
    }
}
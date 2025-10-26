#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int n, t, k, q; cin>>n>>t>>k;
    int lo = 1, hi = n;
    int m = (lo+hi)/2;
    while(true){
        cout<<"? "<<lo<<" "<<m<<"\n";
        cout.flush();
        cin >> q;
        if(lo==m&&k==1&&q==0)break;
        q=m-lo+1-q;
        if(q>=k){ // it is in 1st half
            hi = m;
            m = (lo+hi)/2;
        } else { // it is not in 1st half
            k-=q;
            lo = m+1;
            m = (lo+hi)/2;
        }
    }
    cout<<"! "<<lo;
}
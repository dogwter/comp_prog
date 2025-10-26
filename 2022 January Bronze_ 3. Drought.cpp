#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    for(int i=0;i<t;i++){
        int n; cin>>n;
        long long bag = 0;
        long long cows[100001];
        for(int j=1;j<=n;j++) cin>>cows[j];
        for(int j=2;j<=n;j++){
            if(cows[j]<0){bag = -1; break;}
            if(cows[j]>cows[j-1]){
                bag += 2*(cows[j]-cows[j-1]);
                if(j!=n){
                    cows[j+1]-=cows[j]-cows[j-1];
                    cows[j]-=cows[j]-cows[j-1];
                } else {bag = -1; break;}
            } else if(cows[j]<cows[j-1]){
                if((j-1)%2!=0){bag = -1; break;}
                else{
                    for(int k=1;k<j;k++)bag+=cows[j-1]-cows[j];
                }
            }
        }
        cout << bag << "\n";
    }
}

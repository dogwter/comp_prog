#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
    vector<int>cows;
    for(int i=0,j;i<n;i++){
        cin>>j; cows.push_back(j);
    }
    cows[0]=0;
    n--;
    while(n>=0){
        if(cows[n]!=-1){
            for(int i = cows[n]; i>0;i--){
                if(cows[n-i]!=-1&&cows[n-i]!=cows[n]-i){
                    cout << -1;
                    return 0;
                }
                cows[n-i]=cows[n]-i;
            }
            n-=cows[n];
        } 
        n--;
    }
    int a=0,b=0;
    for(int i=0;i<cows.size();i++){
        if(cows[i]==-1)b++;
        if(cows[i]==0){
            a++;
            b++;
        }
    }
    cout<<a<<" "<<b;
}

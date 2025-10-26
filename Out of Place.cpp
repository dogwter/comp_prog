#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
    int swaps = 0;
    vector<int>cows;
    vector<int>good;
    for(int i=0,j;i<n;i++){
        cin>>j;
        cows.push_back(j);
        good.push_back(j);
    }
    sort(good.begin(),good.end());
    for(int i=0;i<n;i++){
        if(good[i]!=cows[i])swaps++;
    }
    swaps--;
    cout << swaps;
}

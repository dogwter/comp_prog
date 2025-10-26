#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    unordered_set<char>pok;
    multiset<char>p;
    vector<char>houses(n);
    for(int i=0;i<n;i++){
        cin >> houses[i];
        pok.insert(houses[i]);
    }
    int t = pok.size();
    pok.clear();
    int left =0, right =0;
    int ans =-1;

    while(left<n&&right<n){
        while(pok.size()!=t&&right<n){
            pok.insert(houses[right]);
            p.insert(houses[right]);
            right++;
        }
        while(p.upper_bound(houses[left])!=next(p.lower_bound(houses[left]))){
            p.erase(p.lower_bound(houses[left]));
            left++;
        }
        if(pok.size()==t){
            if(ans==-1)ans=right-left;
            else ans = min(right-left,ans);
        }
        pok.erase(houses[left]);
        p.erase(houses[left]);
        left++;
    }
    cout<<ans;
}

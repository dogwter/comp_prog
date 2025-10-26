// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
    cin >> n;
    map<string,int> cows;
    cows["Annabelle"]=0;
    cows["Bessie"]=0;
    cows["Elsie"]=0;
    cows["Daisy"]=0;
    cows["Gertie"]=0;
    cows["Maggie"]=0;
    cows["Henrietta"]=0;
    for(int i=0;i<n;i++){
        string name; int m;
        cin>>name>>m;
        cows[name]+=m;
    }
    priority_queue<pair<int,string>>pq;
    for(const auto&x:cows){
        pq.push({-x.second, x.first});
    }
    int big = pq.top().first; 
    string cow = pq.top().second;
    pq.pop(); 
    int second = 0;
    while(!pq.empty()){
        int check = pq.top().first;
        if(check==big && second !=1)pq.pop();
        else if(second!=1){
            second = 1; big = check; cow = pq.top().second; pq.pop();
        } else if (check==big && second == 1){
            second = 0; break;
        } else break;
    }
    if(second == 1) cout << cow+"\n";
    else cout <<"Tie\n";
}

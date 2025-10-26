#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
    set<pair<int,int>>cowx;
    set<pair<int,int>>cowy;
    for(int i=0,x,y;i<n;i++){
        cin>>x>>y;
        cowx.insert({x,y});
        cowy.insert({y,x});
    }
    long long c[4][4];
    auto a = prev(cowx.end());
    auto b = prev(cowy.end());
    auto d = cowx.begin();
    auto e = cowy.begin();
    for(int i=1;i<=4;i++){
        c[0][i-1]=a->first;
        c[1][i-1]=b->first;
        c[2][i-1]=d->first;
        c[3][i-1]=e->first;
        a--;
        b--;
        d++;
        e++;
    }
    long long area = -1;
    for(int i=0;i<4;i++){ //ux
        for(int j=0;j<4;j++){ //uy
            for(int k=0;k<4;k++){ //lx
                for(int l=0;l<4;l++){ //ly
                    set<pair<int,int>>temp;
                    for(auto x = cowx.upper_bound({c[0][i]+1,0}); x != cowx.end();x++){
                        temp.insert(*x);
                        cowy.erase(cowy.find({x->second,x->first}));
                    }
                    for(auto x = cowx.begin(); x != cowx.upper_bound({c[2][k],0});x++){
                        temp.insert(*x);
                        cowy.erase(cowy.find({x->second,x->first}));
                    }
                    for(auto x = cowy.upper_bound({c[1][j]+1,0}); x != cowy.end();x++){
                        temp.insert({x->second,x->first});
                    }
                    for(auto x = cowy.begin(); x != cowy.upper_bound({c[3][l],0});x++){
                        temp.insert({x->second,x->first});
                    }
                    if(temp.size()<=3 && (area==-1||(c[0][i]-c[2][k])*(c[1][j]-c[3][l])<area)){
                        area = (c[0][i]-c[2][k])*(c[1][j]-c[3][l]);
                    }
                    for(auto x:temp) cowy.insert({x.second,x.first});
                }
            }
        }
    }
    cout<<area;
}

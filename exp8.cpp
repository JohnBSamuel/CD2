#include<bits/stdc++.h>
using namespace std;
struct I{string l;vector<string>r;int d;};
vector<vector<I>>S;
map<pair<int,string>,int>G;
vector<pair<string,vector<string>>>P={{"S'",{"S"}},{"S",{"S","+","S"}},{"S",{"S","*","S"}},{"S",{"id"}}};
set<string>N;
bool eq(I a,I b){return a.l==b.l&&a.r==b.r&&a.d==b.d;}
bool has(vector<I>&v,I x){for(auto&i:v)if(eq(i,x))return 1;return 0;}
vector<I>clos(vector<I>C){
    bool f=1;
    while(f){
        f=0;
        for(auto&i:C)
            if(i.d<i.r.size()){
                string B=i.r[i.d];
                if(B[0]>='A'&&B[0]<='Z')
                    for(auto&p:P)if(p.first==B){
                        I x={p.first,p.second,0};
                        if(!has(C,x))C.push_back(x),f=1;
                    }
            }
    }
    return C;
}
vector<I>go(vector<I>&C,string X){
    vector<I>R;
    for(auto&i:C)
        if(i.d<i.r.size()&&i.r[i.d]==X)
            R.push_back({i.l,i.r,i.d+1});
    return clos(R);
}
int add(vector<I>C){
    for(int i=0;i<S.size();i++){
        if(S[i].size()!=C.size())continue;
        bool f=1;
        for(auto&x:C)if(!has(S[i],x))f=0;
        if(f)return i;
    }
    S.push_back(C);
    return S.size()-1;
}
int main(){
    for(auto&p:P)N.insert(p.first);
    S.push_back(clos({{P[0].first,P[0].second,0}}));
    queue<int>Q;Q.push(0);
    while(Q.size()){
        int i=Q.front();Q.pop();set<string>sy;
        for(auto&x:S[i])if(x.d<x.r.size())sy.insert(x.r[x.d]);
        for(auto&s:sy){
            auto g=go(S[i],s);
            if(!g.size())continue;
            int j=add(g);
            G[{i,s}]=j;
            if(j==S.size()-1)Q.push(j);
        }
    }
    for(int i=0;i<S.size();i++){
        cout<<"I"<<i<<":\n";
        for(auto&x:S[i]){
            cout<<x.l<<"→";
            for(int j=0;j<x.r.size();j++)
                cout<<(j==x.d?".":"")<<x.r[j]<<" ";
            if(x.d==x.r.size())cout<<".";
            cout<<"\n";
        }
        cout<<"-----\n";
    }
}

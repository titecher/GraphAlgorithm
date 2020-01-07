#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <vector>
#include <utility>
#include <string>
#include <math.h>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <string.h>
#include <stack>
#include <queue>
#include <unordered_map>
#include <boost/bimap/bimap.hpp>
#include <tuple>

using namespace std;

bool pairCompare1st(const pair<int, int> &firstElof, const pair<int, int> &secondElof)
{
    if (firstElof.first != secondElof.first){
        return firstElof.first < secondElof.first;
    }else{
        return firstElof.second < secondElof.second;
    }
}

//元リストから整序リスト
tuple <vector<pair<int,string>>,vector<pair<int, int>>> list2list(ifstream &fin){
    vector<pair<int, int>> Link;
    vector<pair<int,string>> Node;

    typedef boost::bimaps::bimap<string, int> bimap;
    bimap mp;

    string a,b;
    int i=-1;
    while (fin >> a >> b){
        if(mp.left.count(a)==0){i++;mp.insert({a,i});};
        if(mp.left.count(b)==0){i++;mp.insert({b,i});};
        Link.push_back(make_pair(mp.left.at(a),mp.left.at(b)));
        Node.push_back(make_pair(mp.left.at(a),a));
        Node.push_back(make_pair(mp.left.at(b),b));
    }

    sort(Node.begin(), Node.end());
    Node.erase(unique(Node.begin(), Node.end()), Node.end());
    
    return forward_as_tuple(Node,Link); 
}

//元隣接行列から整序リスト
tuple <vector<pair<int,string>>,vector<pair<int, int>>> matrix2list(ifstream &fin){
    vector<pair<int, int>> Link;
    vector<pair<int,string>> Node;
    
    int N,M,i=0;
    string a;
    vector<string> inp;
    while (fin >> a){
        inp.push_back(a);
        i++;
    }
    fin.close();
    //行列の縦横
    N=(-1+sqrt(1+4*i))/2;
    M=N+1;
    for(int i=0;i<N;i++){
        for(int j=1;j<M;j++){
            if(inp[M*i+j]=="1"){
                //syring naosu
                //Link.push_back(make_pair(inp[M*i],inp[M*(j-1)]));
            }
        }
    }

    return forward_as_tuple(Node,Link); 
}
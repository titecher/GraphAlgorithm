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
#include "Common.cpp"

using namespace std;

int main(int argc, char *argv[]){

    vector<pair<int, int>> Link;
    vector<pair<int,string>> Node;
    
    //Reading two-line file 
    ifstream fin(argv[2]);
    int opt;
    while ((opt = getopt(argc, argv, "lm")) != -1) {
        switch (opt) {
        case 'l':
            tie(Node, Link)=list2list(fin);
            break;
        case 'm':
            printf("まだ\n");
            //tie(Node, Link)=list2list(fin);
            break;   
        default:
            cout << "nonono" << endl;
            break;
        }
    }
    fin.close();

    for (int i = 0; i < Link.size(); i++){
    cout << Link[i].first << " " << Link[i].second << endl;
    }
    cout << "Node" << endl;
    for (int i = 0; i < Node.size(); i++){
        cout << Node[i].first << " " << Node[i].second << endl;
    }
}

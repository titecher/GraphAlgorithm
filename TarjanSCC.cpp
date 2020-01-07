#include <iostream>
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
#include "Common.cpp"

using namespace std;

vector<pair<int, int>> Link;
vector<pair<int,string>> Node;

int ind = 1;
int deep=0;
int *D;
int *low;
int *stin;
int *scc;
stack<int> tar;

void Tarjan(int root)
{
    D[root] = ind;
    low[root]= ind;
    ind++;

    vector<pair<int, int>>::iterator line_start, line_end;
    tar.push(root);
    stin[tar.top()] = 1;

    line_start = lower_bound(Link.begin(), Link.end(), make_pair(tar.top(), 0), pairCompare1st);
    line_end = lower_bound(Link.begin(), Link.end(), make_pair(tar.top() + 1, 0), pairCompare1st);
    for (int i = line_start - Link.begin(); i < line_end - Link.begin(); i++)
    {
        if (D[Link[i].second] < 1){
            Tarjan(Link[i].second);
            low[root] = min(low[root], low[Link[i].second]);
        }
        else if (stin[Link[i].second] == 1){
            low[root] = min(low[root], D[Link[i].second]);
        }
    }

    if (low[root] == D[root])
    {
        deep++;
        while (D[tar.top()] >= D[root]){
            scc[tar.top()] = deep;
            stin[tar.top()] = 0;
            cout << tar.top() << "d" << deep << endl;
            if(D[tar.top()] > D[root]){
                tar.pop();
            }else{
                if(tar.top()==root){
                    tar.pop();
                }
                break;
            }
        }
    }
}

int main(int argc, char *argv[]){
    //Start DFS from this Node.
 
    ifstream fin(argv[1]);
    tie(Node, Link)=list2list(fin);
    fin.close();

    D = new int[Node.size()]();
    low = new int[Node.size()]();
    stin = new int[Node.size()]();
    scc = new int[Node.size()]();
    for(auto i:Node){
        if(D[i.first]==0){
            cout << i.first << endl;
            Tarjan(i.first);
        }
    }
    //出力の数値を制御する


    delete [] D;
    delete [] low;
    delete [] stin;
    delete [] scc;
}

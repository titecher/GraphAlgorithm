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

using namespace std;

vector<pair<int, int>> Link;
vector<int> Node;

bool pairCompare1st(const pair<int, int> &firstElof, const pair<int, int> &secondElof)
{
    if (firstElof.first != secondElof.first){
        return firstElof.first < secondElof.first;
    }else{
        return firstElof.second < secondElof.second;
    }
}
/////
/////
/////このしたバグ
/////ノード番号に1000があっても
/////size分しか確保されない。

int ind = 1;
int deep=0;
int *D = new int[Node.size()]();
int *low = new int[Node.size()]();
int *stin = new int[Node.size()]();
int *scc = new int[Node.size()]();
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
    cout << line_start - Link.begin() << " " << line_end - Link.begin() <<endl;
    for (int i = line_start - Link.begin(); i < line_end - Link.begin(); i++)
    {
        if (D[Link[i].second] < 1){
            cout << Link[i].first << " " << Link[i].second << endl;
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
            cout << tar.top() << " " << D[tar.top()] << "a" << D[root] <<" " << root << endl;
            scc[tar.top()] = deep;
            stin[tar.top()] = 0;
            cout << tar.top() << "d" << deep << endl;
            if(D[tar.top()] > D[root]){
                cout << tar.top() <<" 1popsuru"<< endl;
                tar.pop();
            }else{
                if(tar.top()==root){
                    cout << tar.top() <<" 2popsuru"<< endl;
                    tar.pop();
                }
                break;
            }
        }
        cout << "aaa" << endl;
    }
}

int main(int argc, char *argv[]){
    //Start DFS from this Node.
    int RootNode=atoi(argv[1]);

    //Reading two-line file 
    FILE *fpr = fopen(argv[2], "r" );
    int a,b;
    while(fscanf(fpr, "%d %d", &a, &b) != EOF) {
        Link.push_back(make_pair(a,b));
	}
    fclose(fpr);

    //Define node list
    for (int i = 0; i < Link.size(); i++)
    {
        Node.push_back(Link[i].first);
        Node.push_back(Link[i].second);
    }
    sort(Node.begin(), Node.end());
    Node.erase(unique(Node.begin(), Node.end()), Node.end());
    //Node is a sorted list of the numbered nodes 

    // for(int i:Node){
    //     cout << i << endl;
    // }
    Tarjan(RootNode);

    cout << "sss" << endl;

    delete [] D;
    delete [] low;
    delete [] stin;
    delete [] scc;
    cout << "sss" << endl;
}

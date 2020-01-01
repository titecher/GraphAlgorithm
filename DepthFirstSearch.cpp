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

void DFS(int root){
    int cnt=0;
    vector<pair<int, int>>::iterator line_start, line_end;

    int *Visited = new int[Node.size()]();
    stack<int> dstack;
    dstack.push(root);
    Visited[root] = 1;
    while (dstack.size() > 0)
    {
        cout << dstack.top() << " " << cnt << endl;
        cnt++;
        line_start = lower_bound(Link.begin(), Link.end(), make_pair(dstack.top(), 0), pairCompare1st);
        line_end = lower_bound(Link.begin(), Link.end(), make_pair(dstack.top() + 1, 0), pairCompare1st);
        dstack.pop();
        for (int i = line_start - Link.begin(); i < line_end - Link.begin(); i++)
        {
            if (Visited[Link[i].second] == 0){
                dstack.push(Link[i].second);
                Visited[Link[i].second] = 1;
            }
        }
    }
}

int main(int argc, char *argv[])
{
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

    DFS(RootNode);
}

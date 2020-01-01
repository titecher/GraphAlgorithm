Basic tools for Network Analysis # Not Completed.
===================

Prepared C++ scripts and Executable files for analysing the network data. 
Currently, the files are under construction and listed separatedly.
The following algorithms will be implemented and summerized into a library. 

# Description
Data of the relation is usually described as a pair of components.
This type of data whose relation between the components is nature is categorized into network(graph).
To analyze the network data, we need some tricky algorithms to obtain feature values.
This repo provides you scripts for basic calculation tools of Network Analysis.

# Algorithm and Methods
All scripts are in C++
## Graph Algorithm
    Edge List ⇔ Adjacency Matrix
    DepthFirstSearch
    BreadthFirstSearch
    Node-Node Distance 
    Strongly Connected Component
    
## Basic feature value
    Nodes' Degree
    Degree-Degree Correlation
    
## Advanced calculation on a network.
    Centrality
    Community Detection

# Requirement
  C++ Compiler
  CUI environment (reccomended)

# Usage
In CUI, clone this repo.
```
git clone https://github.com/titecher/GraphAlgorithm/
```
For example, if you apply depth first search algorithm to your network file, [filename] with numbered nodes in edge-list format.
'Depth' command with [start node No.] and [input filename] sorts the list and returns the order of visited nodes.
```
Depth [start node No.] [filename]
```



You can build the source.  
```
g++ -std=gnu++11 -lm -o Depth DepthFirstSearch.cpp
```

# Author
titecher

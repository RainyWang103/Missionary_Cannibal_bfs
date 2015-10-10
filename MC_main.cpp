//
//  MC_main.cpp
//  2.Missionary Cannibal
//
//  Created by WangYuli on 10/10/2015.
//  Copyright © 2015 WangYuli. All rights reserved.
//

#include <iostream>
#include "MC_Functions.h"
#include <map>
#include <queue>
using namespace std;

void bfs_missionary_cannibal (Lbank root, Lbank goal, Lbank end)
{
    map<Lbank, Lbank> memory; //key: the actual state; value: the parent of it; root's parent is end
    queue<Lbank> myQueue;
    bool goalReached = false;
    int finaldepth = 0;
    
    memory[root] = end;
    myQueue.push(root);
    if(root == goal) goalReached = true;
    bfs_MC_expand(root, goal, goalReached, finaldepth, memory, myQueue);
    while(!goalReached && !myQueue.empty())
    {
        Lbank toExpand = myQueue.front(); myQueue.pop();
        bfs_MC_expand(toExpand, goal, goalReached, finaldepth, memory, myQueue);
    }
    
    if(goalReached){
        cout<<"success!"<<endl;
        map<Lbank,Lbank>::iterator it = memory.begin();
        while(!(it->first == goal)) it++;
        if(it!=memory.end())
            PrintSolution(root, goal, memory, finaldepth);
    }
    
    else {
        cout<<endl<<"OOPS!!!FAIL!!!!!"<<endl;
    }
    
}



int main() {
    int rootState[3]={3,3,1};
    int goalState[3]={0,0,0};
    int endState[3] ={-1,-1,-1};
    Lbank root(rootState); root.SetDepth(0);
    Lbank end(endState); end.SetDepth(-1);
    Lbank goal(goalState);
    bfs_missionary_cannibal(root, goal, end);
    return 0;
}

//
//  MC_Functions.h
//  2.Missionary Cannibal
//
//  Created by WangYuli on 10/10/2015.
//  Copyright © 2015 WangYuli. All rights reserved.
//

#ifndef MC_Functions_h
#define MC_Functions_h
#include "MC_Successor.h"
#include <map>
#include <queue>
using namespace std;

void PrintLbank(Lbank target) {
    for(int i=0; i<STATE_SIZE; i++){
        cout<<target.GetState(i)<<",";
    }
    cout<<"depth="<<target.GetDepth();
}

void bfs_MC_expand(const Lbank& parent,                         //Helper for BFS_search()
                   Lbank& goal,
                   bool& finish,           //The finish flag, updated when child reach goal
                   int& goalDepth,         //The resulting moves, updated when child reach goal
                   map<Lbank, Lbank>& memory,    //The memory to check for duplication
                   queue<Lbank>& myQueue)
{
    MC_Successor next(parent);
    for(int i=0; i<NUM_OF_NEXT; i++)
        if(next.IsValid(i))
        {
            Lbank toBeCheck = next.GetLbank(i);
            if(toBeCheck == goal) {
                finish = true;
                goalDepth = toBeCheck.GetDepth();
                goal.SetDepth(goalDepth);
                memory[toBeCheck] = parent;
                return;
            }
            
            else if (memory.count(toBeCheck)==0) {
//                cout<<"Add to Memory & Queue------------"<<endl;
//                PrintLbank(toBeCheck); cout<<endl;
//                cout<<"Child of-------------------------"<<endl;
//                PrintLbank(parent); cout<<endl;
                
                myQueue.push(toBeCheck);
                memory[toBeCheck]=parent;
            }
            
        }
    
}

void PrintSolution(Lbank root, Lbank target, map<Lbank,Lbank> memory, int step)
{
    map<Lbank,Lbank>::iterator it = memory.find(target);
    if(it->first == root){
        cout<<"***********************************************"<<endl;
        cout<<"********* From "; PrintLbank(it->first); cout<<" To Start *********"<<endl;
        cout<<"***********************************************"<<endl<<endl;
        return;
    }
    else {
        PrintSolution(root, it->second,memory,step-1);
        cout<<"Step "<<step<<": From "; PrintLbank(it->second);
        cout<<" To "; PrintLbank(it->first); cout<<endl;
        cout<<endl;
    }
}



#endif /* MC_Functions_h */

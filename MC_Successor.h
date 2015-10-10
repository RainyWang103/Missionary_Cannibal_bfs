//
//  Successor.h
//  2.Missionary Cannibal
//
//  Created by WangYuli on 10/10/2015.
//  Copyright © 2015 WangYuli. All rights reserved.
//

#ifndef Successor_h
#define Successor_h
#include "MC_LBank.h"
#include "MC_Move.h"
class MC_Successor
{
private:
    Move option[5]; // 5 kinds of moves
    Lbank potential[5];
    Lbank parent;
    void Move_boat_to_right(); //helper function for constructor
    void Move_boat_to_left();  //helper function for constructor
public:
    MC_Successor (const Lbank& prev);    //constructor, make the 5 potential children
    bool IsValid(const int& index);            //check if children x is valid
    Lbank GetLbank(const int& index);          //return the children
};

MC_Successor::MC_Successor(const Lbank& prev) {
    parent = prev;
    option[0]=Move(0,1); option[1]=Move(1,0); option[2]=Move(1,1); option[3]=Move(2,0); option[4]=Move(0,2);
    if(parent.GetState(2)==1) Move_boat_to_right();    //if boat on left, move to right
    else if (parent.GetState(2)==0)Move_boat_to_left();//if boat on right, move to left
}

void MC_Successor::Move_boat_to_right() {
    for(int i=0; i<NUM_OF_NEXT; i++) {
        potential[i].SetState(0, parent.GetState(0)-option[i].num_m); //move missionary to right
        potential[i].SetState(1, parent.GetState(1)-option[i].num_c); //move cannibal to right
        potential[i].SetState(2, 0);                                  //move boat to right
        potential[i].SetDepth(parent.GetDepth()+1); //set depth
        potential[i].Validation();                  //set valid
    }
}

void MC_Successor::Move_boat_to_left() {
    for(int i=0; i<NUM_OF_NEXT; i++) {
        potential[i].SetState(0, parent.GetState(0)+option[i].num_m); //move missionary to left
        potential[i].SetState(1, parent.GetState(1)+option[i].num_c); //move cannibal to left
        potential[i].SetState(2, 1);                                  //move boat to left
        potential[i].SetDepth(parent.GetDepth()+1); //set depth
        potential[i].Validation();                  //set valid
    }
}
bool MC_Successor::IsValid(const int &index){return potential[index].GetValid();}
Lbank MC_Successor::GetLbank(const int &index){return potential[index];}


#endif /* Successor_h */

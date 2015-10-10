//
//  MC_Move.h
//  2.Missionary Cannibal
//
//  Created by WangYuli on 10/10/2015.
//  Copyright © 2015 WangYuli. All rights reserved.
//

#ifndef MC_Move_h
#define MC_Move_h
struct Move
{
    int num_m; //number of missionary
    int num_c; //number of cannibals
    
    Move(){}
    Move(int x, int y) {
        num_m = x; num_c = y;
    }
};

#endif /* MC_Move_h */

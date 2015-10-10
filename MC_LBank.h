//
//  MC_Node.h
//  2.Missionary Cannibal
//
//  Created by WangYuli on 10/10/2015.
//  Copyright © 2015 WangYuli. All rights reserved.
//

#ifndef MC_Node_h
#define MC_Node_h
#define STATE_SIZE 3
#define NUM_OF_NEXT 5
#define NUM_OF_MC 3

class Lbank     // structure for states stored, indicates left bank status
{
private:int state[3];   //Set by constructor
        int depth;      //Set by SetDepth
        bool valid;     //Set by Validation, constructor
        bool Isvalid(); //helper function
public:
    Lbank();                  //Default constructor
    Lbank(const int input[]); //construct state and check for valid automatically
    void Validation();
    void SetDepth(const int& x);
    void SetState(const int& index, const int& value);
    bool GetValid();
    int GetDepth();
    int GetState(const int& index);
    void operator=(const Lbank& input);
    friend bool operator<(const Lbank& a, const Lbank& b);
    friend bool operator==(const Lbank& a, const Lbank& b);
};

Lbank::Lbank() {valid = false;}

Lbank::Lbank(const int input[]) {
    for(int i=0;i<STATE_SIZE; i++) state[i]=input[i];
    valid = (Isvalid())? true:false;
    //visited =
}

bool Lbank::Isvalid() {
    if(state[0]>=0&&state[0]<=NUM_OF_MC &&                          // # of missionary within range
       state[1]>=0&&state[1]<=NUM_OF_MC &&                          // # of cannibal within range
       (state[0]==state[1] || state[0]==NUM_OF_MC || state[0]==0))  // not dead
        return true;
    return false;
}

void Lbank::Validation(){valid = (Isvalid())? true:false;}
void Lbank::SetDepth(const int& x) {depth = x;}
void Lbank::SetState(const int &index, const int &value){state[index] = value;}
bool Lbank::GetValid(){return valid;}
int Lbank::GetDepth(){return depth;}
int Lbank::GetState(const int& index){return state[index];}

void Lbank::operator=(const Lbank& input) {
    for(int i=0;i<STATE_SIZE; i++) state[i]=input.state[i];
    depth = input.depth;
    valid = input.valid;
}

bool operator<(const Lbank& a, const Lbank& b) {
    for(int i=0; i<STATE_SIZE; i++) {
        if(a.state[i]<b.state[i]) return true;
        else if (a.state[i]>b.state[i]) return false;
    }
    return false;
}

bool operator==(const Lbank& a, const Lbank& b) {
    for(int i=0; i<STATE_SIZE; i++)
        if(a.state[i]!=b.state[i]) return false;
    return true;
}



#endif /* MC_Node_h */

#pragma once

#include <vector>


///my addings
#include "SelectionPolicy.h"

class SelectionPolicy;
class Simulation;

class Agent
{

  

public:
    //constructor
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);

    ///copy constructor:
    Agent(const Agent &other);
    
    /// move constructor
    Agent(Agent &&other); 

    ///copy Assigment Operator
    Agent& operator=(const Agent &other); 

    ///move Assigment Operator
    Agent& operator=(Agent &&other);

    ///destructor
    ~Agent();


    
    ///functions
    int getPartyId() const;
    int getId() const;
    void step(Simulation &s);
    const int getAgentCoalition() const;
    void setAgentCoalition(int x) ;
    const SelectionPolicy *getSelectionPolicy() const;
    void setAgentId(int _Agentid);
    void setPartyId(int _Partyid);
    
    

private:
 
///fields:
int mAgentId;
int mPartyId;
SelectionPolicy* mSelectionPolicy;
int Agentcoalition;  

};

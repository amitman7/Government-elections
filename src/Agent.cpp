#include "Agent.h"
#include "Simulation.h"
#include "Graph.h"
#include <iostream>
using std::cout;
#include <string>

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy), Agentcoalition(agentId)
{
}

///copy constructor
Agent::Agent(const Agent &other):mAgentId(other.mAgentId), mPartyId(other.mPartyId),mSelectionPolicy(0) , Agentcoalition(other.Agentcoalition){
    SelectionPolicy *Sp;
    
    if (other.getSelectionPolicy()->getType() =='E'){
        Sp = new EdgeWeightSelectionPolicy;
    }
    else{
        Sp = new MandatesSelectionPolicy;
    }
    mSelectionPolicy = Sp;

}

///copy Assigment Operator
Agent& Agent::operator=(const Agent &other){
    
    if(this != &other){
        mAgentId = other.mAgentId;
        mPartyId = other.mPartyId;

        SelectionPolicy *Sp;
        if (other.getSelectionPolicy()->getType()=='E'){
            Sp = new EdgeWeightSelectionPolicy;
        }
        else{
            Sp = new MandatesSelectionPolicy;
        }

        mSelectionPolicy = Sp;
        Agentcoalition = other.Agentcoalition;
    }
    
    return *this;
}

/// move constructor
Agent::Agent(Agent &&other) : mAgentId(other.mAgentId),mPartyId(other.mPartyId) , mSelectionPolicy(other.mSelectionPolicy), Agentcoalition(other.Agentcoalition){
    if (this != &other){ 
        other.mSelectionPolicy = nullptr;

    }

}

/// move Assigment Operator
Agent& Agent::operator=(Agent &&other) {
    
    if(this != &other){
        mAgentId = other.getId();
        mPartyId = other.getPartyId();
    

        if (mSelectionPolicy){
            delete mSelectionPolicy ;
        } 
    
        mSelectionPolicy = other.mSelectionPolicy;
        other.mSelectionPolicy = nullptr;
        Agentcoalition = other.Agentcoalition;

    }
    

    return *this;
}

//destructor
Agent::~Agent(){
    if (mSelectionPolicy) delete mSelectionPolicy;
}


int Agent::getId() const
{
    return mAgentId;
    
}

int Agent::getPartyId() const
{
    return mPartyId;
}

void Agent::step(Simulation &sim)
{
    vector<int> neighbors = sim.getGraph().getneighbors(this->getPartyId());
    
    int size = neighbors.size();
    neighbors.resize(size);

    for(int i = 0; i < size;i++){
        /// erasing parties that cannot be invite to the coalition.
         
        if((sim.getGraph().getParty(neighbors[i]).getPartyCoalition() == this->getAgentCoalition()) | (sim.getGraph().getParty(neighbors[i]).getState() == 2) | (sim.coalitionInv[sim.getGraphNonConst().getPartyNonConst(neighbors[i]).getPartyId()][this->getAgentCoalition()] == 1)){
            neighbors[i] = -1; 
            
        }
    }

    vector<int> updatedNeighbors;
    for(int i = 0; i<size; i++){
        if(neighbors[i] != -1){
            updatedNeighbors.push_back(neighbors[i]);
        }
    }

  
    
    /// using selectionPolicy and invite party to the coalition
    if (updatedNeighbors.size() > 0){
        this->mSelectionPolicy->choose(updatedNeighbors, this->getId(), this->getPartyId(), sim);

    }
    

}

void Agent::setAgentId(int _Agentid){
    this->mAgentId = _Agentid;
}

void Agent::setPartyId(int _Partyid){
    this->mPartyId = _Partyid;
}



void Agent:: setAgentCoalition(int x){
    this->Agentcoalition = x;
}


const int Agent::getAgentCoalition() const{
    return this->Agentcoalition;
}


const SelectionPolicy* Agent:: getSelectionPolicy() const{
    return mSelectionPolicy;
    

}

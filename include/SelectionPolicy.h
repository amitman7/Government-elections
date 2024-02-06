#pragma once

#include <vector>
#include <string>
using std::vector;
class Simulation;

class SelectionPolicy {
public:
    virtual ~SelectionPolicy(){}
    virtual void choose(vector<int> &x, int AgentId, int AgentPartyId, Simulation &s) = 0;
    virtual const char getType() const= 0;

};

class MandatesSelectionPolicy: public SelectionPolicy{
    virtual ~MandatesSelectionPolicy(){}
    virtual void choose(vector<int> &x, int AgentId, int AgentPartyId, Simulation &s);
    virtual const char getType() const;


};

class EdgeWeightSelectionPolicy: public SelectionPolicy{
    virtual ~EdgeWeightSelectionPolicy(){}
    virtual void choose(vector<int> &x, int AgentId, int AgentPartyId, Simulation &s);
    virtual const char getType() const;


};


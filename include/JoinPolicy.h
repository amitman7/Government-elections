#pragma once
#include <vector>
#include "Simulation.h"
#include <string>
using std::vector;
class Simulation;

class JoinPolicy {
public:
    virtual void Join(vector<int> invitations,int PartyId,Simulation &s) = 0;
    virtual ~JoinPolicy(){}
    virtual const char getType() const=0;
};

class MandatesJoinPolicy : public JoinPolicy {
    virtual void Join(vector<int> invitations,int PartyId,Simulation &s);
    virtual ~MandatesJoinPolicy(){}
    virtual const char getType() const;
};

class LastOfferJoinPolicy : public JoinPolicy {
    virtual void Join(vector<int> invitations,int PartyId,Simulation &s);
    virtual ~LastOfferJoinPolicy(){}
    virtual const char getType() const;
};



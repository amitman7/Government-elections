#pragma once
#include <string>
#include <vector>


using std::string;
using std::vector;
class JoinPolicy;
class Simulation;


enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
    //constructor
    Party(int id, string name, int mandates, JoinPolicy *); 
    //copy constructor
    Party(const Party &other);
    /// move constructor
    Party(Party &&other); 

    ///copy Assigment Operator
    Party& operator=(const Party &other); 

    ///move Assigment Operator
    Party& operator=(Party &&other);

    ///destructor
    ~Party();


    //methods
    State getState() const;
    void setState(State state);
    int getMandates() const;
    void step(Simulation &s);
    const string &getName() const;
    void setPartyCoalition(int coalition);
    void setPartyinvitations(vector<int> PartyInv);
    vector<int> &getPartyinvitations();
    const int getPartyCoalition() const;
    int getPartyId();
    int getPartyCoalition();
    //testL
    const JoinPolicy *getJoinPolicy() const;
    
    


private:
    //fields
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    int iter;
    vector<int> Partyinvitations;
    int Partycoalition;
};

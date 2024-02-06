#include "Party.h"
#include "JoinPolicy.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;

//constructor
Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting) , iter(0),Partyinvitations(0),Partycoalition(-1)
{

}

//copy constructor
Party::Party(const Party &other) : mId(other.mId), mName(other.getName()), mMandates(other.getMandates()), mJoinPolicy(other.mJoinPolicy), mState(other.getState()), iter(0),Partyinvitations(0),Partycoalition(-1)
{
    
    JoinPolicy *jp;
    if (other.getJoinPolicy()->getType() == 'M'){
        jp = new MandatesJoinPolicy;
    }
    else{
        jp = new LastOfferJoinPolicy;
    }
    mJoinPolicy = jp;

}


///copy Assigment Operator
Party&  Party::operator=(const Party &other){
    
    if(this != &other){
        mId = other.mId;
        mName = other.mName;
        mMandates = other.mMandates;
        
        mState= other.mState;
        iter = other.iter;
        Partyinvitations = other.Partyinvitations;
        Partycoalition = other.Partycoalition;

    }

    JoinPolicy *jp;
    if (other.getJoinPolicy()->getType() == 'M'){
        jp = new MandatesJoinPolicy;
    }
    else{
        jp = new LastOfferJoinPolicy;
    }
    mJoinPolicy = jp;
    
    return *this;
}

/// move constructor
Party::Party(Party &&other): mId (other.mId), mName(other.mName), mMandates(other.mMandates),mJoinPolicy(other.mJoinPolicy),mState(other.mState),iter(other.iter),Partyinvitations(other.Partyinvitations),Partycoalition(other.Partycoalition)
{
   other.mJoinPolicy = nullptr;
}


/// move Assigment Operator
Party& Party::operator=(Party &&other) {
    if (mJoinPolicy){
            delete mJoinPolicy ;
        } 
   mId = other.mId; 
   mName = other.mName;
   mMandates = other.mMandates;
   mJoinPolicy = other.mJoinPolicy; 
   mState = other.mState;
   iter= other.iter; 
   Partyinvitations= other.Partyinvitations;
   Partycoalition = other.Partycoalition;

   other.mJoinPolicy = nullptr;    


    return *this;
}

//destructor
Party::~Party(){
    if (mJoinPolicy) delete mJoinPolicy;
}

State Party::getState() const
{
    return mState;
}

void Party::setState(State state)
{
    mState = state;
}

int Party::getMandates() const
{
    return mMandates;
}

const JoinPolicy * Party::getJoinPolicy() const{
    return mJoinPolicy;
}
const string & Party::getName() const
{
    return mName;
}

int Party::getPartyId(){
    return mId;
}
void Party::setPartyinvitations(vector<int> PartyInv){
    Partyinvitations = PartyInv;
}
vector<int> &Party::getPartyinvitations(){
    return Partyinvitations;
}
void Party::step(Simulation &s)
{
    
    if (this->getState() == CollectingOffers) {
            
        this->iter++;

        if (this->iter == 3){
            this->mJoinPolicy->Join(Partyinvitations,this->getPartyId(),s);
        }
    }
        

     
        

}




 int Party::getPartyCoalition(){
    return this->Partycoalition;
 }


void Party::setPartyCoalition(int coalition){
    this->Partycoalition = coalition;
}

const int Party::getPartyCoalition() const{
    return Partycoalition;
}








///void Party::reciveInvitation(int partyId){
 ///   this->Partyinvitations.push_back(partyId);
///}

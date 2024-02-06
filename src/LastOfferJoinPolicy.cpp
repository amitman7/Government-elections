
#include "JoinPolicy.h"
#include "Simulation.h"
#include "Agent.h"
#include <iostream>
using std::cout;
#include <string>

void LastOfferJoinPolicy::Join(vector<int> invitations,int PartyId, Simulation &s){

    int invitingAgentId = invitations[invitations.size() - 1];
    s.getmCoalition()[s.getAgents()[invitingAgentId].getAgentCoalition()].push_back(PartyId); ///adding the party to mCoalition vector
    s.getGraphNonConst().getPartyNonConst(PartyId).setPartyCoalition(s.getAgents()[invitations[invitations.size() - 1]].getAgentCoalition()); /// setting the partyCoalition for the party
    s.coalitionMandates[s.getAgents()[invitingAgentId].getAgentCoalition()] +=  s.getGraphNonConst().getPartyNonConst(PartyId).getMandates(); /// adding the party mandates to its new coalition
    s.getGraphNonConst().getPartyNonConst(PartyId).setState(Joined); //chanching the state of the party

    

    ///cloning the inv agent to the mAgents vector:
    Agent clone = Agent(s.getAgents()[invitingAgentId]);
    clone.setAgentId(s.getAgents().size());
    clone.setPartyId(PartyId);
    s.getAgentsNonConst().push_back(clone);




}
const char LastOfferJoinPolicy::getType() const{
    return 'L';
}





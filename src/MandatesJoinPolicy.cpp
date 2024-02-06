#include "JoinPolicy.h"
#include "Simulation.h"
#include "Agent.h"
#include <iostream>
using std::cout;
#include <string>

    void MandatesJoinPolicy::Join(vector<int> invitations,int PartyId,Simulation &s) {
    Graph graph =  s.getGraph();
    int max = 0;
    int currWinner = 0;
    int x = invitations.size();
    for (int i = 0; i < x ; i++) {
        int temp = s.coalitionMandates[s.getAgents()[invitations[i]].getAgentCoalition()];//needs to change to the whole coalition mandates
        if (temp > max){
                    max = temp;
                    currWinner = invitations[i];
            }
    }
    int invitingAgentId = currWinner;
    s.getmCoalition()[s.getAgents()[currWinner].getAgentCoalition()].push_back(PartyId); //pushing the party to mCoalition
    graph.getPartyNonConst(PartyId).setPartyCoalition(s.getGraph().getParty(currWinner).getPartyCoalition()); //setting the party coalition
    s.getGraphNonConst().getPartyNonConst(PartyId).setState(Joined); //chanching the state of the party

   
    ///cloning the inv agent to the mAgents vector:
    Agent clone = Agent(s.getAgents()[invitingAgentId]);
    clone.setAgentId(s.getAgents().size());
    clone.setPartyId(PartyId);
    s.getAgentsNonConst().push_back(clone);
    s.coalitionMandates[s.getAgents()[invitingAgentId].getAgentCoalition()] +=  s.getGraphNonConst().getPartyNonConst(PartyId).getMandates(); /// adding the party mandates to its new coalition


}

const char MandatesJoinPolicy::getType() const{
    return 'M';
}




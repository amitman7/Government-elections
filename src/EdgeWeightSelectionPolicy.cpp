//
// Created by spl211 on 11/16/22.
//

#include "SelectionPolicy.h"
#include "Agent.h"
#include "Simulation.h"
#include <iostream>
using std::cout;
#include <string>

void EdgeWeightSelectionPolicy::choose(vector<int> &neighbors,int AgentId, int AgentPartyId, Simulation &s){
    int max= 0;
    int currWinner = 0;
    int x = neighbors.size();

    for(int i=0; i < x;i++){
        int temp = s.getGraph().getEdgeWeight(AgentPartyId, neighbors[i]);
        if  (temp > max) {
            max = temp;
            currWinner = neighbors[i];
        }
    }

    s.getGraphNonConst().getPartyNonConst(currWinner).getPartyinvitations().push_back(AgentId); ///adding the invitations to the partyinvitations array for the choosen party
    s.getGraphNonConst().getPartyNonConst(currWinner).setState(CollectingOffers); //changing the party status to "collecting offers"
    s.coalitionInv[currWinner][s.getAgents()[AgentId].getAgentCoalition()] = 1;

   

}
 const char EdgeWeightSelectionPolicy::getType() const{
    return 'E';
 }




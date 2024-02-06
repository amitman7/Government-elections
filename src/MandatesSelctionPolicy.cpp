//
// Created by spl211 on 11/16/22.
//

#include "SelectionPolicy.h"
#include "Agent.h"
#include "Simulation.h"
#include <iostream>
using std::cout;
#include <string>

void MandatesSelectionPolicy::choose(vector<int> &neighbors,int AgentId, int AgentPartyId, Simulation &s){
    int max= 0;
    int currWinner = 0;
    int x = neighbors.size();
    

    for(int i=0; i < x;i++){
        int temp = (s.getGraph().getParty(neighbors[i])).getMandates();
        if (temp == max){
             if(s.getGraphNonConst().getPartyNonConst(neighbors[i]).getPartyId() < s.getGraphNonConst().getPartyNonConst(currWinner).getPartyId() ){
                currWinner = neighbors[i];
             }
        }

        if  (temp > max) {
            max = temp;
            currWinner = neighbors[i];
        }
        

       
    }

    s.getGraphNonConst().getPartyNonConst(currWinner).getPartyinvitations().push_back(AgentId);
    s.getGraphNonConst().getPartyNonConst(currWinner).setState(CollectingOffers); //changing the party status to "collecting offers"
    s.coalitionInv[currWinner][s.getAgents()[AgentId].getAgentCoalition()] = 1; //setting the invitation in coalitionInv 

}

const char MandatesSelectionPolicy::getType() const{
    return 'M';
 }




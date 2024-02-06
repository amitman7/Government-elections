#include "Simulation.h"
#include <iostream>
using std::cout;
#include <string>

Simulation::Simulation(Graph graph, vector<Agent> agents) : coalitionInv(0),coalitionMandates(0),mGraph(graph),mAgents(agents),mCoalition(0)
{
    
    //creating "coalition inv" vector ----------------------
    vector<vector<int>> temp2;
    int x = agents.size();
   
    for(int i =0; i < graph.getNumVertices(); i++){
        vector<int> temp;
        for(int j = 0; j< x; j++){
            temp.push_back(0);
          
        }

        temp2.push_back(temp);

    }
    coalitionInv = temp2;

    //setting "Joined" status to all the parties with agents at the beggining ------------------------
    for(int i = 0; i< x; i++){ 
        getGraphNonConst().getPartyNonConst(agents[i].getPartyId()).setState(Joined);
    }

    //setting "coalitionMandates" vector --------------------------------------------------------------
    int coalitionSize = agents.size();
    coalitionMandates.resize(coalitionSize);
    int y = coalitionMandates.size();
    for(int i=0; i< y; i++){
        coalitionMandates[i] = graph.getParty(agents[i].getPartyId()).getMandates();
    }

    //initializing of "mCoalition" and setting parties coalitionsId's --------------------------------------------------------
    vector<vector<int>> coalitionsVector; ///temp vector to be build for mCoalition

    int z = mAgents.size();
    for(int i = 0; i < z;i++){

        /// setting each Agent and Party its coalition id
        Party currParty = mGraph.getVerticesConst()[mAgents[i].getPartyId()];
        currParty.setPartyCoalition(i);
        ///-------------------------------------------------


        /// making of mCoalition
        vector<int> currCoalition;
        currCoalition.push_back(mAgents[i].getPartyId());
        coalitionsVector.push_back(currCoalition);

    }

    mCoalition = coalitionsVector;
}

void Simulation::step()
{
    for(int i = 0; i < mGraph.getNumVertices(); i++){
        mGraph.getPartyNonConst(i).step(*this);
    }
    int x = mAgents.size();

    for(int i = 0; i < x; i++){
        mAgents[i].step(*this);
    }
}

bool Simulation::shouldTerminate() const
{
   
    bool CoalitionFound = false;
    int x = coalitionMandates.size();
    for(int i = 0; (i < x )& (!CoalitionFound); i++){ ///checking each coalition
        if (coalitionMandates[i] >= 61){
                CoalitionFound = true;
                
        }

    }

    /// checking if all the parties joined to a collation but none of the collations have a majority.
    vector<Party> parties = mGraph.getVerticesConst();
    bool joined = true;
    int y = parties.size();
    for(int i = 0; (i < y) & (joined);i++){
        if (parties[i].getState() != Joined){
            joined = false;
        }
    }

    return (CoalitionFound | joined);
}

const Graph &Simulation::getGraph() const
{
    return mGraph;
}

Graph &Simulation::getGraphNonConst(){
    return mGraph;
}

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}


vector<Agent> &Simulation::getAgentsNonConst(){
    return mAgents;

}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}


/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    
    return mCoalition;
}


vector<vector<int>> &Simulation::getmCoalition(){
    return this->mCoalition;
}


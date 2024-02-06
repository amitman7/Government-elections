#pragma once

#include <vector>

#include "Graph.h"
#include "Agent.h"

using std::string;
using std::vector;


class Simulation
{
public:
    Simulation(Graph g, vector<Agent> agents);
    void step();
    bool shouldTerminate() const;

    const Graph &getGraph() const;
    Graph &getGraphNonConst();
    const vector<Agent> &getAgents() const;
    vector<Agent> &getAgentsNonConst();
    const Party &getParty(int partyId) const;
    const vector<vector<int>> getPartiesByCoalitions() const;
    vector<vector<int>> &getmCoalition();

    vector<vector<int>> coalitionInv;
    vector<int> coalitionMandates;

private:
    Graph mGraph;
    vector<Agent> mAgents;
    vector<vector<int>> mCoalition;
};

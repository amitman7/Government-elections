#pragma once
#include <vector>
#include "Party.h"

using std::vector;


class Graph
{
public:

    ///functions
    Graph(vector<Party> vertices, vector<vector<int>> edges);
    int getMandates(int partyId) const;
    int getEdgeWeight(int v1, int v2) const;
    int getNumVertices() const;
    const Party &getParty(int partyId) const;
    Party &getPartyNonConst(int partyId); ///function to get party and change it values (not const)
    const vector<Party> getVertices ();
    const vector<Party> getVerticesConst () const;
    const vector<int> getneighbors(int partyId) const;

    ~Graph();

private:

    vector<Party> mVertices;
    vector<vector<int>> mEdges;
};

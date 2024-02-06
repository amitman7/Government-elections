#include "Graph.h"
#include <iostream>
using std::cout;


Graph::Graph(vector<Party> vertices, vector<vector<int>> edges) : mVertices(vertices), mEdges(edges) 
{
    // You can change the implementation of the constructor, but not the signature!
}

int Graph::getMandates(int partyId) const
{
    return mVertices[partyId].getMandates();
}

int Graph::getEdgeWeight(int v1, int v2) const
{
    return mEdges[v1][v2];
}

int Graph::getNumVertices() const
{
    return mVertices.size();
}

const Party &Graph::getParty(int partyId) const
{
    return mVertices[partyId];
}

Party & Graph::getPartyNonConst(int partyId){  ///function to get party and change it values (not const)
    return mVertices[partyId];
}

const vector<Party> Graph::getVertices()
{
    return mVertices;
}

const vector<Party> Graph::getVerticesConst() const{
    return mVertices;
}
const vector<int> Graph::getneighbors(int partyId) const{
    vector<int> mNeighbors;
     int verticesSize = mVertices.size();
    for(int i = 0; i < verticesSize; i++){
        if (mEdges[partyId][i] != 0){
           
            mNeighbors.push_back(i);
        }
    }

    return mNeighbors;
}

Graph::~Graph() = default;
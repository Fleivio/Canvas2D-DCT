#include "GraphManager.h"

GraphManager::GraphManager(){
    graphs = new vector<Graph*>();
}

GraphManager::GraphManager(vector<Graph*> graphs){
    *(this->graphs) = graphs;
}

void GraphManager::add_graph(Graph* g){
    graphs->push_back(g);
}

void GraphManager::draw(){
    for(auto g : *graphs){
        GraphDrawer::draw(g);
    }
}
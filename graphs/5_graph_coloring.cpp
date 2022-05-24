#include <iostream>
#define NODE 6
using namespace std;

/*
intuition here is to 
go to any node, u = 1 to NODE
    note the colors that have been used for coloring the adjacent nodes, in colorUsed
    find the color that has not been used from colorUsed
    set this color to result[i]
    the colors that have been used for coloring the adjacent nodes, mark them only false
        beacause rest other are already false. 
*/

int graphColoring(){
    vector<int> res(NODE, -1);
    vector<bool> colorUsed(NODE, false);
    
    res[0] = 0;
    for(int i=1 ; i<NODE ; ++i){

        // iterate the adjacent and check if node's result array is not -1
        // then take the asigned color res[it] and set it as colorUsed true.
        for(auto it: list[i])
            if(res[it] != -1)
                colorUsed[res[it]] = true;
        
        int colorNotUsed;
        for(int u=0; u<NODE ; ++u)
            if(!colorUsed[u]){
                colorNotUsed = u;
                break;
            }
        
        // set this color as current's node answer
        res[i] = colorNotUsed;
        
        // iterate and set those colorUsed as false, for which this node's
        // adjacent were colored, i.e. res[it] != -1
        for(auto it: list[i])
            if(res[it] != -1)
                colorUsed[res[it]] = false;
    }
}

main(){
    graphColoring();
}
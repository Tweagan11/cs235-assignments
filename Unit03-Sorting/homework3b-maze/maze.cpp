#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "Grid.h"
using namespace std;

bool check_outside(Grid& grid, int x, int y, int z){
    if ( x < 0 ||  x >= grid.height() || y < 0 || y >= grid.width() || z < 0 || z >= grid.depth()){
        return true;
    }
    else {
        return false;
    }
}

bool check_invalid(Grid& grid, int x, int y, int z){
    if (grid.at(x,y,z) == 0){
        return true;
    }
    else{
        return false;
    }
}

bool check_before(Grid& grid, int x, int y, int z){
    if (grid.at(x,y,z) == 2){
        return true;
    } else {
        return false;
    }
}

bool check_end(Grid& grid, int x, int y, int z){
    if (x == (grid.height()-1) && y == (grid.width()-1) && z == (grid.depth()-1)){
        return true;
    } else {
        return false;
    }
}

bool findPath(Grid& grid, int x, int y, int z, vector<string>& P){
    stringstream ss;
    ss << x << " " << y << " " << z;
    string coordinates = ss.str();
    P.push_back(coordinates);

    if (check_outside(grid,x,y,z) || check_invalid(grid,x,y,z) || check_before(grid,x,y,z)){
        P.pop_back();
        return false;
    }
    if (check_end(grid, x, y, z)){
        return true;
    }

    grid.at(x,y,z) = 2;

    if(findPath(grid,x,y+1,z,P) || findPath(grid,x,y-1,z,P) || findPath(grid,x+1,y,z,P) || findPath(grid,x-1,y,z,P) || findPath(grid,x,y,z+1,P) || findPath(grid,x,y,z-1,P)){
        return true;
    }
    else {
        P.pop_back();
        return false;
    }

}

int main(int argc, char* argv[]) {
    Grid maze;
    ifstream in(argv[1]);
    if (!in){
        cout << "Failed to open file " << argv[1] << endl;
        return 1;
    }
    in >> maze;
    vector<string> solution;

    if (findPath(maze,0,0,0,solution)){
        cout << "SOLUTION" << endl;
        for (auto& line: solution){
            cout << line << endl;
        }
    } else {
        cout << "NO SOLUTION" << endl;
    }

    return 0;
}

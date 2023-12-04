//Jason Gray

#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    vector<vector<char>> table;

    ifstream fin;
    fin.open("Input.txt");

    string input = "";
    int i=0;
    while(getline(fin, input)){
        vector<char> line;
        for(char c : input){
            line.push_back(c);
        }
        table.push_back(line);
        input = "";
    }
    int sum = 0;
    string partNum = "";
    bool valid = false;
    /**
     * 0...***...
     * 1...*5*...
     * 2...***...
    */
   
    for(int i=0; i<table.size(); i++){
        for(int j=0; j<table[i].size(); j++){
            if(isdigit(table[i][j])){
                //not on any edge
                if(i>0 && i<table.size()-1 && j>0 && j<table.size()-1){
                        //check left char
                    if((!isdigit(table[i][j-1]) && table[i][j-1] != '.') ||
                        //check top left char
                        (!isdigit(table[i-1][j-1]) && table[i-1][j-1] != '.') ||
                        //check top char
                        (!isdigit(table[i-1][j]) && table[i-1][j] != '.') || 
                        //check top right char
                        (!isdigit(table[i-1][j+1]) && table[i-1][j+1] != '.') ||
                        //check right char
                        (!isdigit(table[i][j+1]) && table[i][j+1] != '.') || 
                        //check bottom right char
                        (!isdigit(table[i+1][j+1]) && table[i+1][j+1] != '.') ||
                        //check bottom char
                        (!isdigit(table[i+1][j]) && table[i+1][j] != '.') ||
                        //check bottom left char
                        (!isdigit(table[i+1][j-1]) && table[i+1][j-1] != '.')){
                            valid = true;
                    }
                }
                //if on top edge
                else if(i==0){
                    //but not a corner
                    if(j>0 && j<table[i].size()-1){
                            //check left char
                        if((!isdigit(table[i][j-1]) && table[i][j-1] != '.') ||
                            //check right char
                            (!isdigit(table[i][j+1]) && table[i][j+1] != '.') || 
                            //check bottom right char
                            (!isdigit(table[i+1][j+1]) && table[i+1][j+1] != '.') ||
                            //check bottom char
                            (!isdigit(table[i+1][j]) && table[i+1][j] != '.') ||
                            //check bottom left char
                            (!isdigit(table[i+1][j-1]) && table[i+1][j-1] != '.')){
                                valid = true;
                        }
                    }
                    //top left corner
                    else if(j==0){
                            //check right char
                        if((!isdigit(table[i][j+1]) && table[i][j+1] != '.') || 
                            //check bottom right char
                            (!isdigit(table[i+1][j+1]) && table[i+1][j+1] != '.') ||
                            //check bottom char
                            (!isdigit(table[i+1][j]) && table[i+1][j] != '.')){
                                valid = true;
                        }
                    }
                    //top right corner
                    else if(j==table[i].size()-1){
                            //check left char
                        if((!isdigit(table[i][j-1]) && table[i][j-1] != '.') ||
                            //check bottom char
                            (!isdigit(table[i+1][j]) && table[i+1][j] != '.') ||
                            //check bottom left char
                            (!isdigit(table[i+1][j-1]) && table[i+1][j-1] != '.')){
                                valid = true;
                        }
                    }
                }
                //if on bottom edge
                else if(i==table.size()-1){
                    //but not on a corner
                    if(j>0 && j<table[i].size()-1){
                            //check left char
                        if((!isdigit(table[i][j-1]) && table[i][j-1] != '.') ||
                            //check top left char
                            (!isdigit(table[i-1][j-1]) && table[i-1][j-1] != '.') ||
                            //check top char
                            (!isdigit(table[i-1][j]) && table[i-1][j] != '.') || 
                            //check top right char
                            (!isdigit(table[i-1][j+1]) && table[i-1][j+1] != '.') ||
                            //check right char
                            (!isdigit(table[i][j+1]) && table[i][j+1] != '.')){
                                valid = true;
                        }
                    }
                    //bottom left corner
                    else if(j==0){
                            //check top char
                        if((!isdigit(table[i-1][j]) && table[i-1][j] != '.') || 
                            //check top right char
                            (!isdigit(table[i-1][j+1]) && table[i-1][j+1] != '.') ||
                            //check right char
                            (!isdigit(table[i][j+1]) && table[i][j+1] != '.')){
                                valid = true;
                        }
                    }
                    //bottom right corner
                    else if(j==table[i].size()-1){
                            //check left char
                        if((!isdigit(table[i][j-1]) && table[i][j-1] != '.') ||
                            //check top left char
                            (!isdigit(table[i-1][j-1]) && table[i-1][j-1] != '.') ||
                            //check top char
                            (!isdigit(table[i-1][j]) && table[i-1][j] != '.')){
                                valid = true;
                        }
                    }
                }
                //if on left edge, corners already checked
                else if(j==0){
                        //check top char
                    if((!isdigit(table[i-1][j]) && table[i-1][j] != '.') || 
                        //check top right char
                        (!isdigit(table[i-1][j+1]) && table[i-1][j+1] != '.') ||
                        //check right char
                        (!isdigit(table[i][j+1]) && table[i][j+1] != '.') || 
                        //check bottom right char
                        (!isdigit(table[i+1][j+1]) && table[i+1][j+1] != '.') ||
                        //check bottom char
                        (!isdigit(table[i+1][j]) && table[i+1][j] != '.')){
                            valid = true;
                    }
                }
                //if on right edge, corners already checked
                else if(j==table[i].size()-1){
                        //check left char
                    if((!isdigit(table[i][j-1]) && table[i][j-1] != '.') ||
                        //check top left char
                        (!isdigit(table[i-1][j-1]) && table[i-1][j-1] != '.') ||
                        //check top char
                        (!isdigit(table[i-1][j]) && table[i-1][j] != '.') || 
                        //check bottom char
                        (!isdigit(table[i+1][j]) && table[i+1][j] != '.') ||
                        //check bottom left char
                        (!isdigit(table[i+1][j-1]) && table[i+1][j-1] != '.')){
                            valid = true;
                    }
                }
            }
            if(valid){
                while(j>0 && isdigit(table[i][j-1])){
                    j--;
                }
                while(isdigit(table[i][j])){
                    partNum += table[i][j];
                    j++;
                }
                sum += stoi(partNum);
                partNum = "";
                valid = false;
            }
        }
    }

    cout << "The sum is: " << sum << endl;
}
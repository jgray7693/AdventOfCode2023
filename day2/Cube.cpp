//Jason Gray

#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int main(){
    //Maximum red blocks
    const int red_max = 12;
    //Maximum green blocks
    const int green_max = 13;
    //Maximum blue blocks
    const int blue_max = 14;


    ifstream fin;
    fin.open("Input.txt");

    //input string for each line of the file
    string input;
    //partial string for each collection of characters, separated by white space
    string partial;
    //keeps track of the number of blocks removed from the bag
    int blockCount;
    //keeps track of the game index
    int counter = 1;
    //keeps track of total sum of game indices
    int total = 0;
    //boolean to flag a game valid for not
    bool valid;
    //while input file has new lines
    while(getline(fin, input)){
        //set each new game to valid from the start
        valid = true;
        //convert input line to stringstream for easy parsing
        stringstream line(input);
        //parse through each "word" in stringstream if game is still valid
        while(line >> partial && valid){
            //if the word is a number, set it to blockCount
            if(isdigit(partial[0])){
                blockCount = stoi(partial);
            }
            //else check blockCount to each colors maximum amount and flag invalid where appropriate
            else{
                if(partial.find("red") != -1){
                    if (blockCount > red_max){
                        valid = false;
                        
                    }
                }
                else if(partial.find("green") != -1){
                    if(blockCount > green_max){
                        valid = false;
                        
                    }
                }
                else if(partial.find("blue") != -1){
                    if(blockCount > blue_max){
                        valid = false;
                        
                    }
                }
            }
        }
        //if valid, add game index to total
        if(valid){
            total += counter;
        }
        counter++;
    }
    //print results from part 1
    cout << "Sum of indices of valid games: " << total << endl;
}
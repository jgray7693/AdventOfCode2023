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
    //keeps track of total sum of valid game indices
    int total = 0;
    //boolean to flag a game valid for not
    bool valid;
    //keeps track of minimum required red blocks for game to be valid
    int red_min;
    //keeps track of minimum required green blocks for game to be valid
    int green_min;
    //keeps track of minimum required blue blocks for game to be valid
    int blue_min;
    //keeps track of sum of each game cubic
    int cubicTotal = 0;
    //while input file has new lines
    while(getline(fin, input)){
        //set all minimum required blocks to 0 for each new game
        red_min = 0;
        green_min = 0;
        blue_min = 0;
        //set each new game to valid from the start
        valid = true;
        //convert input line to stringstream for easy parsing
        stringstream line(input);
        //parse through each "word" in stringstream if game is still valid
        while(line >> partial){
            //if the word is a number, set it to blockCount
            if(isdigit(partial[0])){
                blockCount = stoi(partial);
            }
            //if the word is not a number
            else{
                //if the word is red
                if((int)partial.find("red") != -1){
                    //set minimum required red blocks for the game
                    red_min = max(red_min, blockCount);
                    //flag game as invalid if greater than maximum allowed blocks
                    if (blockCount > red_max){
                        valid = false;
                    }
                }
                //if the word is green
                else if((int)partial.find("green") != -1){
                    //set minimum required green blocks for the game
                    green_min = max(green_min, blockCount);
                    //flag game as invalid if greater than maximum allowed blocks
                    if(blockCount > green_max){
                        valid = false;
                    }
                }
                //if the word is blue
                else if((int)partial.find("blue") != -1){
                    //set minimum required blue blocks for the game
                    blue_min = max(blue_min, blockCount);
                    //flag game as invalid if greater than maximum allowed blocks
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
        //calculate rolling cubic for the game
        cubicTotal += (red_min * green_min * blue_min);
        counter++;
    }
    //print results from part 1
    cout << "Sum of indices of valid games: " << total << endl;
    //print results from part 2
    cout << "Cubic sum of all games: " << cubicTotal << endl;
}
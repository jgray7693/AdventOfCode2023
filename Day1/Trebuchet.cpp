//Jason Gray

#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int main(){
    ifstream fin;
	fin.open("Trebuchet_Input.txt");
	if (!fin.good()) throw "I/O error";
    
    //contains each word on each line of text
    string input;
    
    //compile a vector of strings of each number 0-9
    string zero = "zero";
    string one = "one";
    string two = "two";
    string three = "three";
    string four = "four";
    string five = "five";
    string six = "six";
    string seven = "seven";
    string eight = "eight";
    string nine = "nine";
    vector<string> nums = {zero, one, two, three, four, five, six, seven, eight, nine};

    //temp int to track index of discovered word
    int x;
    //tracks number associated with the written number as vector is iterated
    int pos;

    //keeps track of integer number of first written number found
    int numLowWord;
    //keeps track of integer number of last written number found
    int numHighWord;
    //keeps track of position of first written number found
    int posLowWord;
    //keeps track of position of last written word found
    int posHighWord;

    //keeps track of position of first digit found
    int posLowNum;
    //keeps track of position of last digit found
    int posHighNum;

    //total for part 1 of prompt - digits only
    int numOnlyTotal = 0;
    //total for part 2 of prompt - digits and written numbers
    int allTotal = 0;

	while(fin >> input) {
        //reset all numbers for each new word processed
        posLowWord = 999;
        posHighWord = -1;
        x=0;
        pos=0;
        numLowWord=-1;
        numHighWord=-1;
        posLowNum = 0;
        posHighNum = input.length()-1;

        //find earliest and latest occurence of a written number
        //for each string num in nums
        for(string num : nums){
            //find starting position of num found in string input
            x = input.find(num);
            //if num is found (x != -1)
            while(x != -1){
                //if the position of the number found is less than the currently lowest position
                if(x < posLowWord){
                    //update the lowest position for word found and what the number is
                    posLowWord = x;
                    numLowWord = pos;
                }
                //if the position of the number found is greater than the currently highest position
                if(x > posHighWord){
                    //update the highest position for word found and what the number is
                    posHighWord = x;
                    numHighWord = pos;
                }
                //update x
                x = input.find(num, x+1);
            }        
            //update pos
            pos++;    
        }

        //string to concatenate for part 1
        string numOnly = "";
        //string to concatenate for part 2
        string allNums = "";
        
        //increment posLowNum until a digit is found
        while(!isdigit(input[posLowNum])){
            posLowNum++;
        }
        //decrement posHighNum until a digit is found
        while(!isdigit(input[posHighNum])){
            posHighNum--;
        }
        //using lowest position word or digit, concatenate number to allNums
        if(posLowNum < posLowWord){
            allNums += (input[posLowNum]);
        }
        else{
            allNums += to_string(numLowWord);
        }
        //using highest position word or digit, concatenate number to allNums
        if(posHighNum > posHighWord){
            allNums += (input[posHighNum]);
        }
        else{
            allNums += to_string(numHighWord);
        }
        //for part 1, concatenate earliest and latest digits
        numOnly += (input[posLowNum]);
        numOnly += (input[posHighNum]);

        //sum total for each part
        numOnlyTotal = numOnlyTotal + stoi(numOnly);
        allTotal = allTotal + stoi(allNums);

	}
    //close the file
    fin.close();

    //print results of calculations
    cout << "Sum of all First and Last Digits in each word is: " << numOnlyTotal << endl;
    cout << "Sum of all First and Last Digits or Written Numbers in each word is: " << allTotal << endl;
}

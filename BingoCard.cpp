/*Jaden Peacock
 *jxp6059@psu.edu
 *Assignment 19
 *November 15, 2022
 *COMP-SCI 121 Sec-001
 *create a program that makes several bingo cards and displays the winner
 */
#include "BingoCard.h"
#include <iomanip>
#include <cmath>
#include <fstream>
#include <iostream>
#include <random>
using namespace std;
// =============================================================
// *** Create the functions definitions here ***
// =============================================================
//  BingoCard constructor function
// bool hasHorizontalBingo();
// bool hasVerticalBingo();
// bool hasDiagonalBingo();
// void updateCard(int numberCalled);
// bool hasBingo();  // Returns true if any of the 3 private "has____Bingo" functions returns true.
// void clearCard();  // Resets the marks[][] array to all false.
// There are several utility function provided at the bottom of this file.
// printCard - Prints out the full card to terminal or into log file


// initialize random seed
// *** CONSTRUCTOR ***
BingoCard::BingoCard() {
    int randNumGen, cCount;

    //the for loop to make the random numbers for the bingo card
    for (int rCount = 0; rCount < ROWS ; rCount++) {
        for (cCount = 0; cCount < COLS; cCount++){
            do{randNumGen = rand() % 15 +(15 *cCount);}while(numberTaken(randNumGen));
            cardNumbers[rCount][cCount] = randNumGen;
        }
    }
    //clears the marks array and makes it all false
    clearCard();



// Constructor should create a new Bingo Card assigned to a player.
// Creates a new Bingo Card, with a set of random numbers
// Store the numbers in private array cardNumbers[][]
// You can assume the random seed was already called.
// B (1-15), I (16-30), N (31-45), G (46-60), O (61-75)
// You can use your code from the previous assignment, but...
// This time, make sure that there are no duplicate numbers on the card!
// Comment: FreeSpace- For the middle cell, cardNumbers[2][2], you can put a number,
//    but it must not affect the hasBingo results when you create those functions.
// *** Call the clearCard function to reset all card marks to false.

}

// *** updateCard ***
void BingoCard::updateCard(int numberCalled) {
    //marks the free space as true
    marks[2][2]= true;
    //the for loop to make the spot on the bingo card true on the marks function
    for (int i =0; i < ROWS; i++){
        for (int j =0; j<COLS; j++){

            if (cardNumbers[i][j] == numberCalled){
                marks[i][j]=true;
            }
        }
    }
}

// ----------------------------------------------
// Update the card marks array when a number is called.
// *** clearCard
void BingoCard::clearCard() {
    //clears the marks array of all true
    for (int i = 0; i < ROWS; i++){
        for (int j= 0; j< COLS; j++){
            marks[i][j] = false;
        }
    }
}
// ----------------------------------------------
// clear card
// This resets all card marks to 'false'
// *** Checking for Bingo



// *** hasBingo ***
bool BingoCard::hasBingo() {
    //checks all the different types of bingo to see if they got bingo
    if (BingoCard::hasHorizontalBingo() or BingoCard::hasDiagonalBingo() or BingoCard::hasVerticalBingo()){
        return true;
    }
    //if not keeps going
    else {return false;}
}
// Check the card to see if it has a Bingo.
// There are 3 types of Bingo:
// * Horizontal Bingo (marks across a whole row)
// * Vertical Bingo (marks down a whole column)
// * Diagonal Bingo (top left to bottom right OR bottom left to top right)
// Remember, that the center 'FREE' spot counts for Bingo in all cases.
// Be sure to return 'true' or 'false'
// *** hasHorizontalBingo
bool BingoCard::hasHorizontalBingo(){
    //goes through all rows to see if there is horizontal bingo
    for (int i = 0; i < ROWS; i++){
        if (marks[i][0] and marks[i][1] and marks[i][2] and marks[i][3] and marks[i][4]){
            return true;
        }
    }
    return false;
}
// *** hasVerticalBingo
bool BingoCard::hasVerticalBingo(){
    //goes through all the columns to see if there is a vertical bingo
    for (int j = 0; j < ROWS; j++){
        if (marks[0][j] and marks[1][j] and marks[2][j] and marks[3][j] and marks[4][j]){
            return true;
        }
        }
    return false;
    }



// *** hasDiagonalBingo
bool BingoCard::hasDiagonalBingo(){
    //checks to see if they got diagonal bingo on either side
    if (marks[0][0] && marks[1][1] && marks[2][2] && marks[3][3] && marks[4][4]){
        return true;
    }
    if (marks[0][4] && marks[1][3] && marks[2][2] && marks[3][1] && marks[4][0]){
    return true;
}
    else {return false;}}

bool BingoCard::numberTaken(int numberCalled) {
    //checks to see if the numbers are the same
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++){
                if (numberCalled == cardNumbers[i][j]) {
                    return true;
                }


        }
    }
    return false;
}


// ============================================================================
// *** Do not modify below this line ***
// ============================================================================
void BingoCard::printCard(){  // *** DO NOT MODIFY ***
    const char TABCHAR = 9;
    cout << "---------------------------------------" << endl;
    // Print the header
    cout << "B" << TABCHAR << "I" << TABCHAR << "N" << TABCHAR << "G" << TABCHAR <<
         "O" << endl;
    // Print each row
    for (int r = 0; r < ROWS; r++){
        for (int c = 0; c < COLS ; c++){  // for each row, print each column
            if (r==2 && c ==2) cout << "FREE" << TABCHAR ;
            else {
                if (marks[r][c]) cout << "*"; // Add a * if number was called
                cout << cardNumbers[r][c];   // the number
                cout << TABCHAR;
            }
        }
        cout << endl; // end of the row
    }
    cout << "---------------------------------------" << endl;
}
// *** DO NOT MODIFY ***
void BingoCard::printCard(ofstream &logFile) { //Overload function for saving to logfile.
    const char TABCHAR = 9;
    logFile << "---------------------------------------" << endl;
    // Print the header
    logFile << "B" << TABCHAR << "I" << TABCHAR << "N" << TABCHAR << "G" << TABCHAR
            << "O" << endl;
    // Print each row
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {  // for each row, print each column
            if (r == 2 && c == 2) logFile << "FREE" << TABCHAR;
            else {
                if (marks[r][c]) logFile << "*"; // Add a * if number was called
                logFile << cardNumbers[r][c];   // the number
                logFile << TABCHAR;
            }
        }
        logFile << endl; // end of the row
    }
    logFile << "---------------------------------------" << endl;

}
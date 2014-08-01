#include <stdio.h>

#define BORDER ' '
#define FILLER '_'

typedef enum {false,true} bool;
typedef enum {pOne,pTwo} turn;

const int SIZE = 4;

void setupTable(char[SIZE][SIZE]);
void printTable(char[SIZE][SIZE]);
int getInput();

void setupTable(char t[][SIZE]) {
  int i,j;
  
  for (i=0; i < SIZE + 1; i++) {
    for (j=0; j < SIZE + 1; j++) {
      if (i==0 || i==SIZE) { t[i][j] = BORDER; }  
      else if (j==0 || j==SIZE) { t[i][j] = BORDER; } 
      else { t[i][j] = FILLER; } 
    }
  }
}

//print the current table
void printTable(char t[][SIZE]) {
  int i,j;

  for (i=0; i < SIZE + 1; i++) {
    for (j=0; j < SIZE + 1; j++) {
      printf(" %c", t[i][j]);
    }
    printf("\n");
  }
}

//this methode only forces the user to input a number
int getInput() {

  int input = 0;
  char ch; 
  
  printf("enter a number between 1 and 9: ");

  while (!scanf("%d", &input))
  {
   //you know what this is duh
   printf("1-9 only: ");

    while ( (ch = getchar()) != '\n' && ch != EOF);
  } 

  return input;
}

turn trackTurn(turn currentTurn){
  //assign choice and change turn over
  if (currentTurn == pOne) {
    //set what ever to an x 
    printf("player one");

    //make sure to change which user's turn it is
    currentTurn = pTwo;
  } else {
    //set what ever to an o
    printf("player two");
    
    //make sure to change which user's turn it is
    currentTurn = pOne;
  }
  return currentTurn;
}

//make sure between 1-9 or location already taken
bool verifyInput (int userInput){
  //default didn't verify
  bool verified = false;

  //ask for a choice again from the user if not between 1 and 9
  if (userInput > 9 || userInput < 1) {
    printf("Input out of range\n");
    return verified = false;
  }
  

  return verified;
}

int main () 
{

  //create table with padding
  char table[10][10];
  
  //track game and end when needed
  bool endGame = false;
  bool inputPassed = false;
  
  //track who's turn
  turn currentTurn = pOne;

  //user input
  int userInput = 0;
  
  //this only prints the table
  setupTable(table);

  //main game loop
  while (endGame == false)
  {
    printTable(table); 
    userInput = getInput();
    inputPassed = verifyInput(userInput); // make sure between 1-9 and the choice isn't taken
    
   
    
    //check if choice is already taken
    // place the user's choice
    //check for a winner
    //change whos turn it is 
  
  }
}

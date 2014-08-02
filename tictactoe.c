#include <stdio.h>

#define BORDER ' '
#define FILLER '_'

typedef enum {false,true} bool;
typedef enum {pOne,pTwo} turn;

const int SIZE = 4;

void setupTable(char[SIZE][SIZE]);
void printTable(char[SIZE][SIZE],turn);
int getInput();
turn trackTurn(turn);
bool assignChoice(int,char[SIZE][SIZE],turn);
bool chkWinner(char[SIZE][SIZE]);


void setupTable(char t[][SIZE]) {
  int i,j;

  for (i=0; i < SIZE + 1; i++) {
    for (j=0; j < SIZE + 1; j++) {
      if (i==0 || i==SIZE) 
        t[i][j] = BORDER; 
      else if (j==0 || j==SIZE) 
        t[i][j] = BORDER;
      else 
        t[i][j] = FILLER;
    }
  }
}

//print the current table
void printTable(char t[][SIZE], turn current) {
  int i,j;
  printf("Player %d's Turn\n", current + 1);

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
  } 
  else
  {
    //set what ever to an o
    printf("player two");

    //make sure to change which user's turn it is
    currentTurn = pOne;
  }
  return currentTurn;
}

//make sure between 1-9 or location already taken
bool assignChoice (int userInput, char table[][SIZE], turn whosTurn) {

  bool verified = true;
  int x = 0 ,y = 0;
  char mark=' ';

  //ask for a choice again from the user if not between 1 and 9
  if (userInput > 9 || userInput < 1) {
    printf("Input out of range\n");
    return verified = false;
  }

  //translate between 1-9 and the matrix locations
  switch (userInput) {
    case 1:
      x=1; y=1;
      break;
    case 2:
      x=1; y=2;
      break;
    case 3:
      x=1; y=3;
      break;
    case 4:
      x=2; y=1;
      break;
    case 5:
      x=2; y=2;
      break;
    case 6:
      x=2; y=3;
      break;
    case 7:
      x=3; y=1;
      break;
    case 8:
      x=3; y=2;
      break;
    case 9:
      x=3; y=3;
      break;
    default:
      printf("something really went wrong here.....\n");
      verified = false;
      return verified;
      break;
  }

  if (table[x][y] != FILLER) {
    return verified = false;
  }
  else {
    if (whosTurn == pOne)
      table[x][y] = 'x';
    else
      table[x][y] = 'o';
  }
  //assign the location if the spot isn't already taken  

  return verified;
}

//check for a winner
bool chkWinner (char table[][SIZE]) {
  bool win = false;

  //check horizontal
  int i;
  for (i=1; i < 4; i++) {
    if ((table[i][2] == table[i][1] && table[i][3] == table[i][1]) && table[i][1] != FILLER)  {
      win = true;
      return win; 
    } 
  }

  //check vertical
  for (i=1; i < 4; i++) {
    if ((table[2][i] == table[1][i] && table[3][i] == table[1][i]) && table[1][i] != FILLER)  {
      win = true;
      return win; 
    } 
  }

  //diagnal left to right
  if ((table[2][2] == table[1][1] && table[3][3] == table[1][1]) && table[1][1] != FILLER) { 
    win = true;
    return win;
  }

  //diagnal right to left
  if ((table[2][2] == table[1][3] && table[3][1] == table[1][3]) && table[1][3] != FILLER) { 
    win = true;
    return win;
  }

  return win;
}

turn changeTurn(turn current) {
  if (current == pOne) 
     current = pTwo;  
  else  
    current = pOne;  

  return current;
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
    printTable(table, currentTurn); 
    userInput = getInput();
    inputPassed = assignChoice(userInput, table, currentTurn); // make sure between 1-9 and the choice isn't taken

    //make sure input was valid before checking for a winner
    if (inputPassed) {
      endGame = chkWinner(table);

      if (!endGame) {
        currentTurn = changeTurn(currentTurn);
      }  
      else {
        printTable(table,currentTurn);
        printf("Player %d is the winner!\n", currentTurn + 1);
      }
    }
    else { 
      continue;
    }
  }
}

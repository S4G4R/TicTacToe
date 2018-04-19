#include "tictactoe.hpp"
#include <unistd.h>
#include <random>
#include <iostream>

ticTac::ticTac() {
  initBoard();
}

void ticTac::initBoard() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j]=" ";
    }
  }
}

void ticTac::printGreeting() {
  std::cout << "Hello user. Welcome to ticTacToe. Pick one of the following :" << std::endl;
  std::cout << "1 - Single Player" << std::endl;
  std::cout << "2 - Two Players" << std::endl;
}

void ticTac::clearScreen() {
  system("clear");
}

void ticTac::userSelection() {
  std::cout << "Enter 1 for 'O' or 2 for 'X'!" << '\n';
  int userChoice;
  std::cin >> userChoice;
  if (userChoice==1) {
    user1='O';
    bot='X';
    pickStart=1;
  } else if (userChoice==2) {
    user1='X';
    bot='O';
    pickStart=0;
  } else {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Wrong Selection. Try again." << std::endl;
    userSelection();
  }
}

void ticTac::pickMode() {
  int mode;
  std::cin >> mode;
  if (mode==1) {
    gamemode=0;
  } else if (mode==2) {
    gamemode=1;
  } else {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout << "Wrong Selection. Try Again." << std::endl;
    pickMode();
  }
}

int ticTac::getStart() {
  return pickStart;
}

int ticTac::getMode() {
  return gamemode;
}

void ticTac::drawBoard() {
  for (int i = 0; i < 3; i++) {
    std::cout << " --- --- --- " << std::endl;
      std::cout << "| ";
    for (int j = 0; j < 3; j++) {
      if (j==2) {
        std::cout << board[i][j] << " |" ;
        continue;
      }
      std::cout << board[i][j] << " | ";
    }
    std::cout << std::endl;
    if(i==2) {
      std::cout << " --- --- --- ";
    }
  }
  std::cout << std::endl;
}

void ticTac::userMove() {
  if (!gamemode) {
    std::cout << "User " << turn+1 << ", ";
  }
  std::cout << "Type a row (1, 2 or 3), and a column (1, 2 or 3)." << std::endl;
  int x, y;
  std::cin >> x;
  std::cin >> y;
  if ((x==1 || x==2 || x==3) && (y==1 || y==2 || y==3)) {
    if(checkFull(x,y)) {
      std::cout << "That position is already filled. Please try again." << std::endl;
      userMove();
    } else {
      if(turn==0) {
        board[x-1][y-1]=user1;
      } else {
        board[x-1][y-1]=user2;
      }
      x_lastplay=x-1;
      y_lastplay=y-1;
    }
  } else {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout << "Please enter a correct row and column!" << std::endl;
    userMove();
  }
}

void ticTac::setUsers() {
  user1="X";
  user2="O";
}

void ticTac::setTurn(int x) {
  if(x==1) turn=0;
  if(x==2) turn=1;
}

void ticTac::botThink() {
  std::cout << "Bot is thinking";
  std::cout.flush();
  usleep(500000);
  std::cout << '.';
  std::cout.flush();
  usleep(500000);
  std::cout << '.';
  std::cout.flush();
  usleep(500000);
  std::cout << '.' << std::endl;
  std::cout.flush();
  sleep(2);
}

bool ticTac::checkFull(int x, int y) {
  if(board[x-1][y-1] != " ") {
    return true;
  } else {
    return false;
  }
}

void ticTac::randomPick() {
  std::random_device random_device;
  std::mt19937 engine{random_device()};
  std::uniform_int_distribution<> dist(0,2);
  int i = dist(engine);
	int j = dist(engine);
  if(board[i][j]==" ") {
    board[i][j]=bot;
    return;
  } else {
    randomPick();
  }
}

void ticTac::botMove() {
  int row=getLastX();
  int col=getLastY();
  if(board[1][1] == " ") {
    board[1][1]=bot;
  } else if ((col+1)<3 && board[row][col+1] == " ") {
    board[row][col+1]=bot;
  } else if ((col-1)>=0 && board[row][col-1] == " ") {
    board[row][col-1]=bot;
  } else if ((row-1)>=0 && board[row-1][col] == " ") {
    board[row-1][col]=bot;
  } else if ((row+1)<3 && board[row+1][col] == " ") {
    board[row+1][col]=bot;
  } else {
    randomPick();
  }
  return;
}

bool ticTac::winCondition() {
  if (board[0][0]==board[0][1] && board[0][0]==board[0][2] && board[0][0]!=" ") {
    winner=board[0][0];
    return true;
  } else if (board[1][0]==board[1][1] && board[1][0]==board[1][2] && board[1][0]!=" ") {
    winner=board[1][0];
    return true;
  } else if (board[2][0]==board[2][1] && board[2][0]==board[2][2] && board[2][0]!=" ") {
    winner=board[2][0];
    return true;
  } else if (board[0][0]==board[1][0] && board[0][0]==board[2][0] && board[0][0]!=" ") {
    winner=board[0][0];
    return true;
  } else if (board[0][1]==board[1][1] && board[0][1]==board[2][1] && board[0][1]!=" ") {
    winner=board[0][1];
    return true;
  } else if (board[0][2]==board[1][2] && board[0][2]==board[2][2] && board[0][2]!=" ") {
    winner=board[0][2];
    return true;
  } else if (board[0][0]==board[1][1] && board[0][0]==board[2][2] && board[0][0]!=" ") {
    winner=board[0][0];
    return true;
  } else if (board[0][2]==board[1][1] && board[0][2]==board[2][0] && board[0][2]!=" ") {
    winner=board[0][2];
    return true;
  } else {
    return false;
  }
}

bool ticTac::boardFull() {
  int count=0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j]!=" ") {
        count++;
      }
    }
  }
  if (count==9) {
    return true;
  } else {
    return false;
  }
}

void ticTac::showResult() {
  if(gamemode) {
    if (winner==user1) {
      std::cout << "User 1 wins! Congratulations." << std::endl;
    } else if (winner==user2) {
      std::cout << "User 2 wins! Congratulations." << std::endl;
    } else {
      std::cout << "It's a tie!" << std::endl;
    }
  } else {
    if (winner==user1) {
      std::cout << "You win! Congratulations." << std::endl;
    } else if (winner==bot) {
      std::cout << "Bot wins! Better luck next time." << std::endl;
    } else {
      std::cout << "It's a tie!" << std::endl;
    }
  }
}

void ticTac::resetBoard() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = " ";
    }
  }
}

int ticTac::getLastX() {
  return x_lastplay;
}

int ticTac::getLastY() {
  return y_lastplay;
}

ticTac::~ticTac() {

}

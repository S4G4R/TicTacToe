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
  std::cout << "1 - O, 2 - X" << std::endl;
}

void ticTac::userSelection() {
  std::cin >> userChoice;
  if (userChoice==1) {
    user='O';
    bot='X';
    pickStart=1;
  } else if (userChoice==2) {
    user='X';
    bot='O';
    pickStart=0;
  } else {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Wrong Selection. Try again." << std::endl;
    userSelection();
  }
}

int ticTac::getStart() {
  return pickStart;
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
  std::cout << "Type a row (1, 2 or 3), and a column (1, 2 or 3)." << std::endl;
  int x, y;
  std::cin >> x;
  std::cin >> y;
  if ((x==1 || x==2 || x==3) && (y==1 || y==2 || y==3)) {
    checkFull(x,y);
    board[x-1][y-1]=user;
    x_lastplay=x-1;
    y_lastplay=y-1;
  } else {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout << "Please enter a correct row and column!" << std::endl;
    userMove();
  }
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

void ticTac::checkFull(int x, int y) {
  if(board[x-1][y-1] != " ") {
    std::cout << "That position is already filled. Please try again." << std::endl;
    userMove();
  } else {
    return;
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
  std::cout << row << ' ' << col << '\n';
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
    return true;
  } else if (board[1][0]==board[1][1] && board[1][0]==board[1][2] && board[1][0]!=" ") {
    return true;
  } else if (board[2][0]==board[2][1] && board[2][0]==board[2][2] && board[2][0]!=" ") {
    return true;
  } else if (board[0][0]==board[1][0] && board[0][0]==board[2][0] && board[0][0]!=" ") {
    return true;
  } else if (board[0][1]==board[1][1] && board[0][1]==board[1][2] && board[0][1]!=" ") {
    return true;
  } else if (board[0][2]==board[1][2] && board[0][2]==board[2][2] && board[0][2]!=" ") {
    return true;
  } else if (board[0][0]==board[1][1] && board[0][0]==board[2][2] && board[0][0]!=" ") {
    return true;
  } else if (board[0][2]==board[1][1] && board[0][2]==board[2][0] && board[0][2]!=" ") {
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

int ticTac::getLastX() {
  return x_lastplay;
}

int ticTac::getLastY() {
  return y_lastplay;
}

ticTac::~ticTac() {

}

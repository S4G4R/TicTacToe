#include "tictactoe.hpp"
#include <cstdlib>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

ticTac::ticTac() {
  initBoard();
}

void ticTac::initBoard() {
  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 3; j++) {
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
    std::cout << "Wrong Selection. Try again." << std::endl;
    userSelection();
  }
}

int ticTac::getStart() {
  return pickStart;
}

void ticTac::drawBoard() {
  for (size_t i = 0; i < 3; i++) {
    std::cout << " --- --- --- " << std::endl;
      std::cout << "| ";
    for (size_t j = 0; j < 3; j++) {
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

void ticTac::addMove() {
  int x, y;
  std::cin >> x;
  std::cin >> y;
  if ((x==1 || x==2 || x==3) && (y==1 || y==2 || y==3)) {
    board[x-1][y-1]=user;
  } else {
    std::cout << "Please enter a correct row and column!" << std::endl;
    addMove();
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

ticTac::~ticTac() {

}

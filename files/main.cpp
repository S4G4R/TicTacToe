#include "tictactoe.hpp"

#include <iostream>

int main() {
  ticTac board;
  std::string decision;
  decision = "yes";
  while (decision == "yes" || decision == "YES" || decision == "Yes") {
    board.clearScreen();
    board.printGreeting();
    board.pickMode();
    if (board.getMode()) {
      board.drawBoard();
      board.setUsers();
      while(true) {
        std::cout << "User 1, play :" << std::endl;
        board.setTurn(1);
        board.userMove();
        board.clearScreen();
        board.drawBoard();
        if(board.winCondition() || board.boardFull()) break;
        std::cout << "User 2, play :" << std::endl;
        board.setTurn(2);
        board.userMove();
        board.clearScreen();
        board.drawBoard();
        if(board.winCondition() || board.boardFull()) break;
      }
    } else {
      board.userSelection();
      if (board.getStart()) {
        std::cout << "You play first! Good luck." << '\n';
        board.drawBoard();
        while(true) {
          board.userMove();
          board.clearScreen();
          board.drawBoard();
          if(board.winCondition() || board.boardFull()) break;
          board.botThink();
          board.botMove();
          board.clearScreen();
          board.drawBoard();
          if(board.winCondition() || board.boardFull()) break;
        }
      } else {
         std::cout << "Bot plays first! Good luck." << '\n';
         board.drawBoard();
         while(true) {
           board.botThink();
           board.botMove();
           board.clearScreen();
           board.drawBoard();
           if(board.winCondition() || board.boardFull()) break;
           board.userMove();
           board.clearScreen();
           board.drawBoard();
           if(board.winCondition() || board.boardFull()) break;
        }
      }
    }
    board.showResult();
    std::cout << "Would you like to play again? Type 'yes' if you do, or enter anything else if you don't." << std::endl;
    std::cin >> decision;
    board.resetBoard();
  }
  return 0;
}

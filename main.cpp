//TODO: #include "tictactoe.hpp"
//Remove below line
#include "tictactoe.cpp"

int main() {
  ticTac board;
  std::string decision;
  decision = "yes";
  while (decision == "yes" || decision == "YES" || decision == "Yes") {
    board.printGreeting();
    board.userSelection();
    if (board.getStart()) {
      std::cout << "You play first! Good luck." << '\n';
      board.drawBoard();
//      while(!board.winCondition() && !board.boardFull()) {
        board.userMove();
        board.drawBoard();
        board.botThink();
        board.botMove();
        board.drawBoard();
        decision = "NULL";
//      }
    } else {
       std::cout << "Bot plays first! Good luck." << '\n';
//       while(!board.winCondition() && !board.boardFull()) {
         board.drawBoard();
         board.botThink();
         board.botMove();
         board.drawBoard();
         board.userMove();
         decision = "NULL";
//      }
    }
  }
  return 0;
}

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
      while(!board.boardFull()) {
        board.userMove();
        board.drawBoard();
        if(board.winCondition()) break;
        board.botThink();
        board.botMove();
        board.drawBoard();
        if(board.winCondition()) break;
        decision = "NULL";
      }
    } else {
       std::cout << "Bot plays first! Good luck." << '\n';
       board.drawBoard();
       while(!board.boardFull()) {
         board.botThink();
         board.botMove();
         board.drawBoard();
         if(board.winCondition()) break;
         board.userMove();
         board.drawBoard();
         if(board.winCondition()) break;
         decision = "NULL";
      }
    }
    board.showResult();
    std::cout << "Would you like to play again? Type 'yes' if you do, or enter anything else if you don't." << std::endl;
    std::cin >> decision;
    board.resetBoard();
  }
  return 0;
}

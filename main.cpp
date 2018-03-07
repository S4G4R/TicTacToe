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
  /*    while( Add win condition here ) {  */
        board.userMove();
        board.drawBoard();
//        board.userMove();
        board.botThink();
        decision = "NULL";
    } else {
      std::cout << "Bot plays first! Good luck." << '\n';
      decision = "NULL";
    }
  /*    }     */
  }
  return 0;
}

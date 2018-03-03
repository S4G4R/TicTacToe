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
        std::cout << "Type a row (1, 2 or 3), and a column (1, 2 or 3)." << std::endl;
        board.addMove();
        board.drawBoard();
        std::cout << "Bot is thinking..." << std::endl;
        sleep(2);
        decision = "NULL";
  /*    }     */
    } else {
      std::cout << "Bot plays first! Good luck." << '\n';
      decision = "NULL";
    }
  }
  return 0;
}

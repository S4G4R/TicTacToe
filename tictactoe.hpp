#ifndef TIC_TAC_TOE
#define TIC_TAC_TOE

#include <string>

class ticTac {
private:
  std::string board[3][3];
  char user;
  char bot;
  int userChoice;
  bool pickStart;
public:
  ticTac();
  int getStart();
  void initBoard();
  void addMove();
  void printGreeting();
  void userSelection();
  void botThink();
  void drawBoard();
  ~ticTac();
};

#endif

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
  void userMove();
  void printGreeting();
  void userSelection();
  void botThink();
  void checkFull(int,int);
  void drawBoard();
  ~ticTac();
};

#endif

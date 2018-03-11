#ifndef TIC_TAC_TOE
#define TIC_TAC_TOE

#include <string>

class ticTac {
private:
  std::string board[3][3];
  std::string user;
  std::string bot;
  std::string winner;
  int userChoice;
  bool pickStart;
  int x_lastplay, y_lastplay;
public:
  ticTac();
  int getStart();
  void initBoard();
  void userMove();
  void printGreeting();
  void userSelection();
  void botThink();
  int getLastX();
  int getLastY();
  void botMove();
  void randomPick();
  void checkFull(int,int);
  bool winCondition();
  void drawBoard();
  bool boardFull();
  void showResult();
  void resetBoard();
  ~ticTac();
};

#endif

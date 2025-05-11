#include "./board/board.hpp"
#include "./ui/console/ConsoleUI.hpp"
#include "./ui/gui/gui.hpp"
#include <cstring>
#include <iostream>

using namespace std;
using namespace chess;

void banner() {
  cout << "          /$$                                            " << endl;
  cout << "          | $$                                           " << endl;
  cout << "  /$$$$$$$| $$$$$$$   /$$$$$$   /$$$$$$$ /$$$$$$$  " << endl;
  cout << " /$$_____/| $$__  $$ /$$__  $$ /$$_____//$$_____/ " << endl;
  cout << "| $$      | $$  \\ $$| $$$$$$$$|  $$$$$$|  $$$$$$ " << endl;
  cout << "| $$      | $$  | $$| $$_____/ \\____  $$\\____  $$" << endl;
  cout << "|  $$$$$$$| $$  | $$|  $$$$$$$ /$$$$$$$//$$$$$$$/" << endl;
  cout << "\\_______/|__/  |__/ \\_______/|_______/|_______/  " << endl;
}

void usage(const char *target) {
  cout << "Usage:\n";
  cout << "\t" << target << " console\n";
  cout << "Commands:\n";
  cout << "\tconsole         Start Chess as a text-based game\n";
  cout << "\thelp            Print this help message\n";
  exit(1);
}

int main(int argc, char **argv) {
  if (argc == 1) {
    banner();
    usage(argv[0]);
  }

  bool consoleMode = false;
  bool guiMode = false;

  for (int i = 1; i < argc; ++i) {
    if (strcmp(argv[i], "console") == 0) {
      consoleMode = true;
    } else if (strcmp(argv[i], "gui") == 0) {
      guiMode = true;
    } else {
      usage(argv[0]);
    }
  }

  if (consoleMode) {
    ConsoleUI cui;
    cui.render();
  } else if (guiMode) {
    GUI gui;
    gui.render();
  }

  return 0;
}

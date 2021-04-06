#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;

inline bool exists_test0(const std::string & name) {
  ifstream f(name.c_str());
  return f.good();
}

int main() {

  ifstream dirfile;
  ofstream failsafedir;
  if (exists_test0("dir.txt") == 0) {
    cout << "dir.txt has been created.\n\n";
    cout << "Please fill with appropriate paths in order.\n\n";
    failsafedir.open("dir.txt");
    failsafedir << "Steam\\steamapps\\common\\Red Dead Redemption 2\\x64\\boot_launcher_flow.ymt\ntempfolderyouuse\\boot_launcher_flow.ymt\nSteam\\steamapps\\common\\Red Dead Redemption 2\\x64\\data\\startup.meta\ntempfolderyouuse\\startup.meta\n\n";
    failsafedir << "dir.txt has been created.\n\n";
    failsafedir << "Please fill with appropriate paths in order.\n\n";
    failsafedir.close();
    system("pause");
  }
  string sline, mline, nline;
  int y;
  LPCSTR a = "steam://rungameid/1404210";
  getline(dirfile, nline);

  cout << "        1.Friendly Mode   " << !exists_test0(nline) << endl 
  << "        2.Offline Mode    " << exists_test0(nline) << endl << "        3.Start the Game\n	4.Exit\n";
  cin >> y;
  while (y = !3) {
    switch (y) {
    case 1:
      while (getline(dirfile, sline)) {
        getline(dirfile, mline);
        if (!rename(sline.c_str(), mline.c_str())) {
          cout << "Completed." << endl;
        } else {
          cout << "Failed." << endl;
        }
      }
      break;
    case 2:
      while (getline(dirfile, sline)) {
        getline(dirfile, mline);
        if (!rename(mline.c_str(), sline.c_str())) {
          cout << "Completed." << endl;
        } else {
          cout << "Failed." << endl;
        }
      }
      break;
    case 3:
      ShellExecute(NULL, NULL, a, NULL, NULL, SW_SHOWNORMAL);
      break;
    case 4:
      dirfile.close();
      return 0;
      break;

    }
  }
  dirfile.close();
  return 0;
}
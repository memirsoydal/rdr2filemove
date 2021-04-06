#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;

inline bool exists_test0(const std::string& name)
{
    ifstream f(name.c_str());
    return f.good();
}

int main()
{

    ifstream dirfile;
    ofstream failsafedir;
    if (exists_test0("dir.txt") == 0)
    {
        cout << "dir.txt has been created.\n\n";
        cout << "Please fill with appropriate paths in order.\n\n";
        failsafedir.open("dir.txt");
        failsafedir << "Steam\\steamapps\\common\\Red Dead Redemption "
                       "2\\x64\\boot_launcher_flow.ymt\ntempfolderyouuse\\boot_"
                       "launcher_flow.ymt\nSteam\\steamapps\\common\\Red Dead "
                       "Redemption "
                       "2\\x64\\data\\startup.meta\ntempfolderyouuse\\startup."
                       "meta\n\n";
        failsafedir << "dir.txt has been created.\n\n";
        failsafedir << "Please fill with appropriate paths in order.\n\n";
        failsafedir.close();
        system("pause");
    }
    string sline, mline;
    int y = 0;
    LPCSTR a = "steam://rungameid/1404210";
    while (y != 3 && y != 4)
    {
        system("cls");
        cout << "        1.Friendly Mode\n           2.Offline Mode\n    3.Start "
                "the Game\n	4.Exit\n";
        cin >> y;
        switch (y)
        {
            case 1:
                dirfile.open("dir.txt");
                while (getline(dirfile, sline))
                {
                    getline(dirfile, mline);
                    rename(sline.c_str(), mline.c_str());
                }
                dirfile.close();

                break;
            case 2:
                dirfile.open("dir.txt");
                while (getline(dirfile, sline))
                {
                    getline(dirfile, mline);
                    rename(mline.c_str(), sline.c_str());
                }
                dirfile.close();

                break;
            case 3:
                ShellExecute(NULL, NULL, a, NULL, NULL, SW_SHOWNORMAL);
                break;
            case 4:
                return 0;
                break;
        }
    }
    return 0;
}

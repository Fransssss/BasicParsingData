
#include <iostream>
#include <fstream>
#include <string>

using std::ifstream;
using std::cout;
using std::endl;
using std::string;

int main() {
    cout << "\n   Let's see an imaginary WorldCup Stats!\n" <<  endl;

    int numData = 0;
    ifstream file;
    file.open("TeamsData.txt");

    if(!file.is_open())
    {
        cout << " Cannot open file " << endl;
        return 1;
    } else
    {
        string team;
        int win;
        int loss;
        getline(file,team);                      // Get 1st team name
        while(!file.fail())                             // while there's data in file
        {
            ++numData;
            file >> win;                                // take win number
            if(file.fail())                             // if no win or loss or the end of file/no data when it hits newline
            {
                cout << numData << ". " <<  team << " did not participate " << endl;
            } else
            {
                file >> loss;                           // take loss number
                if(file.fail())                         // if team never lose
                {
                    cout << numData << ". " << team << " has won " << win << " time/s " << endl;
                } else                                  // if team won and lose some
                {
                    cout << numData << ". " << team << " has won "  << win << " time/s and loss " << loss << " time/s" << endl;
                }
                file.ignore();                           // ignore newline in file
            }
                file.clear();                            // clear error state
                cout << endl;
               getline(file, team);               // read next line
        }
    }
    file.close();
    return 0;
}
#include<iostream>
using namespace std;
int main()
{
    int  j, k, rep, pfaults = 0, numofpages, numofFrames;
    cout << "Enter the desired number of frames : ";
    cin >> numofFrames;
    cout << endl;
    cout << "Enter desired number of pages : ";
    cin >> numofpages;
    int* pages = new int[numofpages];
    cout << endl;
    cout << "Enter the  String : ";
    cout << endl;
    for (int i = 0; i < numofpages; i++)
    {
        cout << "\t";
        cin >> pages[i];
    }
    int* frames = new int[numofFrames];
    for (int i = 0; i < numofFrames; i++)
    {
        frames[i] = -1;
    }
    j = 0;
    for (int i = 0; i < numofpages; i++)
    {
        rep = 0;
        for (k = 0; k < numofFrames; k++) {
            if (frames[k] == pages[i]) {
                rep = 1;
            }
        }
        cout << "\n\t  \n";
        cout << "\t" << pages[i] << " --> ";
        if (rep == 0)
        {
            frames[j] = pages[i];
            j = (j + 1) % numofFrames;
            pfaults++;
            for (k = 0; k < numofFrames; k++)
            {
                cout << "\t" << frames[k] << "  ";
            }
        }
    }
    cout << "\n\t  \n";
    cout << "\nPage Fault = " << pfaults;
    cout << "\n";
}
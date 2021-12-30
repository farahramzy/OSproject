#include<iostream>
using namespace std;
int main()
{
    int numofpages, numofFrames;
    int count = 0;
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
    int* framescount = new int[numofFrames];
    int* frames = new int[numofFrames];
    for (int i = 0; i < numofFrames; i++)
    {
        frames[i] = -1;
        framescount[i] = 0;
    }
    int i = 0;
    while (i < numofpages)
    {
        int j = 0, rep = 0;
        while (j < numofFrames)
        {
            if (pages[i] == frames[j]) {
                rep = 1;
                framescount[j] = i + 1;
            }
            j++;
        }
        j = 0;
        cout << endl;
        cout << "\t\t" << pages[i] << " --> ";
        if (rep == 0)
        {
            int victimpage = 0, k = 0;
            while (k < numofFrames - 1)
            {
                //It will choose victim page
                if (framescount[victimpage] > framescount[k + 1])
                    //victimpage
                    victimpage = k + 1;
                k++;
            }
            frames[victimpage] = pages[i];
            framescount[victimpage] = i + 1;
            count++;
            while (j < numofFrames)
            {
                cout << "\t  " << frames[j] << "  ";
                j++;
            }
        }
        i++;
    }
    cout << endl;
    cout << "\t";
    cout << endl;
    cout << "pages Fault = " << count;
    cout << endl;
    return 0;
}
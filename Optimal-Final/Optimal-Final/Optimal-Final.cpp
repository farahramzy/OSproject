#include<iostream>
using namespace std;
int main()
{
    int i, j, f_1, f_2, f_3, x, max;
    int numofpages, numofFrames, NofPFaults = 0;
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
    }

    for (i = 0; i < numofpages; i++) {
        bool p = true;
        f_1 = f_2 = 0;
        for (j = 0; j < numofFrames; j++) {
            if (frames[j] == pages[i]) {
                f_1 = f_2 = 1;
                p = false;
                break;
            }
        }
        cout << endl;
        cout << "\t\t" << pages[i] << " --> ";
        if (f_1 == 0) {
            for (j = 0; j < numofFrames; j++) {
                if (frames[j] == -1) {
                    NofPFaults++;
                    frames[j] = pages[i];
                    f_2 = 1;
                    break;
                }
            }
        }
        if (f_2 == 0) {
            f_3 = 0;
            for (j = 0; j < numofFrames; j++) {
                framescount[j] = -1;
                for (int k = i + 1; k < numofpages; k++) {
                    if (frames[j] == pages[k]) {
                        framescount[j] = k;
                        break;
                    }
                }
            }
            for (j = 0; j < numofFrames; j++) {
                if (framescount[j] == -1) {
                    x = j;
                    f_3 = 1;
                    break;
                }
            }
            if (f_3 == 0) {
                max = framescount[0];
                x = 0;
                for (j = 1; j < numofFrames; j++) {
                    if (framescount[j] > max) {
                        max = framescount[j];
                        x = j;
                    }
                }
            }
            frames[x] = pages[i];
            NofPFaults++;
        }
        if (p == true) {
            for (j = 0; j < numofFrames; j++) {
                cout << "\t" << frames[j] << "  ";
            }
        }
    }
    cout << endl;
    cout << "\t";
    cout << endl;
    cout << "page Faults = " << NofPFaults;
    cout << endl;
}
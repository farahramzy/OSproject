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
    while (i < numofpages)//7
    {
        int j = 0, rep = 0;
        while (j < numofFrames)//3
        {//1 3 3 0 3 5 6 3 - 3 framess
            //   2          0 /1   =  (j=1/
            if (pages[i] == frames[j]) {  //it checks if page is already in one of the frames
                rep = 1;
                framescount[j] = i + 1; //go to next frames =0+1=1   [3][5]
                //
            }
            j++; //next =1
        }
        j = 0;
        cout << endl;
        cout << "\t\t" << pages[i] << " --> ";
        if (rep == 0)
        {
            //1 3 3 0 3 5 6 3 - 3 framess
            // 1 3 0 
        //[1 5 5]  count 
        //i=0/1/2/
            int victimpage = 0, k = 0;
            while (k < numofFrames - 1)//2
            {     //    0/0 -1   0        0/2 - 2   2
                if (framescount[victimpage] > framescount[k + 1]) //It will choose victim page
                    victimpage = k + 1;//victimpage=1 - 2   2
                k++;//k=1/2 - 1 - 1/2   1/2  1/2
            }
            frames[victimpage] = pages[i];//frames[0]=1-frames[1]=3-frames[2]=0
            framescount[victimpage] = i + 1;  //Increasing the time [6 5 5]
            count++;           //it will count the total pages Fault  -----pf=3
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
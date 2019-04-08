
#include <bits/stdc++.h>
using namespace std;


int title = 0;


int main()
{

    int a[10][10] = {0};
    a[5][2] = 8;
     for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j<10; j++)
            cout << a[i][j] <<  "   ";
        cout << endl;
    }
}

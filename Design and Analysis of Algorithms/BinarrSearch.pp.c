#include <iostream>
#include <string>
#include <stdli.h>
using namespace std;


template<class T>
int BinarrSearch(T *a, int size, T x)
{
    int right = size-1;
    int left = 0;
    while(right > left)
    {
        int middle = (right+left)/2;
        if(a[middle] == x)
            return middle;
        if(a[middle] > x)
            right = middle-1;
        else
            left = middle - 1;


    }
}


int main()
{
    /*���鳤��*/
    int size;
    int a[size];
    for(int i = 0; i<size; i++)
        cin >> a[i];
    /*�����ҵ���x*/
    int x;
    cin >> x;


}





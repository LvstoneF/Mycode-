#include <iostream>
#include <bits/stdc++.h>
using namespace std;


template<class T>
int BinarrSearch(T *a, int size, T x)
{
    int right = size-1;
    int left = 0;
    while(right >= left)
    {
        int middle = (right+left)/2;
        if(a[middle] == x)
            return middle;
        if(a[middle] > x)
            right = middle - 1;
        else
            left = middle + 1;


    }
}


int main()
{
    /*数组长度*/
    int size;
    cin >> size;
    int *a;
    for(int i = 0; i<size; i++)
        cin >> a[i];

    /*排序*/
    sort(a, a+size);

    /*待查找的数x*/
    int x;
    cin >> x;

    /* 元素的位置*/
    int pos = -1;
    pos = BinarrSearch(a, size, x);

    if(pos == -1)
        cout << "该元素不再数组中" << endl;
    else
        cout << "该元素在: " << pos+1 << "的位置" <<endl;



}





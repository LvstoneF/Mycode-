
#include <bits/stdc++.h>
using namespace std;

class Jotype{
public:
    int key;
    int index;
    bool job;
};

bool cmp(Jotype a, Jotype b)
{
    return a.key<b.key;
}


int Flowshop(int n, int a[], int b[], int c[])
{
    Jotype *d = new Jotype[n];
    for(int i = 0; i<n; i++)
    {
        d[i].key = a[i]>b[i]?a[i]:b[i];
        d[i].job = a[i]<=b[i];
        d[i].index = i;
    }
    sort(d, d+n, cmp);
    int j = 0;
    int k =n-1;
    for(int i = 0; i<n; i++)
    {
        if(d[i].index)
        {
            c[j++] = d[i].index;
        }
        else
            c[k--] = d[i].index;
    }
    j = a[c[0]]; // 任务c[0]在M完成需要的时间
    k = j+b[c[0]]; //从c[0]需要的总时间
    for(int i = 1; i<n; i++)
    {
        j+=a[c[i]];
        k = j<k ? k+b[c[i]]:j+b[c[i]];
    }
    delete d;
    return k;
}

int main()
{
    int n;
    cout << "输入任务数：";
    cin >> n ;
    /*输入在A 上需要的时间*/
    int *a = new int[n];
    cout << "输入在A 上需要的时间: " ;
    for(int i = 0; i<n; i++)
    {
        cin >> a[i];
    }

     /*输入在A 上需要的时间*/
    int *b = new int[n];
      cout << "输入在B 上需要的时间: " ;
    for(int i = 0; i<n; i++)
    {
        cin >> b[i];
    }
    /*最优调度序列*/
    int *c = new int[n];
    cout << "加工需要而最少时间为：" << Flowshop(n, a, b, c) << endl;

    cout << "最优调度序列为：" << endl;
    for(int i = 0; i < n; i++)
    {
        cout << c[i] << " ";
    }

}



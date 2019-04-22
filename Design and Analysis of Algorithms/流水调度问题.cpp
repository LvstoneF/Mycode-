
#include <bits/stdc++.h>
using namespace std;

class Jotype{
public:
    int key;
    int index;
    bool job;
};

/*sort 的比较函数，用来进行Jotype 的比较*/
bool cmp(Jotype a, Jotype b)
{
    return a.key<b.key;
}

/*  1, n 任务数
    2, a[] 在机A上的时间
    3, b[] 在机器B上的时间
    4, c[] 用来保存最优的调度序列
*/
int Flowshop(int n, int a[], int b[], int c[])
{
    Jotype *d = new Jotype[n];
    /*  1. d[i].key 用来保存时间比较大的任务
        2. d[i].job 用来表示当前任务是应该用前面开始放还是后面开始放
        3. d[i].index 用来表示这是第几个任务。
         a[i]<a[i+1]<a[i+n]||b[i+n+1]<b[i+n+2]<b[i+n+k]
         b[i] b[i+1] b[i+n]||a[i+n+1] a[i+n+2] s[i+n+k]
        上面的对应的项都大于下面的项
    */
    for(int i = 0; i<n; i++)
    {
        d[i].key = a[i]>b[i]?a[i]:b[i];
        d[i].job = a[i]<=b[i];
        d[i].index = i;
    }
    /*根据key的值从小到大进行排序*/
    sort(d, d+n, cmp);

    int j = 0;
    int k = n-1;
    /*开始往c[]里面进行排序，得到最优的调度序列
    d[i].index == 1 从前面开始一个一个填
    否则从后面开始
    */
    for(int i = 0; i<n; i++)
    {
        if(d[i].job)
        {
            c[j++] = d[i].index;
        }
        else
            c[k--] = d[i].index;
    }
    /*
    j 在机器A上的时间
    k 总时间
    */
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
    cout << "加工需要的最少时间为：" << Flowshop(n, a, b, c) << endl;

    cout << "最优调度序列为：" << endl;
    for(int i = 0; i < n; i++)
    {
        cout << c[i] << " ";
    }

}



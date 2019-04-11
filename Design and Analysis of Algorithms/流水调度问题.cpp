
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
    j = a[c[0]]; // ����c[0]��M�����Ҫ��ʱ��
    k = j+b[c[0]]; //��c[0]��Ҫ����ʱ��
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
    cout << "������������";
    cin >> n ;
    /*������A ����Ҫ��ʱ��*/
    int *a = new int[n];
    cout << "������A ����Ҫ��ʱ��: " ;
    for(int i = 0; i<n; i++)
    {
        cin >> a[i];
    }

     /*������A ����Ҫ��ʱ��*/
    int *b = new int[n];
      cout << "������B ����Ҫ��ʱ��: " ;
    for(int i = 0; i<n; i++)
    {
        cin >> b[i];
    }
    /*���ŵ�������*/
    int *c = new int[n];
    cout << "�ӹ���Ҫ������ʱ��Ϊ��" << Flowshop(n, a, b, c) << endl;

    cout << "���ŵ�������Ϊ��" << endl;
    for(int i = 0; i < n; i++)
    {
        cout << c[i] << " ";
    }

}



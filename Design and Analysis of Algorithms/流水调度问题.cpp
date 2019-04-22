
#include <bits/stdc++.h>
using namespace std;

class Jotype{
public:
    int key;
    int index;
    bool job;
};

/*sort �ıȽϺ�������������Jotype �ıȽ�*/
bool cmp(Jotype a, Jotype b)
{
    return a.key<b.key;
}

/*  1, n ������
    2, a[] �ڻ�A�ϵ�ʱ��
    3, b[] �ڻ���B�ϵ�ʱ��
    4, c[] �����������ŵĵ�������
*/
int Flowshop(int n, int a[], int b[], int c[])
{
    Jotype *d = new Jotype[n];
    /*  1. d[i].key ��������ʱ��Ƚϴ������
        2. d[i].job ������ʾ��ǰ������Ӧ����ǰ�濪ʼ�Ż��Ǻ��濪ʼ��
        3. d[i].index ������ʾ���ǵڼ�������
         a[i]<a[i+1]<a[i+n]||b[i+n+1]<b[i+n+2]<b[i+n+k]
         b[i] b[i+1] b[i+n]||a[i+n+1] a[i+n+2] s[i+n+k]
        ����Ķ�Ӧ��������������
    */
    for(int i = 0; i<n; i++)
    {
        d[i].key = a[i]>b[i]?a[i]:b[i];
        d[i].job = a[i]<=b[i];
        d[i].index = i;
    }
    /*����key��ֵ��С�����������*/
    sort(d, d+n, cmp);

    int j = 0;
    int k = n-1;
    /*��ʼ��c[]����������򣬵õ����ŵĵ�������
    d[i].index == 1 ��ǰ�濪ʼһ��һ����
    ����Ӻ��濪ʼ
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
    j �ڻ���A�ϵ�ʱ��
    k ��ʱ��
    */
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



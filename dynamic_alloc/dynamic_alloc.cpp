#include<bits/stdc++.h>
using namespace std;
void firstfit(int p[],int arr1[],int n,int b)
{
    cout << "\n First fit";
    for (int i = 0; i < n;++i)
    {
        for (int j = 0; j < b;++j)
        {
            if(p[i]<arr1[j])
            {

                cout << "\n the process is allocated to" << arr1[j] << "block";
                cout << "\nthe hole left after" << i + 1 << "process is" << arr1[j] - p[i];
                arr1[j] = arr1[j] - p[i];
                break;
            }
        }
    }
}
void bestfit(int p[], int arr2[], int n, int b)
{
    cout << "\nBest fit";
    sort(arr2, arr2 + b);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < b; ++j)
        {
            if (p[i] < arr2[j])
            {
                cout << "\n the process is allocated to" << arr2[j] << "block";
                cout << "\nthe hole left after" << i + 1 << "process is" << arr2[j] - p[i];
                arr2[j] = arr2[j] - p[i];
                break;
            }
        }
    }
}
void worstfit(int p[], int arr2[], int n, int b)
{
    int temp;
    cout << "\nworst fit";
    sort(arr2, arr2 + b);
    for (int i = 0; i < n; ++i)
    {
        int max = arr2[0];
        for (int j = 0; j < b; ++j)
        {
           if(arr2[j]>max)
           {
               max = arr2[j];
               temp = j;
           }
        }
        cout << "\n the process is allocated to" << max << "block";
        cout << "\nthe hole left after" << i + 1 << "process is" << arr2[temp] - p[i];
        arr2[temp] = arr2[temp] - p[i];
    }
}
int main()
{
    int n, b, choice;
    int p[4] = {212, 417, 112, 426};
    int arr[5] = {100, 500, 200, 300, 600};
    cout << "enter your choice \n1.firstfit\n2.bestfit\n3.worstfit";
    cin >> choice;
    if(choice==1)
        firstfit(p, arr, 4, 5);
    else if(choice==2) 
       bestfit(p, arr, 4, 5);
    else
        worstfit(p, arr, 4, 5);
    return 0;
}
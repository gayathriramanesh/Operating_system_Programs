#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
int n;
int arr[50];
float avg1, max1, min1;
void *avg()
{
    avg1 = 0;
    for (int i = 0; i < n;++i)
    {
        avg1 += arr[i];
    }
    avg1 =avg1 / n;
    printf("\n the average of these numbers is %f", avg1);
}
void *max()
{
    max1 = 0;
    for (int i = 0; i < n; ++i)
    {
        if(arr[i]>max1)
        {
            max1 = arr[i];
        }
    }
    printf("\n the maximum of these numbers is %f", max1);
}
void *min()
{
    min1 = arr[1];
    for (int i = 0; i < n; ++i)
    {

        if (arr[i] <min1)
        {
            min1 = arr[i];
        }
    }
    printf("\n the minimum of these numbers is %f", min1);
}
void main(int argc,char *argv[])
{
    n = argc - 1;
    for (int i = 0; i < n;++i)
    {
        arr[i] = atoi(argv[i + 1]);
    }
    pthread_t pid, pid1, pid2;
    pthread_create(&pid, NULL, *avg, NULL);
    pthread_join(pid, NULL);
    pthread_create(&pid1, NULL, *max, NULL);
    pthread_join(pid1, NULL);
    pthread_create(&pid2, NULL, *min, NULL);
    pthread_join(pid2, NULL);
}
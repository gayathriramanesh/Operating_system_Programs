#include<bits/stdc++.h>
using namespace std;
#define file_size 50
void seq(int *files)
{
    int strtblk, no_of_files;
    cout << "SEQUENTIAL ALLOCATION";
    cout << "\n enter the starting block size";
    cin >> strtblk;
    cout << "\n enter the no of files";
    cin >> no_of_files;
    for (int i = strtblk; i < (strtblk+no_of_files);++i)
    {
        files[i] = 1;
    }
    cout << "\n the files are allocated in the blocks successfully";
}
void index(int *files)
{
    int ind, fs;
    cout << "\n INDEXED ALLOCATION";
    cout << "\n enter the index block";
    cin >> ind;
    if(files[ind]==1)
    {
        cout << "\n please enter the index block again";
        cin >> ind;
    }
    cout << "\n enter the no of files";
    cin >> fs;
    int ind_file[fs];
    for (int i = 0; i<fs;++i)
    {
        cout <<"\nenter the files";
        cin >> ind_file[i];
        files[ind_file[i]] = 1;
    }
    cout << "\n file"
         << "\t" << "index";
    for (int i = 0; i < fs; ++i)
    {
        cout << "\n"<<ind
             << "\t" << ind_file[i];
    }
}
int main()
{
    int files[file_size];
    for (int i = 0; i < file_size;++i)
    {
        files[i] = 0;
    }
    seq(files);
    index(files);
    return 0;
}
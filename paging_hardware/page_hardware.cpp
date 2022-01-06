#include<bits/stdc++.h>
using namespace std;
#define strt_addr 5000
void display(int *pg_table,int no_of_frames,int fs)
{
    cout << "\n Page table\n";
    cout << "\nframe no"
         << "\t"
         << "physical address";
    int count = 0;
    for (int i = 0; i < no_of_frames;++i)
    {
        cout << "\nframe" << i <<"\t"<< pg_table[i] <<"\t"<< strt_addr + count;
        count = count + fs;
    }
}
int main()
{
    int phy_add, fs, pg_no, no_of_frames;
    cout << "enter the no_of_frames";
    cin >> no_of_frames;
    cout << "\n enter the frame size";
    cin >> fs;
    cout << "\n enter the no of pages";
    cin >> pg_no;
    int pg_table[no_of_frames];
    cout << "\n before allocation";
    for (int i = 0; i < no_of_frames; ++i)
    {
        pg_table[i] = -1;
    }
    display(pg_table, no_of_frames,fs);
    while(pg_no)
    {
        int i = rand() % no_of_frames; //for getting  random frame no
        if(pg_table[i]==-1)
        {
        pg_table[i] = pg_no;
        pg_no--;
        }
    }
    cout << "\n after allocation";
    display(pg_table, no_of_frames,fs);
    int pg, offset;
    cout << "\n enter the page no  and offset";
    cin >> pg >> offset;
    if (offset > fs)
    {
        cout << "\n invalid offset";
        exit(0);
    }
    int count = 1;
    for (int i = 1; i <=no_of_frames;++i)
    { 
    
        if(pg==pg_table[i])
        {
            
            cout << "physical address is" << (fs *(count) )+ offset+ strt_addr;
        }
        count++;
    }
    return 0;
}
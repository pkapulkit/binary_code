#include<bits/stdc++.h>
#include<string>
#include<unistd.h>
using namespace std;

class buddy
{

int size;
vector<pair<int, int>> free_list[100000];
map<int, int> mp;
public:
void start()
{
cout<<"\n ----------------------------------------------------------------------------------------";
cout<<"\n                       ~ BINARY BUDDY ALGORITHM";
cout<<"\n-----------------------------------------------------------------------------------------";
cout<<" \a"<<endl;
}
void menu()
{
int ch;
cout<<"\n 1. Binary Buddy \n 2. Display Details \n 3. Exit "<<endl;
cout<<" Choose the option: ";
cin>>ch;
switch(ch)
{
case 1 :
binary_buddy();
break;

case 2 :
display();
break;

case 3 :
exit(0);
break;
default:
cout<<"\n Invalid input";

}
}
void binary_buddy(){
    int total,c,req;
    cout<<"Please Intialize the Memory\n";
    cin>>total;
    initialize(total);
    while(true)
    {
        cout<<"Request for Memory\n";
        cin>>req;
        if(req < 0)
            break;
        allocate(req);
        break;
    }
    menu();
    
}
void initialize(int sz)
{
     
    // Maximum number of powers of 2 possible
    int n = ceil(log(sz) / log(2));
    size = n + 1;
     
    for(int i = 0; i <= n; i++)
        free_list[i].clear();
 
    // Initially whole block of specified
    // size is available
    free_list[n].push_back(make_pair(0, sz - 1));
}
void allocate(int sz)
{
     
    // Calculate index in free list
    // to search for block if available
    int n = ceil(log(sz) / log(2));
     
    // Block available
    if (free_list[n].size() > 0)
    {
        pair<int, int> temp = free_list[n][0];
 
        // Remove block from free list
        free_list[n].erase(free_list[n].begin());
        cout << "Memory from " << temp.first
             << " to " << temp.second << " allocated"
             << "\n";
 
        // map starting address with
        // size to make deallocating easy
        mp[temp.first] = temp.second -
                         temp.first + 1;
    }
    else
    {
        int i;
        for(i = n + 1; i < size; i++)
        {
             
            // Find block size greater than request
            if(free_list[i].size() != 0)
                break;
        }
 
        // If no such block is found
        // i.e., no memory block available
        if (i == size)
        {
            cout << "Sorry, failed to allocate memory \n";
        }
         
        // If found
        else
        {
            pair<int, int> temp;
            temp = free_list[i][0];
 
            // Remove first block to split it into halves
            free_list[i].erase(free_list[i].begin());
            i--;
             
            for(; i >= n; i--)
            {
                 
                // Divide block into two halves
                pair<int, int> pair1, pair2;
                pair1 = make_pair(temp.first,
                                  temp.first +
                                  (temp.second -
                                  temp.first) / 2);
                pair2 = make_pair(temp.first +
                                  (temp.second -
                                  temp.first + 1) / 2,
                                  temp.second);
                                   
                free_list[i].push_back(pair1);
 
                // Push them in free list
                free_list[i].push_back(pair2);
                temp = free_list[i][0];
 
                // Remove first free block to
                // further split
                free_list[i].erase(free_list[i].begin());
            }
            cout << "Memory from " << temp.first
                 << " to " << temp.second
                 << " allocated" << "\n";
                  
            mp[temp.first] = temp.second -
                             temp.first + 1;
        }
    }
}

void display(){
    cout<<"hello";
     menu();
     
}


};
int main()
{
buddy b;
b.start();
b.menu();
return 0;
}
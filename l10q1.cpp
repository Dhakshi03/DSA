//Popping only the 1st element till you get a list of distinguished elements only

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int test, no, count;

    cout<<"\nEnter no. of test cases: ";
    cin>>test;

    while(test--)
    {
        count=0;
        cout<<"\nNo. of elements: ";
        cin>>no;
        vector<int> arr(no);
        for(int i=0;i<no;i++)
        {
            cin >> arr[i];
        }

        //checking whether the elements are unique
        //int unique[no];
        
        while(true)
        {
            bool hasduplicate=false;
            for(int i=0; i<arr.size(); i++)
            {
                for(int j=i+1; j<arr.size(); j++)
                {
                    if (arr[i]==arr[j])
                    {
                        arr.erase(arr.begin()); //pops the first element
                        count++;
                        hasduplicate=true;
                        break;
                    }
                }
                if (hasduplicate) break; //breaking out of the loop if a dupplicate is found
            }
            if (!hasduplicate) break; //if no duplicates found, you break out of the loop completely
        }

        cout<<"\nYou need to perform "<<count<< " no. of moves.\n";
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
    int test;
    cin>>test;

    while(test--)
    {
        int no;
        cin>>no;

        vector<string> player[3]; //player[0] , player[1] , player[2]
        unordered_map<string, int> wordCount; //wordCount: An unordered_map to track how many times each word appears across all players
        //wordCount is a userdefined variable and not any keyword

        //Getting input words for all players
        for(int i=0; i<3; i++)
        {
            player[i].resize(no);
            for(int j=0; j<no; j++)
            {
                cin >> player[i][j];
                wordCount[player[i][j]]++;
            }
        }

        //Score calculation
        int score[3] = {0};
        for(int i=0; i<3; i++)
        {
            for (string& word : player[i]) //This declares word as a reference to each string in the vector
            //Using a reference allows for efficient access to the strings without copying them.
            //The loop iterates over each word in the vector for the current player (player[i])
            {
                if(wordCount[word]==1)
                {
                    score[i]+=3;
                }
                else if(wordCount[word]==2)
                {
                    score[i]+=1;
                }
                //else score[i]+=0 because all three players would have that word
            }
        }
        cout<<"\nThe scores of the three players are as follows: "<<score[0]<<" "<<score[1]<<" "<<score[2]<<"\n";
    }
    return 0;
}
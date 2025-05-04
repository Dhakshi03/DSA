#include <iostream>
using namespace std;
#define MAX 50

class graph
{
    private:
    int mat[MAX][MAX];
    int vertice;

    public:
    graph(int v)
    {
        vertice=v;
        for(int i=0; i<v; i++)
        {
            for(int j=0; j<v; j++)
            {
                mat[i][j]=0;
            }
        }
    }

    //checking validity of the vertices
    bool isvalid(int v)
    {
        if(v>0 && v<vertice)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //insert
    void ins(int v, int u)
    {
        if (isvalid(v) && isvalid(u))
        {
            mat[v][u]=1;
        }
        else
        {
            cout << "Invalid vertices";
        }
    }

    //delete
    void del(int v, int u)
    {
        if (isvalid(v) && isvalid(u))
        {
            if(mat[v][u]!=0)
            {
            mat[v][u]=0;
            }
            else
            {
                cout<<"Already 0";
            }
        }
        else
        {
            cout <<"Invalid vertices";
        }
    }

    //search
    void search(int v, int u)
    {
        if (isvalid(v) && isvalid(u))
        {
            if (mat[v][u]==1)
            {
                cout <<"Yes";
            }
            else
            {
                cout <<"No";
            }
        }
        else
        {
            cout<<"Invalid vertices";
        }
    }

    //display
    void display()
    {
        for (int i=0; i<vertice; i++)
        {
            for (int j=0; j<vertice; j++)
            {
                cout<<mat[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
};

int main()
{
    int choice, v, u, vertice;

    cout << "Enter the number of vertices (max " << MAX << "): ";
    cin >> vertice;

    if (vertice <= 0 || vertice > MAX) {
        cout << "Invalid number of vertices. Exiting...\n";
        return 0;
    }

    graph g(vertice);
    
    while(1)
    {
    cout << "\n---- Graph Menu ----\n";
    cout << "1. Insert Edge\n";
    cout << "2. Delete Edge\n";
    cout << "3. Check/Search Edge\n";
    cout << "4. Display Adjacency Matrix\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
        case 1:
            cout << "Enter source and destination vertex: ";
            cin >> v >> u;
            g.ins(v, u);
            break;
        case 2:
            cout << "Enter source and destination vertex: ";
            cin >> v >> u;
            g.del(v, u);
            break;
        case 4:
            g.display();
            break;
        case 3:
            cout << "Enter source and destination vertex: ";
            cin >> v >> u;
            g.search(v, u);
            break;
        case 5:
            cout << "Exiting...\n";
            exit(0);
        default:
            cout << "Invalid choice. Please try again.\n";
    }
}

    return 0;

}
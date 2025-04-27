#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
#include"l6q3.h"



int main(){
    post obj;
    int choice,ch=1;
    string s;
    while(ch){
        printf("1.Enter Infix\n2.Convert to Postfix\n3.Evaluate Postfix\n4.Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch (choice){
            case 1:
                printf("Enter the string: ");
                cin>>s;
                break;
            case 2:
                cout<<obj.infix_convert(s);
                printf("\n");
                break;
            case 3:
                cout<<obj.post_evaluation(obj.infix_convert(s));
                printf("\n");
                break;
            case 4:
                printf("Exiting...\n");
                ch=0;
                break;
            default:
                printf("Enter a Valid Choice!!\n");
                break;

        }
    }
}


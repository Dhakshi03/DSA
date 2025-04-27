#include<iostream>
#include<stack>
#include <cstring>
using namespace std;

class paranthesis{
    stack<char> st;

    public:
        bool validstring(string s){
            for (char c : s)
            {
                if(c=='{' || c=='[' || c=='('){
                    st.push(c);
                }
                else{
                    if(st.empty()){
                        printf("FALSE\n");
                        return false;
                    }

                    if((c=='}' && st.top()!='{') || (c==']' && st.top()!='[') || (c==')' && st.top()!='(')) 
                    {
                        printf("FALSE\n");
                        return false;
                    }
                
                        st.pop();
                    
                } 
            }
            
            if(st.empty()){
                printf("TRUE\n");
                return true;
            }
            else{
                printf("FALSE\n");
                return false;
            }
        }
};


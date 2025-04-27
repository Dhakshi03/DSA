#include<iostream>
#include<stack>
using namespace std;

class post {
    stack<char> st;
    string postfix;
    
public:
    string infix_convert(string);
    int post_evaluation(string);
    
    int is_operator(char c) {
        return (c == '!' || c == '~' || c == '*' || c == '/' || c == '%' ||
                c == '+' || c == '-' || c == '&' || c == '^' || c == '|' || c == '=');
    }

    int precedence(char c) {
        if (c == '!' || c == '~') return 7;
        if (c == '*' || c == '/' || c == '%') return 6;
        if (c == '+' || c == '-') return 5;
        if (c == '&') return 4;
        if (c == '^') return 3;
        if (c == '|') return 2;
        if (c == '=') return 1;  // Assignment operator, usually not included
        return -1;  // Invalid operator
    }
};

string post::infix_convert(string s) {
    postfix = "";  // Reset postfix expression

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        // If character is an operand (variable or digit)
        if (isalnum(c)) {
            postfix += c;
        }
        // If opening parenthesis, push to stack
        else if (c == '(') {
            st.push(c);
        }
        // If closing parenthesis, pop till '(' is found
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop(); // Remove '('
        }
        // If operator
        else if (is_operator(c)) {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop remaining operators
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int post::post_evaluation(string s){
    for(char c :s) {
        if(isdigit(c)) {
            st.push(c - '0'); 
        }
        else {
            int val2 = st.top(); 
            st.pop();
            int val1 = st.top(); 
            st.pop();
            
            switch(c) {
                case '+': 
                    st.push(val1 + val2);
                    break;
                case '-': 
                    st.push(val1 - val2);
                    break;
                case '*': 
                    st.push(val1 * val2);
                    break;
                case '/': 
                    st.push(val1 / val2);
                    break;
                default:
                    cout << "Invalid operator encountered: " << c << endl;
                    return -1;
            }
        }
    }
    
    return st.top();

}
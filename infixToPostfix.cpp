#include <iostream>
#include <cstring>
using namespace std;

class Stack
{
  char data[50];
  int top;
  public:
    Stack()
    {top = -1;}
     
    void push(char x)
    {data[++top] = x;}
    
    char pop()
    {return data[top--];}
    
    bool isEmpty()
    { return top==-1;}
    
    char Top()
    {return data[top];}
};

bool isOperator(char c)
{
  return (c == '+' || c == '-' || c == '*' || c=='/');
}

int precedence(char c)
{
  if(c=='^') return 3;
  if(c=='*' || c=='/') return 2;
  if(c=='+' || c=='-') return 1;
  return 0;
}

void infixToPostfix(char* infix, char* postfix)
{
  Stack S;
  int k = 0; //index for postfix
  
  for(int i = 0; i< infix[i] != '\0';i++)
  {
    char token = infix[i]; 
    
    if((token>='A' && token <='Z') || (token<='a' && token >='z') || (token >='0' && token <='9'))
    {
      postfix[k++] = token;
      
    }
    
    else if(token=='(')
    {
      S.push(token);
    }
    
    else if(token==')')
    {
      while(!S.isEmpty() && S.Top() != '(')
      {
        postfix[k++] = S.pop();
      }
      if (!S.isEmpty() && S.Top() == '(')
      {
        S.pop();
      }
    }
    else if(isOperator(token))
    {
      while(!S.isEmpty() && S.Top() != '(' && precedence(S.Top()) >=precedence(token))
      {
        postfix[k++] = S.pop();
      }
      S.push(token);
    }
  }
  while(!S.isEmpty())
  {
    postfix[k++] = S.pop();
  }
  
  postfix[k] = '\0';
}

int main()
{
  char infix[50],postfix[50];
  cout<<"Enter infix expression : ";
  cin>>infix;
  
  infixToPostfix(infix,postfix);
  
  cout<<"Postfix expression : "<<postfix<<endl;
  
  return (0);
}
      

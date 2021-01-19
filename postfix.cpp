// Copyright 2020 A.SHT
#include "MyStack.h"
#include "postfix.h"
#include <iostream>

int returnPriority(char a)
{
  if (a == '*' || a == '/')
    return 3;
  else if (a == '+' || a == '-')
    return 2;
  else if (a == '(')
    return 1;
}

std::string infix2postfix(std::string infix) {
  MyStack<char> stack(infix.size());
  std::string str_out;
  int j=0;
  for (int i = 0; i < infix.size(); i++)
  {
    if (infix[i] == ' ')
      continue;
    
    if (infix[i] >= '0' && infix[i] <= '9' || infix[i] == '.')
      str_out.push_back(infix[i]);
    else if (infix[i] == '(')
      stack.push(infix[i]);
    else if (infix[i] == ')')
    {
      while (stack.get() != '(')
        str_out.push_back(stack.pop());
      stack.pop();
    }
    else if (stack.isEmpty() || 
    returnPriority(stack.get()) < returnPriority(infix[i]))
      stack.push(infix[i]);
    else if (returnPriority(stack.get()) >= returnPriority(infix[i]))
    {
      while (!stack.isEmpty() && returnPriority(stack.get()) >= returnPriority(infix[i]))
        str_out.push_back(stack.pop());
      stack.push(infix[i]);
    }
  } 
  while (!stack.isEmpty())
    str_out.push_back(stack.pop());
  
  return str_out;
}

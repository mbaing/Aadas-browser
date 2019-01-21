#include<stdio.h>
#include<string.h>
#include<ctype.h>

using namespace std; 
  
// A utility function to check if a given character is operand 
bool isOperand(char c) { return (c >= '0' && c <= '9'); } 
  
// utility function to find value of and operand i.e '1' = 49 so 49-48 = 1(value)
int value(char c) {  return (c - '0'); }

// This function evaluates simple expressions. It returns -1 if the 
// given expression is invalid. 
int evaluate(char *exp) 
{ 
   int res;
    // Base Case: Given expression is empty 
    if (*exp == '\0')  return -1; 
    
    // The first character must be an operand, find its value 
     res = value(exp[0]); 
    // Traverse the remaining characters in pairs 
    for (int i = 1; exp[i]; i += 2) 
    { 
        // The next character must be an operator, and 
        // next to next an operand 
        char opr = exp[i], opd = exp[i+1]; 
  
        // If next to next character is not an operand 
        if  (!isOperand(opd))  return -1; 
        // If next to next character is not an operand 
        if (!isOperand(opd))  return -1; 
        // Update result according to the operator 
        if (opr == '+')       res += value(opd);
        else if (opr == '-')  res -= value(opd); 
        else if (opr == '*')  res *= value(opd); 
        else if (opr == '/')  res /= value(opd); 
        // If not a valid operator 
        else                 
           return -1; 
    } 
    return res; 
} 
int main(int argc , char *argv[])
{ 
  char expr1[50];
  strcpy(expr1,argv[1]);


 int res = evaluate(expr1); 
    (res == -1)? printf("%s is Invalid\n",expr1): 
                 printf("Value of %d is\n",res); 
 return 0;
}


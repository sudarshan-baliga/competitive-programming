#include <stdio.h>
#include <stdlib.h>
struct node
{
    char ary[100];
    int top;
};
struct node s;
char postfix[100],infix[100],sym;
int pos = 0;
int precedence(char sym)
{
    switch(sym)
    {
    case '$':
        return 3;
    case '/':
    case '*':
            return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}
int main()
{
   s.top = -1;
   scanf("%s",infix);
   int i = 0;
   for(;i < strlen(infix);i++)
   {
       sym = infix[i];
       switch(sym)
       {
       case '(':
                s.ary[++s.top] = sym;
                break;
       case ')':
                while(s.top != -1 && s.ary[s.top] != '(')
                {
                    postfix[pos++] = s.ary[s.top--];
                }
                s.top--;
                break;

       case '+':
       case '-':
       case '*':
                while(s.top != -1 && precedence(s.ary[s.top])>=precedence(sym))
                {
                    postfix[pos++] = s.ary[s.top--];
                }
                s.ary[++s.top] = sym;

                break;
       default:
                postfix[pos++] = sym;
       }
   }

   while(s.top != -1 )
   {
       postfix[pos++] = s.ary[s.top--];
   }

   printf("%s",postfix);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 100

typedef enum
{
    lparen,
    rparen,
    plus,
    minus,
    times,
    divide,
    mod,
    eos,
    operand
} precedence;

int stack[MAX_STACK_SIZE];
char iexpr[MAX_EXPR_SIZE];
char pexpr[MAX_EXPR_SIZE] = "";
int top = -1;

precedence get_token(char *psymbol, int *pn)
{
    *psymbol = iexpr[(*pn)++];
    switch (*psymbol)
    {
    case '(':
        return lparen;
    case ')':
        return rparen;
    case '+':
        return plus;
    case '-':
        return minus;
    case '*':
        return times;
    case '/':
        return divide;
    case '%':
        return mod;
    case ' ':
        return eos;
    default:
        return operand;
    }
}

int eval()
{
    precedence token;
    char symbol;
    int op1, op2;
    int n = 0;
    int top = -1;
    token = get_token(&symbol, &n);
    while (token != eos)
    {
        if (token == operand)
            push(&top, symbol - '0');
        else
        {
            op2 = pop(&top);
            op1 = pop(&top);
            switch (token)
            {
            case plus:
                push(&top, op1 + op2);
                break;
            case minus:
                push(&top, op1 - op2);
                break;
            case times:
                push(&top, op1 * op2);
                break;
            case divide:
                push(&top, op1 / op2);
                break;
            case mod:
                push(&top, op1 % op2);
                break;
            }
        }
        token = get_token(&symbol, &n);
    }
    return pop(&top);
}

void print_token(precedence token)
{
    switch (token)
    {
    case plus:
        printf("+");
        break;
    case minus:
        printf("-");
        break;
    case divide:
        printf("/");
        break;
    case times:
        printf("*");
        break;
    case mod:
        printf("%");
        break;
    }
}

precedence pstack[MAX_STACK_SIZE];
static int isp[] = {0, 19, 12, 12, 13, 13, 13, 0};
static int icp[] = {20, 19, 12, 12, 13, 13, 13, 0};

void infix_to_postfix()
{
    char symbol;
    precedence token;
    int n = 0;
    pstack[0] = eos;
    int top = 0;
    token = get_token(&symbol, &n);

    for (; token != eos; token = get_token(&symbol, &n))
    {
        if (token == operand)
            printf("%c", symbol);

        else if (token == rparen)
        {
            while (pstack[top] != lparen)
                print_token(pop(&top));
            pop(&top);
        }

        else
        {
            while (isp[pstack[top]] >= isp[token])
                print_token(pop(&top));
            push(&top, token);
        }
    }
    while ((token = pop(&top)) != eos)
        print_token(token);
    printf("\n");
}

int IsEmpty()
{
    return (top < 0);
}
int IsFull()
{
    return (top >= MAX_STACK_SIZE - 1);
}
void push(int *ptop, int item)
{
    if (*ptop >= MAX_STACK_SIZE - 1)
    {
        IsFull();
        return;
    }
    printf("push: %d\n", item);
    stack[++*ptop] = item;
}

int pop(int *ptop)
{
    if (*ptop == -1)
    {
        IsEmpty();
    }
    else
    {
        printf("pop: %d\n", stack[*ptop]);
        return stack[(*ptop)--];
    }
}

int main(void)
{
    printf("please input\n");
    scanf("%s", &iexpr);
    infix_to_postfix();

    return 0;
}
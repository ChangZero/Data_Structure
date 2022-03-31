#include <stdio.h>
#include <stdlib.h>

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
char pexpr[MAX_EXPR_SIZE];

static int isp[] = {0, 19, 12, 12, 13, 13, 13, 0};
static int icp[] = {20, 19, 12, 12, 13, 13, 13, 0};

void print_token(int token)
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
        printf("%%");
        break;
    default:
        break;
    }
}

void push(int *ptop, int item)
{
    if (*ptop >= MAX_STACK_SIZE - 1)
    {
        return;
    }
    stack[++*ptop] = item;
}
int pop(int *ptop)
{
    if (*ptop == -1)
    {
        exit(1);
    }
    else
    {
        return stack[(*ptop)--];
    }
}

precedence get_token(char *symbol, int *n)
{
    *symbol = iexpr[*n];
    (*n)++;

    switch (*symbol)
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

int eval(void)
{
    precedence token;
    int op1, op2, n = 0, top = -1;
    char symbol;
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
            default:
                break;
            }
        }
        token = get_token(&symbol, &n);
    } // while
    return pop(&top);
}

void infix_to_postfix(void)
{
    // e는 주어진 중위표기식으로 끝은 ;으로 표시
    // ISP와 ICP는 우선 순위를 반환해주는 함수
    // pos는 e에서 현재 위치
    char symbol;
    precedence token;
    int n = 0, top = 0;
    stack[top] = eos;
    for (; token != eos; token = get_token(&symbol, &n))
    {
        if (token == operand)
            printf("%c", symbol);
        else if (token == rparen)
        {
            while (stack[top] != lparen)
                print_token(pop(&top));
            pop(&top); // 왼쪽괄호를 버림
        }
        else
        {
            while (isp[stack[top]] >= icp[token])
                print_token(pop(&top));
            push(&top, token);
        } // else
    }     // for
    while ((token = pop(&top)) != eos)
        print_token(token);
    print_token('\n');
}

int main(void)
{
    printf("Please input string: ");
    scanf("%s", iexpr);
    infix_to_postfix();

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 100

typedef struct result
{
    char infix[MAX_EXPR_SIZE];
    char postfix[MAX_EXPR_SIZE];
    int eval_result;
} Output;

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

void print_token(precedence token, int *p)
{
    if (token == plus)
        pexpr[(*p)++] = '+';
    else if (token == minus)
        pexpr[(*p)++] = '-';
    else if (token == times)
        pexpr[(*p)++] = '*';
    else if (token == divide)
        pexpr[(*p)++] = '/';
    else if (token == mod)
        pexpr[(*p)++] = '%';
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
    return stack[(*ptop)--];
}

precedence get_token(char expr[], char *symbol, int *n)
{
    *symbol = expr[(*n)++];

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
    case '$':
        return eos;
    default:
        return operand;
    }
}

int eval(void)
{
    precedence token;
    int op1, op2;
    int n = 0, top = -1;
    char symbol;
    token = get_token(pexpr, &symbol, &n);
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
        token = get_token(pexpr, &symbol, &n);
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
    int n = 0, top = 0, p = 0;
    stack[0] = eos;
    for (token = get_token(iexpr, &symbol, &n); token != eos; token = get_token(iexpr, &symbol, &n))
    {
        if (token == operand)
            pexpr[p++] = symbol;
        else if (token == rparen)
        {
            while (stack[top] != lparen)
                print_token(pop(&top), &p);
            pop(&top); // 왼쪽괄호를 버림
        }
        else
        {
            while (isp[stack[top]] >= icp[token])
                print_token(pop(&top), &p);
            push(&top, token);
        } // else
    }     // for
    while ((token = pop(&top)) != eos)
        print_token(token, &p);
    pexpr[p] = '$';
}

void reset()
{
    int i;
    for (i = 0; i < MAX_EXPR_SIZE; i++)
    {
        iexpr[i] = ' ';
        pexpr[i] = ' ';
    }
}
int main(void)
{
    Output output[MAX_STACK_SIZE];
    int num_count = 0;
    int i = 0, k = 0, j;
    char c;
    FILE *fp = NULL;
    fp = fopen("test.txt", "r");

    while ((c = fgetc(fp)) != EOF)
    {
        if (c == '$')
        { //'$'가 나오면 출력
            iexpr[i] = c;
            strcpy(output[k].infix, iexpr);

            infix_to_postfix();
            output[k].eval_result = eval();

            char *ptr = strtok(pexpr, "$"); //첫번째 strtok 사용.
            strcpy(output[k].postfix, ptr);

            k++;
            num_count++;
            i = 0;
            reset();
        }
        else if (isdigit(c)) // c가 숫자이면 infix에 저장
            iexpr[i++] = c;

        else if (isalpha(c))
        { // c가 알파벳이면 break
            break;
        }
        else if (isprint(c)) // c가 부호이면 infix에 저장
            iexpr[i++] = c;
    }
    fclose(fp);

    for (k = 0; k < num_count; k++)
    {
        printf("\n입력 스트링: %s\n", output[k].infix);
        printf("Postfix 형태: %s\n", output[k].postfix);
        printf("결과: %d\n", output[k].eval_result);
    }
    printf("END-OF-OUTPUT");
    return 0;
}

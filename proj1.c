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
    // e�� �־��� ����ǥ������� ���� ;���� ǥ��
    // ISP�� ICP�� �켱 ������ ��ȯ���ִ� �Լ�
    // pos�� e���� ���� ��ġ
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
            pop(&top); // ���ʰ�ȣ�� ����
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
        { //'$'�� ������ ���
            iexpr[i] = c;
            strcpy(output[k].infix, iexpr);

            infix_to_postfix();
            output[k].eval_result = eval();

            char *ptr = strtok(pexpr, "$"); //ù��° strtok ���.
            strcpy(output[k].postfix, ptr);

            k++;
            num_count++;
            i = 0;
            reset();
        }
        else if (isdigit(c)) // c�� �����̸� infix�� ����
            iexpr[i++] = c;

        else if (isalpha(c))
        { // c�� ���ĺ��̸� break
            break;
        }
        else if (isprint(c)) // c�� ��ȣ�̸� infix�� ����
            iexpr[i++] = c;
    }
    fclose(fp);

    for (k = 0; k < num_count; k++)
    {
        printf("\n�Է� ��Ʈ��: %s\n", output[k].infix);
        printf("Postfix ����: %s\n", output[k].postfix);
        printf("���: %d\n", output[k].eval_result);
    }
    printf("END-OF-OUTPUT");
    return 0;
}

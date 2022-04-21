#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COURSE 35
#define STUDENT 500

typedef struct enroll_s
{
    int id_num;
    int course_num;
    struct enroll_s *left;
    struct enroll_s *right;
} * enroll_sp;

enroll_sp courses[35] = {NULL};
enroll_sp students[500] = {NULL};

int error_count = 0;
int total_count = 0;
int valid_count = 0;
int invalid_count = 0;

int error_check(FILE *fp, int id, int course, char regi)
{
    if (id > 2500 || id < 2000)
    {
        fprintf(fp, "\t%d \t%d \t%c \t\t ** 유효하지 않는 학생 ID **\n", id, course, regi);
        error_count++;
        return 1;
    }
    else if (course < 100 || course > 135)
    {
        fprintf(fp, "\t%d \t%d \t%c \t\t ** 유효하지 않는 코스 ID **\n", id, course, regi);
        error_count++;
        return 1;
    }
    else if (regi != 'A' && regi != 'D')
    {
        fprintf(fp, "\t%d \t%d \t%c \t\t ** 'A' 혹은 'D'가 아님 **\n", id, course, regi);
        error_count++;
        return 1;
    }
    else
        return 0;
}
void add(int id, int course)
{
    enroll_sp ptrc = (enroll_sp)malloc(sizeof(struct enroll_s));
    enroll_sp ptrs = (enroll_sp)malloc(sizeof(struct enroll_s));
    enroll_sp temp;

    ptrc->id_num = id;
    ptrc->course_num = course;
    ptrc->left = NULL;
    ptrc->right = NULL;

    if (courses[course] == NULL)
        courses[course] = ptrc;
    else
    {
        temp = courses[course];
        if (id < temp->id_num)
        {
            ptrc->right = temp;
            temp->left = ptrc;
            courses[course] = ptrc;
        }
        else
        {
            while (id > temp->id_num)
            {
                if (temp->right)
                    temp = temp->right;
                else
                {
                    ptrc->left = temp;
                    temp->right = ptrc;
                    break;
                }
            }
            if (temp->id_num > ptrc->id_num)
            {
                ptrc->right = temp;
                ptrc->left = temp->left;
                temp->left->right = ptrc;
                temp->left = ptrc;
            }
        }
    }
    ptrs->id_num = id;
    ptrs->course_num = course;
    ptrs->left = NULL;
    ptrs->right = NULL;

    if (students[id] == NULL)
        students[id] = ptrs;
    else
    {
        temp = students[id];
        if (id < temp->id_num)
        {
            ptrs->right = temp;
            temp->left = ptrs;
            students[id] = ptrs;
        }
        else
        {
            if (id > temp->id_num)
            {
                temp = temp->right;
                if (temp->right = NULL)
                {
                    ptrs->left = temp;
                    temp->right = ptrs;
                }
            }
            if (temp->id_num > ptrs->id_num)
            {
                ptrs->right = temp;
                ptrs->left = temp->left;
                temp->left->right = ptrs;
                temp->left = ptrs;
            }
        }
    }
    valid_count++;
}

int enroll_check1(FILE *fp, int id, int course, char regi)
{
    enroll_sp ptr;
    int flag = 0;
    ptr = courses[course];

    for (; ptr; ptr = ptr->right)
    {
        if (ptr->course_num == course)
        {
            flag++;
        }
    }
    ptr = students[id];
    for (; ptr; ptr = ptr->right)
    {
        if (ptr->id_num == id && flag)
        {
            fprintf(fp, "\t%d \t%d \t%c \t\t 중복등록 \n", id + 2000, course + 100, regi);
            error_count++;
            return 0;
        }
    }
    return 1;
}

int enroll_check2(FILE *fp, int id, int course, char regi)
{
    enroll_sp ptr;
    int flag = 0;
    ptr = courses[course];
    for (; ptr; ptr = ptr->right)
    {
        if (ptr->course_num == course)
        {
            flag++;
        }
    }
    ptr = students[id];
    for (; ptr; ptr = ptr->right)
    {
        if (ptr->id_num == id)
        {
            flag++;
        }
    }
    if (flag == 2)
        return 1;

    fprintf(fp, "\t%d \t%d \t%c \t\t 미등록 \n", id + 2000, course + 100, regi);
    error_count++;
    return 0;
}

int drop(int id, int course)
{

    enroll_sp ptr;
    ptr = courses[course];

    while (id != ptr->id_num)
        ptr = ptr->right;
    if (ptr == courses[course])
        courses[course] = ptr->right;
    else
    {
        if (ptr->left)
            ptr->left->right = ptr->right;
        if (ptr->right)
            ptr->right->left = ptr->left;
    }
    free(ptr);

    ptr = students[id];
    while (course != ptr->course_num)
        ptr = ptr->right;
    if (ptr == students[id])
        students[id] = ptr->right;
    else
    {
        if (ptr->left)
            ptr->left->right = ptr->right;
        if (ptr->right)
            ptr->right->left = ptr->left;
    }
    free(ptr);
    valid_count--;
    invalid_count++;
    return 0;
}
void print(FILE *fp)
{
    enroll_sp ptr;
    int course = 0;
    while (course != 35)
    {
        ptr = courses[course];
        if (ptr)
        {
            fprintf(fp, "\n%d:", course + 100);
            do
            {
                fprintf(fp, "\t%d", ptr->id_num);
                ptr = ptr->right;
            } while (ptr);
        }
        course++;
    }

    fprintf(fp, "\n[입력보고]\t읽은카드수:%d\t유효등록:%d\t오류수:%d\t취소:%d", total_count, valid_count, error_count, invalid_count);
}
int main(void)
{
    int id, i;
    int course;
    char regi;
    FILE *fp1 = fopen("C:\\Coding\\Cource\\Data Structure\\project2\\input.txt", "r");
    FILE *fp2 = fopen("output.txt", "w");

    if (fp1 == NULL)
    {
        printf("input file open error\n");
        exit(0);
    }
    else
        printf("input file open success\n");

    if (fp2 == NULL)
    {
        printf("output file can't open \n");
        exit(0);
    }
    else
        printf("output file open success\n");

    while (EOF != fscanf(fp1, "%d %d %c", &id, &course, &regi))
    {
        printf("%d %d %c\n", id, course, regi);
        total_count++;
        if (error_check(fp2, id, course, regi))
            continue;

        id = id - 2000;
        course = course - 100;

        if (regi == 'A')
        {
            if (enroll_check1(fp2, id, course, regi))
                add(id, course);
        }
        else
        {
            if (enroll_check2(fp2, id, course, regi))
                drop(id, course);
        }
    }
    print(fp2);

    fclose(fp1);
    fclose(fp2);
    return 0;
}
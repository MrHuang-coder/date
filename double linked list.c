#include <stdio.h>
#include "conio.h"
#include "stdlib.h"

void menu();
struct people *add(struct people *head);
void look(struct people *head);
void change(struct people *head);
void find(struct people *head);
struct people *del(struct people *head);
struct people *sort(struct people *head);

struct people
{
    char name[20];
    char tel[12];
    char address[50];
    struct people *perior;
    struct people *next;
};

int main(void)
{
    struct people *head;
    int choice;
    head = (struct people*)malloc(sizeof(struct people));
    head->next = NULL;
    while (1)
    {
        system("cls");
        menu();
        printf("请输入0~5的整数:");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: head = add(head); break;
            case 2: look(head); break;
            case 3: change(head); break;
            case 4: find(head); break;
            case 5: head = del(head); break;
            case 6: head = sort(head);break;
            case 0: exit(0);
            default: printf("输出错误！");
        }
    }
    return 0;
}

void menu()
{
    puts("通讯录");
    puts("1.增添信息");
    puts("2.浏览信息");
    puts("3.修改信息");
    puts("4.查找信息");
    puts("5.删除信息");
    puts("6.信息排序");
    puts("0.退出");
}

struct people *add(struct people *head)
{
    struct people *p1, *p2;
    p1 = (struct people*)malloc(sizeof(struct people));
    printf("请输入你的姓名:");
    scanf("%s", p1->name);
    printf("请输入你的电话号码:");
    scanf("%s", p1->tel);
    printf("请输入你的家庭住址:");
    scanf("%s", p1->address);
    if (head->next == NULL)
    {
        head->next = p1;
        p1->perior = head;
        head->perior = NULL;
        p1->next = NULL;
        return head;
    }
    p2 = head;
    while (p2->next != NULL)
        p2 = p2->next;
    p2->next = p1;
    p1->perior = p2;
    p1->next = NULL;
    return head;
}

void look(struct people *head)
{
    struct people *p1, *p2;
    p1 = head->next;
    while (p1 != NULL)
    {
        printf("姓名:%s 电话号码:%s 家庭住址:%s\n", p1->name, p1->tel, p1->address);
        p1 = p1->next;
    }
    system("pause");
}

void change(struct people *head)
{
    struct people *p1;
    char name[20];
    printf("请输入你要修改信息的人的名字:");
    scanf("%s", name);
    if (head->next == NULL)
    {
        printf("无任何人员信息！");
        system("pause");
        return;
    }
    p1 = head->next;
    while (p1 != NULL)
    {
        if (strcmp(p1->name, name) == 0)
        {
            printf("该联系人信息如下:\n姓名:%s 电话号码:%s 家庭住址:%s\n", p1->name, p1->tel, p1->address);
            puts("请输入修改后的信息:");
            printf("姓名:");
            scanf("%s", p1->name);
            printf("电话号码:");
            scanf("%s", p1->tel);
            printf("家庭住址:");
            scanf("%s", p1->address);
            return;
        }
        p1 = p1->next;
    }
    printf("未查到此人信息！");
}

void find(struct people *head)
{
    struct people *p1;
    char name[20];
    int flag = 0;

    if (head->next == NULL)
    {
        printf("无任何联系人的信息!");
        system("pause");
        return;
    }
    printf("请输入你要查找的人名:");
    scanf("%s", name);
    p1 = head->next;
    while (p1 != NULL)
    {
        if(strcmp(p1->name, name) == 0)
        {
            printf("该联系人信息如下:\n姓名:%s 电话号码:%s 家庭住址:%s\n", p1->name, p1->tel, p1->address);
            flag = 1;
        }
        p1 = p1->next;
    }
    if (flag == 0)
        printf("未查到该联系人信息！");
    system("pause");
    return;
}

struct people *del(struct people *head)
{
    struct people *p1;
    char name[20];


    if (head->next == NULL)
    {
        printf("无任何联系人的信息!");
        system("pause");
        return head;
    }
    printf("请输入要删除的联系人的名字: ");
    scanf("%s", name);
    p1 = head->next;
    if (p1->next == NULL)
    {
        if (strcmp(p1->name, name) == 0)
        {
            head->next = NULL;
            free(p1);
            printf("删除成功！");
        } else{
            printf("无此联系人信息！");
        }
        return head;
    }
    while (p1 != NULL)
    {
        if (p1->next != 0 && strcmp(p1->name, name) == 0)
        {
            p1->perior->next = p1->next;
            p1->next->perior = p1->perior;
            free(p1);
            printf("删除成功!");
            system("pause");
            return head;
        }
        else if (strcmp(p1->name, name) == 0)
        {
            printf("2222222");
            p1->perior->next = NULL;
            free(p1);
            printf("删除成功！");
            system("pause");
            return head;
        }
        p1 = p1->next;
    }
    printf("无此联系人信息！");
    return head;
}

struct people *sort(struct people *head)
{
    struct people *p1, *p2;
    if (head->next->next == NULL)
    {
        printf("已成功排序！");
        return head;
    }
    p1 = head->next;
    p2 = p1->next;
    while (p2 != NULL)
    {
        if (p2->next != NULL && strcmp(p2->name, p1->name) < 0)
        {
            p2->perior = p1->perior;
            p1->perior->next = p2;
            p1->next = p2->next;
            p2->next->perior = p1;
            p2->next = p1;
            p1->perior = p2;
        }
        else if (strcmp(p2->name, p1->name) < 0)
        {
            p2->perior = p1->perior;
            p1->perior->next = p2;
            p1->next = NULL;
            p2->next = p1;
            p1->perior = p2;
        }
        p1 = p2;
        p2 = p2->next;
    }
    printf("排序完成！");
    system("pause");
    return head;
}

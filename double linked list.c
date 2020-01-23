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
        printf("������0~5������:");
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
            default: printf("�������");
        }
    }
    return 0;
}

void menu()
{
    puts("ͨѶ¼");
    puts("1.������Ϣ");
    puts("2.�����Ϣ");
    puts("3.�޸���Ϣ");
    puts("4.������Ϣ");
    puts("5.ɾ����Ϣ");
    puts("6.��Ϣ����");
    puts("0.�˳�");
}

struct people *add(struct people *head)
{
    struct people *p1, *p2;
    p1 = (struct people*)malloc(sizeof(struct people));
    printf("�������������:");
    scanf("%s", p1->name);
    printf("��������ĵ绰����:");
    scanf("%s", p1->tel);
    printf("��������ļ�ͥסַ:");
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
        printf("����:%s �绰����:%s ��ͥסַ:%s\n", p1->name, p1->tel, p1->address);
        p1 = p1->next;
    }
    system("pause");
}

void change(struct people *head)
{
    struct people *p1;
    char name[20];
    printf("��������Ҫ�޸���Ϣ���˵�����:");
    scanf("%s", name);
    if (head->next == NULL)
    {
        printf("���κ���Ա��Ϣ��");
        system("pause");
        return;
    }
    p1 = head->next;
    while (p1 != NULL)
    {
        if (strcmp(p1->name, name) == 0)
        {
            printf("����ϵ����Ϣ����:\n����:%s �绰����:%s ��ͥסַ:%s\n", p1->name, p1->tel, p1->address);
            puts("�������޸ĺ����Ϣ:");
            printf("����:");
            scanf("%s", p1->name);
            printf("�绰����:");
            scanf("%s", p1->tel);
            printf("��ͥסַ:");
            scanf("%s", p1->address);
            return;
        }
        p1 = p1->next;
    }
    printf("δ�鵽������Ϣ��");
}

void find(struct people *head)
{
    struct people *p1;
    char name[20];
    int flag = 0;

    if (head->next == NULL)
    {
        printf("���κ���ϵ�˵���Ϣ!");
        system("pause");
        return;
    }
    printf("��������Ҫ���ҵ�����:");
    scanf("%s", name);
    p1 = head->next;
    while (p1 != NULL)
    {
        if(strcmp(p1->name, name) == 0)
        {
            printf("����ϵ����Ϣ����:\n����:%s �绰����:%s ��ͥסַ:%s\n", p1->name, p1->tel, p1->address);
            flag = 1;
        }
        p1 = p1->next;
    }
    if (flag == 0)
        printf("δ�鵽����ϵ����Ϣ��");
    system("pause");
    return;
}

struct people *del(struct people *head)
{
    struct people *p1;
    char name[20];


    if (head->next == NULL)
    {
        printf("���κ���ϵ�˵���Ϣ!");
        system("pause");
        return head;
    }
    printf("������Ҫɾ������ϵ�˵�����: ");
    scanf("%s", name);
    p1 = head->next;
    if (p1->next == NULL)
    {
        if (strcmp(p1->name, name) == 0)
        {
            head->next = NULL;
            free(p1);
            printf("ɾ���ɹ���");
        } else{
            printf("�޴���ϵ����Ϣ��");
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
            printf("ɾ���ɹ�!");
            system("pause");
            return head;
        }
        else if (strcmp(p1->name, name) == 0)
        {
            printf("2222222");
            p1->perior->next = NULL;
            free(p1);
            printf("ɾ���ɹ���");
            system("pause");
            return head;
        }
        p1 = p1->next;
    }
    printf("�޴���ϵ����Ϣ��");
    return head;
}

struct people *sort(struct people *head)
{
    struct people *p1, *p2;
    if (head->next->next == NULL)
    {
        printf("�ѳɹ�����");
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
    printf("������ɣ�");
    system("pause");
    return head;
}

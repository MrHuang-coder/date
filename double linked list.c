#include <stdio.h>
#include "conio.h"
#include "stdlib.h"
void menu();
struct people *add(struct people *head);
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
        menu();
        printf("������0~5������:");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: head = add(head); break;
            case 2: look(head); break;
          /*  case 3: change(); break;
            case 4: find(); break;
            case 5: del(); break;
            case 6: sort();break;
            case 0: exit();
            */
        }
    }
    return 0;
}

void menu()
{
    puts("ͨѶ¼");
    puts("1.������Ϣ");
    puts("2.�����Ϣ")
    puts("3.�޸���Ϣ");
    puts("4.������Ϣ");
    puts("5.ɾ����Ϣ");
    puts("6.��Ϣ����");
    puts("0.�˳�");
}

struct people *add(struct people *head)
{
    struct people *p1, *p2, *tail;
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
    while(p2->next != NULL)
        p2 = p2->next;
    p2->next = p1;
    p1->perior = p2;
    p1->next = NULL;
    return head;
}


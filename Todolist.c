#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
struct block
{
  int pr;
  char val[100];
  struct block *next;
} * start;

void newdel(struct block *);

void del();

void push(char[100], int);

void reschedule()
{
  char task[100];
  int new_pr, flag = 0, choice;
  struct block *temp;
  temp = start;
  if (temp->next == NULL)
  {
    printf("Enter At Least One More Task To Proceed With Rescheduling\n");
  }
  else if (start != NULL)
  {
    printf("1. Delete\n");
    printf("2. Reschedule\n");
    scanf("%d", &choice);
    printf("Enter The Task Which You Would Like To Reschedule/Delete (Case Sensitive)\n");
    scanf("%s", task);
    if (choice == 2)
    {
      printf("Enter New Priority\n");
      scanf("%d", &new_pr);
    }
    while (temp != NULL)
    {
      if (strcmp(temp->val, task) == 0)
      {
        flag = 1;
        break;
      }
      else
      {
        flag = 0;
      }
      temp = temp->next;
    }
    if (flag == 1)
    {
      newdel(temp);
      if (choice == 2)
      {
        push(task, new_pr);
      }
    }
    else
    {
      printf("Task Not Found\n");
    }
  }
  else
    printf("List Is Empty\n");
}

void disp() // Function To Display Tasks According To Priority
{
  struct block *temp;
  temp = start;
  printf("\nTo-Do List:\n\n");
  printf("\tTask\t\t\tPriority\n");
  while (temp != NULL)
  {
    printf("\t%s\t\t", temp->val);
    printf("\t%d\t\n", temp->pr);
    temp = temp->next;
  }
  printf("\n");
}

void search() // Function To Search For A Specific Task
{
  int flag = 0;
  char key_task[100];
  struct block *temp;
  temp = start;
  if (start != NULL)
  {
    printf("Enter Task Name(Case Sensitive)\n");
    scanf("%s", key_task);
    while (temp != NULL)
    {
      if (strcmp(temp->val, key_task) == 0)
      {
        flag = 1;
        break;
      }
      else
        flag = 0;
      temp = temp->next;
    }
    if (flag == 1)
    {
      printf("Task %s Found With Priority %d\n", temp->val, temp->pr);
    }
    else
      printf("Task Not Found\n");
  }
  else
    printf("List Is Empty\n");
}

void push(char temp1[100], int pri)
{
  struct block *temp, *t;
  temp = (struct block *)malloc(sizeof(struct block));
  strcpy(temp->val, temp1);
  temp->pr = pri;
  temp->next = NULL;
  if (start == NULL)
  {
    start = temp;
  }
  else if (start->pr > pri)
  {
    temp->next = start;
    start = temp;
  }
  else
  {
    t = start;
    while (t->next != NULL && (t->next)->pr <= pri)
      t = t->next;
    temp->next = t->next;
    t->next = temp;
  }
}

void del() // Function To Delete Task With Highest Priority
{
  if (start != NULL)
  {
    printf("\n\tTask %s Was Marked As Done\n", start->val);
    start = start->next;
  }
  else
    printf("\nList Is Empty\n");
}

void newdel(struct block *delement) // Function To Delete Or Reschedule Any Task
{
  struct block *temp2;
  struct block *temp;
  struct block *prev;
  temp = start;
  printf("Operation Completed Successfully");
  if (delement->next != NULL)
  {
    temp2 = delement->next;
    while (temp->val != delement->val)
    {
      prev = temp;
      temp = temp->next;
    }
    free(delement);
    prev->next = temp2;
  }
  else
  {
    while (temp->next != NULL)
    {
      prev = temp;
      temp = temp->next;
    }
    prev->next = NULL;
  }
}

int main()
{ system("color E4");
  int ch, pr, check = 1;
  char temp1[100];
  // clrscr();
  printf("\n\n\t\t\t    TO-DO LIST\n\n\t     PRIORITY QUEUE IMPLEMENTED USING LINKED LISTS\n");
  printf("\nTEAM MEMBERS -\n1.Parshad\n2.Tanmay\n3.Kunal\n4.Dev\n5.Bhavya\n");
  while (check == 1)
  {
    printf("\nIn To Do List Select:\n1. Add New Task\n2. Mark The Task With Highest Priority As Done\n3. Display My Tasks\n4. Search For A Task\n5. Reschedule Or Delete Any Task\n6. Exit\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      printf("\nEnter Task And Its Priority: \n");
      scanf("%s%d", temp1, &pr);
      push(temp1, pr);
      break;

    case 2:
      del();
      break;

    case 3:
      disp();
      break;

    case 4:
      search();
      break;

    case 5:
      reschedule();
      break;

    case 6:
      check = 0;
      break;

    default:
      printf("Wrong Choice\n");
      printf("\nPress 1 To Continue Or 0 To Stop\n");
      scanf("%d", &check);
    }
  }
  return 0;
}

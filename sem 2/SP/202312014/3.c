#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

struct program
{
    int prog_id;
    char prog_name[50];
    char uid_executing[25];
    uint64_t start_time;
    uint64_t time_elapsed;
    int status;
    struct program *next;
    struct program *prev;
};

struct program *head = NULL;
struct program *tail = NULL;
int j = 1;

int newProgram(char program_name[], char uid[])
{
    struct program *new_node = (struct program *)malloc(sizeof(struct program));
    new_node->prog_id = j++;
    strcpy(new_node->prog_name, program_name);
    strcpy(new_node->uid_executing, uid);
    new_node->status = 0;
    new_node->time_elapsed = 0;
    if (head == NULL)
    {
        head = new_node;
    }
    else if (tail != NULL)
    {
        tail->next = new_node;
        new_node->prev = tail;
    }
    tail = new_node;
    if ((new_node->prog_name) != NULL && (new_node->uid_executing) != NULL)
        return 1;
    else
        return 0;
}

uint64_t getCurrentTime()
{
    struct timeval tv;
    if (gettimeofday(&tv, NULL) == 0)
        return (uint64_t)tv.tv_sec;
    else
        return 0;
}

int UpdateToRunning(int id)
{
    int q = 0;
    struct program *temp;
    temp = head;
    while (temp != NULL)
    {
        if (temp->prog_id == id)
        {
            temp->status = 1;
            temp->start_time = getCurrentTime();
            q = 1;
        }
        temp = temp->next;
    }
    return q;
}

int UpdateToFinished(int id)
{
    int q = 0;
    struct program *temp;
    temp = head;
    while (temp != NULL)
    {
        if (temp->prog_id == id)
        {
            temp->status = 2;
            temp->time_elapsed = (uint64_t)getCurrentTime - (uint64_t)temp->start_time;
            q = 1;
        }
        temp = temp->next;
    }
    return q;
}

void Display()
{
    struct program *temp = head;
    while (temp != NULL)
    {
        printf("\n---------------------------\n");
        if (temp->status == 0)
        {
            printf("Status : Submitted\n");
        }
        else if (temp->status == 1)
        {
            printf("Status : Running\n");
        }
        else
        {
            printf("Status : Finished\n");
        }
        printf("Id : %d\n", temp->prog_id);
        printf("Program : %s\n", temp->prog_name);
        printf("User Id : %s\n", temp->uid_executing);
        printf("Time elapsed : %u\n\n", temp->time_elapsed);
        // printf("Status : %d\n",ptr[k].status);
        temp = temp->next;
    }
}

void updateTimeElapsed()
{
    struct program *curr = head;
    while (curr != NULL)
    {
        if (curr->status == 1)
            curr->time_elapsed = (uint64_t)getCurrentTime - (uint64_t)curr->start_time;
        curr = curr->next;
    }
}

void Delete()
{
    struct program *temp = head;
    while (temp != NULL)
    {
        if (head == NULL || temp == NULL)
            return;

        if (temp->status == 2)
        {
            if (temp == head)
            {
                head = head->next;
                free(temp);
                if (head == NULL)
                    return;
                temp = head;
                head->prev = NULL;
            }
            else if (temp == tail)
            {
                tail = tail->prev;
                tail->next = NULL;
                free(temp);
                temp = tail;
            }
            else
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                struct program *temp = temp->next;
                free(temp);
                temp = temp;
                free(temp);
            }
        }
        else
            temp = temp->next;
    }
}

void DeleteAll()
{
    struct program *temp = head;
    while (temp != NULL)
    {
        head = head->next;
        free(temp);
        temp = head;
    }
}

int main()
{
    int k = 0, choice, id, microsec;
    char program_text[50], uid[25];
    int success = 0;
    while (1)
    {
        printf("\n---------\n");
        printf("1. Enter a new program.\n2. Update program status to running.\n3. Update program status to finished.\n4. Update time-elapsed for all programs\n5.Delete all finished queries.\n6. Display all the queries\n7. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter a string : ");
            scanf("%s", program_text);
            printf("Enter your user id : ");
            scanf("%s", uid);
            success = newProgram(program_text, uid);
            if (success == 0)
            {
                printf("\nprogram not inserted\n");
            }
            else
            {
                printf("\n\nprogram successfully inserted\n\n");
            }
            break;
        case 2:
            printf("\nEnter the id of program to change it's status to running : ");
            scanf("%d", &id);
            success = UpdateToRunning(id);
            if (success == 0)
            {
                printf("Status of %d was not able to change, try again\n", id);
            }
            else
            {
                printf("Status of %d changes to running successfully\n", id);
            }
            break;

        case 3:
            printf("\nEnter the id of program to change it's status to finished : ");
            scanf("%d", &id);
            success = UpdateToFinished(id);
            if (success == 0)
            {
                printf("Status of %d was not able to change, try again\n", id);
            }
            else
            {
                printf("Status of %d changes to finished successfully\n", id);
            }
            break;
        case 4:
            updateTimeElapsed();
            break;
        case 5:
            Delete();
            break;
        case 6:
            Display();
            break;
        case 7:
            DeleteAll();
            exit(0);
        }
    }
}
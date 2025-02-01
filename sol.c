#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Patient
{
    int unique_id;
    char severity[100];
    struct Patient *NextPersonAddress;
};
int PriorityOnBasesOfCondition(char *severity)
{
    if (strcasecmp(severity, "critical") == 0)
        return 1;
    if (strcasecmp(severity, "serious") == 0)
        return 2;
    if (strcasecmp(severity, "stable") == 0)
        return 3;
    return 4;
}
struct Patient *FirstPatient = NULL;
// struct Patient *head1 = NULL;

void InsertDetailsOfPerson(struct Patient **FirstPersonOfLISt)
{
    struct Patient *presentPointer, *HelperPointer = NULL;
    int id;
    char severity[100];

    int count;
    scanf("%d", &count);
    printf("enter the patient details \n");
    // while (scanf("%d %s", &id, severity) == 1)
    while (count--)
    {
        scanf("%d %s", &id, severity);
        presentPointer = (struct Patient *)malloc(sizeof(struct Patient));
        presentPointer->unique_id = id;
        strcpy(presentPointer->severity, severity);
        presentPointer->NextPersonAddress = NULL;

        if (*FirstPersonOfLISt == NULL)
        {
            *FirstPersonOfLISt = presentPointer;
            HelperPointer = presentPointer;
        }
        else
        {
            HelperPointer->NextPersonAddress = presentPointer;
            HelperPointer = presentPointer;
        }
    }
}

void RecordDisplay(struct Patient *FristPersonOfLIst)
{
    struct Patient *PresentPointer = FristPersonOfLIst;
    while (PresentPointer != NULL)
    {
        printf("%d %s\n", PresentPointer->unique_id, PresentPointer->severity);
        PresentPointer = PresentPointer->NextPersonAddress;
    }
    printf("\n");
}
void SortAccordingToCategory()
{
    struct Patient *PresentPointer, *HelperPointer;
    int tempIdPatient;
    char tempVariableforSeverity[100];

    for (PresentPointer = FirstPatient; PresentPointer != NULL; PresentPointer = PresentPointer->NextPersonAddress)
    {
        for (HelperPointer = PresentPointer->NextPersonAddress; HelperPointer != NULL; HelperPointer = HelperPointer->NextPersonAddress)
        {
            if (PriorityOnBasesOfCondition(PresentPointer->severity) > PriorityOnBasesOfCondition(HelperPointer->severity))
            {

                tempIdPatient = PresentPointer->unique_id;
                strcpy(tempVariableforSeverity, PresentPointer->severity);

                PresentPointer->unique_id = HelperPointer->unique_id;
                strcpy(PresentPointer->severity, HelperPointer->severity);

                HelperPointer->unique_id = tempIdPatient;
                strcpy(HelperPointer->severity, tempVariableforSeverity);
            }
        }
    }
}

int main()
{
    printf("enter the number of patient\n");

    InsertDetailsOfPerson(&FirstPatient);
    // RecordDisplay(FirstPatient);
    // newlink();
    printf("enter the sorted patient details \n");
    SortAccordingToCategory(FirstPatient);
    RecordDisplay(FirstPatient);
    return 0;
}

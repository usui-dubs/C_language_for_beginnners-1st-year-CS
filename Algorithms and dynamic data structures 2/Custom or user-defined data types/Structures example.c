#include <stdio.h>
#include <string.h>

#define Max 100
#define subject_num 4
#define student_num 30

typedef struct Student 
{
    int mat;
    char first_name[Max];
    char family_name[Max];
    float exam[subject_num] ;
    float moy;
    char res[Max];
} Student ;
    

float moy(float arr[Max], int size)
{
    int index;
    float result, exam = 0;
    
    for(index = 0; index < size; index++)
    {
        exam += arr[index];
    }
    
    result = exam / size ;
    
    return result;
}

int main()
{
    int i, j, N;
    char temp; //to clear the buffer
    Student E[student_num];
    
    do
    {
    printf("enter the students number <= 30 : ");
    scanf("%d", &N);
    } while (N <= 0 || N > 30);
    
    for(i = 0; i < N; i++)
    {
        printf("\nEnter the matricule of the Student number %d : ", i+1);
        scanf("%d", &E[i] .mat);

        scanf("%c", &temp);
        printf("\nEnter the First Name of the %d Student: ", i+1);
        //scanf("%[^\n]%*c", &E[i] .first_name); doesn't work 
        fgets(&E[i] .first_name, Max, stdin);
        //gets(E[i] .first_name);
        
        printf("\nEnter the Family name of the %d Student: ", i + 1);
        //scanf("%[^\n]%*c", &E[i] .family_name); doesn't work 
        fgets(&E[i] .family_name, Max, stdin);
        //gets(E[i] .family_name);
    
        for(j = 0; j < subject_num; j++)
        {
            printf("enter the exam %d result: ", j+1);
            scanf("%f",&E[i] .exam[j]);
        }
        
        E[i] .moy = moy(E[i].exam, subject_num);
        
        if (E[i] .moy >= 10)
           strcpy(E[i].res, "admet");
    }
    
    for(i = 0; i < N; i++)
    {
        if (strcmp(E[i] .res, "admet") == 0)
                printf("the student number %d %s %s with the matricule %d is %s with result = %.2f",i+1, &E[i] .first_name, &E[i] .family_name ,E[i].mat, E[i].res, E[i] .moy);
    }
    
    return 0;
}
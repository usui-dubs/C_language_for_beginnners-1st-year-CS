#include <stdio.h>
#define Max 100
#define num_ouv 8
#define num_sub 4
#define num_ready 4

typedef struct ouvrage
{
    int code_ouvrage;
    int domain_code;
    char title[Max];
} ouvrage ;

typedef struct subscriber
{
    int sub_code;
    int department_code;
    char name[Max];
} subscriber ;

typedef struct ready
{
    int sub_code;
    int code_ouvrage;
} ready ;

    
int main()
{
    int i, j, k;

    ouvrage o[num_ouv];
    subscriber s[num_sub];
    ready r[num_ready];
    
    for(i=0; i < num_ouv; i++)
    {
        scanf("%d", &o[i].code_ouvrage);
        scanf("%d", &o[i].domain_code);
        fgets(o[i]. title, num_ouv , stdin);
    }
    
    for(i=0; i < num_sub; i++)
    {
        scanf("%d", &s[i].sub_code);
        scanf("%d", &s[i].department_code);
        fgets(s[i]. name, num_sub , stdin);
    }
    
    for(i=0; i < num_ready; i++)
    {
        scanf("%d", &r[i].sub_code);
        scanf("%d", &r[i].code_ouvrage);
    }
    
    for(i=0; i<num_ready; i++)
    {
        for(j=0; j<num_sub; j++)
        {
            if(r[i]. sub_code == s[j]. sub_code && s[j]. department_code == 3)
            {
                k = 0;
                while(k< num_ouv && o[k].code_ouvrage != r[i].code_ouvrage)
                    k++ ;
                
                printf("%d", o[k]. domain_code);
            }
        }
    }
    
    return 0;
}
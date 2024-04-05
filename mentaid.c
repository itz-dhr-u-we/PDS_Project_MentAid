#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

//for storing credentials
void saveCredentials(const char* firstname, const char* lastname,const char* usrname, long long int phone) 
{
    FILE *saveCrd = fopen("C:\\Users\\brije\\OneDrive\\Desktop\\MentAid\\mentdata.txt", "a"); 
    if (saveCrd != NULL) 
    {
        fprintf(saveCrd, "First Name: %s\nLast Name: %s\nUsername: %s\nContact Number: %lld\n\n", firstname, lastname,usrname, phone);
    } else 
    {
        printf("Error opening the file for saving credentials.\n");
    }
    fclose(saveCrd);
}
//for storing the data of appointments
void bookAppointment(char *doctor, int slot, char res) 
{
    FILE *appointmentsFile = fopen("C:\\Users\\brije\\OneDrive\\Desktop\\MentAid\\appointment.txt", "a");
    if (res == 'n' || res == 'N') 
    {
        fprintf(appointmentsFile, "No appointments\n");
    } else {
        fprintf(appointmentsFile, "%s Slot %d\n", doctor, slot);
    }

    fclose(appointmentsFile);
}

int main() 
{
    char fname[50], lname[70],tempnum[10],uname[30];
    long long int phnum;
    printf("\n\t\t\t\t\t\tWelcome to MentAid\n");
    printf("\t\t\t\t\t\t\033[3m!!Live Life King Size!!\033[0m\n");
    //personal credentials
    printf("\n\n\nFirst Name: ");
    scanf("%s",&fname);
    for (int g = 0; fname[g] != '\0'; ++g) 
    {
        if (!isalpha(fname[g])) {
            printf("\n\033[1mWarning:\033[0m First name cannot contain numbers.\n");
            return 1;
        }
    } 
    printf("\nLast Name: ");
    scanf("%s",&lname);
    for (int g = 0; lname[g] != '\0'; ++g)
    {
        if (!isalpha(lname[g])) {
            printf("\n\033[1mWarning:\033[0m Last name cannot contain numbers.\n");
            return 1;  
        }
    }

    printf("\nUsername: ");
    char ch;
    int m = 0;
    while((ch = getch()) != '\r') 
    {
        if (isalnum(ch) || ispunct(ch)) 
        {
            uname[m++] = ch; 
            printf("%c", ch);
        }
    }
    uname[m] = '\0'; 
    printf("\n");
    printf("\nPhone Number: ");
    if (scanf("%lld", &phnum) != 1 || phnum < 0) 
    {
        printf("\n\033[1mWarning:\033[0m Enter a valid Phone Number...\n");
        return 1;
    }

    //function call
    saveCredentials(fname,lname,uname,phnum);

    int c, t;

    printf("\nEnter the number of calories burnt during meditation: ");
    scanf("%d", &c);
    printf("\nEnter the duration of meditation: ");
    scanf("%d", &t);
    // focus measurement
    int f = c / t;
    int s = 20;

    int d = ((f - s) / s * 100);
    if (d < 0) 
    {
        printf("\n\033[1mYour mental health is %d percent deviated from normal. You are mentally unfit.\033[0m",d);
    } 
    else 
    {
        printf("\n\tYou are mentally fit");
    }

    char response;
    printf("\n\tDo you want counselling? (Y/N): ");
    scanf(" %c", &response);

    if (response == 'n' || response == 'N') 
    {
        printf("\n\t\t\t\t\t\033[1mThanks for visiting MentAid\033[0m\n");
        if (response == 'n' || response == 'N') 
        {
            bookAppointment(NULL, 0, response);//function call
            int i,j;
            int sml = 2;
            for(i=1;i<=3;i++)
            {
                for(j=1;j<=i;j++)
                {
                    printf("\t\t%c ",sml);
                }   
            }
            printf("\n");
        }
    } 
    else if (response == 'Y' || response == 'y') 
    {
        int c;
        printf("\n\tPsychiatrists Available\n");
        printf("\t 1. Dr. A \n");
        printf("\t 2. Dr. B \n");
        printf("\t 3. Dr. C \n");
        printf("\t 4. Dr. D \n");
        printf("\t 5. Dr. E \n");

        printf("\n\tSelect Psychiatrist : ");
        scanf("%d", &c);

        char *arr[5] = {"Dr. A", "Dr. B", "Dr. C", "Dr. D", "Dr. E"};

        if (c >= 1 && c <= 5) 
        {
            printf("\n\tBook appointment with %s\n", arr[c - 1]);
            int sl;
            printf("\n\tCheck available slots\n");
            printf("\t 1. Slot 1  10:00-11:00 am \n");
            printf("\t 2. Slot 2  12:00-1:00  pm \n");
            printf("\t 3. Slot 3  4:00-5:00   pm  \n");
            printf("\t 4. Slot 4  6:00-7:00   pm  \n");
            printf("\t 5. Slot 5  8:00-9:00   pm  \n");

            printf("\n\tSpecify your preferred slot : ");
            scanf("%d", &sl);

            switch (sl) 
            {
                case 1:
                    printf("\n\tYour appointment has been confirmed with %s during slot %d", arr[c - 1], sl);
                    bookAppointment(arr[c - 1], sl,response);//function call
                    break;
                case 2:
                    printf("\n\tYour appointment has been confirmed with %s during slot %d", arr[c - 1], sl);
                    bookAppointment(arr[c - 1], sl,response);//function call
                    break;
                case 3:
                    printf("\n\tYour appointment has been confirmed with %s during slot %d", arr[c - 1], sl);
                    bookAppointment(arr[c - 1], sl,response);//function call
                    break;
                case 4:
                    printf("\n\tYour appointment has been confirmed with %s during slot %d", arr[c - 1], sl);
                    bookAppointment(arr[c - 1], sl,response);//function call
                    break;
                case 5:
                    printf("\n\tYour appointment has been confirmed with %s during slot %d", arr[c - 1], sl);
                    bookAppointment(arr[c - 1], sl,response);//function call
                    break;
                default:
                    printf("\n\tInvalid input!!!");
            }
            printf("\n\t\t\t\t\t\033[1mThanks for visiting MentAid\033[0m\n");
            int i,j;
            int sml = 2;
            for(i=1;i<=3;i++)
            {
                for(j=1;j<=i;j++)
                {
                    printf("\t\t%c  ",sml);
                }   
            }
            printf("\n");
        } 
        else 
        {
            printf("\n\tInvalid psychiatrist selection");
        }
    }
    return 0;
}

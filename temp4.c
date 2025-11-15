#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
struct node
{
    char seat, name[32], mob[32], stjrny[32], endjrny[32];
    int status, seatNumber,day,month,year;
    struct node *next;
};
typedef struct node Node;
Node *head=NULL;
void printUser()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int ck=0,day,month,year;
    printf("Enter date of  journy (dd-mm-yyyy) : ");
    scanf("%d-%d-%d",&day,&month,&year);
    printf("Enter Seat Number : ");
    char sitNumber[5];
    scanf("%s",&sitNumber);
    Node *ptr=head;
    for(ptr=head; ptr->next!=NULL; ptr=ptr->next)
    {

        if(ptr->seat==sitNumber[0]  && ptr->day==day && ptr->seatNumber==sitNumber[1]-'0')
        {
            ck++;
            if(ptr->status==1)
            {
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                printf("|\tSeat Number : %c%d\n",ptr->seat,ptr->seatNumber);
                printf("|\tPasserger Name : %s\n",ptr->name);
                printf("|\tPasserger Mobile : %s\n",ptr->mob);
                printf("|\tJourny date : %d-%d-%d\n",ptr->day,ptr->month,ptr->year);
                printf("|\tJourny From : %s\n",ptr->stjrny);
                printf("|\tJourny To : %s\n",ptr->endjrny);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
            else
            {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
                printf("*** \a%s is Till Available !***\n",sitNumber);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
        }
    }
    if(ck==0)
    {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
        printf("***\aYou Enter Invalid Seat Number.***\n***\aPlease Enter a Valid Seat Number ***\n");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

        printf("Available List\n\n");
        Node *p=head;
        int i=1;
        for(p=head; p!=NULL; p=p->next)
        {
            char value[20];
            if(p->status==0)
                strcpy(value,"Avail");
            else if(p->status==1)
            {
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                strcpy(value,"Booked");
            }
            printf("\t%c%d[%s]",p->seat,p->seatNumber,value);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            if(i%4==0)
                printf("\n\n");
            i++;
        }
        printf("\n");
    }
}
void printAvail()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    Node *p=head;
    int i=1,day,month,year;
    printf("Enter date(dd-mm-yyyy) :" );
    scanf("%d-%d-%d",&day,&month,&year);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    printf("\n\t\t  [Available list for : %d-%d-%d]\n\n",day,month,year);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    for(p=head; p!=NULL; p=p->next)
    {
        char value[20];
        if(p->day==day)
        {
            if(p->status==0)
                strcpy(value,"Avail");
            else if(p->status==1)
            {
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                strcpy(value,"Booked");
            }
            printf("\t%c%d[%s] ",p->seat,p->seatNumber,value);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            if(i%4==0)
                printf("\n\n");
            i++;
        }
    }
    printf("\n");
}
void initial()
{
    int temp='A', status, seatNumber;
    char seat;
    int day,month,year;
    printf("Enter the Current Date(dd-mm-yyyy) : " );
    scanf("%d-%d-%d",&day,&month,&year);
    for(int d=1; d<=5; d++)
    {
        temp='A';
        for (int i=1; i<10; i++)
        {
            for(int j=1; j<5; j++)
            {
                Node *lk;
                lk=(Node*) malloc(sizeof(Node));
                lk->status=0;
                lk->day=day;
                lk->month=month;
                lk->year=year;
                lk->seat=temp;
                lk->seatNumber=j;
                if(head==NULL)
                {
                    lk->next=head;
                    head=lk;
                }
                else
                {
                    lk->next=NULL;
                    Node *ptr=head;
                    for(ptr=head; ptr->next!=NULL; ptr=ptr->next) {}
                    ptr->next=lk;
                }
            }
            temp=temp+1;
        }
        if(day==30)
            day=1;
        else
            day++;
    }
}
void bookingSit()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    char name[32], mob[32], stjrny[32], endjrny[32];
    int quantity, ck=0,day,month,year;
    printf("\t\t\t***Passenger Information***\n");
    printf("Enter Passenger Name : ");
    scanf("%s",&name);
    printf("Enter Contract Number : ");
    scanf("%s",&mob);
    printf("Enter date of  journy (dd-mm-yyyy) : ");
    scanf("%d-%d-%d",&day,&month,&year);
    printf("Starting Point of journy : ");
    scanf("%s",&stjrny);
    printf("Ending Point of journy  : ");
    scanf("%s",&endjrny);
    printf("\t\t\t***Seat Information***\n ");
    printf("How many Seat want to book? : ");
    scanf("%d",&quantity);
    for(int x=1; x<=quantity; x++)
    {
        if(x==1)
            printf("Enter 1st  Seat Number : ");
        else  if(x==2)
            printf("Enter 2nd  Seat Number : ");
        else  if(x==3)
            printf("Enter 3rd  Seat Number : ");
        else
            printf("Enter  %dth Seat Number : ",x);

        char sitNumber[5];
        scanf("%s",&sitNumber);
        Node *ptr=head;
        ck=0;
        for(ptr=head; ptr->next!=NULL; ptr=ptr->next)
        {
            if(ptr->seat==sitNumber[0] && ptr->day==day  && ptr->seatNumber==sitNumber[1]-'0')
            {
                ck++;
                if(ptr->status==0)
                {
                    ptr->status=1;
                    strcpy(ptr->name,name);
                    strcpy(ptr->mob,mob);
                    ptr->day=day;
                    ptr->month=month;
                    ptr->year=year;
                    strcpy(ptr->stjrny,stjrny);
                    strcpy(ptr->endjrny,endjrny);
                    ptr->seat=sitNumber[0];
                    ptr->seatNumber=(sitNumber[1]-'0');
                    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                    printf("%s is Booked Successful.\n",sitNumber);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                }
                else
                {
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
                    printf("*** \a%s is Alrady Booked!***\nPlease Select Another Seat....\n",sitNumber);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    x--;
                }
            }
        }
        if(ck==0)
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
            printf("***\aYou Enter Invalid Seat Number.***\n***\aPlease Enter a Valid Seat Number ***\n");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            x--;
        }
    }
}
void deleteSit()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int ck=0,day,month,year;
    char sitNumber[5];
    printf("Enter date of  journy (dd-mm-yyyy) : ");
    scanf("%d-%d-%d",&day,&month,&year);
    printf("Enter Seat Number for Delete : ");
    scanf("%s",&sitNumber);
    Node *ptr=head;
    for(ptr=head; ptr->next!=NULL; ptr=ptr->next)
    {
        if(ptr->seat==sitNumber[0]  && ptr->day==day && ptr->seatNumber==sitNumber[1]-'0')
        {
            ck++;
            if(ptr->status==1)
            {
                ptr->status=0;
                strcpy(ptr->name," ");
                strcpy(ptr->mob," ");
                strcpy(ptr->stjrny," ");
                strcpy(ptr->endjrny," ");
                ptr->seat=sitNumber[0];
                ptr->seatNumber=(sitNumber[1]-'0');
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                printf("%s is Delete Successful.\n",sitNumber);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
            else
            {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
                printf("*** \a%s is Alrady Available!***\nPlease Select Correct Seat....\n",sitNumber);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
        }
    }
    if(ck==0)
    {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
        printf("***\aYou Enter Invalid Seat Number.***\n***\aPlease Enter a Valid Seat Number ***\n");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
}

int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    printf("\t***Wellcome to Bus Management System***\n\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    initial();

    while(1)
    {
        int n;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
        printf("_______________________________________________________________________\n");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN |FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        printf("\t***Bus Management System***\n\n");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN| FOREGROUND_INTENSITY);
        printf("\t***Main Menu***\n");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        printf("1: View Available List.\n2: Booking.\n3: Booking Cancel.\n4: Passenger information.\n0: Exit.\n");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
        printf("_______________________________________________________________________\n");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        printf("Enter your Choice : ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        scanf("%d",&n);
        if(n==0)
        {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        printf("Thanks For Using Our System.\n");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            break;
        }

        switch(n)
        {
        case 1:
            printAvail();
            break;
        case 2:
            bookingSit();
            break;
        case 3:
            deleteSit();
            break;
        case 4:
            printUser();
            break;

        default :
            printf("***Invalid Enter***\n");
        }
    }
    return 0;
}

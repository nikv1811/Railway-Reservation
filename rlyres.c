#include <stdio.h>
#include "conio2.h"
#include "rlyres.h"
#include <string.h>
#include <ctype.h>
int enterchoice()
{
int choice,i;
textcolor(YELLOW);
gotoxy(40,1);
printf("RAILWAY RESERVATION SYSTEM\n");
for(i=1;i<=60;i++)
printf("_ ");

printf("\nSelect an option");
printf("\n1- View Trains\n2- Book Ticket\n3- View Ticket\n4- Search Ticket No\n5- View All Bookings\n6- View Train Bookings\n7- Cancel Ticket\n8- Cancel Train\n9- Quit");
printf("\n\nEnter choice:");
scanf("%d",&choice);
return choice;

}

void add_trains()
{
    clrscr();
FILE*fp;
fp=fopen("d:\\myproject\\alltrains.dat","rb");
if(fp==NULL)
{
    train alltrains[4]={
    {"123","BPL","GWA",2100,1800},
    {"528","DEL","KOL",2400,1600},
    {"382","MUM","UJJ",2000,1500},
    {"784","IND","KAN",2800,1900}
                       };
    fp=fopen("d:\\myproject\\alltrains.dat","wb");
    fwrite(alltrains,4*sizeof(train),1,fp);
    //printf("File Saved Successfully\n");
    fclose(fp);
}
    //printf("File Already Present\n");
    fclose(fp);

}

void view_trains()
{
    int i;
    FILE*fp;
    train t;

    textcolor(YELLOW);
    printf("\nTRAIN NO.\tFROM\tTO\tFIRST AC FARE\tSECOND AC FARE\n");
    for(i=1;i<=60;i++)
    printf("_ ");

    fp=fopen("d:\\myproject\\alltrains.dat","rb");

    while(fread(&t,sizeof(t),1,fp)==1)
    {
    printf("\n%s\t\t%s\t%s\t%d\t\t%d",t.train_no,t.from,t.to,t.fac_fare,t.sac_fare);
    }
    fclose(fp);

}


passenger* get_passenger_details()
{
    clrscr();
    gotoxy(60,1);
    textcolor(LIGHTGREEN);
    printf("Press 0 to exit!");
    gotoxy(1,1);
    textcolor(YELLOW);
    static passenger psn;
    printf("ENTER PASSENGER NAME: ");
    fflush(stdin);
    fgets(psn.p_name,20,stdin);
    char*pos;
    pos=strchr(psn.p_name,'\n');
    *pos='\0';
    if(strcmp(psn.p_name,"0")==0)
{
    textcolor(LIGHTRED);
    gotoxy(1,25);
    printf("RESERVATION CANCELLED!!");
    getch();
    textcolor(YELLOW);
    return NULL;
}

   char gender;
   int valid;
   printf("Enter gender(M/F):");
   do
   {
    valid=1;
    fflush(stdin);
    scanf("%c",&psn.gender);
    if(psn.gender=='0')
    {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("\t\t\t\t\t\t\t");
        gotoxy(1,25);
        printf("RESERVATION CANCELLED!!");
        getch();
        textcolor(YELLOW);
        return NULL;
    }

    if(psn.gender!='M'&&psn.gender!='F')
{
    textcolor(LIGHTRED);
    gotoxy(1,25);
    printf("ERROR!! Gender should be either M or F");
    valid=0;
    getch();

    gotoxy(20,2);
    printf("\b");
    textcolor(YELLOW);
}
}while(valid==0);
gotoxy(1,25);
printf("\t\t\t\t\t\t\t");


gotoxy(1,3);
printf("Enter Train No.");
do
{
    fflush(stdin);
    scanf("%s",psn.train_no);
    if(strcmp(psn.train_no,"0")==0)
    {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("\t\t\t\t\t\t\t");
        gotoxy(1,25);
        printf("RESERVATION CANCELLED!!");
        getch();
        textcolor(YELLOW);
        return NULL;
    }

    valid=check_train_no(psn.train_no);
    if(valid==0)
    {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("Invalid Train No.!!");
        getch();
        printf("\t\t\t\t\t\t\t");
        gotoxy(19,3);
        printf("\b\b\b");
        textcolor(YELLOW);
    }

 }while(valid==0);
 gotoxy(1,25);
 printf("\t\t\t\t\t\t\t");


 gotoxy(1,4);
 printf("Enter Travelling Class(First AC-F,Second AC-S):");

 do
 {
    valid=1;
    fflush(stdin);
    scanf("%c",&psn.p_class);
    if(psn.p_class=='0')
    {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("RESERVATION CANCELLED!!");
        getch();
        textcolor(YELLOW);
        return NULL;

    }
    if(psn.p_class!='F'&&psn.p_class!='S')
    {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("Error!! Travelling class should be F or S");
        valid=0;
        getch();
        gotoxy(46,4);
        printf("\b");
        textcolor(YELLOW);

    }

}while(valid==0);
gotoxy(1,25);
printf("\t\t\t\t\t\t\t");

gotoxy(1,5);
printf("Enter Address:");
fflush(stdin);
fgets(psn.address,20,stdin);
pos=strchr(psn.address,'\n');
*pos='\0';
if(strcmp(psn.address,"0")==0)
{
    textcolor(LIGHTRED);
    gotoxy(1,25);
    printf("RESERVATION CANCELLED!!");
    getch();
    textcolor(YELLOW);
    return NULL;

}

gotoxy(1,6);
printf("Enter Age:");
do
{
    valid=1;
    fflush(stdin);
    scanf("%d",&psn.age);
    if(psn.age==0)
    {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("\t\t\t\t\t\t\t");
        gotoxy(1,25);
        printf("RESERVATION CANCELLED!!");
        getch();
        textcolor(YELLOW);
        return NULL;
    }
    if(psn.age<0)
    {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("Error!! Age should be Positive");
        valid=0;
         getch();
        gotoxy(12,6);
        printf("\b");
        textcolor(YELLOW);
    }
}while(valid==0);
 gotoxy(1,25);
 printf("\t\t\t\t\t\t\t");

 gotoxy(1,7);
 printf("Enter Mobile No.:");
 do
 {
   valid=1;
  // printf("YOUR AGE: %d",psn.age);
   fflush(stdin);

   fgets(psn.mob_no,11,stdin);

   pos=strchr(psn.mob_no,'\n');
   if(pos!=NULL)
   *pos='\0';

   if(strcmp(psn.mob_no,"0")==0)
   {
       textcolor(LIGHTRED);
       gotoxy(1,25);
       printf("\t\t\t\t\t\t\t");
       gotoxy(1,25);
       printf("RESERVATION CAANCELLED");
       getch();
       textcolor(YELLOW);
       return NULL;
    }

 valid=check_mob_no(psn.mob_no);

 if(valid==0)
 {
     textcolor(LIGHTRED);
     gotoxy(1,25);
     printf("Error! Invalid Mobile No.");
     getch();
     gotoxy(21,7);
     printf("\t\t\t\t\t\t");
     gotoxy(21,7);
     textcolor(YELLOW);
 }
 }while(valid==0);

 return &psn;

}


int get_booked_ticket_count(char* train_no,char tc)
{
    FILE* fp;
    fp=fopen("d:\\myproject\\allbookings.dat","rb");
    if(fp==NULL)
    {
        return 0;
    }
    passenger pr;
    int count=0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.train_no,train_no)==0&&pr.p_class==tc)
        ++count;
    }
    fclose(fp);
    return count;
}

int last_ticket_no()
{
    FILE* fp;
    fp=fopen("d:\\myproject\\allbookings.dat","rb");
    if(fp==NULL)
    {
        return 0;
    }
    passenger pr;
    fseek(fp,-1*sizeof(pr),SEEK_END);
    int last = fread(&pr,sizeof(pr),1,fp);
    fclose(fp);
    if(last ==0)
        return 0;

    return pr.ticket_no;


}


int book_ticket(passenger p)
{
int ticket_count,ticket_no;
ticket_count=get_booked_ticket_count(p.train_no,p.p_class);
if(ticket_count==30)
    {
     textcolor(LIGHTRED);
     printf("Seats Full in Train %s in Class %c\n",p.train_no,p.p_class);
     return -1;
    }
    ticket_no=last_ticket_no()+1;
    p.ticket_no=ticket_no;
    printf("\nYour ticket no: %d\n",ticket_no);
    FILE* fp;
    fp=fopen("d:\\myproject\\allbookings.dat","ab");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("Can not open file");
        return -1;
    }
   // printf("\nNAME: %s\nGENDER: %c\nTRAIN NO: %s\nCLASS: %c\nADDRRESS: %s\nAGE: %d\nMOBILE NO: %s\nTICKET NO: %d\n",p.p_name,p.gender,p.train_no,p.p_class,p.address,p.age,p.mob_no,p.ticket_no);
   // printf("\n\n");
    fwrite(&p,sizeof(p),1,fp);
    fclose(fp);
    return ticket_no;
}

int accept_ticket_no()
{
    printf("Enter Ticket No.:");
    int valid;
    int ticket_no;
    do
    {
        valid=1;
        scanf("%d",&ticket_no);
        if(ticket_no==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("Cancelling Process..");
            textcolor(YELLOW);
            return 0;
        }
        if(ticket_no<0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("Ticket No. should be Positive");
            valid=0;
            getch();
            gotoxy(11,1);
            printf("\t\t\t\t\t\t\t");
            gotoxy(11,1);
            textcolor(YELLOW);

        }
    }while(valid==0);
    return ticket_no;
}

void view_ticket(int ticket_no)
{
    FILE* fp;
    fp=fopen("d:\\myproject\\allbookings.dat","rb");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("\nNo bookings done yet");
        return;
    }

    passenger pr;
    int found=0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
    if(pr.ticket_no==ticket_no)
    {

      printf("\nNAME: %s\nGENDER: %c\nTRAIN NO: %s\nCLASS: %c\nADDRRESS: %s\nAGE: %d\nMOBILE NO: %s\nTICKET NO: %d\n",pr.p_name,pr.gender,pr.train_no,pr.p_class,pr.address,pr.age,pr.mob_no,pr.ticket_no);
      printf("\n\n");
      found=1;
      break;
    }

    }
    if(!found)
    {
        textcolor(LIGHTRED);
        printf("\nNo details of ticket no %d found!",ticket_no);

    }
fclose(fp);
}

 int check_mob_no(char* p_mob)
{
    if(strlen(p_mob)!=10)
    return 0;
    while(*p_mob!='\0')
      {
        if(isdigit(*p_mob)==0)
        return 0;
        p_mob++;
      }
    return 1;
}

char* accept_mob_no()
{
   static mob_no[11];
   int valid;
   char* pos;
   textcolor(YELLOW);
   printf("Enter Mobile NO.");
  do
    {
    fflush(stdin);
    valid=1;
    fgets(mob_no,11,stdin);
    pos=strchr(mob_no,'\n');
    if(pos!=NULL)
    *pos='\0';
    if(strcmp(mob_no,"0")==0)
    {
       gotoxy(1,25);
       textcolor(LIGHTRED);
       printf("Cancelling Process..");
       getch();
       textcolor(YELLOW);
       return NULL;
    }
   valid=check_mob_no(mob_no);
    if(valid==0)
    {
        gotoxy(1,25);
        printf("\t\t\t\t\t\t");
        gotoxy(1,25);
        textcolor(LIGHTRED);
        printf("Enter valid mobile no");
        textcolor(YELLOW);
        gotoxy(17,1);
        printf("       \b\b\b\b");
    }

    }while(valid==0);
    clrscr();
    return mob_no;
}

int* get_ticket_no(char *p_mob_no)
{
   int count=0;
   FILE* fp;
   fp=fopen("d:\\myproject\\allbookings.dat","rb");
   if(fp==NULL)
    {
        return NULL;
    }
   passenger pr;
   while(fread(&pr,sizeof(pr),1,fp)==1)
    {
     //  printf("\nNAME: %s\nGENDER: %c\nTRAIN NO: %s\nCLASS: %c\nADDRRESS: %s\nAGE: %d\nMOBILE NO: %s\nTICKET NO: %d\n",pr.p_name,pr.gender,pr.train_no,pr.p_class,pr.address,pr.age,pr.mob_no,pr.ticket_no);
     //    printf("\n\n");

      if(strcmp(pr.mob_no,p_mob_no)==0)
      ++count;
   }
    if(count==0)
    {
        fclose(fp);
        return NULL;
    }
    rewind(fp);
    int* p;
    p=(int*)malloc((count+1)*sizeof(int));
    int i=0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
      if(strcmp(pr.mob_no,p_mob_no)==0)
      {
        *(p+i)=pr.ticket_no;
         i++;
      }
    }
*(p+i)=-1;
fclose(fp);
return p;
}

void view_all_tickets(char* pmob_no,int* pticket_no)
{
    if(pticket_no==NULL)
    {
        textcolor(LIGHTRED);
        printf("Sorry! No tickets booked against mobile no %s",pmob_no);
        textcolor(WHITE);
        printf("\n\nPress any key to go back to the main screen");
        textcolor(YELLOW);
        getch();
        return;
    }
    printf("Following are tickets booked for mobile no %s",pmob_no);
    int i;
    printf("\n\nTICKET NO\n");
    printf("---------");
    for(i=0;*(pticket_no+i)!=-1;i++)
        printf("\n%d",*(pticket_no+i));
    textcolor(WHITE);
    printf("\n\nPress any key to go back to the main screen");
    textcolor(YELLOW);
    getch();
}

void view_all_bookings()
{

FILE*fp;
fp=fopen("d:\\myproject\\allbookings.dat","rb");
if(fp==NULL)
{
    textcolor(LIGHTRED);
    printf("Sorry! No bookings done yet..");

}
if(fp!=NULL)
{
textcolor(YELLOW);
printf("Train No.");
gotoxy(23,1);
printf("Ticket No.");
gotoxy(44,1);
printf("Name");
gotoxy(63,1);
printf("Class");
gotoxy(90,1);
printf("Mobile No");
int i;
for(i=1;i<=120;i++)
{
    gotoxy(i,2);
    printf("_ ");
}


int j=3;
passenger pr;
while(fread(&pr,sizeof(pr),1,fp)==1)
{
    gotoxy(1,j);
    printf("%s",pr.train_no);
    gotoxy(23,j);
    printf("%d",pr.ticket_no);
    gotoxy(44,j);
    printf("%s",pr.p_name);
    gotoxy(63,j);
    printf("%c",pr.p_class);
    gotoxy(90,j);
    printf("%s",pr.mob_no);
    j++;
}
fclose(fp);
}
}


void view_booking(char* tr_no)
{
   FILE*fp;
   fp=fopen("d:\\myproject\\allbookings.dat","rb");
   passenger ps;
   int j=3;
    clrscr();
         textcolor(YELLOW);
         printf("Train no");
         gotoxy(23,1);
         printf("Ticket No.");
         gotoxy(44,1);
         printf("Name");
         gotoxy(63,1);
         printf("Class");
         gotoxy(90,1);
         printf("Mobile No");
        int i;
        for( i=1;i<=120;i++)
        {
          gotoxy(i,2);
          printf("_ ");
        }
    while(fread(&ps,sizeof(ps),1,fp)==1)
       {
        if(strcmp(ps.train_no,tr_no)==0)
        {

    gotoxy(1,j);
    printf("%s",ps.train_no);
    gotoxy(23,j);
    printf("%d",ps.ticket_no);
    gotoxy(44,j);
    printf("%s",ps.p_name);
    gotoxy(63,j);
    printf("%c",ps.p_class);
    gotoxy(90,j);
    printf("%s",ps.mob_no);
    j++;
}
}
if(j<4)
{
  textcolor(LIGHTRED);
  printf("No bookings done yet in %s Train no.",tr_no);
}

fclose(fp);
}

int cancel_ticket(int ticket_no)
{
    FILE* fp1;
    fp1=fopen("d:\\myproject\\allbookings.dat","rb");
    if(fp1==NULL)
    {
        textcolor(LIGHTRED);
        printf("\nNo Booking Done yet");
        return -1;
    }
    FILE* fp2;
    fp2=fopen("d:\\myproject\\temp.dat","wb+");
    passenger pr;
    int found=0;
    while(fread(&pr,sizeof(pr),1,fp1)==1)
    {
       if(ticket_no!=pr.ticket_no)
       {
           fwrite(&pr,sizeof(pr),1,fp2);
       }
       else
       {
           found=1;
       }
    }
   fclose(fp1);
   fclose(fp2);
   if(found==0)
       {
        remove("d:\\myproject\\temp.dat");
       }
    else
    {
        remove("d:\\myproject\\allbookings.dat");
        rename("d:\\myproject\\temp.dat","d:\\myproject\\allbookings.dat");

    }

return found;
}

char* accept_train_no()
{
static char train_no[10];
int valid;
printf("Enter train number:");
            do
            {
            fflush(stdin);
            scanf("%s",train_no);
            if(strcmp(train_no,"0")==0)
            {
                textcolor(LIGHTRED);
                gotoxy(1,25);
                printf("\t\t\t\t\t\t\t");
                gotoxy(1,25);
                printf("Cancelling Process..");
                textcolor(YELLOW);
                return NULL;
            }
            valid=check_train_no(train_no);
            if(valid==0)
            {
            textcolor(LIGHTRED);
            gotoxy(1,25);

            printf("Error! Invalid Train No");
            getch();
            gotoxy(20,1);
            printf("\t\t\t\t\t\t");
            gotoxy(20,1);
            textcolor(YELLOW);
            }

            }while(valid==0);
 clrscr();
 return train_no;
}


int check_train_no(char* trainno)
{
    FILE* fp;
    fp=fopen("d:\\myproject\\alltrains.dat","rb");
    train tr;
    while(fread(&tr,sizeof(tr),1,fp)==1)
    {
        if(strcmp(tr.train_no,trainno)==0)
        {
        fclose(fp);
        return 1;
        }
    }
        fclose(fp);
        return 0;
}


int cancel_train(char* ptrain_no)
{
    FILE*fp1;
    fp1=fopen("d:\\myproject\\allbookings.dat","rb");

        if(fp1==NULL)
        {
            textcolor(LIGHTRED);
            printf("No bookings done yet..!");
            return -1;
        }
    FILE* fp2;
    fp2=fopen("d:\\myproject\\temp.dat","wb+");
    passenger pr;
    int found=0;
  while(fread(&pr,sizeof(pr),1,fp1)==1)
    {
      if(strcmp(pr.train_no,ptrain_no)!=0)
      {
          fwrite(&pr,sizeof(pr),1,fp2);
      }
      else
      {
          found=1;
      }
    }
    fclose(fp1);
    fclose(fp2);
    if(found==0)
    {
        remove("d:\\myproject\\temp.dat");
    }
    else
    {
        remove("d:\\myproject\\allbookings.dat");
        rename("d:\\myproject\\temp.dat","d:\\myproject\\allbookings.dat");

    }

return found;
}





#include <stdio.h>
#include <stdlib.h>
#include "rlyres.h"
#include "conio2.h"

int main()
{
     int choice;
     add_trains();
     while(1)
    {
     choice=enterchoice();
        if(choice==9)
        {
            exit(0);
        }

    switch(choice)
    {
    case 1:
        clrscr();
    view_trains();
    getch();
    clrscr();
    break;

    case 2:
    clrscr();
    passenger* ptr;
    ptr=get_passenger_details();
    getch();
    if(ptr!=NULL)
    {
      int get_ticket_no=book_ticket(*ptr);

    if(get_ticket_no==-1)
    {
        textcolor(LIGHTRED);
        printf("Booking Failed");
    }
    else
        printf("Booking Done");
    }
    textcolor(WHITE);
    printf("\nPress any key to go to main menu");
    getch();
    clrscr();
    break;

    case 3:
    clrscr();
    int ticket_no=accept_ticket_no();
    if(ticket_no!=0);
    view_ticket(ticket_no);
    textcolor(WHITE);
    printf("\nPress any key to go to main menu");
    getch();
    clrscr();
    break;

 case 4:
     clrscr();
 char *    pmob_no=accept_mob_no();
     if(pmob_no!=NULL)
     {
        int pticket_no=get_ticket_no(pmob_no);
         view_all_tickets(pmob_no,pticket_no);
     }
     clrscr();
     break;

 case 5:
     clrscr();
     view_all_bookings();
     textcolor(WHITE);
     printf("\nPress any key to go to main menu");
     getch();
     clrscr();
     getch();
     break;

 case 6:
     clrscr();
        char* train_no=accept_train_no();
        if(train_no!=NULL)
            view_booking(train_no);
        textcolor(WHITE);
        printf("\nPress any key to go to main menu");
        getch();
        clrscr();
                break;

 case 7:
     clrscr();
     ticket_no=accept_ticket_no();
    if(ticket_no!=0)
    {
       int result=cancel_ticket(ticket_no);
       if(result==0)
        {
        textcolor(LIGHTRED);
        printf("Sorry! No tickets booked against ticket no %d",ticket_no);

        }
        else if(result==1)
        {
        textcolor(LIGHTGREEN);
        printf("Ticket no %d successfully cancelled!",ticket_no);
        }
        textcolor(WHITE);
        printf("\n\nPress any key to go back to the main screen");
    }

        getch();
        clrscr();
        break;


 case 8:
          clrscr();
          int ptrain_no=accept_train_no();
          if(ptrain_no!=NULL)
            {
            int result=cancel_train(ptrain_no);
            if(result==0)
            {
            textcolor(LIGHTRED);
            printf("Sorry! No tickets booked in train no no %s",ptrain_no);
            }
            else
            {
            textcolor(LIGHTGREEN);
            printf("Train no %s successfully cancelled!",ptrain_no);
            }
            textcolor(WHITE);
            printf("\n\nPress any key to go back to the main screen");

            }


         getch();
         clrscr();
         break;

 default:
                textcolor(LIGHTRED);
                printf("\nWrong Choice.!! Try Again");
                getch();
                clrscr();

    }
    }
    return 0;
}

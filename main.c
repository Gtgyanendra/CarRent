#include <stdio.h>
#include <stdlib.h>
#include"conio2.h"
#include"car.h"
#include<time.h>

 int main()
 {
     int i,type;
     int k,choice,x;
     User *usr;
     int result;
     gotoxy(35,12);
     textcolor(YELLOW);
     printf("||  WELCOME TO CAR RENTAL SYSTEM  ||");
     gotoxy(32,15);
     textcolor(LIGHTGREEN);
     printf(":-   RENT A CAR AND GO WHEREVER YOU NEED   -:");
     getch();
     textcolor(YELLOW);
     addAdmin();
     while(1)
     {
         clrscr();
          textcolor(LIGHTCYAN);
    gotoxy(40,1);
    printf("CAR RENTAL SYSTEM");
    gotoxy(38,2);
    textcolor(WHITE);
    for(i=1;i<22;i++)
      printf("%c",247);
         gotoxy(1,6);
         textcolor(LIGHTGREEN);
         for(i=0;i<104;i++)
         {
             printf("*");
         }
         gotoxy(1,18);
         for(i=0;i<104;i++)
         {
             printf("*");
         }
         gotoxy(40,10);
         textcolor(YELLOW);
         printf("1. Admin");
         gotoxy(40,12);
         printf("2. Employee");
         gotoxy(40,14);
         printf("3. Quit");
         gotoxy(40,16);
         textcolor(WHITE);
         printf("Select your role :");
         do
         {
             scanf("%d",&type);
             if(type==1)
             {

           do
           {
                usr=getInput();
                if(usr==NULL)
                    break;
                else
                {
                    k=checkUserExist(*usr,"admin");
                }

             }while(k==0);
             if((k==-1)||(usr==NULL))
                break;
            if(k==1)
            {
                gotoxy(1,20);
                textcolor(WHITE);
                printf("press any key to continue");
                getch();
                while(1)
                {
                    clrscr();
                    choice=adminMenu();
                    if(choice==7)
                    {
                        break;
                    }
                    switch(choice)
                    {
                    case 1:
                        clrscr();
                        addEmployee();
                        break;
                    case 2:
                        clrscr();
                        addCarDetails();
                        break;
                    case 3:
                        clrscr();
                        viewEmploye();
                        break;
                    case 4:
                        clrscr();
                        showCarDetails();
                        break;
                    case 5:
                        clrscr();
                        result=deleteEmp();
                        gotoxy(15,14);
                        if(result==0)
                        {
                            textcolor(LIGHTRED);
                            printf("Sorry! no record of the given emp found");
                        }
                        else if(result==1)
                        {
                            textcolor(LIGHTRED);
                            printf("Record deleted successfully");
                        }
                        else if(result==2)
                        {
                            textcolor(LIGHTRED);
                            printf("Error in deletion try again");
                        }
                        textcolor(WHITE);
                        printf("\n\n press any key to go back to main screen!");
                        getch();
                        break;
                    case 6:
                        clrscr();
                        result=deleteCarModel();
                        gotoxy(15,14);
                        if(result==0)
                        {
                            textcolor(LIGHTRED);
                            printf("Sorry! no record of the given car found");
                        }
                        else if(result==1)
                        {
                            textcolor(LIGHTRED);
                            printf("Record deleted successfully");
                        }
                        else if(result==2)
                        {
                            textcolor(LIGHTRED);
                            printf("Error in deletion try again");
                        }
                        textcolor(WHITE);
                        printf("\n\n press any key to go back to main screen!");
                        getch();
                        break;
                    default:
                          gotoxy(50,20);
                          textcolor(LIGHTRED);
                        printf("Incorrect choice! \n");
                        textcolor(WHITE);
                        gotoxy(50,21);
                        printf("Try Again");
                        getch();
                        break;
                    }
                }
                if(choice==7)
                    break;
            }
           }
            else if(type==2)
             {
                 do
                {
                usr=getInput();
                if(usr==NULL)
                    break;
                else
                {
                    k=checkUserExist(*usr,"emp");
                }

             }while(k==0);
             if(k==-1||usr==NULL)
                break;
                if(k==1)
            {
                gotoxy(1,20);
                textcolor(WHITE);
                printf("Press any key to continue...");
                getch();
                while(1)
                {
                    clrscr();
                    choice=empMenu();
                    if(choice==7)
                    {
                        break;
                    }
                    switch(choice)
                    {
                    case 1:
                        clrscr();
                         x=rentCar();
                         if(x==-2)
                         {
                             gotoxy(35,9);
                             textcolor(LIGHTRED);
                             printf(" Sorry All Cars are Booked !!   Try later....");
                             getch();
                         }
                         else if(x==0)
                         {
                             gotoxy(35,18);
                             textcolor(LIGHTRED);
                             printf("You did not choose any car..");
                             getch();
                         }

                        break;
                    case 2:
                        clrscr();
                        bookedCarDetials();
                        break;
                    case 3:
                        clrscr();
                          avilCarDetails();
                        break;
                    case 4:
                        clrscr();
                        showCarDetails();
                        break;
                    case 5:
                        clrscr();
                        textcolor(RED);
                        gotoxy(40,1);
                        printf("CAR RENTAL SYSTEM");
                        textcolor(GREEN);
                        gotoxy(1,3);
                        for(i=1;i<=104;i++)
                        printf("%c",247);
                        gotoxy(35,5);
                        printf("* Return Car's Details *");
                        gotoxy(1,7);
                        for(i=1;i<=104;i++)
                        printf("%c",247);
                        returnCar();
                        gotoxy(25,18);
                        textcolor(GREEN);
                        printf("Car returned successfully! Dear customer thank you for visiting us...");
                        getch();
                        break;
                    case 6:
                        clrscr();
                        textcolor(RED);
                        gotoxy(40,1);
                        printf("CAR RENTAL SYSTEM");
                        textcolor(GREEN);
                        gotoxy(1,3);
                        for(i=1;i<=104;i++)
                        printf("%c",247);
                        gotoxy(35,5);
                        printf("* Canceling Car's Details *");
                        gotoxy(1,7);
                        for(i=1;i<=104;i++)
                        printf("%c",247);
                        returnCar();
                        gotoxy(35,18);
                        textcolor(GREEN);
                        printf("This Booking is canceled!!");
                        getch();
                        break;

                    default:
                          gotoxy(60,23);
                          textcolor(LIGHTRED);
                        printf("Incorrect choice!!");
                        getch();
                        break;
                    }
                }
                if(choice==7)
                        break;
             }
            }
             else if(type==3)
             {
                 clrscr();
                 textcolor(GREEN);
                 gotoxy(35,12);
                 printf("THANK YOU FOR USING THIS APP!!.....");
                 getch();
                 exit(0);
             }
             else
             {
                 textcolor(RED);
                 gotoxy(40,20);
                 printf("Invalid choice");
                 getch();
                 gotoxy(40,20);
                 printf("\t\t\t\t\t");
                 gotoxy(58,16);
                 printf("\t\t\t");
                 textcolor(WHITE);
                 gotoxy(58,16);
             }
         }while(1);
             getch();
     }

    return 0;
}

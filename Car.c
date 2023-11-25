#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"conio2.h"
#include"car.h"
#include<time.h>
#include<dos.h>
void addAdmin()
{
    FILE*fp=fopen("admin.bin","rb");
    if(fp==NULL)
    {
        fp=fopen("admin.bin","wb");
        User u[2]={{"Gyanendra","1234","ravi"},{"Kapil","test","anil"}};
        fwrite(u,sizeof(u),1,fp);
    }
    fclose(fp);
}
User* getInput()
{
    int i;
    clrscr();
    textcolor(LIGHTCYAN);
    gotoxy(40,1);
    printf("CAR RENTAL SYSTEM");
    gotoxy(38,2);
    textcolor(WHITE);
    for(i=1;i<22;i++)
      printf("%c",247);
   textcolor(GREEN);
    gotoxy(1,3);
    for(i=1;i<104;i++)
        printf("%c",247);
    gotoxy(40,6);
    textcolor(GREEN);
    printf("LOGIN PANEL");
    gotoxy(1,8);
    for(i=1;i<104;i++)
        printf("%c",247);
     gotoxy(1,16);
    for(i=1;i<104;i++)
        printf("%c",247);
    gotoxy(80,9);
    textcolor(WHITE);
    printf("press 0 to exit");
    textcolor(LIGHTCYAN);
    gotoxy(40,11);
    printf("Enter userid:");
    textcolor(WHITE);
    static User u;
    fflush(stdin);
    fgets(u.userid,20,stdin);
    char*pos;
    pos=strchr(u.userid,'\n');
    if(*pos!=NULL)
    {
        *pos='\0';
    }
    if(strcmp(u.userid,"0")==0)
    {
      textcolor(LIGHTRED);
      gotoxy(40,18);
      printf("login canceled");
      getch();
      textcolor(YELLOW);
      return NULL;
    }
    gotoxy(40,12);
    textcolor(LIGHTCYAN);
    printf("Enter Password:");
    fflush(stdin);
    textcolor(WHITE);
    for(i=0;;)
    {
     u.pwd[i]=getch();
     if(u.pwd[i]==13)
        break;
     printf("*");
     if(u.pwd[i]==8)
     {
       printf("\b\b  \b\b");
       i=i-2;
     }
     i++;
    }
    u.pwd[i]='\0';
    if(strcmp(u.pwd,"0")==0)
    {
      textcolor(LIGHTRED);
      gotoxy(40,18);
      printf("login canceled");
      getch();
      textcolor(YELLOW);
     return NULL;
    }
    return &u;
}


int checkUserExist(User u,char*usertype)
{
    if(strlen(u.userid)==0||strlen(u.pwd)==0)
    {
        gotoxy(40,20);
        textcolor(LIGHTRED);
        printf("Both fields are mandatory. Try again and press enter");
        getch();
        gotoxy(40,20);
        printf("\t\t\t\t\t\t\t");
        return 0;
    }
    FILE *fp;
    if(strcmp(usertype,"admin")==0)
    {
        fp=fopen("admin.bin","rb");
    }
    else
    {
        fp=fopen("emp.bin","rb");
    }
    if(fp==NULL)
    {
        gotoxy(40,20);
        textcolor(LIGHTRED);
        printf("Sorry! Cannot open the file");
        getch();
        gotoxy(40,20);
        printf("\t\t\t\t\t\t\t");
        return -1;
    }
    int found=0;
    User user;
    while(fread(& user ,sizeof(user),1,fp)==1)
    {
        if(strcmp(u.userid,user.userid)==0&&strcmp(u.pwd,user.pwd)==0)
        {
            found=1;
            break;
        }
    }
    if(found==0)
    {
        gotoxy(40,20);
        textcolor(LIGHTRED);
        printf("Invalid user id/Password. Try again and press enter");
        getch();
        gotoxy(40,20);
        printf("\t\t\t\t\t\t\t\t");

    }
    else
    {
        gotoxy(40,20);
        textcolor(GREEN);
        printf("Login successful ! Press enter.");
        getch();
        gotoxy(40,20);
        printf("\t\t\t\t\t\t\t");

    }
    fclose(fp);
    return found;
}

int adminMenu()
{
    int choice,i;
  textcolor(LIGHTCYAN);
    gotoxy(40,1);
    printf("CAR RENTAL SYSTEM");
    textcolor(WHITE);
    for(i=38;i<=58;i++)
    {
    gotoxy(i,2);
    printf("=");
    }
    textcolor(LIGHTGREEN);
    gotoxy(45,5);
    printf("ADMIN MENU");
    gotoxy(43,6);
    for(i=1;i<=13;i++)
      printf("=");
    for(i=1;i<105;i++)
    {
        gotoxy(i,3);
        printf("*");
        gotoxy(i,25);
        printf("-");
    }

    textcolor(LIGHTCYAN);
    for(i=8;i<20;i++)
    {
    gotoxy(32,i);
    printf("||");
    gotoxy(64,i);
    printf("||");
    }
    textcolor(YELLOW);
    gotoxy(40,9);
    printf("1. Add Employe");
    gotoxy(40,10);
    printf("2. Add Car Details");
    gotoxy(40,11);
    printf("3. Show Employe");
    gotoxy(40,12);
    printf("4. Show Car Details");
    gotoxy(40,13);
    printf("5. Delete Employe");
    gotoxy(40,14);
    printf("6. Delete Car Details");
    gotoxy(40,15);
    printf("7. Exit");
    gotoxy(37,17);
    printf("Enter your choice: ");
    textcolor(WHITE);
    scanf("%d",&choice);
    return choice;
}



void addEmployee()
{
    char temp[20];
    char choice;
    char *pos;
    User u;
    FILE *fp=fopen("emp.bin","ab+");
    fseek(fp,0,SEEK_END);
    long total_rec=ftell(fp)/sizeof(User);
    if(total_rec!=0)
     {
        fseek(fp,-60,SEEK_END);
        fread(temp,sizeof(temp),1,fp);
        pos=strchr(temp,'-');
        total_rec=atoi(pos+1);
     }
    total_rec++;
    sprintf(u.userid,"EMP-%d",total_rec);
    fseek(fp,0,SEEK_END);
    do
    {
      clrscr();
      int i;
     textcolor(LIGHTCYAN);
    gotoxy(40,1);
    printf("CAR RENTAL SYSTEM");
    textcolor(WHITE);
    for(i=38;i<=58;i++)
    {
    gotoxy(i,2);
    printf("=");
    }
        textcolor(LIGHTGREEN);
        for(i=1;i<=104;i++)
        {
            gotoxy(i,3);
            printf("*");
              gotoxy(i,7);
              printf("*");
        }
        gotoxy(35,5);
        printf("***** ADD EMPLOYEE DETAILS *****");
        gotoxy(1,9);
        textcolor(GREEN);
        printf("Enter Employee Name:");
        fflush(stdin);
        textcolor(WHITE);
        fgets(u.name,20,stdin);
        char *pos;
        pos=strchr(u.name,'\n');
        if(pos!=NULL)
        {
            *pos='\0';
        }
        textcolor(GREEN);
        printf("Enter Employee Pwd:");
        fflush(stdin);
        textcolor(WHITE);
        fgets(u.pwd,20,stdin);
        pos=strchr(u.pwd,'\n');
        if(pos!=NULL)
        {
            *pos='\0';
        }
        fwrite(&u,sizeof(u),1,fp);
        gotoxy(35,16);
        textcolor(LIGHTGREEN);
        printf("EMPLOYEE ADDED SUCCESSFULY!");
        printf("\nEMPLOYEE ID IS %s",u.userid);
        //getch();
        gotoxy(1,20);
        textcolor(WHITE);
        printf("Do you want to add more employees (Y/N)? ");
        fflush(stdin);
        scanf("%c",&choice);
        if(choice=='N')
            break;
        total_rec++;
        sprintf(u.userid,"EMP-%d",total_rec);
    }while(choice=='Y');
    fclose(fp);

}
void addCarDetails()
{
    car c;
    char choice;
    int carid;
    FILE *fp=fopen("car.bin","ab+");
    if(fp==NULL)
    {
        textcolor(RED);
        printf("Sorry! can not open this file");
        return ;
    }

  do
    {
      clrscr();
      int i;
    textcolor(LIGHTCYAN);
    gotoxy(40,1);
    printf("CAR RENTAL SYSTEM");
    textcolor(WHITE);
    for(i=38;i<=58;i++)
    {
    gotoxy(i,2);
    printf("=");
    }
      textcolor(LIGHTGREEN);
    for(i=1;i<105;i++)
    {
      gotoxy(i,3);
      printf("*");
      gotoxy(i,6);
      printf("*");
    }
    gotoxy(35,5);
    textcolor(WHITE);
    printf("***** ADD CAR DETAILS *****");
    gotoxy(1,7);
    textcolor(YELLOW);
    printf("Enter Car Model :");
    textcolor(WHITE);
    fflush(stdin);
    fgets(c.car_name,20,stdin);
    char *pos;
    pos=strchr(c.car_name,'\n');
    if(pos!=NULL)
    {
        pos='\0';
    }
    gotoxy(1,8);
    textcolor(YELLOW);
    printf("Enter Car Capacity :");
    textcolor(WHITE);
    scanf("%d",&c.capacity);
    gotoxy(1,9);
    textcolor(YELLOW);
    printf("Enter Car Count :");
    textcolor(WHITE);
    scanf("%d",&c.car_count);
    gotoxy(1,10);
    textcolor(YELLOW);
    printf("Enter Car price for per day :");
    textcolor(WHITE);
    scanf("%d",&c.price);
    gotoxy(40,14);
    textcolor(LIGHTGREEN);
    printf("CAR ADDED SUCCESSFULLY!");
    gotoxy(1,17);
    fseek(fp,0,SEEK_END);
    c.car_id=ftell(fp)/sizeof(c);
    if(c.car_id!=0)
    {
        fseek(fp,-36,SEEK_END);
        fread(&carid,sizeof(carid),1,fp);
        c.car_id=carid;
    }
    c.car_id++;
    fseek(fp,0,SEEK_END);
    printf("Car id is:%d",c.car_id);
    fwrite(&c,sizeof(c),1,fp);
    getch();
    gotoxy(1,21);
    textcolor(LIGHTRED);
    printf("Do you want to add more cars(y/n)? ");
    fflush(stdin);
    scanf("%c",&choice);
    if(choice=='n')
    {
     break;
    }
    }while(choice=='y');
    fclose(fp);
}

void viewEmploye()
{
    FILE*fp=fopen("emp.bin","rb");
    User ur;
    char ch;
    int row=10;
    int i=1;
   textcolor(LIGHTCYAN);
    gotoxy(40,1);
    printf("CAR RENTAL SYSTEM");
    gotoxy(38,2);
    textcolor(WHITE);
    for(i=38;i<60;i++)
    {
      gotoxy(i,2);
      printf("%c",247);
    }
    textcolor(GREEN);
    gotoxy(1,3);
    for(i=1;i<105;i++)
        printf("%c",247);
    gotoxy(40,5);
    textcolor(YELLOW);
    printf("* EMPLOYE DETAILS *");
    textcolor(WHITE);
    gotoxy(80,6);
    printf("Press enter to go back..");
    textcolor(GREEN);
    for(i=1;i<105;i++)
    {
      gotoxy(i,7);
    printf("%c",247);
    gotoxy(i,9);
    printf("%c",247);
    }
    gotoxy(1,8);
    if(fp==NULL)
    {
        printf("Sorry!! No employees added yet");
        return ;
    }
    printf("EMPLOYE ID \t\t\t\t NAME \t\t\t\t PASSWORD");
    textcolor(YELLOW);
    while(fread(&ur,sizeof(ur),1,fp)==1)
    {
        gotoxy(1,row);
        printf("%s",ur.userid);
        gotoxy(42,row);
        printf("%s",ur.name);
        gotoxy(74,row);
        printf("%s",ur.pwd);
        row++;
    }
    getch();
    fclose(fp);
}

void showCarDetails()
{
    FILE*fp=fopen("car.bin","rb");
    car c;
    char ch;
    int row=10;
    int i=1;
    textcolor(LIGHTCYAN);
    gotoxy(40,1);
    printf("CAR RENTAL SYSTEM");
    gotoxy(38,2);
    textcolor(WHITE);
    for(i=1;i<22;i++)
      printf("%c",247);
    textcolor(GREEN);
    for(i=1;i<104;i++)
    {
          gotoxy(i,3);
        printf("%c",247);
        gotoxy(i,7);
        printf("%c",247);
        gotoxy(i,9);
        printf("%c",247);
    }
    gotoxy(40,5);
    textcolor(YELLOW);
    printf("* CAR MODELS DETAILS *");
    textcolor(WHITE);
    gotoxy(80,6);
    printf("Press enter to go back..");
    textcolor(GREEN);
    gotoxy(1,8);
    if(fp==NULL)
    {
        printf("Sorry no car added: ");
        return ;
    }
    printf("CAR ID \t\t CAR NAME \t\t CAPACITY \t\t AVAILABLE \t\t PRICE");
    textcolor(YELLOW);
    while(fread(&c,sizeof(c),1,fp)==1)
    {
        gotoxy(1,row);
        printf("%d",c.car_id);
        gotoxy(18,row);
        printf("%s",c.car_name);
        gotoxy(42,row);
        printf("%d",c.capacity);
        gotoxy(66,row);
        printf("%d",c.car_count);
        gotoxy(90,row);
        printf("%d",c.price);
        row++;
    }
    getch();
    fclose(fp);
}
int deleteEmp()
{
    FILE*fp1=fopen("emp.bin","rb");
    char empid[10];
    int i,result;
   textcolor(LIGHTCYAN);
    gotoxy(40,1);
    printf("CAR RENTAL SYSTEM");
    textcolor(WHITE);
    for(i=38;i<=58;i++)
    {
    gotoxy(i,2);
    printf("=");
    }
    textcolor(GREEN);
    for(i=1;i<105;i++)
    {
      gotoxy(i,4);
      printf("*");
      gotoxy(i,8);
      printf("*");
    }
            gotoxy(40,6);
            textcolor(WHITE);
            printf("DELETE EMPLOYEE");
    if(fp1==NULL)
        {
        textcolor(YELLOW);
        gotoxy(40,10);
        printf("Sorry! employee not added...");
        return -1;
    }
    FILE*fp2=fopen("temp.bin","wb+");
    if(fp2==NULL)
    {
        textcolor(RED);
        gotoxy(40,10);
        printf("Sorry! cannot create temp file");
        return -1;
    }
    gotoxy(10,9);
    textcolor(YELLOW);
    printf("Enter employee id to delete the record:");
    textcolor(WHITE);
    scanf("%s",empid);
    User u;
    int found=0;
    while(fread(&u,sizeof(u),1,fp1)==1)
    {
        if(strcmp(u.userid,empid)!=0)
        {
            fwrite(&u,sizeof(u),1,fp2);
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
        remove("temp.bin");
    }
    else
    {
        result=remove("emp.bin");
        if(result!=0)
            return 2;
        result=rename("temp.bin","emp.bin");
        if(result!=0)
            return 2;
    }
    return found;
}


int deleteCarModel()
{
    FILE*fp1=fopen("car.bin","rb");
    int carid;
    int i,result;
   textcolor(LIGHTCYAN);
    gotoxy(40,1);
    printf("CAR RENTAL SYSTEM");
    textcolor(WHITE);
    for(i=38;i<=58;i++)
    {
    gotoxy(i,2);
    printf("=");
    }
    textcolor(GREEN);
    for(i=1;i<=104;i++)
    {
    gotoxy(i,5);
            printf("*");
    gotoxy(i,7);
            printf("*");
    }
            gotoxy(40,6);
            printf("* DELETE CAR MODEL *");
    if(fp1==NULL)
        {
        textcolor(YELLOW);
        gotoxy(40,10);
        printf("Sorry! car not added yet");
        return -1;
    }
    FILE*fp2=fopen("temp.bin","wb+");
    if(fp2==NULL)
    {
        textcolor(RED);
        gotoxy(40,10);
        printf("Sorry! cannot create temp file");
        return -1;
    }
    gotoxy(10,9);
    textcolor(YELLOW);
    printf("Enter car id to delete the record:");
    textcolor(WHITE);
    scanf("%d",&carid);
    car c;
    int found=0;
    while(fread(&c,sizeof(c),1,fp1)==1)
    {
        if(c.car_id!=carid)
        {
            fwrite(&c,sizeof(c),1,fp2);
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
        remove("temp.bin");
    }
    else
    {
        result=remove("car.bin");
        if(result!=0)
            return 2;
        result=rename("temp.bin","car.bin");
        if(result!=0)
            return 2;
    }
    return found;
}

int empMenu()
{
    int choice,i;
    textcolor(LIGHTCYAN);
    gotoxy(40,1);
    printf("CAR RENTAL SYSTEM");
    textcolor(WHITE);
    for(i=38;i<=58;i++)
    {
    gotoxy(i,2);
    printf("=");
    }
    textcolor(GREEN);
    for(i=1;i<105;i++)
    {
      gotoxy(i,3);
    printf("*");
     gotoxy(i,24);
     printf("-");
    }
    gotoxy(45,6);
    printf("EMPLOYEE MENU");
    textcolor(LIGHTCYAN);
    for(i=43;i<60;i++)
    {
      gotoxy(i,7);
    printf("=");
    }
    for(i=10;i<=20;i++)
    {
          gotoxy(30,i);
          printf("||");
          gotoxy(72,i);
          printf("||");
    }
     textcolor(YELLOW);
     gotoxy(40,10);
     printf("1.Rent a car ");
     gotoxy(40,11);
     printf("2.Booking details ");
     gotoxy(40,12);
     printf("3.Available car details ");
     gotoxy(40,13);
     printf("4.Show all car details ");
     gotoxy(40,14);
     printf("5.Return car");
     gotoxy(40,15);
     printf("6. Delete car booking");
     gotoxy(40,16);
     printf("7. Exit");
     gotoxy(40,18);
     printf("Enter your choice:");
     textcolor(WHITE);
     scanf("%d",&choice);
     return choice;
}
int selectCarModel()
{
    FILE*fp=fopen("car.bin","rb");
    int flag;
    int choice,rowno=10,carcount=0;
    car c;
    gotoxy(40,rowno);
    textcolor(YELLOW);
    while(fread(&c,sizeof(c),1,fp)==1)
    {
        if(c.car_count>0)
        {
            printf("%d. %s",c.car_id,c.car_name);
            gotoxy(40,++rowno);
            carcount++;
        }
    }
    if(carcount==0)
    {
        return -2;
    }
    gotoxy(40,rowno+2);
    printf("Enter your choice (0 to quit):  ");
    textcolor(WHITE);
    while(1)
    {
        flag=0;
        scanf("%d",&choice);
        if(choice==0)
        {
            fclose(fp);
            return 0;
        }
        rewind(fp);
        while(fread(&c,sizeof(c),1,fp)==1)
        {
            if((c.car_id==choice)&&(c.car_count>0))
               {
                flag=1;
                break;
               }
        }
    if(flag==1)
    {
        fclose(fp);
        return choice;
    }
    gotoxy(40,rowno+4);
    textcolor(LIGHTRED);
    printf("Wrong Input!!  press enter..");
    getch();
    gotoxy(40,rowno+4);
    printf("\t\t\t\t\t\t\t\t");
    gotoxy(58,rowno+2);
    printf("\t");
    gotoxy(58,rowno+2);
    textcolor(WHITE);
    }
}

int isValidDate(struct tm dt)
{
    time_t obj=time(0);
    struct  tm *p=localtime(&obj);
    if((dt.tm_year>=1900+p->tm_year)&&(dt.tm_year<=1900+p->tm_year+1))
    {
        if(dt.tm_mon>=1&&dt.tm_mon<=12)
        {
         if((dt.tm_mday>=1&&dt.tm_mday<=31)&&(dt.tm_mon==1||dt.tm_mon==3||dt.tm_mon==5||dt.tm_mon==7||dt.tm_mon==8||dt.tm_mon==10||dt.tm_mon==12))
            return 1;
         else if((dt.tm_mday>=1&&dt.tm_mday<=30)&&(dt.tm_mon==4||dt.tm_mon==6||dt.tm_mon==9||dt.tm_mon==11))
                 return 1;
         else if((dt.tm_mday>=1&&dt.tm_mday<=28)&&(dt.tm_mon==2))
            return 1;
         else if((dt.tm_mday>=1&&dt.tm_mday<=29)&&(dt.tm_mon==2)&&(dt.tm_year%400==0&&(dt.tm_year%4==0&&dt.tm_year%100!=0)))
                return 1;
        }
    }
    return 0;
}
void updateCarCount(int c_id)
{
    FILE*fp=fopen("car.bin","rb+");
    if(fp==NULL)
    {
        printf(" sorry file cannot be opened");
        getch();
        return ;
    }
    car c;
    while(fread(&c,sizeof(car),1,fp)==1)
    {
        if(c.car_id==c_id)
        {
            int x=c.car_count;
            x--;
            fseek(fp,-8,SEEK_CUR);
            fwrite(&x,sizeof(int),1,fp);
            break;
        }
    }
    fclose(fp);
}

void bookedCarDetials()
{
    clrscr();
    FILE*fp=fopen("customer.bin","rb");
    customer_car_details a;
    int i;
     textcolor(LIGHTCYAN);
    gotoxy(40,1);
    printf("CAR RENTAL SYSTEM");
    textcolor(WHITE);
    for(i=38;i<=58;i++)
    {
    gotoxy(i,2);
    printf("=");
    }
    textcolor(GREEN);
    for(i=1;i<=104;i++)
    {
      gotoxy(i,3);
      printf("%c",247);
      gotoxy(i,7);
      printf("%c",247);
      gotoxy(i,9);
      printf("%c",247);
    }
    textcolor(YELLOW);
    gotoxy(38,4);
    printf("* BOOKED CAR DETAILS *");
    textcolor(WHITE);
    gotoxy(80,6);
    printf("Press enter to go back..");
    textcolor(GREEN);
    gotoxy(1,8);
    printf("Model\t      Cust_Name\t     PickUp\t\t Drop\t\t\tS_Date\t\t E_Date");
    int row=10;
    textcolor(YELLOW);
    while(fread(&a,sizeof(customer_car_details),1,fp)==1)
    {

        gotoxy(1,row);
        printf("%s",getCarName(a.car_id));

        gotoxy(15,row);
        printf("%s",a.cust_name);

        gotoxy(30,row);
        printf("%s",a.pickup);

        gotoxy(50,row);
        printf("%s",a.drop);

        gotoxy(73,row);
        printf("%d/%d/%d",a.sd.tm_mday,a.sd.tm_mon,a.sd.tm_year);

        gotoxy(90,row);
        printf("%d/%d/%d",a.ed.tm_mday,a.ed.tm_mon,a.ed.tm_year);

        row++;
    }
    fclose(fp);
    getch();
}

char* getCarName(int c_id)
{
    FILE*fp=fopen("car.bin","rb");
    if(fp==NULL)
    {
        printf("Sorry! file not found");
        return NULL;
    }
    static car c;
    while(fread(&c,sizeof(c),1,fp)==1)
    {
        if(c_id==c.car_id)
          break;
    }
    fclose(fp);
    return c.car_name;
}

int rentCar()
{
    customer_car_details a;
    char pick[30],drop[30];
    int i,c;
    textcolor(LIGHTCYAN);
    gotoxy(40,1);
    printf("CAR RENTAL SYSTEM");
    textcolor(WHITE);
    for(i=38;i<=58;i++)
    {
    gotoxy(i,2);
    printf("=");
    }
    textcolor(GREEN);
    for(i=1;i<=104;i++)
    {
      gotoxy(i,4);
      printf("*");
       gotoxy(i,6);
        printf("*");
    }
        gotoxy(40,5);
    printf("EMPLOYE MENU");
        textcolor(YELLOW);
        gotoxy(40,7);
        c=selectCarModel();
        if(c==0||c==-2)
        {
            return c;
        }
        a.car_id=c;
        clrscr();
     textcolor(LIGHTCYAN);
    gotoxy(40,1);
    printf("CAR RENTAL SYSTEM");
    textcolor(WHITE);
    for(i=38;i<=58;i++)
    {
    gotoxy(i,2);
    printf("=");
    }
    textcolor(GREEN);
    for(i=1;i<=104;i++)
    {
        gotoxy(i,4);
         printf("*");
        gotoxy(i,6);
         printf("*");
        gotoxy(i,17);
           printf("*");
    }
        gotoxy(40,5);
    printf("EMPLOYE MENU");
        printf("*");
        textcolor(YELLOW);
        gotoxy(35,9);
        printf("Enter Customer Name:");
        fflush(stdin);
        textcolor(WHITE);
        fgets(a.cust_name,30,stdin);
        char*pos;
        pos=strchr(a.cust_name,'\n');
        *pos='\0';
        textcolor(YELLOW);
        gotoxy(35,10);
        printf("Enter pickup point:");
        fflush(stdin);
        textcolor(WHITE);
        fgets(a.pickup,30,stdin);
        pos=strchr(a.pickup,'\n');
        *pos='\0';
        gotoxy(35,11);
        textcolor(YELLOW);
        printf("Enter drop point:");
        fflush(stdin);
        textcolor(WHITE);
        fgets(a.drop,30,stdin);
        pos=strchr(a.drop,'\n');
        *pos='\0';
        gotoxy(35,12);
        textcolor(YELLOW);
        printf("Enter start date(dd/mm/yyyy):");
        do
        {
            textcolor(WHITE);
            scanf("%d/%d/%d",&a.sd.tm_mday,&a.sd.tm_mon,&a.sd.tm_year);
            int datevalid=isValidDate(a.sd);
            if(datevalid==1)
                break;
            gotoxy(40,19);
            textcolor(LIGHTRED);
            printf("Wrong date!!press enter..");
            getch();
            gotoxy(40,19);
            printf("\t\t\t\t\t\t");
            gotoxy(64,12);
            printf("\t\t\t\t\t\t\t");
            gotoxy(64,12);
        }while(1);
        gotoxy(35,13);
        textcolor(YELLOW);
        printf("Enter end date(dd/mm/yyyy):");
        do
        {
            textcolor(WHITE);
            scanf("%d/%d/%d",&a.ed.tm_mday,&a.ed.tm_mon,&a.ed.tm_year);
            int datevalid=isValidDate(a.ed);
            if(datevalid==1)
                break;
            gotoxy(40,19);
            textcolor(LIGHTRED);
            printf("Wrong date!!press enter..");
            getch();
            gotoxy(40,19);
            printf("\t\t\t\t\t\t");
            gotoxy(62,13);
            printf("\t\t\t\t\t\t\t");
            gotoxy(62,13);
        }while(1);
       // NOW validate the dates against current date as well as against each other

        if((a.sd.tm_year>a.ed.tm_year)||(a.sd.tm_mon>a.ed.tm_mon)||(a.sd.tm_mday>a.ed.tm_mday))
            {
                   gotoxy(35,19);
                   textcolor(LIGHTRED);
                   printf("Invalid Dates! check your start and end dates !! press enter..");
                   getch();
                   gotoxy(35,19);
                   printf("\t\t\t\t\t\t\t\t\t\t\t\t");
                   gotoxy(64,12);
                   printf("\t\t\t\t");
                   gotoxy(62,13);
                   printf("\t\t\t\t");
                   gotoxy(64,12);
                   do
           {
               textcolor(WHITE);
            scanf("%d %d %d",&a.sd.tm_mday,&a.sd.tm_mon,&a.sd.tm_year);
            int datevalid=isValidDate(a.sd);
            if(datevalid==1)
                break;
            gotoxy(40,19);
            textcolor(LIGHTRED);
            printf("Wrong date!! Press enter..");
            getch();
            gotoxy(40,19);
            printf("\t\t\t\t\t\t");
            gotoxy(62,12);
            printf("\t\t\t\t\t\t\t");
            gotoxy(62,12);
        }while(1);
        gotoxy(35,13);
        printf("\t\t\t\t\t\t\t\t");
        gotoxy(35,13);
        textcolor(YELLOW);
        printf("Enter end date(dd/mm/yyyy):");
        do
        {
            textcolor(WHITE);
            scanf("%d %d %d",&a.ed.tm_mday,&a.ed.tm_mon,&a.ed.tm_year);
            int datevalid=isValidDate(a.ed);
            if(datevalid==1)
                break;
            gotoxy(40,19);
            textcolor(LIGHTRED);
            printf("Wrong date!!press enter..");
            getch();
            gotoxy(40,19);
            printf("\t\t\t\t\t\t");
            gotoxy(62,13);
            printf("\t\t\t\t\t\t\t");
            gotoxy(62,13);
        }while(1);

           }

       FILE*fp=fopen("customer.bin","ab");
       if(fp==NULL)
       {
           gotoxy(40,19);
           printf("Sorry ! file cannot be opened");
           return -1;
       }
       fwrite(&a,sizeof(customer_car_details),1,fp);
       gotoxy(40,19);
       textcolor(WHITE);
       printf("Booking done for car %d",a.car_id);
       printf("\n Press any key to continue");
       getch();
       fclose(fp);
       updateCarCount(a.car_id);
       bookedCarDetials();
       return 1;
}

void avilCarDetails()
{
    FILE*fp=fopen("car.bin","rb");
    car c;
    int i;
    textcolor(LIGHTCYAN);
    gotoxy(40,1);
    printf("CAR RENTAL SYSTEM");
    textcolor(WHITE);
    for(i=38;i<=58;i++)
    {
    gotoxy(i,2);
    printf("=");
    }
    textcolor(GREEN);
    for(i=1;i<=104;i++)
    {
      gotoxy(i,3);
      printf("%c",247);
      gotoxy(i,7);
      printf("%c",247);
    }
        gotoxy(37,5);
        textcolor(LIGHTCYAN);
    printf("*- AVAILABLE CAR DETAILD  -*");
    textcolor(WHITE);
    gotoxy(80,6);
    printf("Press enter to go back..");
    textcolor(GREEN);
    if(fp==NULL)
    {
        gotoxy(40,8);
        textcolor(RED);
        printf("Sorry! file can not be opened");
        getch();
        return ;
    }
    gotoxy(1,8);
    printf("CAR ID\t      Model\t   \tCapacity\t\tAvailable\t \tPrice/Day");
    gotoxy(1,9);
    for(i=1;i<104;i++)
        printf("%c",247);
        int row=10;
        textcolor(YELLOW);
        while(fread(&c,sizeof(c),1,fp)==1)
        {
            if(c.car_count>0)
            {
                gotoxy(2,row);
                printf("%d",c.car_id);
                gotoxy(15,row);
                printf("%s",c.car_name);
                gotoxy(35,row);
                printf("%d",c.capacity);
                gotoxy(58,row);
                printf("%d",c.car_count);
                gotoxy(83,row);
                printf("%d",c.price);
                row++;
            }
        }
        fclose(fp);
        getch();
}
void returnCar()
{
   customer_car_details a;
   char name[30];
   int i;
   FILE*fp=fopen("customer.bin","rb");

    if(fp==NULL)
    {
        gotoxy(40,8);
        textcolor(RED);
        printf("Sorry file can not be opened");
        getch();
        return ;
    }
    gotoxy(35,9);
    textcolor(YELLOW);
    printf("Enter customer's name :");
    fflush(stdin);
    fgets(name,30,stdin);
   char*pos=strchr(name,'\n');
        *pos='\0';
        int c_id;
    while(fread(&a,sizeof(a),1,fp)==1)
        {
            if(strcmp(name,a.cust_name)==0)
            {
                gotoxy(35,10);
                printf("Booked Car id :%d",a.car_id);
                c_id=a.car_id;
                gotoxy(35,11);
                printf("Booked car piked up from :%s",a.pickup);
                gotoxy(35,12);
                printf("Booked car dropped at :%s",a.drop);
                gotoxy(35,13);
                printf("Car booked at :%d/%d/%d",a.sd.tm_mday,a.sd.tm_mon,a.sd.tm_year);
                gotoxy(35,14);
                printf("Car returned at :%d/%d/%d",a.ed.tm_mday,a.ed.tm_mon,a.ed.tm_year);
            }
        }
        fclose(fp);
        getch();
    fp=fopen("car.bin","rb+");
    if(fp==NULL)
    {
        printf(" Sorry!! file cannot be opened");
        getch();
        return ;
    }
    car c;

    while(fread(&c,sizeof(car),1,fp)==1)
    {
        if(c.car_id==c_id)
        {
            int x=c.car_count;
            x++;
            fseek(fp,-8,SEEK_CUR);
            fwrite(&x,sizeof(int),1,fp);
            break;
        }
    }
    fclose(fp);

}


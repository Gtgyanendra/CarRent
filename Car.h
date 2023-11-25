#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED
#include<time.h>
struct User
{
    char userid[20];
    char pwd[20];
    char name[20];
};
struct car
{
    int car_id;
    char car_name[20];
    int capacity;
    int car_count;
    int price;
};
struct customer_car_details
{
    int car_id;
    char cust_name[30];
    char pickup[30];
    char drop[30];
    struct tm sd;
    struct tm ed;
} ;
typedef struct User User;
typedef struct car car;
typedef struct customer_car_details customer_car_details;
void addAdmin();
User* getInput();
int checkUserExist(User,char[]);
int adminMenu();
void addEmployee();
void viewEmploye();
void addCarDetails();
void showCarDetails();
int deleteEmp();
int deleteCarModel();
int empMenu();
int selectCarModel();
int isValidDate(struct tm);
void updateCarCount(int);
void bookedCarDetials();
char* getCarName(int);
int rentCar();
void avilCarDetails();
void returnCar();

#endif // CAR_H_INCLUDED

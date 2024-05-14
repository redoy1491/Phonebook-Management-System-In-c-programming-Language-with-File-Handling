#include<stdio.h>
#include<string.h>                       // Library where strcmp(),strcpy() is stored
#include<stdlib.h>                      // Library where exit() is stored
#include<conio.h>                      // Library where getch() is stored

/** structure of PhoneBook data type */
struct person
{
    char firstname[30];
    char lastname[30];
    char countrycode[10];
    char phonenumber[20];
    char address[50];
    char mail[30];
} p;

/** structure of Call History data type */
struct call
{
    char callername[20];
    char receivername[20];
    char callerphonenumber[20];
    char receiverphonenumber[20];
} c;

/**Function prototype*/
void mainMenu();               /*This function is used to display the main menu*/
void addnewcontact();          /*This function is used to add a new contact*/
void viewallcontacts();        /*This function is used to view all contacts*/
void searchcontacts();         /*This function is used to search contacts*/
void updatecontact();          /*This function id used to update contact*/
void deletecontact();          /*This function id used to delete contact*/
void quickdial();              /*This function id used to quick dial*/
void showcallhistory();        /*This function id used to show call history contact*/
void showrecentcalllist();     /*This function id used to show recent call list*/

/** main function*/
int main()
{
    system("color 4f"); /*For output coloring */
    mainMenu();
    getch();
}

void mainMenu()    /*This function is used to display the main menu*/
{
    printf("\n\n\t\t\t========================================\n");
    printf("\t\t\t WELCOME TO PHONEBOOK MANAGEMENT SYSTEM\n");
    printf("\t\t\t========================================\n");
    printf("\n\t\t\tMenu");
    printf("\n\t\t\t----");
    printf("\n\t\t\t1. Add New Contact");
    printf("\n\t\t\t2. View All Contacts");
    printf("\n\t\t\t3. Search Contacts");
    printf("\n\t\t\t4. Update Contact");
    printf("\n\t\t\t5. Delete Contact");
    printf("\n\t\t\t6. Quick Dial");
    printf("\n\t\t\t7. Show Call History");
    printf("\n\t\t\t8. Show Recent Call List");
    printf("\n\t\t\t0. Exit");
    printf("\n\n\t\t\tPlease Enter Your Choice : ");

    switch(getch())
    {
    case '1':
        addnewcontact();
        break;
    case '2':
        viewallcontacts();
        break;
    case '3':
        searchcontacts();
        break;
    case '4':
        updatecontact();
        break;
    case '5':
        deletecontact();
        break;
    case '6':
        quickdial();
        break;
    case '7':
        showcallhistory();
        break;
    case '8':
        showrecentcalllist();
        break;
    case '0':
        printf("\n\n\t\t\t====Program End====\n");
        exit(0);      /*This function id used to exit the program*/
        break;
    default:
        system("cls");
        printf("\n\n\t\t\t~~~ERROR !! \n\n\t\t\tWRONG CHOICE\n\n\t\t\tPLEASE PRESS (1-8) AND 0 ONLY\n");
        printf("\n\t\t\tEnter Any Key For Main Menu: ");
        getch();
        system("cls");
        mainMenu();
    }
}
void addnewcontact()      //this function is used to add a new phone book record//
{
    system("cls");
    FILE *file;
    file=fopen("phonebook.txt","a+");
    printf("\n\t\t\t  NEW CONTACT");
    printf("\n\t\t\t===============\n");
    printf("\n\tEnter Your First Name: ");
    fflush(stdin);
    gets(p.firstname);
    printf("\tEnter Your Last Name: ");
    fflush(stdin);
    gets(p.lastname);
    printf("\tEnter Your Country Code: ");
    fflush(stdin);
    gets(p.countrycode);
    printf("\tEnter Your Phone Number: ");
    fflush(stdin);
    gets(p.phonenumber);
    printf("\tEnter Your E-mail: ");
    fflush(stdin);
    gets(p.mail);
    printf("\tEnter Your Address: ");
    fflush(stdin);
    gets(p.address);
    fprintf(file,"%s  %s  %s  %s  %s  %s\n",p.firstname,p.lastname,p.countrycode,p.phonenumber,p.mail,p.address);
    printf("\n\t\t New contact saved successfully!!");
    printf("\n\t\t---------------------------------\n");
    fclose(file);
    printf("\n\t\tEnter Any Key To Continue: ");
    getch();
    system("cls");
    mainMenu();
}
void viewallcontacts()              /*This function is used to view all contacts*/
{
    system("cls");
    int f=0;
    FILE *file;
    file=fopen("phonebook.txt","r");
    printf("\n\t\t\t\t\t VEW ALL CONTACTS");
    printf("\n\t\t\t\t\t==================\n\n\n");
    printf("\t%-13s%-13s%-17s%-20s%-23s%-10s\n","FIRST NAME","LAST NAME","COUNTRY CODE","PHONENUMBER","EMAIL","ADDRESS");
    printf("\t================================================================================================\n");
    while(fscanf(file,"%s %s %s %s %s %s\n",p.firstname,p.lastname,p.countrycode,p.phonenumber,p.mail,p.address)!=EOF)
    {
        f=1;
        printf("\t%-13s%-13s%-17s%-20s%-23s%-10s\n",p.firstname,p.lastname,p.countrycode,p.phonenumber,p.mail,p.address);
    }
    fclose(file);
    if(f==0)
    {
        printf("\n\tNo Record Contact!\n\n");
    }
    printf("\n\t\tEnter Any Key To Continue: ");
    getch();
    system("cls");
    mainMenu();
}
void searchcontacts()            /*This function is used to search contacts*/
{
    char searchname[30],searchphonenumber[30];
    int d=0;
    system("cls");
    FILE *file;
    file=fopen("phonebook.txt","r");
    printf("\n\n\t\t\t  SEARCH CONTACT");
    printf("\n\t\t\t ================\n\n");
    printf("\t\t1.Search By First Name\n");
    printf("\t\t2.Search By Phone Number\n");
    printf("\t\t3.If You Don't Search(Go To Main Menu)\n");
    printf("\n\t\tEnter Your Choice : ");
    switch(getch())
    {
    case '1':
        system("cls");
        printf("\n\n\t\t\t  SEARCH CONTACT");
        printf("\n\t\t\t ================\n\n");
        printf("\n\t\tEnter The First Name Of The Contact You Want To Update: ");
        fflush(stdin);
        gets(searchname);
        while(fscanf(file,"%s %s %s %s %s %s\n",p.firstname,p.lastname,p.countrycode,p.phonenumber,p.mail,p.address)!=EOF)
        {
            if(strcmp(searchname,p.firstname)==0)
            {
                d=1;
                printf("\n\t\tFound The Record On This Name~\n");
                printf("\t\t-------------------------------");
                printf("\n\t\tName: %s %s\n",p.firstname,p.lastname);
                printf("\t\tPhone Number: %s\n",p.phonenumber);
                printf("\t\tE-mail: %s\n",p.mail);
                printf("\t\tAddress: %s\n",p.address);
                break;
            }
        }
        fclose(file);
        if(d==0)
        {
            printf("\n\t\tCan't Found The Record On This Name!\n");
        }
        printf("\n\t\tEnter Any Key To Continue: ");
        getch();
        system("cls");
        mainMenu();
        break;
    case '2':
        system("cls");
        printf("\n\n\t\t\t  SEARCH CONTACT");
        printf("\n\t\t\t ================\n\n");
        printf("\n\t\tEnter The Phone Number Of The Contact You Want To Update:: ");
        fflush(stdin);
        gets(searchphonenumber);
        while(fscanf(file,"%s %s %s %s %s %s\n",p.firstname,p.lastname,p.countrycode,p.phonenumber,p.mail,p.address)!=EOF)
        {
            if(strcmp(searchphonenumber,p.phonenumber)==0)
            {
                d=1;
                printf("\n\t\tFound The Record On This Name~\n");
                printf("\t\t-------------------------------");
                printf("\n\t\tName: %s %s\n",p.firstname,p.lastname);
                printf("\t\tPhone Number: %s\n",p.phonenumber);
                printf("\t\tE-mail: %s\n",p.mail);
                printf("\t\tAddress: %s\n",p.address);
                break;
            }
        }
        fclose(file);
        if(d==0)
        {
            printf("\n\t\tCan't Found The Record On This Name!\n");
        }
        printf("\n\t\tEnter Any Key To Continue: ");
        getch();
        system("cls");
        mainMenu();
        break;
    case '3':
        system("cls");
        mainMenu();
        break;
    default :
        system("cls");
        printf("\n\n\t\t\t~~~ERROR !! \n\n\t\t\tWRONG CHOICE\n\n\t\t\tPLEASE PRESS (1-3) ONLY\n");
        printf("\n\t\t\tEnter Any Key For Search Contact: ");
        getch();
        system("cls");
        searchcontacts();
    }
}

void updatecontact()                            /*This function id used to update contact*/
{
    int f=0,ch;
    char searchname[30];
    FILE *file,*newrec;
    file = fopen("phonebook.txt","r");
    newrec = fopen("temp.txt","w");
    system("cls");
    printf("\n\t\t\t  UPDATE CONTACT");
    printf("\n\t\t\t ================\n\n");
    printf("\tEnter The First Name Of The Contact You Want To Update: ");
    fflush(stdin);
    gets(searchname);

    while(fscanf(file,"%s %s %s %s %s %s\n",p.firstname,p.lastname,p.countrycode,p.phonenumber,p.mail,p.address)!=EOF)
    {
        if(strcmp(searchname,p.firstname)==0)
        {
            f=1;
            do
            {
                system("cls");
                printf("\n\t\t\t  UPDATE CONTACT");
                printf("\n\t\t\t ================\n");
                printf("\n\t\t\tWhat You Want to Update?\n");
                printf("\n\t\t\t1.First Name");
                printf("\n\t\t\t2.Last Name");
                printf("\n\t\t\t3.Country Code");
                printf("\n\t\t\t4.Phone Number");
                printf("\n\t\t\t5.E-mail");
                printf("\n\t\t\t6.Address");
                printf("\n\t\t\t0.Back(Main Menu)");
                printf("\n\t\t\t========================");
                printf("\n\t\t\tEnter option : ");
                scanf("%d",&ch);
                switch(ch)
                {
                case 1:
                    printf("\n\t\t\tEnter New First Name: ");
                    fflush(stdin);
                    gets(p.firstname);
                    printf("\n\t\t\t=====SUCCESSFUL=====\n\n");
                    printf("\t\t\tEnter Any Key to Continue Update: ");
                    getch();
                    break;
                case 2:
                    printf("\n\t\t\tEnter New Last Name: ");
                    fflush(stdin);
                    gets(p.lastname);
                    printf("\n\t\t\t=====SUCCESSFUL=====\n\n");
                    printf("\t\t\tEnter Any Key to Continue Update: ");
                    getch();
                    break;
                case 3:
                    printf("\n\t\t\tEnter New Country Code: ");
                    fflush(stdin);
                    gets(p.countrycode);
                    printf("\n\t\t\t=====SUCCESSFUL=====\n\n");
                    printf("\t\t\tEnter Any Key to Continue Update: ");
                    getch();
                    break;
                case 4:
                    printf("\n\t\t\tEnter New Phone Number: ");
                    fflush(stdin);
                    gets(p.phonenumber);
                    printf("\n\t\t\t=====SUCCESSFUL=====\n\n");
                    printf("\t\t\tEnter Any Key to Continue Update: ");
                    getch();
                    break;
                case 5:
                    printf("\n\t\t\tEnter New E-mail: ");
                    fflush(stdin);
                    gets(p.mail);
                    printf("\n\t\t\t=====SUCCESSFUL=====\n\n");
                    printf("\t\t\tEnter Any Key to Continue Update: ");
                    getch();
                    break;
                case 6:
                    printf("\n\t\t\tEnter New Address: ");
                    fflush(stdin);
                    gets(p.address);
                    printf("\n\t\t\t=====SUCCESSFUL=====\n\n");
                    printf("\t\t\tEnter Any Key to Continue Update: ");
                    getch();
                    break;
                case 0:
                    fprintf(newrec,"%s %s %s %s %s %s\n",p.firstname,p.lastname,p.countrycode,p.phonenumber,p.mail,p.address);
                    break;
                }
            }
            while(ch != 0);
        }
        else
        {
            fprintf(newrec,"%s %s %s %s %s %s\n",p.firstname,p.lastname,p.countrycode,p.phonenumber,p.mail,p.address);
        }
    }
    fclose(file);
    fclose(newrec);
    remove("phonebook.txt");
    rename("temp.txt","phonebook.txt");
    if(f == 0)
    {
        printf("\n\tCannot found the name\n\n");
    }
    system("cls");
    mainMenu();
}


void deletecontact()                   /*This function id used to delete contact*/
{
    char searchname[30];
    int d=0;
    FILE *file,*newcontact;
    file=fopen("phonebook.txt","r");
    newcontact=fopen("temp.txt","w");
    system("cls");
    printf("\n\t\t\t  DELETE CONTACT");
    printf("\n\t\t\t ================\n\n");
    printf("\tEnter The First Name Of The Contact You Want To Delete: ");
    fflush(stdin);
    gets(searchname);
    while(fscanf(file,"%s %s %s %s %s %s\n",p.firstname,p.lastname,p.countrycode,p.phonenumber,p.mail,p.address)!= EOF)
    {
        if(strcmp(searchname,p.firstname)==0)
        {
            d=1;
        }
        else
        {
            fprintf(newcontact,"%s %s %s %s %s %s\n",p.firstname,p.lastname,p.countrycode,p.phonenumber,p.mail,p.address);
        }
    }
    fclose(file);
    fclose(newcontact);
    remove("phonebook.txt");
    rename("temp.txt","phonebook.txt");
    if(d==0)
    {
        printf("\n\t\tCannot found the name\n\n");
    }
    else
    {
        printf("\n\t\t=====DELETE SUCCESSFUL=====\n\n");
    }
    printf("\n\t\tEnter Any Key To Continue: ");
    getch();
    system("cls");
    mainMenu();
}

void quickdial()                /*This function id used to quick dial*/
{
    int d=0,f=0;
    char tempcallername[30],tempreceivername[30];
    system("cls");
    FILE *file,*file2;
    file=fopen("phonebook.txt","r");
    file2=fopen("phonebook_extra.txt","a+");
    printf("\n\t\t\t   QUICK DIAL");
    printf("\n\t\t\t ==============\n\n");
    printf("\t\t1.Call By First Name\n");
    printf("\t\t2.Call By Phone Number\n");
    printf("\t\t3.If You Don't Call(Go To Main Menu)\n");
    printf("\n\t\tEnter Your Choice : ");
    switch(getch())
    {
    case '1':
        system("cls");
        printf("\n\t\t\t   QUICK DIAL");
        printf("\n\t\t\t ==============\n\n");
        printf("\n\t\tEnter Caller First Name: ");
        fflush(stdin);
        gets(c.callername);
        while(fscanf(file,"%s %s %s %s %s %s\n",p.firstname,p.lastname,p.countrycode,p.phonenumber,p.mail,p.address)!=EOF)
        {
            if(strcmp(c.callername,p.firstname)==0)
                d=1;
        }
        if(d==0)
        {
            printf("\n\t\tCan't Found The Record On Caller First Name!\n");
        }
        fclose(file);
        if(d==1)
        {
            file=fopen("phonebook.txt","r");
            printf("\t\tEnter Receiver First Name: ");
            fflush(stdin);
            gets(c.receivername);
            while(fscanf(file,"%s %s %s %s %s %s\n",p.firstname,p.lastname,p.countrycode,p.phonenumber,p.mail,p.address)!=EOF)
            {
                if(strcmp(c.receivername,p.firstname)==0)
                    f=1;
            }
            if(f==0)
            {
                printf("\n\t\tCan't Found The Record On Receiver First Name!\n");
            }
            if(f==1 && d==1)
            {
                printf("\n\t\tCALLING........\n");
                printf("\n\t\t%s To %s\n",c.callername,c.receivername);
                printf("\n\t\tEnter Any Key To Stop call: ");
                getch();
                printf("\n\n\t\tCall Stopped!!\n");
            }
            fclose(file);
        }
        while(f>0)
        {
            fprintf(file2,"%s  %s \n",c.callername,c.receivername);
            break;
        }
        fclose(file2);
        break;
    case '2':
        system("cls");
        printf("\n\t\t\t   QUICK DIAL");
        printf("\n\t\t\t ==============\n\n");
        printf("\n\t\tEnter Caller Phone Number: ");
        fflush(stdin);
        gets(c.callerphonenumber);
        while(fscanf(file,"%s %s %s %s %s %s\n",p.firstname,p.lastname,p.countrycode,p.phonenumber,p.mail,p.address)!=EOF)
        {
            if(strcmp(c.callerphonenumber,p.phonenumber)==0)
            {
                d=1;
                strcpy(tempcallername,c.callerphonenumber);
                strcpy(c.callerphonenumber,p.firstname);
            }
        }
        if(d==0)
        {
            printf("\n\t\tCan't Found The Record On Caller Phone Number!\n");
        }
        fclose(file);
        if(d==1)
        {
            file=fopen("phonebook.txt","r");
            printf("\n\t\tEnter Receiver Phone Number: ");
            fflush(stdin);
            gets(c.receiverphonenumber);
            while(fscanf(file,"%s %s %s %s %s %s\n",p.firstname,p.lastname,p.countrycode,p.phonenumber,p.mail,p.address)!=EOF)
            {
                if(strcmp(c.receiverphonenumber,p.phonenumber)==0)
                {
                    f=1;
                    strcpy(tempreceivername,c.receiverphonenumber);
                    strcpy(c.receiverphonenumber,p.firstname);
                }
            }
            if(f==0)
            {
                printf("\n\t\tCan't Found The Record On Receiver Phone Number!\n");
            }
            if(f==1 && d==1)
            {
                printf("\n\t\tCALLING........\n");
                printf("\n\t\t%s(%s) To %s(%s)\n",c.callerphonenumber,tempcallername,c.receiverphonenumber,tempreceivername);
                printf("\n\t\tEnter Any Key To Stop call: ");
                getch();
                printf("\n\n\t\tCall Stopped!!\n");
            }
            fclose(file);
        }
        while(f>0)
        {
            fprintf(file2,"%s  %s \n",c.callerphonenumber,c.receiverphonenumber);
            break;
        }
        fclose(file2);
        break;
    case '3':
        system("cls");
        mainMenu();
        break;
    default :
        system("cls");
        printf("\n\n\t\t\t~~~ERROR !! \n\n\t\t\tWRONG CHOICE\n\n\t\t\tPLEASE PRESS (1-3) ONLY\n");
        printf("\n\t\t\tEnter Any Key For Search Contact: ");
        getch();
        system("cls");
        quickdial();
    }
    printf("\n\t\tEnter Any Key To Continue: ");
    getch();
    system("cls");
    mainMenu();
}

void showcallhistory()                    /*This function id used to show call history contact*/
{
    system("cls");
    int f=0;
    FILE *file2;
    file2=fopen("phonebook_extra.txt","r");
    printf("\n\t\t\t   SHOW CALL HISTORY");
    printf("\n\t\t\t =====================\n\n");
    printf("\t%-15s %-15s\n","CALLER NAME","RECEIVER NAME");
    printf("\t===================================\n");
    while(fscanf(file2,"%s %s\n",c.callername,c.receivername)!=EOF)
    {
        f=1;
        printf("\t%-15s %-15s\n",c.callername,c.receivername);
    }
    fclose(file2);
    if(f==0)
    {
        printf("\n\tNo Record Call History!\n\n");
    }
    printf("\n\t\tEnter Any Key To Continue: ");
    getch();
    system("cls");
    mainMenu();
}

void showrecentcalllist()                   /*This function id used to show recent call list*/
{
    system("cls");
    int f=0;
    FILE *file2;
    file2=fopen("phonebook_extra.txt","r");
    printf("\n\t\t\t   SHOW CALL HISTORY");
    printf("\n\t\t\t =====================\n\n");
    printf("\t%-15s %-15s\n","CALLER NAME","RECEIVER NAME");
    printf("\t===================================\n");
    while(fscanf(file2,"%s %s\n",c.callername,c.receivername)!=EOF)
    {
        f=1;
        printf("\t%-15s %-15s\n",c.callername,c.receivername);
    }
    fclose(file2);
    if(f==0)
    {
        printf("\n\tNo Record Call History!\n\n");
    }
    printf("\n\t\tEnter Any Key To Continue: ");
    getch();
    system("cls");
    mainMenu();
}


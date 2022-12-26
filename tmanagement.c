#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum state{menu,loggedin};
enum state currentstate=menu;

typedef struct User
{
    char username[100];
    char password[100];
    char place[100];
    float price;
    int numtick;
    struct User *next;
}User;
User* InitializeList(User*);
void ShowDomesticBrochure();
void ShowInternationalBrochure(); 
void User_Login(User*);
User* RegisterUser(User*);
void WriteToFile(User*);
void BookDTicket(User*);
void BookIntTicket(User*);
void PrintTicket(User*);
void CheckTicket(User*);
void CancelTicket(User*);
void ChangePassword(User*);
void User_Logout();
void TermsandConditions();
void DisplayAll(User*);
void Exit();

char currentuser[100];

int main()
{
    printf("\t\t\t==== || TOURISM MANAGEMENT SYSTEM || ====\n");
    User *u=NULL;
    int ch1,ch2;
    u=InitializeList(u);
    while (1)
    {

        if(currentstate==menu)
        {

            printf("\n\t\t\t\tREGISTER - 1\n\t\t\t\tUSER LOGIN - 2\n\t\t\t\tDOMESTIC TOUR BROCHURE - 3\n\t\t\t\tINTERNATIONAL TOUR BROCHURE - 4\n\n\t\t\t\tEXIT - 5\n\n\t\t\tENTER:");
            scanf("%d",&ch1);
            switch(ch1)
            {
                case 1:
                    RegisterUser(u);
                    break;
                case 2:
                    User_Login(u);
                    break;
                case 3:
                    ShowDomesticBrochure();
                    break;
                case 4:
                    ShowInternationalBrochure();
                    break;
                case 5:
                    Exit();
                    exit(0);
                    break;
                default:
                    printf("NOT A VALID INPUT\n");
            }
        }
        else if(currentstate==loggedin)
        {
        system("CLS");
        printf("\n\t\t\t\t=========================");
		printf("\n\t\t\t\tTOURISM MANAGEMENT SYSTEM");
		printf("\n\t\t\t\t=========================\n");
            printf("\n\t\t\t\tBOOK DOMESTIC TOUR - 1\n\t\t\t\tBOOK INTERNATIONAL TOUR - 2\n\t\t\t\tCHECK TICKET - 3\n\t\t\t\tPRINT TICKET - 4\n\t\t\t\tCANCEL TICKET - 5\n\t\t\t\tCHANGE PASSWORD - 6"
                   "\n\t\t\t\tLOGOUT USER - 7\n\t\t\t\tDOMESTIC TOURS - 8\n\t\t\t\tINTERNATIONAL TOURS - 9\n\t\t\t\tTnC - 10\n\t\t\t\tEXIT - 11");
            scanf("%d",&ch2);
            switch(ch2)
            {
                case 1:
                    BookDTicket(u);
                    system("PAUSE");
                    system("CLS");
                    break;
                case 2:
                    BookIntTicket(u);
                    system("PAUSE");
                    system("CLS");
                    break;
                case 3:
                    CheckTicket(u);
                    system("PAUSE");
                    system("CLS");
                    break;
                case 4:
                    PrintTicket(u);
                    system("PAUSE");
                    system("CLS");
                    break;
                case 5:
                    CancelTicket(u);
                    system("PAUSE");
                    system("CLS");
                    break;
                case 6:
                    ChangePassword(u);
                    system("PAUSE");
                    system("CLS");
                    break;
                case 7:
                    User_Logout(u);
                    system("PAUSE");
                    system("CLS");
                    break;
                case 8:
                    ShowDomesticBrochure();
                    system("PAUSE");
                    system("CLS");
                    break;
                case 9:
                    ShowInternationalBrochure();
                    system("PAUSE");
                    system("CLS");
                    break;
                case 10:
                    TermsandConditions();
                    system("PAUSE");
                    system("CLS");
                    break;
                case 11:
                    Exit();
                    exit(0);
                    break;
                default:
                    printf("Not a valid input at this stage\n");
            }
        }
     }
     return 0;
}
User* InitializeList(User *u)
{
    User* t,*ptr,temp;
    FILE *fp;
    int cc=0,x;
    float ff;
    fp=fopen("CUSTOMER.txt","r");

    if(fp==NULL)
        return NULL;

    if(fgetc(fp)==EOF)
        return NULL;

    rewind(fp);
	while(fscanf(fp,"%s %s %s %f %d",temp.username,temp.password,temp.place,&temp.price,&temp.numtick)!=EOF)
	{
		ptr=(User*)malloc(sizeof(User));
		strcpy(ptr->username,temp.username);
		strcpy(ptr->password,temp.password);
		strcpy(ptr->place,temp.place);
		ptr->price=temp.price;
		ptr->numtick=temp.numtick;
		ptr->next=NULL;

		if(u==NULL)
            u=t=ptr;
		else
		{
			u->next=ptr;
			u=ptr;
		}
	}
	fclose(fp);
    return t;
}

void ShowDomesticBrochure()
{
    printf("\n TOUR CODE\tDESTINATIONS\t\tDURATION\tCOST PER PAX");
    printf("\n NJK101   \tJAMMU&KASHMIR\t\t7N8D\t       RS26000");
    printf("\n NHP101   \tHIMACHAL     \t\t6N7D\t       RS20000");
    printf("\n NUA101   \tUTTARAKHAND  \t\t5N6D\t       RS20000");
    printf("\n NPB101   \tPUNJAB       \t\t4N5D\t       RS22500");
    printf("\n NRJ101   \tRAJASTHAN  \t\t11N10D\t       RS33000");
    printf("\n NUP101   \tUTTAR PRADESH\t\t7N8D\t       RS28000");
    printf("\n NDL101   \tDELHI        \t\t3N4D\t       RS15000");
    printf("\n EBR101   \tBIHAR        \t\t3N4D\t       RS16000");
    printf("\n EWB101   \tWEST BENGAL  \t\t5N6D\t       RS24000");
    printf("\n CMP101   \tMADHYAPRADESH\t\t7N8D\t       RS24000");
    printf("\n WGJ101   \tGUJARAT      \t\t7N8D\t       RS24000");
    printf("\n WMH101   \tMAHARASHTRA  \t\t8N9D\t       RS24000");
    printf("\n WGA101   \tGOA          \t\t4N5D\t       RS24000");
    printf("\n SKA101   \tKARNATAKA    \t\t7N8D\t       RS24000");
    printf("\n SKL101   \tKERALA       \t\t5N6D\t       RS24000");
    printf("\n STN101   \tTAMILNADU    \t\t7N8D\t       RS24000");
    printf("\n SAP101   \tAP-TELANGANA \t\t5N6D\t       RS24000");
}
void ShowInternationalBrochure()
{
    printf("\n TOUR CODE\tDESTINATIONS              DURATION     PRICE");
    printf("\n NA101    \tUS,CANADA,MEXICO            19N20D     RS360000");
    printf("\n NA202    \tHAITI,CUBA,PANAMA            9N10D     RS300000");
    printf("\n NC101    \tJAMAICA,WESTINDIES           9N10D     RS200000");
    printf("\n SA101    \tBRAZIL,ARGENTINA              4N5D     RS225000");
    printf("\n UK101   \tUNITED KINGDOM              11N10D     RS330000");
    printf("\n EU101   \tFRANCE,SPAIN,PORTUGAL         7N8D     RS380000");
    printf("\n EU102   \tGERMANY,BELGIUM,HOLLAND       7N8D     RS350000");
    printf("\n EU103   \tNORWAY,FINLAND,SWEDEN         7N8D     RS460000");
    printf("\n EU104   \tITALY,GREECE,CROATIA          8N9D     RS440000");
    printf("\n EU105   \tHUNGARY,CZECHIA,POLAND        7N8D     RS340000");
    printf("\n AS101   \tS.KOREA,JAPAN,HONG KONG       7N8D     RS240000");
    printf("\n AS102   \tCHINA                         8N9D     RS240000");
    printf("\n AS103   \tRUSSIA                        4N5D     RS340000");
    printf("\n AS104   \tTHAILAND,MALAYSIA,SINGAPORE   7N8D     RS440000");
    printf("\n AS105   \tINDONESIA,PHILLIPINES         5N6D     RS270000");
    printf("\n AS106   \tNEPAL,BHUTAN,SRILANKA         5N6D     RS240000");
    printf("\n AS107   \tUAE,QATAR,KUWAIT,BAHRAIN      5N6D     RS340000");
    printf("\n AS108   \tTURKEY,JORDAN,LEBANON,IRAN    7N8D     RS260000");
    printf("\n AS109   \tISRAEL                        4N5D     RS200000");
    printf("\n AU101   \tAUSTRALIA,NEWZEALAND          8N9D     RS500000");
    printf("\n AF101   \tEGYPT,MOROCCO                 6N7D     RS325000");
    printf("\n AF102   \tSOUTH AFRICA,KENYA            6N7D     RS200000");

}
User* RegisterUser(User* u)
{
    User *t;
    t=u;
    User *nw;
    nw=(User*)malloc(sizeof(User));
    fflush(stdin);
    printf("ENTER USERNAME: \n");
    scanf("%s",nw->username);
    while(u!=NULL)
    {
        if(!strcmp(u->username,nw->username))
        {
            printf("USER EXISTS\n");
            return t;
        }
        u=u->next;
    }
    u=t;
    fflush(stdin);
    printf("ENTER PASSWORD\n");
    scanf(" %[^\n]",&nw->password);
    nw->next=NULL;
    strcpy(nw->place,"N/A");
    nw->price=0.0;
    nw->numtick=0;

    if(u==NULL)
    {
        u=t=nw;
    }
    else
    {
        while(u->next!=NULL)
        {
            u=u->next;
        }
        u->next=nw;
    }
    WriteToFile(t);
    return t;
}
void WriteToFile(User *u)
{
    FILE *fp;
    fp=fopen("CUSTOMER.txt","w");
    while(u!=NULL)
    {
        fprintf(fp,"%s %s %s %f %d\n",u->username,u->password,u->place,u->price,u->numtick);
        u=u->next;
    }
    fclose(fp);
}

void User_Login(User* u)
{
    char username[100];
    char password[100];
    fflush(stdin);
    printf("\n\n");
    printf("\t\tENTER USERNAME;\n\t\t");
    scanf("%s",username);
    fflush(stdin);
    printf("\n\t\tENTER PASSWORD:\n\t\t");
    scanf(" %[^\n]s",password);
    while(u!=NULL)
    {
        if((!strcmp(u->username,username)) && (!strcmp(u->password,password)))
        {
            currentstate=loggedin;
            strcpy(currentuser,username);

            printf("\n\t\tLogin successful!\n");
            system("PAUSE");
            return;
        }
        else if((!strcmp(u->username,username)) && (strcmp(u->password,password)))
        {
            printf("Password mismatch\n");
            return;
        }
        u=u->next;
    }
    printf("Sorry, no such user record was found\n");
}

void BookDTicket(User *u)
{
    User *t=u;
    char place[100];
    while(u!=NULL)
    {
        if(!strcmp(u->username,currentuser))
            break;
            u=u->next;
    }
    if(u==NULL)
        return;
    if(u->price!=0.0)
    {
        printf("YOU HAVE A TOUR BOOKED.PLEASE CANCEL THE CURRENT BOOKING TO BOOK A NEW TOUR.\n");
        return;
    }
    ShowDomesticBrochure();
    float pricelist[]={26000.0,20000.0,20000.0,22500.0,33000.0,28000.0,15000.0,16000.0,24000.0,24000.0,24000.0,24000.0,24000.0,24000.0,24000.0,24000.0,24000.0};
    fflush(stdin);
    printf("\nENTER TOUR CODE (eg: NJK101, NHP101)\n");
    scanf(" %[^\n]s",place);
    char choice;
    fflush(stdin);
    printf("\nCONFIRM BOOKING ?\n[1] - YES\n[2] - NO\n");
    scanf("%c",&choice);
    float price;
    if(choice!='1')
        return;
    if(strcmp(place,"NJK101")==0)
        price=pricelist[0];
    else if(strcmp(place,"NHP101")==0)
        price=pricelist[1];
    else if(strcmp(place,"NUA101")==0)
        price=pricelist[2];
    else if(strcmp(place,"NPB101")==0)
        price=pricelist[3];
    else if(strcmp(place,"NRJ101")==0)
        price=pricelist[4];
    else if(strcmp(place,"NUP101")==0)
        price=pricelist[5];
    else if(strcmp(place,"NDL101")==0)
        price=pricelist[6];
    else if(strcmp(place,"EBR101")==0)
        price=pricelist[7];
    else if(strcmp(place,"EWB101")==0)
        price=pricelist[8];
    else if(strcmp(place,"CMP101")==0)
        price=pricelist[9];
    else if(strcmp(place,"WGJ101")==0)
        price=pricelist[10];
    else if(strcmp(place,"WMH101")==0)
        price=pricelist[11];
    else if(strcmp(place,"WGA101")==0)
        price=pricelist[12];
    else if(strcmp(place,"SKA101")==0)
        price=pricelist[13];
    else if(strcmp(place,"SKL101")==0)
        price=pricelist[14];
    else if(strcmp(place,"STN101")==0)
        price=pricelist[15];
    else if(strcmp(place,"SAP101")==0)
        price=pricelist[16];
    else
    {
        printf("THAT TOUR CODE DOESNT EXIST\n");
        return;
    }
    printf("ENTER NUMBER OF TICKETS:\n");
    scanf("%d",&u->numtick);
    if(u->numtick==0)
        return;
    strcpy(u->place,place);
    u->price=price;
    WriteToFile(t);
    printf("Bookings Done!!\n");
    system("PAUSE");

}
void BookIntTicket(User *u)
{
    User *t=u;
    char place[100];
    while(u!=NULL)
    {
        if(!strcmp(u->username,currentuser))
            break;
        u=u->next;
    }
    if(u==NULL)
        return;
    if(u->price!=0.0)
    {
        printf("YOU HAVE A TOUR BOOKED.PLEASE CANCEL THE CURRENT BOOKING TO BOOK A NEW TOUR.\n");
        return;
    }
    ShowInternationalBrochure();
    float pricelist[]={360000.0,300000.0,200000.0,225000.0,330000.0,380000.0,350000.0,460000.0,440000.0,340000.0,240000.0,240000.0,340000.0,440000.0,27000.0,240000.0,340000.0,260000.0,200000.0,500000.0,325000.0,200000.0};
    fflush(stdin);
    printf("\nENTER TOUR CODE (eg: NA101,SA101, )\n");
    scanf(" %[^\n]s",place);
    char choice;
    fflush(stdin);
    printf("\nCONFIRM BOOKING ?\n[1] - YES\n[2] - NO\n");
    scanf("%c",&choice);
    float price;
    if(choice!='1')
        return;
    if(strcmp(place,"NA101")==0)
        price=pricelist[0];
    else if(strcmp(place,"NA202")==0)
        price=pricelist[1];
    else if(strcmp(place,"NC101")==0)
        price=pricelist[2];
    else if(strcmp(place,"SA101")==0)
        price=pricelist[3];
    else if(strcmp(place,"UK101")==0)
        price=pricelist[4];
    else if(strcmp(place,"EU101")==0)
        price=pricelist[5];
    else if(strcmp(place,"EU102")==0)
        price=pricelist[6];
    else if(strcmp(place,"EU103")==0)
        price=pricelist[7];
    else if(strcmp(place,"EU104")==0)
        price=pricelist[8];
    else if(strcmp(place,"EU105")==0)
        price=pricelist[9];
     else if(strcmp(place,"AS101")==0)
        price=pricelist[10];
    else if(strcmp(place,"AS102")==0)
        price=pricelist[11];
    else if(strcmp(place,"AS103")==0)
        price=pricelist[12];
    else if(strcmp(place,"AS104")==0)
        price=pricelist[13];
    else if(strcmp(place,"AS105")==0)
        price=pricelist[14];
    else if(strcmp(place,"AS106")==0)
        price=pricelist[15];
    else if(strcmp(place,"AS107")==0)
        price=pricelist[16];
    else if(strcmp(place,"AS108")==0)
        price=pricelist[17];
    else if(strcmp(place,"AS109")==0)
        price=pricelist[18];
    else if(strcmp(place,"AU101")==0)
        price=pricelist[19];
    else if(strcmp(place,"AF101")==0)
        price=pricelist[20];
    else if(strcmp(place,"AF102")==0)
        price=pricelist[21];
    else
    {
        printf("THAT TOUR CODE DOESN'T EXIST\n");
        return;
    }
    printf("ENTER NUMBER OF TICKETS:\n");
    scanf("%d",&u->numtick);
    if(u->numtick==0)
        return;
    strcpy(u->place,place);
    u->price=price;
    WriteToFile(t);
    printf("Bookings Done!!\n");
    system("PAUSE");

}
void CheckTicket(User *u)
{
    while(u!=NULL)
    {
        if(!strcmp(u->username,currentuser))
            break;
        u=u->next;
    }
    if(!strcmp(u->place,"\0") || u->price==0.0 || u->numtick==0)
    {
        printf("You do not have a ticket booked yet\n");
        return;
    }
    float total=0.0;
    total=(u->price)*(u->numtick);
    printf("You have booked %d tickets for a sum total of Rs %f for tour code %s\n",u->numtick,total,u->place);
}
void PrintTicket(User *u)
{
    while(u!=NULL)
    {
        if(!strcmp(u->username,currentuser))
            break;
        u=u->next;
    }
    if(!strcmp(u->place,"\0") || u->price==0.0 || u->numtick==0)
    {
        printf("You do not have a ticket booked yet\n");
        return;
    }
    float total=0.0;
    total=(u->price)*(u->numtick);
    FILE *fp;
    char filename[50];
    strcpy(filename,u->username);
    strcat(filename,"ticket.txt");
    fp=fopen(filename,"w");
    if(fp==NULL)
    {
        printf("Problem opening the file\n");
        return;
    }
    if(fgetc(fp)==EOF)
    {
        fprintf(fp,"TOURISM TICKET\n===============\n\n");
    }
    fprintf(fp,"Email ID: %s\nTour Code: %s\nTicket Cost: Rs %f\nNumber of tickets: %d\nTotal Cost: Rs %f\n",u->username,u->place,u->price,u->numtick,total);
    fclose(fp);
}
void ChangePassword(User *u)
{
    User *t=u;
    char passcurr[100];
    fflush(stdin);
    printf("Enter your current password to continue:\n");
    scanf(" %[^\n]s",passcurr);
    while(u!=NULL)
    {
        if(!strcmp(u->username,currentuser))
            break;
        u=u->next;
    }
    if(u==NULL)
        return;
    if(!strcmp(passcurr,u->password))
    {
        printf("Enter new password:\n");
        scanf(" %[^\n]s",u->password);
    }
    WriteToFile(t);
}
void CancelTicket(User *u)
{
    User *t=u;
    while(u!=NULL)
    {
        if(!strcmp(u->username,currentuser))
            break;
        u=u->next;
    }

    int flag=-1;

    if(u==NULL)
        printf("No such user\n");

    if(strcmp(u->place,"NJK101")==0)
        flag++;
    else if(strcmp(u->place,"NHP101")==0)
        flag++;
    else if(strcmp(u->place,"NUA101")==0)
        flag++;
    else if(strcmp(u->place,"NPB101")==0)
        flag++;
    else if(strcmp(u->place,"NRJ101")==0)
        flag++;
    else if(strcmp(u->place,"NUP101")==0)
        flag++;
    else if(strcmp(u->place,"NDL101")==0)
        flag++;
    else if(strcmp(u->place,"EBR101")==0)
        flag++;
    else if(strcmp(u->place,"EWB101")==0)
        flag++;
    else if(strcmp(u->place,"CMP101")==0)
        flag++;
    else if(strcmp(u->place,"WGJ101")==0)
        flag++;
    else if(strcmp(u->place,"WMH101")==0)
        flag++;
    else if(strcmp(u->place,"WGA101")==0)
        flag++;
    else if(strcmp(u->place,"SKA101")==0)
        flag++;
    else if(strcmp(u->place,"SKL101")==0)
        flag++;
    else if(strcmp(u->place,"STN101")==0)
        flag++;
    else if(strcmp(u->place,"SAP101")==0)
        flag++;
    else if(strcmp(u->place,"NA101")==0)
        flag++;
    else if(strcmp(u->place,"NA202")==0)
        flag++;
    else if(strcmp(u->place,"NC101")==0)
        flag++;
    else if(strcmp(u->place,"SA101")==0)
        flag++;
    else if(strcmp(u->place,"UK101")==0)
        flag++;
    else if(strcmp(u->place,"EU101")==0)
        flag++;
    else if(strcmp(u->place,"EU102")==0)
        flag++;
    else if(strcmp(u->place,"EU103")==0)
        flag++;
    else if(strcmp(u->place,"EU104")==0)
        flag++;
    else if(strcmp(u->place,"EU105")==0)
        flag++;
    else if(strcmp(u->place,"AS101")==0)
        flag++;
     else if(strcmp(u->place,"AS102")==0)
        flag++;
    else if(strcmp(u->place,"AS103")==0)
        flag++;
    else if(strcmp(u->place,"AS104")==0)
        flag++;
    else if(strcmp(u->place,"AS105")==0)
        flag++;
    else if(strcmp(u->place,"AS106")==0)
        flag++;
    else if(strcmp(u->place,"AS107")==0)
        flag++;
    else if(strcmp(u->place,"AS108")==0)
        flag++;
    else if(strcmp(u->place,"AS109")==0)
        flag++;
    else if(strcmp(u->place,"AU101")==0)
        flag++;
    else if(strcmp(u->place,"AF101")==0)
        flag++;
    else if(strcmp(u->place,"AF102")==0)
        flag++;
    else
    {
        printf("You haven't booked a tour yet\n");
        return;
    }
    if(flag==0)
    {
        printf("Your ticket has been successfully cancelled\nA refund of Rs %f for Tour Code %s for %d tickets will soon be made to your original source of purchase\n",u->price,u->place,u->numtick);
        strcpy(u->place,"N/A");
        u->price=0.0;
        u->numtick=0;
        WriteToFile(t);
    }
}
void User_Logout()
{
    if(currentstate==menu || strcmp(currentuser,"\0")==0)
    {
        printf("YOU MUST BE LOGGED IN TO LOG OUT.\n");
        return;
    }
    strcpy(currentuser,"\0");
    currentstate=menu;
    printf("YOU HAVE BEEN SUCCESSFULLY LOGGED OUT\n");
}
void TermsandConditions()
{
    printf("\t\t\t\t******************Terms and Conditions****************\n");
    printf("\n-->Current Terms & Conditions:\nYou are at least 18 years of age and have the legal authority to create a binding legal obligation\nBy booking a Tour you acknowledge that you have read, understand and agree to be bound by these Terms.\n");
    printf("\n-->POLICY REGARDING CANCELLATION / NO SHOW / EARLY DEPARTURE\nIn the event of cancellation of travel arrangements due to any reasons–we must be notified of the same in writing.\nCancellation charges will be effective from the time/date we receive your intimation in writing.\nCancellation fees as below apply to the land packages and/or services.\n");
    printf("\n-->REFUNDS\nNo refund or reduction will be made to any member in respect of airfare, accommodation, meals, sightseeing tours,transport or any other services which are included in the tour fare out not utilized by the tour member due to personal reasons.\n");
    printf("\n-->PASSPORT, VISA & IMMIGRATION REQUIREMENTS\nIt is your responsibility to obtain information and to have in your possession all the required documentation and identification required for entry,departure and travel to each country or region.\n");
    printf("\n-->LOCAL LAWS AND REGULATIONS\nAll participants in tours operated by us are expected to obey the laws and regulations of the countries visited and any failure to do so may relieve us of all obligations that we may otherwise have to you.\n\n");
    printf("\n**********************************************HAVE A SAFE JOURNEY****************************************************");
}
void Exit()
{
    printf("EXITING...\n\nPress \"Enter Or Return\" to exit");
    char exitprog;
    fflush(stdin);
    scanf("%c",&exitprog);
}




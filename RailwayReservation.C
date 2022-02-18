#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

/*******************************************GLOBAL VARIABLES**********************************************************/
//ALl the globle variables and the composite data types will be declared here
// Global variables

char source[20], des[20], train[40];
char station[40], cla[40];
int time1, time2, a[55];
int j;

struct pd
{
	char val[20],name[20],gen[6],gender[6];
	int ag,age,d,m,year;
	double Ph_no,Phno,UID;
	int train_num;
	int num_of_seats,RID;
}passdetails,pd1;

struct billpay
{
	int bill_amt;
	int RID1;	
}bp;
 
/*******************************************FUNCTION PROTOTYPE**********************************************************/
									//function prototypes to be used	
									
void details(void); 										//main reservation function
void details1(int);										//main reservation function				
int seat(int);
int cal(int, int, int);
void bill(); 
void viewdetails(void);												//view details of all the trains
void specifictrain(void);											//print data related to specific train	
void login();
void cancel(void);	
void search(void);
int getUniqueID();  
					

/******************************************FUNCTION DECLARATION**********************************************************/

/*********************************************MAIN()*************************************************/
int main()

{
	system("cls"); 
	printf("\t\t=================================================\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|           TRAIN TICKET RESV. SYSTEM           |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|              BROUGHT TO YOU BY                |\n");
	printf("\t\t|           |  	  SOUL CYNICS     |             |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t=================================================\n\n\n");
		
	    
	printf(" \n Press any key to continue:");
	getch();	
    system("cls");
	login();
	int menu_choice,choice_return;
	start:
	system("cls");
	printf("\n=================================\n");
	printf("    TRAIN RESERVATION SYSTEM");
	printf("\n=================================");
	printf("\n1>> Reservation Menu");
	printf("\n------------------------");
	printf("\n2>> Print The Bill/Receipt OF The Reservation");
	printf("\n------------------------");
	printf("\n3>> View Specific Train");
	printf("\n------------------------");
	printf("\n4>> View All Available Trains");
	printf("\n------------------------");
	printf("\n5>> Cancel Reservation");
	printf("\n------------------------");
	printf("\n6>> Search For Passenger Detail");
	printf("\n------------------------");
	printf("\n7>> Exit");
	printf("\n------------------------");
	printf("\n\n-->");
	scanf("%d",&menu_choice);
	switch(menu_choice)
	{
		case 1:
			details();		
			break;
		case 2:
			 bill();
			 break;
		case 3:
			specifictrain();
			printf("\n\nPress any key to go to Main Menu..");
			getch();
			break;
		case 4:
			viewdetails();
			printf("\n\nPress any key to go to Main Menu..");
			getch();
			break;
		case 5:
			cancel();
			printf("\n\nPress any key to go to Main Menu..");
			getch();
			break;
		case 6:
			search();
			printf("\n\nPress any key to go to Main Menu..");
			getch();
			break;
		case 7:
			return(0);
		default:
			printf("\nInvalid choice");
	}
	goto start;
	return(0);
}

/*********************************************RESERVATION()*************************************************/

/*********************************************Adding Details Of The Passengers()*************************************************/


void details()
{
	FILE *fp,*fq;
	fp=fopen("Railway_Reservation.txt","a+");
	if(fp==NULL)
	{
	   puts("File cannot be opened ");
	   exit(0);
	}
	fq=fopen("Railway_Reservation1.txt","a+");
    if (fq==NULL)
    {
	   puts("File cannot be opened ");
	   exit(0);
	}
	int i,ag,m,year,d;
	double Phno,UID;
	int train_num;
    int a1, a2, b, c,RID; 
	int x = 0,  e, r;
    char o, gen[6], confirm,another;
    char val[20], gender[6];
	system("cls");
	printf("Enter Number Of Passengers: ");
	fflush(stdin);
    scanf("%d", &j);
	another='y';
	while(another=='y'|| another=='Y')
	{
        printf("\nEnter the Name of Passenger: ");
        fflush(stdin);
        gets(passdetails.val);
        printf("\nEnter the Gender of Passenger(Male/Female): ");
        fflush(stdin);
        gets(passdetails.gender);
        printf("\nEnter the Age of Passenger: ");
        fflush(stdin);
        scanf("%d",&passdetails.ag);
        printf("\nEnter the Phone number of Passenger: ");
        fflush(stdin);
        scanf("%lf",&passdetails.Phno);
        printf("\nEnter the date of reservation(dd/mm/yy): ");
        fflush(stdin);
    	scanf("%d/%d/%d",&passdetails.d,&passdetails.m,&passdetails.year);
        printf("\nPlease enter Unique ID(Citizenship Number/ Passport Number) of Passenger: ");
        fflush(stdin);
        scanf("%lf", &passdetails.UID);
        printf("\nReceipt Id: ");
        fflush(stdin);
        scanf("%d",&passdetails.RID);
        fwrite(&passdetails,sizeof(passdetails),1,fp);
        printf("\nAdd another Record(y/n)-: ");
	 	another=getche();
	}
	bp.RID1 = passdetails.RID;
	printf("\n\n>>Press Enter To View Available Trains<< ");
	getch();
	system("cls");
	viewdetails();
	label:
	printf("\n\nEnter train number:> ");
	scanf("%d",&train_num);
	do {
        switch(train_num) 
		{
        case 1001:
		 {
            
            a1 = 2099;
            a2 = 1560;
            // Calling cal() function
            // with the three argument
            // and return value
            d = cal(a1, a2, j);
            printf("Total Bill Amount: Rs %d \n",d); 
        }break;
        case 1002:
		 {
            
            a1 = 2099;
            a2 = 1560;
  
            // Calling cal() function with
            // three argument & return value
            d = cal(a1, a2, j);
            printf("Total Bill Amount: Rs %d \n",d);
        } break;
        case 1003:
		 {
            
            a1 = 1801;
            a2 = 981;
  
            // Calling cal() function with
            // three argument & return value
            d = cal(a1, a2, j);
            printf("Total Bill Amount: Rs %d\n", d);
        } break;
        case 1004:
		 {
        
           	a1 = 1801;
            a2 = 981;
  
            // Calling cal() function with
            // three argument & return value
            d = cal(a1, a2, j);
            printf("Total Bill Amount: Rs %d\n", d);
        } break;
        case 1005:
		 {
        
            a1 = 2199;
            a2 = 1780;
  
            // Calling cal() function with
            // three argument & return value
            d = cal(a1, a2, j);
            printf("Total Bill Amount: Rs %d\n", d);
        } break;
        case 1006:
		 {
    
            a1 = 2199;
            a2 = 1780;
  	
            // Calling cal() function with
            // three argument & return value
            d = cal(a1, a2, j);
            printf("Total Bill Amount: Rs %d\n", d);
        } break;
        case 1007: 
		{
            a1 = 1759;
            a2 = 1200;
  
            // Calling cal() function with
            // three argument & return value
            d = cal(a1, a2, j);
            printf("Total Bill Amount: Rs %d\n", d); 
        } break;
        case 1008:
		 {
            a1 = 1759;
            a2 = 1200;
  
            // Calling cal() function with
            // three argument & return value
            d = cal(a1, a2, j);
            printf("Total Bill Amount: Rs %d\n", d); 
        } break;
        case 1009: 
		{
            a1 = 2205;
            a2 = 1905;
  
            // Calling cal() function with
            // three argument & return value
            d = cal(a1, a2, j);
            printf("Total Bill Amount: Rs %d\n", d);
        } break;
        case 1010:
		 {
           	a1 = 2205;
            a2 = 1905;
  
            // Calling cal() function with
            // three argument & return value
            d = cal(a1, a2, j);
            printf("Total Bill Amount: Rs %d\n", d);
        } break;
        default:
            printf("Please Enter The Correct Choice.....\n");
        	goto label;
        }
    } while (x);
    bp.bill_amt=d;
	//fseek(fq,0, SEEK_END);
    fwrite(&bp,sizeof(bp),1,fq);
    printf("\n *****For Booking Seats*****\n");
    // Calling seat() function with number of passenger
    seat(j);
    printf("\n\nConfirm Reservation (y/n):>");
	start:
	scanf(" %c",&confirm);
	if(confirm == 'y')
	{
		printf("==================");
		printf("\n Reservation Done\n");
		printf("==================");
		printf("\nPress any key to go back to Main menu");
	}
	else
	{
		if(confirm=='n'){
			printf("\nReservation Not Done!\nPress any key to go back to  Main menu!");
		}
		else
		{
			printf("\nInvalid choice entered! Enter again-----> ");
			goto start;
		}
	}
	fclose(fp);
	fclose(fq);
	getch();
}


/*********************************************PRINTTICKET()*************************************************/
										// Code for printing receipt
void bill()
{
    char confirm;
    long int recsize,recsize1;
    time_t currentTime;
    time(&currentTime);
    int i,c,reID,x;
    FILE *fp,*fq;
	fp=fopen("Railway_Reservation.txt","r+");
	if(fp==NULL)
	{
	   puts("File cannot be opened ");
	   exit(0);
	}
	fq=fopen("Railway_Reservation1.txt","r+");
    if (fq==NULL)
    {
	   puts("File cannot be opened ");
	   exit(0);
	}
	system("cls");
	
	recsize=sizeof(passdetails);
	
	recsize1=sizeof(bp);
	//fseek(fp,0, SEEK_END);
	//fseek(fq,0, SEEK_END);
	top5:
		
	printf("\n\nEnter the receipt ID of passenger: ");
	fflush(stdin);
	scanf("%d",&reID);
	
	rewind(fp);
	rewind(fq);
    printf("\n\n*********************** YOUR RECEIPT ****************************");
    
	while(fread(&passdetails,recsize,1,fp)>0)
	{
		if(reID == passdetails.RID)
		{
			x=1;
    		printf("\t\t\n\nPassenger Name: ");
    		puts(passdetails.val);
    		printf("\t\t\nPassenger Gender: ");
    		puts(passdetails.gender);
    		printf("\t\t\nPassenger Age: %d",passdetails.ag);
        
    		printf("\t\t\n\nPassenger Phone Number %.1lf",passdetails.Phno);
        
    		printf("\t\t\n\nPassenger Date Of Reservation %d/%d/%d",passdetails.d,passdetails.m,passdetails.year);
        
    		printf("\t\t\n\nPassenger's Unique ID(UID) is %.1lf",passdetails.UID);
 		}
	}
	while(fread(&bp,recsize1,1,fq)>0)
	{
		if(reID == bp.RID1)
		{
    		printf("\t\t\n\nReceipt Id -: %d",bp.RID1);
        
    		printf("\t\t\n\nTotal Bill amount -: Rs %d",bp.bill_amt);
		}	
	}
	if(x!=1)
	{
		printf("\nSorry there is no record of the entered Receipt ID.\n\nPlease enter a Valid Receipt ID");
		goto top5;
	}
    printf("\t\t\n\nTime : %s",ctime(&currentTime));
    printf("\n");
    
    printf("\n\nConfirm Ticket (y/n):>");
	start:
	scanf(" %c",&confirm);
	if(confirm == 'y')
	{
		printf("==================");
		printf("\n Reservation Done\n");
		printf("==================");
		printf("\nPress any key to go back to Main menu");
	}
	else
	{
		if(confirm=='n'){
			printf("\nReservation Not Done!\nPress any key to go back to  Main menu!");
		}
		else
		{
			printf("\nInvalid choice entered! Enter again-----> ");
			goto start;
		}
	}
	getch();
	fclose(fp);
	fclose(fq);
}
	
int cal(int y1, int y2, int h)
{
    int b, c, i, t, r, n;
    printf("\n\n********** The seat class available in this Railway Express is :- *********\n");
    printf("\n\t 1) Slepper Class....\n");
    printf("\n\t 2) A.C Class.......\n");
    printf("\t\nEnter your choice of class for your travel: ");
    scanf("%d", &i);
    switch (i) {
    case 1: {
        strcpy(cla,"Slepper Class");
        b = y2 * h;
        c = b + (b * 0.18);
    } break;
    case 2: {
    	printf("\n\n********** The sub classes of seat for A.C Class available are :- *********\n");
        printf("\t\t 1) 3A Class....\n");
        printf("\t\t 2) 2A Class....\n");
        printf("\t\t 3) 1st Class A.C.....\n");
        printf("\t\nEnter Your Choice of subclass: ");
        scanf("%d", &n);
        switch (n) {
        case 1: {
            strcpy(cla,"3A Class");
            b = y1 * h;
            c = b + (b * 0.18);
        } break;
        case 2: {
            strcpy(cla,"2A Class");
            b = (y1 + 1000) * h;
            c = b + (b * 0.18);
        } break;
        case 3: {
            strcpy(cla,"1st Class A.C.");
            b = (y1 + 5000) * h;
            c = b + (b * 0.18);
        } break;
        default: {
            printf("\t\tEnter Right Choice......\n");
        }
        }
    } break;
    default: {
        printf("\t\tEnter Right Choice......\n");
    }
    }
    return c;
}

/*********************************************SPECIFICTRAIN()*************************************************/

void specifictrain()
{
	system("cls");
	int train_num;
	printf("Enter specific train number(1001-1010): ");
	scanf("%d",&train_num);
	if (train_num==1001)
	{
		printf("\nTrain:\t\t\tRed Lines Express");
		printf("\nDestination:\t\tBoston to Manhattan");
		printf("\nDeparture time:\t\t09:00 am ");
		printf("\nArrival time:\t\t11:50 am");
	}
	if (train_num==1002)
	{
		printf("\nTrain:\t\t\tRed Lines Express");
		printf("\nDestination:\t\tManhattan to Boston");
		printf("\nDeparture time:\t\t12:00 pm ");
		printf("\nArrival time:\t\t02:50 pm");
	}
	if (train_num==1003)
	{
		printf("\nTrain:\t\t\tLA City Express");
		printf("\nDestination:\t\tBoston to L.A");
		printf("\nDeparture time:\t\t08:00 am ");
		printf("\nArrival time:\t\t01:00 pm");
	}
	if (train_num==1004)
	{
		printf("\nTrain:\t\t\tLA City Express");
		printf("\nDestination:\t\tL.A to Boston");
		printf("\nDeparture time:\t\t01:10 pm ");
		printf("\nArrival time:\t\t06:10 pm");
	}
	if (train_num==1005)
	{
		printf("\nTrain:\t\t\tIron City Express");
		printf("\nDestination:\t\tBoston to Chicago");
		printf("\nDeparture time:\t\t07:00 am ");
		printf("\nArrival time:\t\t11:00 am");
	}
	if (train_num==1006)
	{
		printf("\ntrain:\t\t\tIron City Express");
		printf("\nDestination:\t\tChicago to Boston");
		printf("\nDeparture time:\t\t11:05 am ");
		printf("\nArrival time:\t\t03:05 pm");
	}
	if (train_num==1007)
	{
		printf("\ntrain:\t\t\tKeystone Express");
		printf("\nDestination:\t\tBoston to Washington");
		printf("\nDeparture time:\t\t01:00 pm ");
		printf("\nArrival time:\t\t05:00 pm");
	}
	if (train_num==1008)
	{
		printf("\ntrain:\t\t\tKeystone Express");
		printf("\n Destination:\t\tWashington to Boston");
		printf("\nDeparture time:\t\t05:15 pm ");
		printf("\nArrival time:\t\t09:15 pm");
	}
	if (train_num==1009)
	{
		printf("\ntrain:\t\t\tMeteor Express");
		printf("\nDestination:\t\tBoston to Miami");
		printf("\nDeparture time:\t\t03:15 pm ");
		printf("\nArrival time:\t\t06:15 pm");
	}
	if (train_num==1010)
	{
		printf("\ntrain:\t\t\tMeteor Express");
		printf("\nDestination:\t\tMiami to Boston");
		printf("\nDeparture time:\t\t06:20 am ");
		printf("\nArrival time:\t\t09:20 am");
	}
}

/*********************************************VIEWDETAILS()*************************************************/

void viewdetails(void)
{
	system("cls");
	printf("----------------------------------------------------------------------------------------------------------------");	
	printf("\nTr.No\tName\t\t\tDestinations\t\tDeparture Time\t\tArrival Time\n");
	printf("----------------------------------------------------------------------------------------------------------------");
	printf("\n1001\tRed Lines Express\tBoston to Manhattan\t\t09:00\t\t11:50");
	printf("\n1002\tRed Lines Express\tManhattan To Boston\t\t12:00\t\t14:50");
	printf("\n1003\tLA City Express\t\tBoston To L.A\t\t\t08:00\t\t13:00");
	printf("\n1004\tLA City Express\t\tL.A To Boston\t\t\t13:10\t\t18:10");
	printf("\n1005\tIron City Express\tBoston To Chicago\t\t07:00\t\t11:00");
	printf("\n1006\tIron City Express\tChicago To Boston\t\t11:05\t\t15:05");
    printf("\n1007\tKeystone Express\tBoston To Washington\t\t13:00\t\t17:00");	
    printf("\n1008\tKeystone Express\tWashington To Boston\t\t17:15\t\t21:15");
    printf("\n1009\tMeteor Express\t\tBoston To Miami\t\t\t15:15\t\t\18:15");
    printf("\n1010\tMeteor Express\t\tMiami To Boston\t\t\t18:20\t\t21:20");
    
}

/*********************************************SEATDETAILS()*************************************************/

// Function for chosing seats
int seat(int p)
{
    int i,a[50],k[50];
    printf("\t           -:SEAT MATRIX:-        \n");
    printf("\t(U)    (M)        (L)    (L)    "
           "    (U)\n\n");
    printf("\t01    02        03\t04        "
           "05\n\n");
    printf("\t06    07        08\t09        "
           "10\n");
    printf("\t11    12        13\t14        "
           "15\n\n");
    printf("\t16    17        18\t19        "
           "20\n");
    printf("\t21    22        23\t24        "
           "25\n\n");
    printf("\t26    27        28\t29        "
           "30\n");
    printf("\t31    32        33\t34        "
           "35\n\n");
    printf("\t36    37        38\t39        "
           "40\n");
    printf("\t41    42        43\t44        "
           "45\n\n");
    printf("\t46    47        48\t49        "
           "50\n");
    printf("\t51    52        53\t54        "
           "55\n\n");
    printf("\t56    57        58\t59        "
           "60\n");
    top2:
    printf("\n\n\tEnter Seat Numbers: ");
    for (i = 0; i < p; i++)
    {
        scanf("%d", &a[i]);
        if(k[i]==a[i])
        {
        	printf("Sorry, The seat is already taken");
        	goto top2;
		}
        k[i]=a[i];
    }
}
/*********************************************Function for Cancel Menu()*************************************************/
void cancel(void)
{
	int recpID,status;
	float cancelp;
	long int recsize1;
	FILE *fq;
	fq=fopen("Railway_Reservation1.txt","r+");
    if (fq==NULL)
    {
       fq=fopen("Railway_Reservation1.txt","w+");

       if (fq==NULL)
	{
	   puts("File cannot be opened ");
	   exit(0);
	}
	}
	recsize1= sizeof(bp);
	system("cls");
	top:
	printf("\n\nEnter the receipt id to cancel the ticket: "); 
	fflush(stdin);
	scanf("%d",&recpID); 

	rewind(fq);
	
	printf("\n\n---------Cancel a Ticket----------\n"); 
	
   	while(fread(&bp,recsize1,1,fq)>0)
   	{
   		if(recpID == bp.RID1)
   		{
   			status=0;
   			printf("\n\nYour Total Bill Amount is :- Rs %d",bp.bill_amt);
   			cancelp= bp.bill_amt - bp.bill_amt * 0.15 ;
   			printf("\n\nThe amount you get after cancellation charge is -: Rs %.2f",cancelp);
   		}
	}
	if (status != 0)
   		{
   			printf("\n\nPlease enter a valid receipt ID");
   			goto top;
		}
	if(status == 0) 
	{
		printf("\n\nYour reservation is cancelled successfully.");
	}
	getch();
	fclose(fq);
}

/*********************************************Function for Search Menu()*************************************************/

void search()
{
	system("cls");
	int i,j,recID,x;
	long int resize,resize1;
	FILE *fp,*fq;
	fp=fopen("Railway_Reservation.txt","r+");
    if (fp==NULL)
    {
	   puts("File cannot be opened ");
	   exit(0);
	}
	fq=fopen("Railway_Reservation1.txt","r+");
    if (fq==NULL)
    {
	   puts("File cannot be opened ");
	   exit(0);
	}
	
	resize=sizeof(passdetails);
	
	resize1=sizeof(bp);
	
	flag5:
		
	printf("\n\nEnter the receipt ID of the passenger: ");
	fflush(stdin);
	scanf("%d",&recID);
	
	rewind(fp);
	rewind(fq);
	printf("*********************** YOUR SEARCH DETAILS ****************************");
	
	while(fread(&passdetails,resize,1,fp)>0)
	{
		if(recID == passdetails.RID)
		{
			x=1;
    		printf("\t\t\n\nPassenger Name: ");
    		puts(passdetails.val);
    		printf("\t\t\nPassenger Gender: ");
    		puts(passdetails.gender);
    		printf("\t\t\nPassenger Age: %d",passdetails.ag);
        
    		printf("\t\t\n\nPassenger Phone Number %.1lf",passdetails.Phno);
        
    		printf("\t\t\n\nPassenger Date Of Reservation %d/%d/%d",passdetails.d,passdetails.m,passdetails.year);
        
    		printf("\t\t\n\nPassenger's Unique ID(UID) is %.1lf",passdetails.UID);
 		}
	}
	if(x!=1)
	{
		printf("\nSorry there is no record of the entered Receipt ID.\n\nPlease enter a Valid Receipt ID");
		goto flag5;
	}
	while(fread(&bp,resize1,1,fq)>0)
	{
		if(recID == bp.RID1)
		{
    		printf("\t\t\n\nReceipt Id -: %d",bp.RID1);
        
    		printf("\t\t\n\nTotal Bill amount -: Rs %d",bp.bill_amt);
		}	
	}
	getch();
	fclose(fp);
	fclose(fq);
	
}
/*********************************************Function for Login Menu()*************************************************/
void login()
{
	int a=0,i=0;
    char uname[10],c=' '; 
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do
{
	
    printf("\n  =======================  LOGIN FORM  =======================\n  ");
    printf(" \n                       ENTER USERNAME:-");
	scanf("%s", &uname); 
	printf(" \n                       ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	//char code=pword;
	i=0;
	//scanf("%s",&pword); 
		if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0)
	{
	printf("  \n\n\n       WELCOME TO OUR SYSTEM !! YOUR LOGIN IS SUCCESSFUL");
	printf("\n\n\n\t\t\tPress any key to continue...");
	getch();//holds the screen
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;
		getch();//holds the screen
		system("cls");
	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");
		getch();
		
	}
		system("cls");	
}
//

              


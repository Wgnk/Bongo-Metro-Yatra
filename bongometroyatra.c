/*A project using C language to perform operation of an app that allows user to signin, signup, close app, access app  the app. Sidewise it also allows user to check availability of metro with time as per user
enters station with desire route and fare calculation based on criteria with ticket booking feature. It also calculates estimated travel time calculation, multiple ticket options (single journey, daily pass, monthly pass), and real-time crowd information, card Recharge, Live train tracking.*/
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>
typedef struct {
    char name[50];
    char lineColor[10];
    char platform[5];
    char timings[100];
    int travelTime;
} Station;
void generateTicketID(char *ticketID) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    srand(time(NULL));
    ticketID[0] = charset[rand() % 26];
    ticketID[1] = charset[rand() % 26];
    ticketID[2] = charset[rand() % 26];
    for (int i = 3; i < 12; i++) {
        ticketID[i] = '0' + rand() % 10;
    }
    ticketID[12] = '\0';
}
int calculateFare(int numStations, int numPassengers, int isStudent, int isSenior) {
    int baseFare = 10 + (numStations * 5);
    if (isStudent || isSenior) {
        return (baseFare * numPassengers) * 0.8;
    }
    return baseFare * numPassengers;
}
int main()
{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    Sleep(1000);
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tBONGO METRO YATRA\n");
    Sleep(1000);
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tPowered by\n");
    Sleep(1000);
    printf("\t\t\t\t\t\t\t\t\t\t\t\tAgnish Samajpati\n");
    Sleep(1000);
    system("cls");
    mains();
    return 0;
}
void mains()
{
    int ch;
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tBONGO METRO YATRA\n");
    printf("\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tQuicker Solution to ride in Metro!\n");
    printf("\n");
    time_t t;
    struct tm *tm_info;
    char buffer[50];
    time(&t);
    tm_info = localtime(&t);
    strftime(buffer, sizeof(buffer), "%a,%d %b %Y,%H:%M", tm_info);
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t%s\n\n", buffer);
    printf("_______________________________________________________________________________________________________________________________________________________________________\n\n");
    printf("\t\t\t\t\tEnter '1' for Signin\tEnter '2' for Sign Up\tEnter '3' for Exit\tEnter '4' for Access\n\n");
    printf("_______________________________________________________________________________________________________________________________________________________________________\n");
    char message[] = "[NOTE:- If already having an account then sign in/login else do sign up..If already signed in or signed up then access app...]";
    int i, spaces;
    for (spaces = 0; spaces < 40; spaces++)
        {
        for (i = 0; i < spaces; i++)
        {
            printf(" ");
        }
        printf("%s\r", message);
        fflush(stdout);
        #ifdef _WIN32
            Sleep(100);
        #else
            usleep(10);
        #endif
    }
    printf("\n\n");
    printf("\nEnter user choice :");
    scanf("%d",&ch);
    printf("\n");
    switch(ch)
    {
    case 1:
        signin();
        break;
    case 2:
        signup();
        break;
    case 3:
        close1();
        break;
    case 4:
        access1();
        break;
    default:
        printf("Oops!! Something went wrong");
    }
}
void signin()
{
    long phno,passkey,passkey1;
    int n;
    char acc[100],pass[100];
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ________\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t| Signin |\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ________\n\n");
    printf("\nEnter Mobile Number :+91\t");
    scanf("%ld",&phno);
    printf("\nEnter Account Name :");
    scanf("%s",&acc);
    printf("Enter '1' if know password\t\tEnter '2' if forgot password\n");
    printf("\nEnter user choice :");
    scanf("%d",&n);
    if(n==1)
    {
        printf("\nEnter Password:");
        scanf("%s",pass);
        printf("\nEnter Passkey :");
        scanf("%ld",&passkey);
        if(passkey==936781)
        {
            printf("\n\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tWelcome %s\n",acc);
             printf("Redirecting to new page");
            Sleep(1000);
            system("cls");
            access1();
        }
        else
        {
            printf("\nRe-Enter Passkey :");
            scanf("%ld",&passkey1);
            if(passkey1==936781)
            {
            printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tWelcome %s\n",acc);
             printf("Redirecting to new page");
    Sleep(1000);
    system("cls");
            access1();
            }
            else
            {
                printf("Session expired signup!!\n");
                printf("Redirecting to new page\n");
                Sleep(1000);
                system("cls");
                mains();
            }
        }
    }
    else
    {
         printf("Redirecting to new page");
    Sleep(1000);
    system("cls");
        reset();
    }
}
void signup()
{
    long phno2,passw,passwe;
    char first[100],emailid[100],pass1[100];
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ________\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t| Sign Up |\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ________\n\n");
    printf("\nEnter Full Name :");
    scanf("%s",&first);
    printf("\nEnter Mobile Number :+91\t");
    scanf("%ld",&phno2);
    printf("\nEnter Email ID :");
    scanf("%s",&emailid);
    printf("\nEnter Email Password :");
    scanf("%s",&pass1);
    printf("\n");
    srand(time(0));
    int random_number = rand() % 900000 + 100000;
    printf("Password: %d\n", random_number);
    printf("\nEnter the password :");
    scanf("%ld",&passw);
    if(passw==random_number)
    {
    printf("Your passkey for accessing app : 936781\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tWelcome %s\n",first);
    printf("Redirecting to new page");
    Sleep(1000);
    system("cls");
    access1();
    }
    else
        {
            srand(time(0));
    int random_number = rand() % 900000 + 100000;
    printf("Password: %d\n", random_number);
        printf("\nRe-enter Password :");
        scanf("%ld",&passwe);
    if(passwe==random_number)
    {
        printf("Your passkey for accessing app : 936781\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tWelcome %s\n",first);
     printf("Redirecting to new page");
    Sleep(1000);
    system("cls");
    access1();
    }
    else
    {
        printf("Session expired signup again!!");
    }
    }
}
void close1()
{
    int a;
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ____________\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t| Close App ! |\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ____________\n\n");
    printf("Are you sure?\n");
    printf("Enter '1' for YES\t\tEnter '2' for NO\n");
    printf("\nEnter user choice :");
    scanf("%d",&a);
    if(a==1)
    {
        exit(0);
        Sleep(1000);
        system("cls");
    }
    else
    {
        printf("Redirecting to new page");
        Sleep(1000);
        system("cls");
        mains();
    }
}
void reset()
{
    long phno1,ne,nei;
    char email[100];
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tBONGO METRO YATRA\n");
    printf("\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tQuicker Solution to ride in Metro!\n");
    printf("\n");
    time_t t;
    struct tm *tm_info;
    char buffer[50];
    time(&t);
    tm_info = localtime(&t);
    strftime(buffer, sizeof(buffer), "%a,%d %b %Y,%H:%M", tm_info);
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t%s\n", buffer);
    printf("_______________________________________________________________________________________________________________________________________________________________________\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t________________\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t| Reset Password |\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t________________\n\n");
    printf("Enter your mobile number and email id. We will send you temporary password for one time login.\n");
    printf("\nEnter Mobile Number :+91\t");
    scanf("%ld",&phno1);
    printf("\nEnter Email ID :");
    scanf("%s",&email);
    printf("\n\n");
    srand(time(0));
    int random_number = rand() % 900000 + 100000;
    printf("Password: %d\n", random_number);
    printf("\nEnter the password received :");
    scanf("%ld",&ne);
    if(ne==random_number)
    {
    printf("Passkey : 936781\n\n");
    printf("Reset Successful\n");
    printf("Exit and to go signin and enter this passkey for further application. In future this will be your passkey\n");
    printf("Redirecting to new page\n");
    Sleep(10000);
    system("cls");
    signin();
    }
    else
    {
        srand(time(0));
    int random_number = rand() % 900000 + 100000;
    printf("Password: %d\n", random_number);
        printf("\nRe-enter password correctly :");
        scanf("%ld",&nei);
    if(nei==random_number)
    {
    printf("Passkey : 936781\n\n");
    printf("Reset Successful\n");
    printf("Exit and to go signin and enter this passkey for further application. In future this will be your passkey\n");
    printf("Redirecting to new page\n");
    Sleep(10000);
    system("cls");
    signin();
    }
    else
    {
        printf("Session expired do again!!\n");
    }
  }
}
void home()
{
    Sleep(1000);
    system("cls");
    int ch1;
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tBONGO METRO YATRA\n");
    printf("\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tQuick Solution to travel in Metro!\n");
    printf("\n");
    time_t t;
    struct tm *tm_info;
    char buffer[50];
    time(&t);
    tm_info = localtime(&t);
    strftime(buffer, sizeof(buffer), "%a,%d %b %Y,%H:%M", tm_info);
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t%s\n\n", buffer);
    printf("_______________________________________________________________________________________________________________________________________________________________________\n\n");
    printf("Enter '1' UP ticket\t\tEnter '2' DOWN ticket\t\tEnter '3' Close\t\tEnter '4' for card recharge\t\tEnter '5' for Live train tracking\n\n");
    printf("_______________________________________________________________________________________________________________________________________________________________________\n\n");
     char message[] = "[NOTE:-As of now KMRCL only offers UP and DOWN tickets separately...]";
    int i, spaces;
    for (spaces = 0; spaces < 40; spaces++)
        {
        for (i = 0; i < spaces; i++)
        {
            printf(" ");
        }
        printf("%s\r", message);
        fflush(stdout);
        #ifdef _WIN32
            Sleep(100);
        #else
            usleep(10);
        #endif
    }
    printf("\n\n");
    printf("\nEnter user choice :");
    scanf("%d",&ch1);
    switch(ch1)
    {
    case 1:
        up();
        break;
    case 2:
        down();
        break;
    case 3:
        close2();
        break;
    case 4:
        rechargeCard();
        break;
    case 5:
        {
                char source[50], destination[50];
                int travelTime;
                printf("Enter Source Station: ");
                scanf("%s", source);
                printf("Enter Destination Station: ");
                scanf("%s", destination);
                printf("Enter Estimated Travel Time (mins): ");
                scanf("%d", &travelTime);
                trackTrain(source, destination, travelTime);
                break;
            }
    default:
        printf("Oops!! Something went wrong");
    }
}
int metroBalance = 0;
void rechargeCard() {
    int recharge;
    printf("Your Current Balance: Rs. %d\n", metroBalance);
    printf("Enter Balance To Recharge: ");
    scanf("%d", &recharge);

    if (recharge > 0) {
        metroBalance += recharge;
        printf("Recharge Successful! Your Balance: Rs. %d\n", metroBalance);
    } else {
        printf("Invalid Amount! Please enter a valid recharge amount.\n");
    }
}
void trackTrain(char *source, char *destination, int travelTime) {
    printf("\nTracking Train from %s to %s...\n", source, destination);
    for (int i = 0; i <= travelTime; i += 2) {
        printf("Train at %d%% of journey\n", (i * 100) / travelTime);
        sleep(2);
    }
    printf("Train has arrived at %s!\n", destination);
}
void access1()
{
    long pass1;
    int g;
    char name12[100];
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ____________\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t| Access App |\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ____________\n");
    printf("\nEnter Passkey :");
    scanf("%ld",&pass1);
    if(pass1==936781)
    {
        printf("\nEnter user name :");
        scanf("%s",name12);
       printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tWelcome %s\n",name12);
        printf("Redirecting to new page");
    Sleep(1000);
    system("cls");
       home();
    }
    else
    {
        printf("Oops!! Wrong passkey\n");
        printf("Enter '1' for user login\t\tEnter '2' for Re-enter\n");
        printf("\nEnter user choice :");
        scanf("%d",&g);
        if(g==1)
        {
            printf("Redirecting to new page\n");
            Sleep(1000);
            system("cls");
            mains();
        }
        else
        {
            printf("\nRe-enter passkey :");
            scanf("%ld",&pass1);
            if(pass1 ==936781)
            {
                printf("\nEnter user name :");
               scanf("%s",name12);
            printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tWelcome %s\n",name12);
             printf("Redirecting to new page");
    Sleep(1000);
    system("cls");
            home();
            }
            else
            {
                printf("Session expired signup first!!\n");
                printf("Redirecting to new page\n");
                Sleep(1000);
                system("cls");
                mains();
            }
        }
    }
}
void up()
{
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t____________\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t| UP Tickets |\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t____________\n\n");
    Station stations[] = {
        // Blue Line (6 Stations)
    {"Kavi_Subhash_B","Blue", "PF1A", "06:25, 07:25, 08:25, 09:25", 7},
    {"Rabindra_Sadan","Blue", "PF1", "06:20, 07:20, 08:20, 09:20", 6},
    {"Park_Street", "Blue", "PF1", "06:15, 07:15, 08:15, 09:15", 8},
    {"Esplanade_B", "Blue", "PF1A", "06:10, 07:10, 08:10, 09:10", 7},
    {"Dumdum", "Blue", "PF1", "06:05, 07:05, 08:05, 09:05", 6},
    {"Dakshineswar", "Blue", "PF1", "06:00, 07:00, 08:00, 09:00", 5},
        // Green Line (6 Stations)
    {"Howrah_Maidan", "Green", "PF1", "06:30, 07:30, 08:30, 09:30", 5},
    {"Mahakaran", "Green", "PF1", "06:35, 07:35, 08:35, 09:35", 6},
    {"Esplanade_G", "Green", "PF1B", "06:40, 07:40, 08:40, 09:40", 7},
    {"Sealdah", "Green", "PF1", "06:45, 07:45, 08:45, 09:45", 8},
    {"Phoolbagan", "Green", "PF1", "06:50, 07:50, 08:50, 09:50", 6},
    {"Salt_Lake_Sector_V", "Green", "PF1", "06:55, 07:55, 08:55, 09:55", 7},
        // Orange Line (5 Stations)
        {"Kavi_Subhash_O", "Orange", "PF1B", "07:00, 08:00, 09:00, 10:00", 6},
    {"Satyajit_Roy", "Orange", "PF1", "07:10, 08:10, 09:10, 10:10", 7},
    {"Joytirindra_Nandi", "Orange", "PF1", "07:15, 08:15, 09:15, 10:15", 8},
    {"Kavi_Sukanta", "Orange", "PF1", "07:20, 08:20, 09:20, 10:20", 6},
    {"Hemanta_Mukhopadhyay", "Orange", "PF1", "07:25, 08:25, 09:25, 10:25", 7},
        // Purple Line (6 Stations)
        {"Esplanade_P", "Purple", "PF1B", "07:55, 08:55, 09:55, 10:55", 7},
    {"Majerhat", "Purple", "PF1", "07:50, 08:50, 09:50, 10:50", 6},
    {"Behala_Bazar", "Purple", "PF1", "07:45, 08:45, 09:45, 10:45", 8},
    {"Behala_Chowrasta", "Purple", "PF1", "07:40, 08:40, 09:40, 10:40", 7},
    {"Thakurpukur", "Purple", "PF1", "07:35, 08:35, 09:35, 10:35", 6},
    {"Joka", "Purple", "PF1", "07:30, 08:30, 09:30, 10:30", 5}
    };
    int numStations = sizeof(stations) / sizeof(stations[0]);
    char source[50], destination[50];
    int numPassengers,stationsTraveled = 0;
    int travelTime = 0;
    int userHour, userMinute;
    int crowdLevel;
    int isStudent = 0, isSenior = 0;
    char lineColor[20];
    char platform[5];
    printf("\nEnter source station: ");
    scanf("%s", source);
    printf("\nEnter destination station: ");
    scanf("%s", destination);
    printf("\nEnter travel time (HH:MM format 24-hr): ");
    scanf("%d %d", &userHour, &userMinute);
    printf("\nEnter number of passengers: ");
    scanf("%d", &numPassengers);
    printf("\nAre you a student? (1=Yes, 0=No): ");
    printf("\nEnter user choice :");
    scanf("%d", &isStudent);
    printf("\nAre you a senior citizen? (1=Yes, 0=No): ");
    printf("\nEnter user choice :");
    scanf("%d", &isSenior);
    const char *sourceColor = NULL;
    const char *destinationColor = NULL;
    int foundSource = 0, foundDest = 0,sourceIndex=-1,destIndex=-1;
    for (int i = 0; i < numStations; i++) {
        if (strcmp(stations[i].name, source) == 0) {
            foundSource = 1;
            sourceIndex = i;
             sourceColor = stations[i].lineColor;
            strcpy(platform, stations[i].platform);
        }
        if (strcmp(stations[i].name, destination) == 0) {
            foundDest = 1;
            destIndex = i;
            destinationColor = stations[i].lineColor;
            strcpy(platform, stations[i].platform);
        }
    }
    if (!foundSource || !foundDest) {
        printf("Invalid station entered!\n");
        return 1;
    }
     if (sourceIndex > destIndex) {
        printf("\nError: Only UP direction allowed! Choose a valid UP route.\n");
        return;
    }
 for (int i = sourceIndex; i < destIndex; i++) {
        stationsTraveled++;
        travelTime += stations[i].travelTime;
    }
    srand(time(NULL));
    crowdLevel = rand() % 3;
    char *crowdText[] = {"Low", "Medium", "High"};
    printf("\n");
    printf("\n===== Available Trains ================================================================================================\n\n");
    printf("%02d:%02d | %s to %s | Travel Time: %d mins | Crowd : %s | Line : %s -> %s | Platform :%s\n\n",
           userHour, userMinute, source, destination, travelTime, crowdText[crowdLevel],sourceColor,destinationColor,platform);
    printf("========================================================================================================================\n\n");
    int choice;
    printf("\nDo you want to book a ticket? (1='YES'/2='NO'): ");
    printf("\nEnter user choice :");
    scanf("%d", &choice);
    if (choice == 1) {
        char ticketID[13];
        generateTicketID(ticketID);
        int fare = calculateFare(stationsTraveled, numPassengers, isStudent, isSenior);
        int baseFare = 20 * numPassengers;
        int dailyPass = 150;
        int monthlyPass = 1200;
        int selectedFare;
        int passChoice;
        printf("\nChoose ticket type:\n1. Single Journey (Rs. %d)\n2. Daily Pass (Rs. %d)\n3. Monthly Pass (Rs. %d)\n",
               baseFare, dailyPass, monthlyPass);
               printf("\nEnter user choice :");
        scanf("%d", &passChoice);
        switch (passChoice) {
            case 1: selectedFare = baseFare; break;
            case 2: selectedFare = dailyPass; break;
            case 3: selectedFare = monthlyPass; break;
            default: selectedFare = baseFare;
        }
        printf("\n\n");
        printf("\n===== Ticket Details ========================\n\n");
        printf("Ticket ID: %s\n", ticketID);
        printf("Source: %s\n", source);
        printf("Destination: %s\n", destination);
        printf("Number of Passengers: %d\n", numPassengers);
        printf("Total Fare: Rs. %d\n", selectedFare);
        printf("Time Taken :%d mins\n",travelTime);
        printf("Route/Line Color : %s -> %s\n", sourceColor, destinationColor);
        printf("Platform :%s\n\n",platform);
        printf("================================================");
    } else {
        printf("Thank you! Have a great journey.\n");
        exit(0);
    }
}
void down()
{
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t _____________\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t| DOWN Tickets |\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t _____________\n\n");
    Station stations[] = {
        // Blue Line (6 Stations)
        {"Dakshineswar", "Blue", "PF2", "06:00, 07:00, 08:00, 09:00", 5},
        {"Dumdum", "Blue", "PF2", "06:05, 07:05, 08:05, 09:05", 6},
        {"Esplanade_B", "Blue", "PF2A", "06:10, 07:10, 08:10, 09:10", 7},
        {"Park_Street", "Blue", "PF2", "06:15, 07:15, 08:15, 09:15", 8},
        {"Rabindra_Sadan","Blue", "PF2", "06:20, 07:20, 08:20, 09:20", 6},
        {"Kavi_Subhash_B","Blue", "PF2A", "06:25, 07:25, 08:25, 09:25", 7},
        // Green Line (6 Stations)
             {"Salt_Lake_Sector_V", "Green", "PF2", "06:55, 07:55, 08:55, 09:55", 7},
    {"Phoolbagan", "Green", "PF2", "06:50, 07:50, 08:50, 09:50", 6},
    {"Sealdah", "Green", "PF2", "06:45, 07:45, 08:45, 09:45", 8},
    {"Esplanade_G", "Green", "PF2B", "06:40, 07:40, 08:40, 09:40", 7},
    {"Mahakaran", "Green", "PF2", "06:35, 07:35, 08:35, 09:35", 6},
    {"Howrah_Maidan", "Green", "PF2", "06:30, 07:30, 08:30, 09:30", 5},
        // Orange Line (5 Stations)
            {"Hemanta_Mukhopadhyay", "Orange", "PF2", "07:25, 08:25, 09:25, 10:25", 7},
    {"Kavi_Sukanta", "Orange", "PF2", "07:20, 08:20, 09:20, 10:20", 6},
    {"Joytirindra_Nandi", "Orange", "PF2", "07:15, 08:15, 09:15, 10:15", 8},
    {"Satyajit_Roy", "Orange", "PF2", "07:10, 08:10, 09:10, 10:10", 7},
    {"Kavi_Subhash_O", "Orange", "PF2B", "07:00, 08:00, 09:00, 10:00", 6},
        // Purple Line (6 Stations)
        {"Joka", "Purple", "PF2", "07:30, 08:30, 09:30, 10:30", 5},
        {"Thakurpukur", "Purple", "PF2", "07:35, 08:35, 09:35, 10:35", 6},
        {"Behala_Chowrasta", "Purple", "PF2", "07:40, 08:40, 09:40, 10:40", 7},
        {"Behala_Bazar", "Purple", "PF2", "07:45, 08:45, 09:45, 10:45", 8},
        {"Majerhat", "Purple", "PF2", "07:50, 08:50, 09:50, 10:50", 6},
        {"Esplanade_P", "Purple", "PF2B", "07:55, 08:55, 09:55, 10:55", 7}
    };
    int numStations = sizeof(stations) / sizeof(stations[0]);
    char source[50], destination[50];
    int numPassengers,stationsTraveled = 0;
    int travelTime = 0;
    int userHour, userMinute;
    int crowdLevel;
    int isStudent = 0, isSenior = 0;
    char lineColor[20];
    char platform[5];
    printf("\nEnter source station: ");
    scanf("%s", source);
    printf("\nEnter destination station: ");
    scanf("%s", destination);
    printf("\nEnter travel time (HH:MM format 24-hr): ");
    scanf("%d %d", &userHour, &userMinute);
    printf("\nEnter number of passengers: ");
    scanf("%d", &numPassengers);
    printf("\nAre you a student? (1=Yes, 0=No): ");
    printf("\nEnter user choice :");
    scanf("%d", &isStudent);
    printf("\nAre you a senior citizen? (1=Yes, 0=No): ");
    printf("\nEnter user choice :");
    scanf("%d", &isSenior);
    const char *sourceColor = NULL;
    const char *destinationColor = NULL;
    int foundSource = 0, foundDest = 0,sourceIndex=-1,destIndex=-1;
    for (int i = 0; i < numStations; i++) {
        if (strcmp(stations[i].name, source) == 0) {
            foundSource = 1;
            sourceIndex = i;
             sourceColor = stations[i].lineColor;
            strcpy(platform, stations[i].platform);
        }
        if (strcmp(stations[i].name, destination) == 0) {
            foundDest = 1;
            destIndex = i;
            destinationColor = stations[i].lineColor;
            strcpy(platform, stations[i].platform);
        }
    }
    if (!foundSource || !foundDest) {
        printf("Invalid station entered!\n");
        return 1;
    }
     if (sourceIndex > destIndex) {
        printf("\nError: Only DOWN direction allowed! Choose a valid DOWN route.\n");
        return;
    }
 for (int i = sourceIndex; i < destIndex; i++) {
        stationsTraveled++;
        travelTime += stations[i].travelTime;
    }
    srand(time(NULL));
    crowdLevel = rand() % 3;
    char *crowdText[] = {"Low", "Medium", "High"};
    printf("\n");
    printf("\n===== Available Trains ================================================================================================\n\n");
    printf("%02d:%02d | %s to %s | Travel Time: %d mins | Crowd : %s | Line : %s -> %s | Platform :%s\n\n",
           userHour, userMinute, source, destination, travelTime, crowdText[crowdLevel],sourceColor,destinationColor,platform);
    printf("========================================================================================================================\n\n");
    int choice;
    printf("\nDo you want to book a ticket? (1='YES'/2='NO'): ");
    printf("\nEnter user choice :");
    scanf("%d", &choice);
    if (choice == 1) {
        char ticketID[13];
        generateTicketID(ticketID);
        int fare = calculateFare(stationsTraveled, numPassengers, isStudent, isSenior);
        int baseFare = 20 * numPassengers;
        int dailyPass = 150;
        int monthlyPass = 1200;
        int selectedFare;
        int passChoice;
        printf("\nChoose ticket type:\n1. Single Journey (Rs. %d)\n2. Daily Pass (Rs. %d)\n3. Monthly Pass (Rs. %d)\n",
               baseFare, dailyPass, monthlyPass);
               printf("\nEnter user choice :");
        scanf("%d", &passChoice);
        switch (passChoice) {
            case 1: selectedFare = baseFare; break;
            case 2: selectedFare = dailyPass; break;
            case 3: selectedFare = monthlyPass; break;
            default: selectedFare = baseFare;
        }
        printf("\n\n");
        printf("\n===== Ticket Details ========================\n\n");
        printf("Ticket ID: %s\n", ticketID);
        printf("Source: %s\n", source);
        printf("Destination: %s\n", destination);
        printf("Number of Passengers: %d\n", numPassengers);
        printf("Total Fare: Rs. %d\n", selectedFare);
        printf("Time Taken :%d mins\n",travelTime);
        printf("Route/Line Color : %s -> %s\n", sourceColor, destinationColor);
        printf("Platform :%s\n\n",platform);
        printf("================================================");
    } else
    {
        printf("Thank you! Have a great journey.\n");
        exit(0);
    }
}
void close2()
{
    int a;
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ____________\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t| Close App ! |\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ____________\n\n");
    printf("Are you sure?\n");
    printf("Enter '1' for YES\t\tEnter '2' for NO\n");
    printf("\nEnter user choice :");
    scanf("%d",&a);
    if(a==1)
    {
        printf("Redirecting to new page\n");
        Sleep(1000);
        system("cls");
        mains();
    }
    else
    {
        printf("Redirecting to new page\n");
        Sleep(1000);
        system("cls");
        home();
    }
}

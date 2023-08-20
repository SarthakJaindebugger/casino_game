//MIAMI's CASINO GAME Copywrite Sarthak Jain

//Remove comments wherever, if u r on windows...this is designed on MacOs
//Read the disclamer before playing!!
//Happy playing

/*
DISCLAMER:

This game is designed only for fun purpose!!Any harm or loss is your call!!
Developer will not be responsible for any kind of addiction!
This game doesn't gaurentee winnings, u have to bear the losses as well!
No kind of REAL money is used in this game, everything is virtual for now!
This game doesn't store your prsnl info BUT HAS ACCESS TO UR HARDWARE & Internet
To access all the features use, Windows, MacOs, DOS, Ubuntu, Chrome Os & use GCC 9.1 or 9.7 compilers 
If ofenssive close the game immediatly!!

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
//#include<conio.h>


/*
Only Windows Users
#include<windows.h>
#include<MMsystem.h>
*/

//Check IPV4 address
void checkHostName(int hostname)
{
    if (hostname == -1)
    {
        perror("gethostname");
        exit(1);
    }
}
void checkHostEntry(struct hostent * hostentry)
{
    if (hostentry == NULL)
    {
        perror("gethostbyname");
        exit(1);
    }
}
  
void checkIPbuffer(char *IPbuffer)
{
    if (NULL == IPbuffer)
    {
        perror("inet_ntoa");
        exit(1);
    }
}

//validate product key
void product_key()
{
    FILE *fp;
    fp = fopen("product_key.bin", "r");
    char read_var[500];
    
    while(fscanf(fp, "%s", read_var) !=  EOF)
    {
        printf("%s", read_var);
        char passwd[500];
        printf("\nEnter passwd: ");
        scanf("%s",&passwd);
    
        if(passwd == read_var)
        {
            printf("\nY");
        }
        else
        {
            printf("\nN");
        }

    }
    fclose(fp);
}

int main()
{
    char player_nm[20];
    double final_money, loan;
    double win, loose;
    win = 0;
    loose = 0;
    final_money = 0;

    printf("\nREAD DISCLAMER.TXT BEFORE PLAYING\n");

	FILE *fp;
    fp = fopen("product_key.bin", "r");
    char read_var[100] ,var_pkey[100] ;
    int tt;
    
    
    while(fscanf(fp, "%s", read_var) !=  EOF)
    {
        //printf("%s", read_var);
        printf("\nEnter product key: ");
        scanf("%s",&var_pkey);

        tt = strcmp(var_pkey,read_var);
        
        if( tt == 0)
        {
            printf("\nSuccess!\n");
            continue;
        }
        else
        {
            printf("\nInvalid product key!\n");
            exit(1);
        }

    }
    fclose(fp);

    /*
    Only Windows users
    int music;
    printf("\n1.Sound track 1\n2.Sound track 2\n3.Sound track 3\n4.Sound track 4\n5.Shutdown");
    scanf("%d",&music);
    
    if(music == 1)
    {
        //PlaySound(TEXT("//File path"), NULL, SND_SYNC);
    }
    else if(music == 2)
    {
        //PlaySound(TEXT("//File path"), NULL, SND_SYNC);
    }
    else if(music == 3)
    {
        //PlaySound(TEXT("//File path"), NULL, SND_SYNC);
    }
    else if(music == 4)
    {
        //PlaySound(TEXT("//File path"), NULL, SND_SYNC);
    }
    else if(music == 5)
    {
        system("C:\\Windows\\system32\\shutdown /s /t 0");
    }
    else
    {
        printf("\nInvalid option!!");
        break;
    }
    */

    
    printf("\n===================================================================");
    printf("\n  *******        *        *******  *******  **      *   *********  ");
    printf("\n *              * *       *           *     * *     *   *       *  ");
    printf("\n *             *   *      *           *     *  *    *   *       *  ");
    printf("\n *            *     *     *******     *     *   *   *   *       *  ");
    printf("\n *           *********          *     *     *    *  *   *       *"  );
    printf("\n *          *         *         *     *     *     * *   *       *  ");
    printf("\n  *******  *           *  *******  *******  *      **   *********  ");
    printf("\n===================================================================\n");

    printf("\n# RULES OF THE MIAMI's CASINO GAME:");
    printf("\n>>Everytime u win, ur money gets 10X");
    printf("\n>>Everytime u loose, ur money is lost");
    printf("\n>>Don't have any money?\n  dw, u can take a loan at an intrest of 20 perct. every mili sec.! ");
    printf("\n#CAUTION: Fail to repay the loan, hmm? cops r behind u, dw!\nRead the disclamer before continuing!\n");

    printf("\n \t\t  ~~ ~~       ");
    printf("\n \t\t  $   $    1.Play");
    printf("\n \t\t  .   .    2.Exit");
    printf("\n  \t\t   . .    ");

    double choice, state, in_money ;
    state = 1;
    printf("\nEnter: ");
    scanf("%lf",&choice);

    clock_t t;
    t = clock();
    
    if(choice == 1)
    {
        printf("\nYour name: ");
        scanf("%s",&player_nm);

        while(state == 1)
        {

            printf("\nEnter bet money $: ");
            scanf("%lf",&in_money);

            //+ve money
            if(in_money > 0)
            {
                int i;
                int lower = 1, upper = 100, count = 1;
                int user_no;
                int num;

                printf("\nEnter a no. b/w 1-->100: ");
                scanf("%d",&user_no);

                if(user_no >= 1 && user_no <= 100)
                {
                    for (i = 0; i < count; i++) 
                    {
                        num = (rand() % (upper - lower + 1)) + lower;
                        //here
                        //printf("%d ", num);
                    }
                    srand(time(0));               
                
                    if(user_no == num)
                    {
                        printf("\nGood play!!");
                        in_money = in_money * 10;
                        final_money = final_money + in_money;
                        win = win + in_money;
                        in_money = 0;
                    }
                    else
                    {
                        int choice4;
                        loose = loose + in_money;
                        final_money = final_money - loose;
                        in_money = 0;
                        printf("\nBad play, Try again!");
                        printf("\nDo u want to cont.? 1/0: ");
                        scanf("%d",&choice4);

                        if (choice4 == 1)
                        {
                            continue;
                        }
                        else
                        {
                            printf("\n#Player: %s",&player_nm);
                            printf("\nWon money $: %lf",win);
                            printf("\nLost money $: %lf",loose);
                            printf("\nFinal Amount $: %lf",final_money);
                            printf("\nLoan $: %lf",loan);
                            break;

                        }
                    }
                }
                else
                {
                    printf("\nInvalid input!!");
                    break;
                }

            }

            //Loan case
            else if(in_money == 0)
            {
                int choice2;
                double loan_use;
                double loan2;
                printf("\nWant loan? 1/0: ");
                scanf("%d",&choice2);

                if(choice2 == 1)
                {
                    printf("\nEnter loan amount <= $ 100,000: ");
                    scanf("%lf",&loan);
                    loan2 = loan;

                    if(loan <= 100000)
                    {
                        while(loan >= 0)
                        {
                            printf("\nEnter money to be used from loan: ");
                            scanf("%lf",&loan_use);

                            loan = loan - loan_use;

                            int i;
                            int lower = 1, upper = 100, count = 1;
                            int user_no;
                            int num;

                            printf("\nEnter a no. b/w 1-->100: ");
                            scanf("%d",&user_no);

                            if(user_no >= 1 && user_no <= 100)
                            {
                                for (i = 0; i < count; i++) 
                                {
                                    num = (rand() % (upper - lower + 1)) + lower;
                                    //here
                                    //printf("%d ", num);
                                }
                                srand(time(0));               
                
                                if(user_no == num)
                                {
                                    printf("\nGood play!!");
                                    loan_use = loan_use * 10;
                                    final_money = final_money + loan_use;
                                    win = win + loan_use;
                                    in_money = 0;
                                }
                                else
                                {
                                    int choice4;
                                    loose = loose + loan_use;
                                    final_money = final_money - loose;
                                    in_money = 0;
                    
                                    printf("\nBad play, Try again!");

                                    if(loan>0)
                                    {
                                        continue;
                                    }
                                    //Loan finishes
                                    else
                                    {
                                        printf("\nLoan finished!\n");
                                        //exit(1);
                                        //break;
                                    }

                                    if(loan>0)
                                    {
                                        printf("\nDo u want to cont.? 1/0: ");
                                        scanf("%d",&choice4);
                                    }
                                
                                    if (choice4 == 1 && loan>0)
                                    {
                                        continue;
                                    }
                                    else
                                    {
                                        printf("\n#Player: %s",&player_nm);
                                        printf("\nWon money $: %lf",win);
                                        printf("\nLost money $: %lf",loose);
                                        printf("\nFinal Amount $: %lf",final_money);
                                        t = clock() - t;
                                        double time_taken = ((double)t)/CLOCKS_PER_SEC;
                                        double final_time = time_taken * 1000;
                                        double loan3;
                                        loan3 = loan2 + loan2 * final_time * 0.2 ;
                                        printf("\nLoan $:%lf",loan3);

                                        //Loan repay
                                        printf("\n\nHow would u like to repay the loan??");
                                        printf("\n1.By Cash\n2.By Credit card\n3.Don't have");
                                        int choice5;
                                        printf("\nEnter: ");
                                        scanf("%d",&choice5);

                                        if(choice5 == 1)
                                        {
                                            double cash;
                                            printf("\nEnter the amount $: ");
                                            scanf("%lf",&cash);
                                            
                                            if(cash == loan3)
                                            {
                                                printf("\nPaid successfully!!");
                                                exit(1);
                                            }
                                            else
                                            {
                                                printf("\nTransaction failed!!");
                                            }
                                        }
                                        else if(choice5 == 2)
                                        {
                                            char card_no[20], cvv[20];
                                            int captcha;
                                            printf("\nEnter card no. without space: ");
                                            scanf("%s",&card_no);
                                            printf("\nEnter CVV: ");
                                            scanf("%s",&cvv);

//BUG 2 if invalid card/cvv length...
                                            if(strlen(card_no) == 16 && strlen(cvv) == 3)
                                            {
                                                int check = 0;
                                                
                                                while(check == 0)
                                                {
                                                    int lower = 1000, upper = 9999, count = 1;
                                                    for (i = 0; i < count; i++) 
                                                    {
                                                        num = (rand() % (upper - lower + 1)) + lower;
                                                        printf("\nCaptcha: %d ", num);
                                                    }
                                                    srand(time(0));
                                                    printf("\nEnter the captcha seen: ");
                                                    scanf("%d",&captcha);
                                                    if(captcha == num)
                                                    {
                                                        check = 1;
                                                        printf("\nAmount deducted from the bank acc.!!");
                                                        printf("\nThanks for playing");
                                                        exit(1);

                                                    }
                                                }
                                                
                                            }
                                            else
                                            {
                                                char hostbuffer[256];
                                                char *IPbuffer;
                                                struct hostent *host_entry;
                                                int hostname;
                                                hostname = gethostname(hostbuffer, sizeof(hostbuffer));
                                                checkHostName(hostname); 
                                                host_entry = gethostbyname(hostbuffer);
                                                checkHostEntry(host_entry);
                                                IPbuffer = inet_ntoa(*((struct in_addr*)
                                                host_entry->h_addr_list[0]));

                                                printf("\nFraud details");
                                                printf("\nThese r your IP details!");
                                                printf("\nCops will catch u soon!\n");

                                                printf("\nHostname: %s\n", hostbuffer);
                                                printf("\nHost IP: %s", IPbuffer);
/*Remove test v1.1
                                                int n;
                                                struct ifreq ifr;
                                                char array[] = "eth0";
 
                                                n = socket(AF_INET, SOCK_DGRAM, 0);
                                                ifr.ifr_addr.sa_family = AF_INET;
                                                strncpy(ifr.ifr_name , array , IFNAMSIZ - 1);
                                                ioctl(n, SIOCGIFADDR, &ifr);
                                                close(n);
                                                printf("\nIP Address is %s - %s\n" , array , inet_ntoa(( (struct sockaddr_in *)&ifr.ifr_addr )->sin_addr) );
*/
                                                exit(1);

                                            }                                          
                                        }
                                        else if(choice5 == 3)
                                        {
                                            char hostbuffer[256];
                                            char *IPbuffer;
                                            struct hostent *host_entry;
                                            int hostname;
                                            hostname = gethostname(hostbuffer, sizeof(hostbuffer));
                                            checkHostName(hostname); 
                                            host_entry = gethostbyname(hostbuffer);
                                            checkHostEntry(host_entry);
                                            IPbuffer = inet_ntoa(*((struct in_addr*)
                                            host_entry->h_addr_list[0]));
                                            printf("\nThese r your IP details!");
                                            printf("\nCops will catch u soon!\n");
                                            printf("\nHostname: %s\n", hostbuffer);
                                            printf("\nHost IP: %s", IPbuffer);
/*Remove test v1.1
                                            int n;
                                            struct ifreq ifr;
                                            char array[] = "eth0";
 
                                            n = socket(AF_INET, SOCK_DGRAM, 0);
                                            ifr.ifr_addr.sa_family = AF_INET;
                                            strncpy(ifr.ifr_name , array , IFNAMSIZ - 1);
                                            ioctl(n, SIOCGIFADDR, &ifr);
                                            close(n);
                                            printf("\nIP Address is %s - %s\n" , array , inet_ntoa(( (struct sockaddr_in *)&ifr.ifr_addr )->sin_addr) );
*/
                                            exit(1);
                                        }
                                        else
                                        {
                                            char hostbuffer[256];
                                            char *IPbuffer;
                                            struct hostent *host_entry;
                                            int hostname;
                                            hostname = gethostname(hostbuffer, sizeof(hostbuffer));
                                            checkHostName(hostname); 
                                            host_entry = gethostbyname(hostbuffer);
                                            checkHostEntry(host_entry);
                                            IPbuffer = inet_ntoa(*((struct in_addr*)
                                            host_entry->h_addr_list[0]));
                                            printf("\nInvalid input!!");
                                            printf("\nThese r your IP details!");
                                            printf("\nCops will catch u soon!\n");
                                            printf("\nHostname: %s\n", hostbuffer);
                                            printf("\nHost IP: %s", IPbuffer);

/*Remove test v1.1                          int n;
                                            struct ifreq ifr;
                                            char array[] = "eth0";
 
                                            n = socket(AF_INET, SOCK_DGRAM, 0);
                                            ifr.ifr_addr.sa_family = AF_INET;
                                            strncpy(ifr.ifr_name , array , IFNAMSIZ - 1);
                                            ioctl(n, SIOCGIFADDR, &ifr);
                                            close(n);
                                            printf("\nIP Address is %s - %s\n" , array , inet_ntoa(( (struct sockaddr_in *)&ifr.ifr_addr )->sin_addr) );
*/
                                            exit(1);

                                        }
                                    }
                                }
                            }
                        }
                    }

                    else
                    {
                        printf("\nInvalid loan amount!! ");
                        break;
                    }

                }    
                else
                {
                    state = 0;
                    printf("\n#Player: %s",&player_nm);
                    printf("\nWon money $: %lf",win);
                    printf("\nLost money $: %lf",loose);
                    printf("\nFinal Amount $: %lf",final_money);
                    printf("\nLoan $: %lf",loan);
                    
                    printf("\nThanks for playing!!\n");
                    //exit(1);
                    break;
                }
            }

            //-ve money
            else
            {
                printf("\nInvalid input!!");
                int choice3;
                printf("\nWant 2 try again? Enter 1/0 : ");
                scanf("%d",&choice3);
                
                if(choice3 == 1)
                {
                    continue;
                }

                else
                {
                    state = 0;
                    break;
                }
            }
        }
    }        
    return 0;
}
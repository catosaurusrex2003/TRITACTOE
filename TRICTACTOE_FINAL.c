//  WE BOAST TO SAY THAT WE HAVE USED ONLY THE MOST BASIC LIBRARY IN C 
#include <stdio.h>
/*
                                    RULES
                      THIS GAME IS 6x6  3 PLAYER TICTACTOE
                    CONNECT 3 SAME CHARACTERS TO GAIN 1 POINT
                    PERSON WITH THE MAXIMUM POINT WINS THE GAME
WHEN 3 CHARACTERS ARE CONNECTED THEN THEY CANNOT BE USED TO CONNECT AGAIN AND WILL BE
                              CONVERTED INTO A '-'
            A ALREADY CONNECTED CHAR CANNOT BE USED IN CONNECTING FURTHER
*/
char board[6][6];
char p1 = 'X'; // WILL BE RED
char p2 = 'O'; // WILL BE CYAN
char p3 = 'Z'; // WILL BE YELLOW
char answer;

// THESE ARE THE VARIABLES CONTAINING THE SCORES OF THE GAME
int xscore = 0, oscore = 0, zscore = 0, x_final = 0, o_final = 0, z_final = 0;


// THESE ARE COMMANDS WHICH CAN BE PRINTED TO CHANGE THE COLOR OF THR TERMINAL
// WE USE THESE TO CHANGE THE COLOUR OF TERMINAL ACCORDING TO OUR REQUIREMENT 
// THEN WE PRINT THE CHAR WE WANT IN THE COLOR OF THE TERMINAL AND THEN WE 
// CHANGE THE COLOR OF THE TERMINAL BACK TO ORIGINAL TO CHANGE AGAIN IN THE FUTURE

void red() { printf("\033[1;31m"); }     // change colour of terminal/console to RED
void yellow() { printf("\033[1;33m"); }  // change colour of terminal/console to YELLOW
void blue(){ printf("\033[0;34m"); }     // change colour of terminal/console to BLUE
void cyan() { printf("\033[0;36m"); }    // change colour of terminal/console to CYAN
void purple() { printf("\033[0;35m"); }  // change colour of terminal/console to PURPLE
void resetcolor() { printf("\033[0m"); } // change colour of terminal/console to NORMAL


// A FUNCTION TO DELAY TIME BY RUNNING NESTED LOOPS
void delay()
{
    int c, d;
       
       for (c = 1; c <= 10000; c++)
	   for (d = 1; d <= 10000; d++)
           {}

}

// PRINTS WELCOME MESSAGE
// WE MADE NEW FUNCTION FOR EVERY WORD BECAUSE WE WANTED TO KEEP A DELAY IN BETWEEN
void welcome()
{  // IMPROVED ATHARVAS BRAINLESS LOGIC TO IMPLEMENT THIS  ;)    :0
    red();
    printf("WW      WW EEEEEEE LL       CCCCC   OOOOO  MM    MM EEEEEEE \n");
    printf("WW      WW EE      LL      CC      OO   OO MMM  MMM EE      \n");
    printf("WW   W  WW EEEEE   LL      CC      OO   OO MM MM MM EEEEE   \n");
    printf(" WW WWW WW EE      LL      CC      OO   OO MM    MM EE      \n");
    printf("  WW   WW  EEEEEEE LLLLLLL  CCCCC   OOOO0  MM    MM EEEEEEE \n");
    resetcolor();
    delay();
    yellow();
    printf("TTTTTTT  OOOOO  \n");
    printf("  TTT   OO   OO \n");
    printf("  TTT   OO   OO \n");
    printf("  TTT   OO   OO \n");
    printf("  TTT    OOOO0  \n");
    resetcolor();
    delay();
    blue();
    printf("TTTTTTT RRRRRR  IIIII \n");
    printf("  TTT   RR   RR  III  \n");
    printf("  TTT   RRRRRR   III  \n");
    printf("  TTT   RR  RR   III  \n");
    printf("  TTT   RR   RR IIIII \n");
    resetcolor();
    delay();
    cyan();
    printf("TTTTTTT   AAA    CCCCC \n"); 
    printf("  TTT    AAAAA  CC     \n");
    printf("  TTT   AA   AA CC      \n");
    printf("  TTT   AAAAAAA CC     \n");
    printf("  TTT   AA   AA  CCCCC  \n");
    resetcolor();
    delay();
    purple();
    printf("TTTTTTT  OOOOO  EEEEEEE\n"); 
    printf("  TTT   OO   OO EE     \n");
    printf("  TTT   OO   OO EEEEE  \n"); 
    printf("  TTT   OO   OO EE     \n"); 
    printf("  TTT    OOOO0  EEEEEEE\n"); 
    resetcolor();
    printf("made by Atharv Patawar - 60009210176 and Mohammed Mehdi - 60009210187 Bhaumik Kore - 60009210179 from CSE DS :)\n");
    delay();
}


// WE MADE THIS FUNCTION TO CONVERT THE COLOR OF THE TERMINAL TO THE RESPECTIVE 
// COLOR OF THE CHAR AND THEN RESET IT BACK TO NORMAL ACCORDING TO THE CHAR
void printelement(int row, int column)
{
    if (board[row][column] == 'X')
    {
        red();
        printf("%c", board[row][column]);
        resetcolor();
    }
    if (board[row][column] == 'O')
    {
        cyan();
        printf("%c", board[row][column]);
        resetcolor();
    }
    if (board[row][column] == 'Z')
    {
        yellow();
        printf("%c", board[row][column]);
        resetcolor();
    }
    if (board[row][column] == ' ')
    {
        printf(" ");
    }
    if(board[row][column] == '-')
    {
        purple();
        printf("-");
        resetcolor();
    }
}

// FUNCTION TO PRINT THE WHOLE BOARD WITH THE RESPECTIVE CHARS IN THEIR PLACE
// THE CHARS ARE STORED IN A 2D ARRAY
void printboard() 
{   //mehdis improved code keeping color in mind :)    :0
   purple();
   printf("  1 "); printf("  2 "); printf("  3 "); printf("  4 "); printf("  5 ");printf("  6 "); printf("\n");
   resetcolor();
   purple(); printf("1"); resetcolor(); printf(" ");printelement(0,0);printf(" | ");printelement(0,1);printf(" | ");printelement(0,2);printf(" | ");printelement(0,3);printf(" | ");printelement(0,4);printf(" | ");printelement(0,5);;
   printf("\n ---|---|---|---|---|---\n");
   purple(); printf("2"); resetcolor(); printf(" ");printelement(1,0);printf(" | ");printelement(1,1);printf(" | ");printelement(1,2);printf(" | ");printelement(1,3);printf(" | ");printelement(1,4);printf(" | ");printelement(1,5);;
   printf("\n ---|---|---|---|---|---\n");
   purple(); printf("3"); resetcolor(); printf(" ");printelement(2,0);printf(" | ");printelement(2,1);printf(" | ");printelement(2,2);printf(" | ");printelement(2,3);printf(" | ");printelement(2,4);printf(" | ");printelement(2,5);;
   printf("\n ---|---|---|---|---|---\n");
   purple(); printf("4"); resetcolor(); printf(" ");printelement(3,0);printf(" | ");printelement(3,1);printf(" | ");printelement(3,2);printf(" | ");printelement(3,3);printf(" | ");printelement(3,4);printf(" | ");printelement(3,5);;
   printf("\n ---|---|---|---|---|---\n");
   purple(); printf("5"); resetcolor(); printf(" ");printelement(4,0);printf(" | ");printelement(4,1);printf(" | ");printelement(4,2);printf(" | ");printelement(4,3);printf(" | ");printelement(4,4);printf(" | ");printelement(4,5);;
   printf("\n ---|---|---|---|---|---\n");
   purple(); printf("6"); resetcolor(); printf(" ");printelement(5,0);printf(" | ");printelement(5,1);printf(" | ");printelement(5,2);printf(" | ");printelement(5,3);printf(" | ");printelement(5,4);printf(" | ");printelement(5,5);;
   printf("\n ---|---|---|---|---|---\n");
}

// FUNCTION TO PRINT LEADERBOARD AT THE END OF MATCH
void printleaderboard()
{
    purple();
    printf("\n-----------------------\n");
    printf("X:%d\n",x_final);
    printf("Y:%d\n",o_final);
    printf("Z:%d\n",z_final);
    printf("\n-----------------------\n");
    resetcolor();
}

// FUNCTION TO RESET THE BOARD IF U WANT TO REPLAY
void resetboard()
{
    int i, j;
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 6; j++)
        {
            board[i][j] = ' ';
        }
    }
}

// THIS FUNCTION CHECKS IF THERE ARE EMPTY SPACES LEFT ON THE BOPARD OR NOT
int emptyspaces()
{
    int i, j, ath = 0; // 0 --> false     1 --> true
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 6; j++)
        {
            if (board[i][j] == ' ')
            {
                ath = 1;
            }
        }
    }
    if (ath==1)
        return 1;
    else
        return 0;
}

// THE 3 FUNCTIONS BELOW ARE DIFFERENT PLAYER MOVES
// WE HAD TO SPLIT THEM INTO 3 PARTS BECAUSE WE WANTED TO PRINT THE BOARD AFTER EVERY PLAYER MOVES AND NOT 
// AFTER ALL THE 3 PLAYERS HAVE PLAYED THEIR MOVE
// ALSO WITHOUT SPLITTING THE CODE COULDNT CATCH MORE THAN ONE PLAYER CONNECTING 3 CHARS
void red_playermove(){ 
    int x;
    int y;
    do
    {
        red();
        printf("Enter row #(1-6): ");
        scanf("%d", &x);
        x--;
        printf("Enter column #(1-6): ");
        scanf("%d", &y);
        y--;
        if (board[x][y] != ' ' || x<0 || x>=6 || y<0 || y>6 || board[x][y] == 'X' ||board[x][y] == 'O' || board[x][y] == 'Z' )
            {
                printf("Invalid move!\n");
            }
            else
            {
                board[x][y] = p1;
                break;
            }
    } while (board[x][y] != ' ');
    resetcolor();

}
void cyan_playermove(){
    int x ,y;
    do
    {
        cyan();
        printf("Enter row #(1-6): ");
        scanf("%d", &x);
        x--;
        printf("Enter column #(1-6): ");
        scanf("%d", &y);
        y--;
        if (board[x][y] != ' ' || x<0 || x>=6 || y<0 || y>6 || board[x][y] == 'X' ||board[x][y] == 'O' || board[x][y] == 'Z' )
            {
                printf("Invalid move!\n");
            }
            else
            {
                board[x][y] = p2;
                break;
            }
    } while (board[x][y] != ' ');
    resetcolor();
}
void yell_playermove()
{   int x , y;
    do
    {
        yellow();
        printf("Enter row #(1-6): ");
        scanf("%d", &x);
        x--;
        printf("Enter column #(1-6): ");
        scanf("%d", &y);
        y--;
        if (board[x][y] != ' ' || x<0 || x>=6 || y<0 || y>6 || board[x][y] == 'X' ||board[x][y] == 'O' || board[x][y] == 'Z' )
            {
                printf("Invalid move!\n");
            }
            else
            {
                board[x][y] = p3;
                break;
            }
    } while (board[x][y] != ' ');
    resetcolor();
}

// MOST IMPORTANT FUNCTION TO CHECK WINNER AND WITH 4 CONDITIONS
// THIS FUNCTION CATCHES ANY NEW 3 LINKAGE AND RETURNS THE CHAR WHICH CONNECTED THE 3 GRIDS
// IT THEN PLAYS AND IMPORTANT ROLE TO CONVERT THE CONNECTED CHAR TO - TO DISABLE FURTHER USE OF THE GRID 
// WE USE A TEMPORARY VARIABLE TO DO SO
char checkWinner()
{
    // HORIZONTAL CHECK
    int i = 0, j = 0 ; 
    char tempchar;
    for (i = 0; i < 6; i++)
    {
        for (j = 1; j < 5; j++)
        {
            if (board[i][j] == board[i][j - 1] && board[i][j] == board[i][j + 1] && board[i][j] != ' ' && board[i][j] != '-')
            {
                tempchar = board[i][j];
                board[i][j] = board[i][j - 1] = board[i][j + 1] = '-';  // REPLACING CHAR WITH -
                return tempchar;
            }

        }
    }
    // VERTICAL CHECK
    for (i = 0; i < 6; i++)
    {
        for (j = 1; j < 5; j++)
        {
            if (board[j][i] == board[j - 1][i] && board[j][i] == board[j + 1][i] && board[j][i] != ' ' && board[j][i] != '-')
            {
                tempchar = board[j][i];
                board[j][i] = board[j - 1][i] = board[j + 1][i] = '-';   // REPLACING CHAR WITH -
                return tempchar;
            }
        }
    }
    // \ DIAGONAL CHECK
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2] && board[i][j] != ' ' && board[i][j] != '-')
            {
                tempchar =  board[i][j];
                board[i][j] = board[i + 1][j + 1] = board[i + 2][j + 2] = '-';   // REPLACING CHAR WITH -
                return tempchar;

            }
        }
    }
    // / DIAGONAL CHECK
    for (i = 2; i < 6; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (board[i][j] == board[i - 1][j + 1] && board[i][j] == board[i - 2][j + 2] && board[i][j] != ' ' && board[i][j] != '-')
            {
                tempchar =  board[i][j];
                board[i][j] = board[i - 1][j + 1] = board[i - 2][j + 2] = '-';   // REPLACING CHAR WITH -
                return tempchar;
            }
        }
    }
    return ' ';
}

// THIS FUNCTION IS PARENT OF WINCHECK() AND INCREMENTS THE SCORE OF THE PLAYER
// THIS FUNCTION CALLS WINCHECK() AND TAKES THE RETURNED VALUE AND THEN INCREMENTS THE RESPECTIVE SCORE VARIABLE
void par_wincheck(){
    char checkwinnervalue = checkWinner();
    if (checkwinnervalue == 'O')
            {
                oscore++;
                printf("Player O connected 3 \n");
                printf("X = %d \nO = %d \nZ = %d \n", xscore, oscore, zscore);
            }
    if (checkwinnervalue == 'X')
            {
                xscore++;
                printf("Player X connected 3 \n");
                printf("X = %d \nO = %d \nZ = %d \n", xscore, oscore, zscore);
            }
    if (checkwinnervalue == 'Z')
            {
                zscore++;
                printf("Player Z connected 3 \n");
                printf("X = %d \nO = %d \nZ = %d \n", xscore, oscore, zscore);
            }
}

// IF YOU WANT TO UNDERSTAND THE PROGRAM START READING FROM HERE OR U WILL GET LOST ... PROBABLY
void main()
{
    welcome();
    resetboard();
    printboard();
    for (;;) // INFINITE LOOP TILL RETURN OR BREAK
    {
        if (emptyspaces() == 1)  // IF EMPTY SPACES ARE THERE THEN IT RUNS AND EXECUTES
        {
            red_playermove();
            printboard();
            par_wincheck();
            
            cyan_playermove();
            printboard();
            par_wincheck();
            
            yell_playermove();
            printboard();
            par_wincheck();
        }
        else   // ELSE LOOP TO DECIDE SCORE DO REMATCH AND STUFF
        {
            if(xscore>oscore)
            {
                if(xscore>zscore)
                {
                    printf("The winner of this round is player X \n");
                    x_final++; 
                }
                else if(xscore<zscore)
                {
                    printf("The winner of this round is player Z\n");
                    z_final++;
                }
                else if(xscore==zscore)
                {
                    printf("The winners of this round are player X and player Z\n");
                    x_final++;
                }
            }
            else if(xscore==oscore)
            {
                if(xscore>zscore)
                {
                    printf("The winners of this round are player X and player O\n");
                    x_final++;
                    o_final++;
                }
                else if(xscore<zscore)
                {
                    printf("The winner of this round is player Z");
                    z_final++;
                }
                else if(xscore==zscore)
                {
                    printf("It's a draw!");
                    x_final++;
                    o_final++;
                    z_final++;
                }
            }
            else if(xscore<oscore)
            {
                if(oscore>zscore)
                {
                    printf("The winner of this round is player O\n");
                    o_final++;
                }
                else if(oscore<zscore)
                {
                    printf("The winner of  this round is player Z\n");
                    z_final++;
                }
                else if(oscore==zscore)
                {
                    printf("The winners of this round are player O and player Z\n");
                    o_final++;
                    z_final++;
                }
            }
            // print leader board here
            printleaderboard();

            // asking for rematch
            label:
                printf("do you want to play another match \nanswer in y / n \n");
                scanf("%c", &answer);
                if (answer == 'y')
                {
                    main();
                }
                else if(answer == 'n')
                {
                    return ;
                }
                else
                {
                    printf("invalid answer please try again \n");
                    goto label;
            }
        }
            
    }
}

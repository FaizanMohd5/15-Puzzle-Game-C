//PLEASE READ THE ReadMe FILE FIRST

#include<stdio.h>
#include<time.h>
void rulesScr();
void createMatrix(int matrix[][4]);
void showMatrix(int matrix[][4]);
int readEnteredKey();
int Up(int matrix[][4]);
int Down(int matrix[][4]);
int Right(int matrix[][4]);
int Left(int matrix[][4]);
void swap(int*,int*);
int winner(int matrix[][4]);

int main()
{
    int matrix[4][4],moves=150;
    printf("\n\t\t\t\tMATRIX 150\n\n\n");
    printf("\t\t\tPlayer's Name: ");
    char name[30];
    scanf("%s",name);
    while(1)
    {
        createMatrix(matrix);
        system("cls");
        rulesScr();
        system("cls");
    //game screen
        while(!winner(matrix))
        {
            if(!moves)break;
            printf("\n\t\t\t\tMATRIX 150\n\n");
            printf("\tPlayer's Name: %s \t Moves left:%d\n\n\n",name,moves);
            showMatrix(matrix);
            int Askey=readEnteredKey();
            switch(Askey)
            {
                case 69:
                case 101: printf("\n\t\t\tThanks for Playing!\nPress 'Enter' key to exit.");
                            Askey=readEnteredKey();
                            return 0;
                case 72:  if(Up(matrix))
                            moves--;
                            break;
                case 80:  if(Down(matrix))
                            moves--;
                            break;
                case 75:  if(Left(matrix))
                            moves--;
                            break;
                case 77:  if(Right(matrix))
                            moves--;
                            break;
                default: break;
            }
            system("cls");
        }
        if(!moves)
        {
            printf("\n\t\t\tYOU LOSE\a\a\n");
        }
        else
        {
            printf("\n\t\t\tYOU WON %s\a\a\a\n!!!!!",name);
        }
        fflush(stdin);
        char check;
        printf("\nWant to play again ? \n");
        printf("enter 'y' to play again:  ");
        scanf("%c", &check);

        // Leave the game here itself !
        if ((check != 'y') && (check != 'Y'))
            break;
        moves=150;
    }
    return 0;
}
void rulesScr()
{
    printf("\n\t\t\t\tMATRIX 59\n\n\n");
    printf("\t\t\t       RULES OF THE GAME\n");
    printf("\n1)You can move only 1 step at a time with he arrow key.\n");
    printf("\n\tMove UP : UP ARROW");
    printf("\n\tMove DOWN : DOWN ARROW");
    printf("\n\tMove RIGHT : RIGHT ARROW");
    printf("\n\tMove LEFT : LEFT ARROW");
    printf("\n\n2)You can move numbers at an empty position only.");
    printf("\n\n3)For each valid move: your total number of moves will be decrease by 1.");
    printf("\n\n4)Winning situation:Numbers should be arranged from 1 to 15 \n  in 4x4 matrix as shown below\n\n");
    printf("\t\t-----------------------\n");
    printf("\t\t| 1 |  2  |  3  |  4  |\n");
    printf("\t\t| 5 |  6  |  7  |  8  |\n");
    printf("\t\t| 9 | 10  | 11  | 12  |\n");
    printf("\t\t| 13| 14  | 15  |     |\n");
    printf("\t\t-----------------------\n");
    printf("\n5)You can exit the game at any time by pressing \'E\' or \'e\'\n\nEnter any key to start.....");
    getch();
}
void createMatrix(int matrix[][4])
{
    int elements=15; //1-15
    int temp[elements],lastIndex,index=0;
    int row,col;
    for(row=0;row<15;row++)
        temp[row]=row+1;    //eg: temp[0]=1,temp[1]=2.....(lastIndex)temp[14]=15
    srand(time(NULL));      //time(NULL) for a seed, srand() for random gereration of numbers
    lastIndex=elements-1;
    for(row=0;row<4;row++)
    {
        for(col=0;col<4;col++)
        {
            if(lastIndex >= 0)
            {
                index=rand()%(lastIndex+1);
                matrix[row][col]=temp[index];
                temp[index]=temp[lastIndex];
                lastIndex--;
            }
        }
    }
    matrix[row-1][col-1]=0; // same as matrix[4][4]=0
}
void showMatrix(int matrix[][4])
{
    int row,col;
    printf("\n\n");
    printf("--------------------\n");
    for(row=0;row<4;row++)
    {
        printf("|");
        for(col=0;col<4;col++)
        {
            if(matrix[row][col]!=0)
                printf("%2d | ",matrix[row][col]);
            else
                printf("   | ");
        }
        printf("\n");
    }
    printf("--------------------\n");
}
void swap(int *p,int *q)
{
    *p=(*p)^(*q);
    *q=(*p)^(*q);
    *p=(*p)^(*q);
    printf("");
}
int readEnteredKey()
{
    char ch;
    ch=_getch();
        if(ch==-32)
            ch=_getch();
    return ch;
}
int Up(int matrix[][4])
{
    int row,col;
    for(row=0;row<4;row++)
    {
        for(col=0;col<4;col++)
        {
            if(matrix[row][col]==0)
                break;
        }
        if(col<4)
            break;
    }
    if(row==3)
        return 0;
    swap(&matrix[row][col],&matrix[row+1][col]);
    return 1;
}
int Down(int matrix[][4])
{
    int row,col;
    for(row=0;row<4;row++)
    {
        for(col=0;col<4;col++)
        {
            if(matrix[row][col]==0)
                break;
        }
        if(col<4)
            break;
    }
    if(row==0)
        return 0;
    swap(&matrix[row][col],&matrix[row-1][col]);
    return 1;
}
int Left(int matrix[][4])
{
    int row,col;
    for(row=0;row<4;row++)
    {
        for(col=0;col<4;col++)
        {
            if(matrix[row][col]==0)
                break;
        }
        if(col<4)
            break;
    }
    if(col==3)
        return 0;
    swap(&matrix[row][col],&matrix[row][col+1]);
    return 1;
}
int Right(int matrix[][4])
{
    int row,col;
    for(row=0;row<4;row++)
    {
        for(col=0;col<4;col++)
        {
            if(matrix[row][col]==0)
                break;
        }
        if(col<4)
            break;
    }
    if(col==0)
        return 0;
    swap(&matrix[row][col],&matrix[row][col-1]);
    return 1;
}
int winner(int matrix[][4])
{
    int row,col,k=1;
    for(row=0;row<3;row++)
    {
        for(col=0;col<3;col++)
        {
            if(matrix[row][col]==k++)
                continue;
            else
                return 0;
        }
    }
    return 1;
}

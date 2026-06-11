#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 25
#define COLS 50

char buffer[ROWS][COLS];

void initializeBuffer()
{
    for(int i=0;i<ROWS;i++)
        for(int j=0;j<COLS;j++)
            buffer[i][j]=' ';
}

void displayBuffer()
{
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
            printf("%c",buffer[i][j]);
        printf("\n");
    }
}

int isCirclePoint(int x,int y,int cx,int cy,int r)
{
    int value=(x-cx)*(x-cx)+(y-cy)*(y-cy);
    return abs(value-r*r)<=r;
}

void drawCircle(int cx,int cy,int r)
{
    for(int y=0;y<ROWS;y++)
    {
        for(int x=0;x<COLS;x++)
        {
            if(isCirclePoint(x,y,cx,cy,r))
                buffer[y][x]='*';
        }
    }
}

void drawRectangle(int x,int y,int width,int height)
{
    int i;

    for(i=x;i<=x+width;i++)
    {
        if(i>=0 && i<COLS)
        {
            if(y>=0 && y<ROWS)
                buffer[y][i]='*';

            if(y+height>=0 && y+height<ROWS)
                buffer[y+height][i]='*';
        }
    }

    for(i=y;i<=y+height;i++)
    {
        if(i>=0 && i<ROWS)
        {
            if(x>=0 && x<COLS)
                buffer[i][x]='*';

            if(x+width>=0 && x+width<COLS)
                buffer[i][x+width]='*';
        }
    }
}

void drawTriangle(int x,int y,int h)
{
    for(int row=0;row<=h;row++)
    {
        int left=x-row;
        int right=x+row;

        if(y+row<ROWS)
        {
            if(left>=0 && left<COLS)
                buffer[y+row][left]='*';

            if(right>=0 && right<COLS)
                buffer[y+row][right]='*';
        }
    }

    int left=x-h;
    int right=x+h;

    if(y+h>=0 && y+h<ROWS)
    {
        for(int i=left;i<=right;i++)
        {
            if(i>=0 && i<COLS)
                buffer[y+h][i]='*';
        }
    }
}

void drawLine(int x1,int y1,int x2,int y2)
{
    int dx=abs(x2-x1);
    int dy=abs(y2-y1);

    int sx=(x1<x2)?1:-1;
    int sy=(y1<y2)?1:-1;

    int err=dx-dy;

    while(1)
    {
        if(x1>=0 && x1<COLS &&
           y1>=0 && y1<ROWS)
            buffer[y1][x1]='*';

        if(x1==x2 && y1==y2)
            break;

        int e2=2*err;

        if(e2>-dy)
        {
            err-=dy;
            x1+=sx;
        }

        if(e2<dx)
        {
            err+=dx;
            y1+=sy;
        }
    }
}

void deleteArea(int x,int y,int width,int height)
{
    for(int i=y;i<y+height;i++)
    {
        for(int j=x;j<x+width;j++)
        {
            if(i>=0 && i<ROWS &&
               j>=0 && j<COLS)
                buffer[i][j]=' ';
        }
    }
}

int main()
{
    int choice;

    initializeBuffer();

    do
    {
        printf("\n===== SHAPE DRAWER =====\n");
        printf("1. Draw Circle\n");
        printf("2. Draw Rectangle\n");
        printf("3. Draw Triangle\n");
        printf("4. Draw Line\n");
        printf("5. Delete Area\n");
        printf("6. Display Picture\n");
        
        printf("0. Exit\n");

        printf("Enter Choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            {
                int cx,cy,r;

                printf("Center X Center Y Radius: ");
                scanf("%d%d%d",&cx,&cy,&r);

                drawCircle(cx,cy,r);
                break;
            }

            case 2:
            {
                int x,y,w,h;

                printf("X Y Width Height: ");
                scanf("%d%d%d%d",&x,&y,&w,&h);

                drawRectangle(x,y,w,h);
                break;
            }

            case 3:
            {
                int x,y,h;

                printf("ApexX ApexY Height: ");
                scanf("%d%d%d",&x,&y,&h);

                drawTriangle(x,y,h);
                break;
            }

            case 4:
            {
                int x1,y1,x2,y2;

                printf("X1 Y1 X2 Y2: ");
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

                drawLine(x1,y1,x2,y2);
                break;
            }

            case 5:
            {
                int x,y,w,h;

                printf("X Y Width Height: ");
                scanf("%d%d%d%d",&x,&y,&w,&h);

                deleteArea(x,y,w,h);
                break;
            }

            case 6:
                displayBuffer();
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid Choice\n");
        }

    }while(choice!=0);

    return 0;
}

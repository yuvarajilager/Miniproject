#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define ROWS 25
#define COLS 50

typedef struct
{
    int centerX;
    int centerY;
    int radius;
} Circle;
typedef struct
{
    int x;
    int y;
    int width;
    int height;
} Rectangle;

void initializeBuffer(char buffer[ROWS][COLS]);
void drawCircle(char buffer[ROWS][COLS], Circle c);
void displayBuffer(char buffer[ROWS][COLS]);
int isCirclePoint(int x, int y, Circle c);
void drawRectangle(char buffer[ROWS][COLS], Rectangle r);
int main()
{
    char buffer[ROWS][COLS];

    Circle c;

    int choice;
    Rectangle r;

    do
    {
        printf("\n1. Draw Circle\n");
       
        printf("2. Draw Rectangle\n");
         printf("3 Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:

                printf("Enter Center X: ");
                scanf("%d",&c.centerX);

                printf("Enter Center Y: ");
                scanf("%d",&c.centerY);

                printf("Enter Radius: ");
                scanf("%d",&c.radius);

                initializeBuffer(buffer);

                drawCircle(buffer,c);

                displayBuffer(buffer);

                break;

            case 2:

    printf("Enter Top Left X: ");
    scanf("%d",&r.x);

    printf("Enter Top Left Y: ");
    scanf("%d",&r.y);

    printf("Enter Width: ");
    scanf("%d",&r.width);

    printf("Enter Height: ");
    scanf("%d",&r.height);

    initializeBuffer(buffer);

    drawRectangle(buffer,r);

    displayBuffer(buffer);

    break;
            default:
                printf("Invalid Choice\n");
        }

    } while(choice != 5);

    return 0;
}

void initializeBuffer(char buffer[ROWS][COLS])
{
    int i,j;

    for(i=0;i<ROWS;i++)
    {
        for(j=0;j<COLS;j++)
        {
            buffer[i][j]=' ';
        }
    }
}

int isCirclePoint(int x,int y,Circle c)
{
    int value;

    value=(x-c.centerX)*(x-c.centerX)+
          (y-c.centerY)*(y-c.centerY);

    if(abs(value-(c.radius*c.radius))<=c.radius)
    {
        return 1;
    }

    return 0;
}
void drawRectangle(char buffer[ROWS][COLS], Rectangle r)
{
    int i;

    for(i = r.x; i <= r.x + r.width; i++)
    {
        if(i >= 0 && i < COLS)
        {
            if(r.y >= 0 && r.y < ROWS)
                buffer[r.y][i] = '*';

            if(r.y + r.height >= 0 && r.y + r.height < ROWS)
                buffer[r.y + r.height][i] = '*';
        }
    }

    for(i = r.y; i <= r.y + r.height; i++)
    {
        if(i >= 0 && i < ROWS)
        {
            if(r.x >= 0 && r.x < COLS)
                buffer[i][r.x] = '*';

            if(r.x + r.width >= 0 && r.x + r.width < COLS)
                buffer[i][r.x + r.width] = '*';
        }
    }
}

void drawCircle(char buffer[ROWS][COLS],Circle c)
{
    int x,y;

    for(y=0;y<ROWS;y++)
    {
        for(x=0;x<COLS;x++)
        {
            if(isCirclePoint(x,y,c))
            {
                buffer[y][x]='*';
            }
        }
    }
}

void displayBuffer(char buffer[ROWS][COLS])
{
    int i,j;

    for(i=0;i<ROWS;i++)
    {
        for(j=0;j<COLS;j++)
        {
            printf("%c",buffer[i][j]);
        }

        printf("\n");
    }
}

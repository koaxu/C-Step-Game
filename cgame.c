#include <stdio.h>
#include <stdlib.h>

int mapOutput(char layoutPrint[10][10]);
void description(void);

int x, y, a, b, counter = 0;

int main(void)
{
    description();
    
    char layout[10][10];
    
    // Inputting 'blank' spaces on the board
    
    for (int c = 0; c < 10; c++)
    {
        for (int d = 0; d < 10; d++)
        {
            layout[c][d] = '#';
        }
    }
    
    do
    {
        printf("Enter start point coordinates between 0 and 9: ");
        scanf("%i %i", &a, &b);
    }
    while ((a < 0 || a > 9) || (b < 0 || b > 9));
    
    do
    {
        printf("Enter end point coordinates between 0 and 9: ");
        scanf("%i %i", &x, &y);
    }
    while ((x < 0 || x > 9) || (y < 0 || y > 9));
    
    layout[x][y] = 'X';
    layout[a][b] = 'O';

    do
    {
        mapOutput(layout);
    }
    while (layout[a][b] != layout[x][y]);
    
    printf("Complete! Finished in %i turns.\n", counter);
    return 0;
}

void description(void)
{
    char selection;
    printf("Welcome to this simple game I created! The object of the game is to get to the 'X' mark using compass directions (N, S, E, W, etc.)\n");
    printf("You get to choose the start and end point within a 10 x 10 grid. The program will give you instructions on what values to input.\n");
    printf("\nAre you ready to play? Press Y to play or N to quit.\n");
    
    do
    {
        scanf("%c", &selection);
    }
    while (selection != 'Y' && selection != 'N');
    
    if (selection == 'N')
    {
        exit(1);
    }
}

int mapOutput(char layoutPrint[10][10])
{
    char direction;
    int finishA = a;
    int finishB = b;

    // Printing out the grid

    printf("\nYou are here (O), finish point is (X):\n\n");
    
    printf("     0  1  2  3  4  5  6  7  8  9  \n");
    printf("    -------------------------------\n");
    for (int i = 0; i < 10; i ++)
    {
        printf("%i |", i);
        for (int j = 0; j < 10; j++)
        {
            printf("%3c", layoutPrint[j][i]);
        }
        printf("\n");
    }
    printf("\n");
    
    // Selecting direction
    
    printf("Which direction would you like to go?: ");
    scanf("%c", &direction);
    
    switch (direction)
    {
        case 'W':
            if (layoutPrint[a - 1][b] < layoutPrint[0][b])
                {
                    printf("\n\nCannot go further West, try again.\n");
                    break;
                }
            else
                {
                    layoutPrint[a - 1][b] = layoutPrint[finishA][b];
                    layoutPrint[finishA][b] = '#';
                    a = finishA - 1;
                    counter++;
                    break;
                }
        
        case 'E':
            if ((a + 1) > 9)
                {
                    printf("\n\nCannot go further West, try again.\n");
                    break;
                }
            else
                {
                    layoutPrint[a + 1][b] = layoutPrint[finishA][b];
                    layoutPrint[finishA][b] = '#';
                    a = finishA + 1;
                    counter++;
                    break;
                }
        
        case 'N':
            if ((b - 1) < 0)
                {
                    printf("Can't go any further North, try again\n");
                    break;
                    
                }
            else
            {
                layoutPrint[a][b - 1] = layoutPrint[a][finishB];
                layoutPrint[a][finishB] = '#';
                b = finishB - 1;
                counter++;
                break;
            }
        
        case 'S':
            if ((b + 1) > 9)
            {
                printf("Cannot go any further South, try again\n");
                break;
            }
            else
            {
                layoutPrint[a][b + 1] = layoutPrint[a][finishB];
                layoutPrint[a][finishB] = '#';
                b = finishB + 1;
                counter++;
                break;
            }
    }
    return counter;
}

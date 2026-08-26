#include <stdio.h>
#define MAX 20

int stack[3][MAX];
int top[3] = {-1, -1, -1};

void push(int rod, int disk)
{
    top[rod]++;
    stack[rod][top[rod]] = disk;
}

int pop(int rod)
{
    int disk;

    disk = stack[rod][top[rod]];
    top[rod]--;

    return disk;
}

void move(int from, int to, char a, char b)
{
    int disk;

    disk = pop(from);
    push(to, disk);

    printf("Move disk %d from %c to %c\n", disk, a, b);
}

void legalMove(int from, int to, char a, char b)
{
    int disk1, disk2;

    if(top[from] == -1)
    {
        move(to, from, b, a);
    }
    else if(top[to] == -1)
    {
        move(from, to, a, b);
    }
    else
    {
        disk1 = stack[from][top[from]];
        disk2 = stack[to][top[to]];

        if(disk1 < disk2)
        {
            move(from, to, a, b);
        }
        else
        {
            move(to, from, b, a);
        }
    }
}

int main()
{
    int n, i;
    int totalMoves;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    for(i = n; i >= 1; i--)
    {
        push(0, i);
    }

    totalMoves = (1 << n) - 1;

    if(n % 2 != 0)
    {
        for(i = 1; i <= totalMoves; i++)
        {
            if(i % 3 == 1)
                legalMove(0, 2, 'A', 'C');

            else if(i % 3 == 2)
                legalMove(0, 1, 'A', 'B');

            else
                legalMove(1, 2, 'B', 'C');
        }
    }

    else
    {
        for(i = 1; i <= totalMoves; i++)
        {
            if(i % 3 == 1)
                legalMove(0, 1, 'A', 'B');

            else if(i % 3 == 2)
                legalMove(0, 2, 'A', 'C');

            else
                legalMove(1, 2, 'B', 'C');
        }
    }

    return 0;
}

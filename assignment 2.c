#include <stdio.h>

void mataccept(int A[10][10], int r, int c);
void compact(int A[10][10], int B[10][10], int r, int c);
void printCompact(int B[10][10]);

void mataccept(int A[10][10],int r,int c)
{
    printf("Enter the matrix elements:");

    for (int i = 0;i< r;i++)
    {
        for (int j = 0;j < c;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
}

void display(int A[10][10],int r,int c)
{
    int i,j;
    for(i = 0;i < r;i++)
    {
        for(j = 0;j < c;j++)
        {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }
}

void compact(int A[10][10],int B[10][10],int r,int c)
{
    B[0][0]=r;
    B[0][1]=c;

    int k=1;

    for (int i =0;i< r;i++)
    {
        for (int j=0; j<c;j++)
        {
            if (A[i][j] != 0)
            {
                B[k][0] = i;
                B[k][1] = j;
                B[k][2] = A[i][j];
                k++;
            }
        }
    }

    B[0][2]=k-1;   
}


int main()
{
    int A[10][10],B[10][10];
    int r,c;

    printf("Enter rows and columns: ");
    scanf("%d %d",&r,&c);

    mataccept(A,r,c);

    display(A,r,c);          

    printf("Compact Representation:");
    display(B,B[0][2],3); 


    return 0;
}
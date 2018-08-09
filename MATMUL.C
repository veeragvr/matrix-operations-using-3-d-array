#include<stdio.h>
#include<process.h>
#include<conio.h>

struct order
{
int r,c;
};



void accept(int a[8][5][5],int r,int c,int n)
{
int i,j;

for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
printf("\n ENTER ELEMENT [%d][%d] : ",i,j);
scanf("%d",&a[n][i][j]);
}
}

}

void display(int a[8][5][5],int r,int c,int n)
{
int i,j;

for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
printf("\t %d",a[n][i][j]);
}
printf("\n");
}
}

void multi(int a[8][5][5],int r1,int c1,int r2,int c2,int n1,int n2,int n3,struct order s[10])
{
int i,j,k;

for(i=0;i<r1;i++)
{
for(j=0;j<c2;j++)
{
a[n3][i][j]=0;
for(k=0;((k<r2)||(k<c1));k++)
{
a[n3][i][j]=a[n3][i][j]+(a[n1][i][k]*a[n2][k][j]);
}
}
}

s[n3].r=r1;
s[n3].c=c2;

}


void addt(int a[8][5][5],int r1,int c1,int n1,int n2,int n3,struct order s[10])
{
int i,j;

for(i=0;i<r1;i++)
{
for(j=0;j<c1;j++)
{
a[n3][i][j]=a[n1][i][j]+a[n2][i][j];

}
}
s[n3].r=r1;
s[n3].c=c1;

}


void subt(int a[8][5][5],int r1,int c1,int n1,int n2,int n3,struct order s[10])
{
int i,j;

for(i=0;i<r1;i++)
{
for(j=0;j<c1;j++)
{
a[n3][i][j]=a[n1][i][j]-a[n2][i][j];

}

}
s[n3].r=r1;
s[n3].c=c1;

}



void main()
{

int a[8][5][5],i,j,n=0;
struct order s[10];
int ch=1;
char c;
clrscr();


while(ch!=0)
{
if(n==0)
{

printf("\n ENTER NO. OF ROWS AND COLUMNS OF TWO MATRICES: ");
scanf("%d%d%d%d",&s[n].r,&s[n].c,&s[n+1].r,&s[n+1].c);



printf("\n ENTER MATRIX %d ",n);
accept(a,s[n].r,s[n].c,n);
display(a,s[n].r,s[n].c,n);
n++;

printf("\n ENTER MATRIX %d ",n);
accept(a,s[n].r,s[n].c,n);
display(a,s[n].r,s[n].c,n);
n++;

printf("\n ENTER OPERATION TO BE MADE : ");
scanf("%s",&c);

if(c=='*')
{

if(s[n].c!=s[n+1].r)
{
printf("\n MATRIX CANNOT BE MULTIPLIED ");
exit(0);
}

printf("\n  MATRIX %d * MATRIX %d :\n  ",n-2,n-1);
multi(a,s[n-2].r,s[n-2].c,s[n-1].r,s[n-1].c,n-2,n-1,n,s);
display(a,s[n].r,s[n].c,n);
n++;
}


if((s[n-2].r==s[n-1].r)&&(s[n-2].c==s[n-1].c))
{

if(c=='+')
{
printf("\n  MATRIX %d + MATRIX %d :\n  ",n-2,n-1);
addt(a,s[n-2].r,s[n-2].c,n-2,n-1,n,s);
display(a,s[n].r,s[n].c,n);
n++;
}

else if(c=='-')
{
printf("\n  MATRIX %d - MATRIX %d :\n  ",n-2,n-1);
subt(a,s[n-2].r,s[n-2].c,n-2,n-1,n,s);
display(a,s[n].r,s[n].c,n);
n++;
}

}
else
exit(0);

}






else
{

printf("\n ENTER NO. OF ROWS AND COLUMNS OF  MATRIX %d : ",n);
scanf("%d%d",&s[n].r,&s[n].c);


printf("\n ENTER MATRIX %d ",n);
accept(a,s[n].r,s[n].c,n);
display(a,s[n].r,s[n].c,n);


printf("\n ENTER OPERATION TO BE MADE : ");
scanf("%s",&c);

if(c=='*')
{
if(s[n-1].c!=s[n].r)
{
printf("\n MATRIX CANNOT BE MULTIPLIED ");
exit(0);
}

printf("\n  MATRIX %d * MATRIX %d :\n  ",n-1,n);
multi(a,s[n-1].r,s[n-1].c,s[n].r,s[n].c,n-1,n,n+1,s);
display(a,s[n+1].r,s[n+1].c,n+1);
n=n+2;
}

if((s[n-1].r==s[n].r)&&(s[n-1].c==s[n].c))
{

if(c=='+')
{
printf("\n  MATRIX %d + MATRIX %d :\n  ",n-1,n);
addt(a,s[n-1].r,s[n-1].c,n-1,n,n+1,s);
display(a,s[n+1].r,s[n+1].c,n+1);
n=n+2;
}

else if(c=='-')
{
printf("\n  MATRIX %d - MATRIX %d :\n  ",n-1,n);
subt(a,s[n-1].r,s[n-1].c,n-1,n,n+1,s);
display(a,s[n+1].r,s[n+1].c,n);
n=n+2;
}

else
exit(0);
}



}


printf("\n DO YOU WANT TO CONTINUE(0 to exit) : ");
scanf("%d",&ch);
getch();

}
getch();

}



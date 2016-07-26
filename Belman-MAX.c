#include <stdio.h>

int main()
{
	
	int A[20][20];
	int V[20][20];
	int L[20];
	int i , j ,n,k=1,arc,cr,p,min,r,in,fin,ch,max;



	printf("Introdu numarul de virfuri : "); scanf("%d",&n);
	printf("Introdu numarul de arce: "); scanf("%d",&arc);
	
	for(i=0;i<20;i++)
	for(j=0;j<20;j++)
		A[i][j]=-1000;
	for(i=0;i<20;i++)
		A[i][i]=0;

	for(k=0;k<arc;k++)
	{
		printf("\r\nIntrodu originea->extrimitatea si ponderea\r\n");
		printf("Originea -> "); scanf("%d",&i);
		printf("Extrimitatea -> "); scanf("%d",&j);
		printf("Ponderea ->"); scanf("%d",&p);
		A[i-1][j-1]=p;

	}

p1:

	

		for(i=0;i<20;i++)
			L[i]=0;

	

		printf("\r\n\n introdu virful initial : ");
	scanf("%d",&in);
	printf("\r\n introdu virful final : ");
	scanf("%d",&fin);
	in--;
	fin--;

	
	


	for(i=0;i<=fin;i++)
		V[0][i]=A[i][fin];

		
		k=1;

	do
	{
		cr=0;

		for(i=0;i<=fin;i++)
		{	
			max=-1000;

		for(j=0;j<=fin;j++)
		{
			if(i==j) continue;
		if(A[i][j]+V[k-1][j]>max ) max=A[i][j]+V[k-1][j];
		 }


		V[k][i]=max;

		}

		V[k][fin]=0;

		for(i=0;i<=fin;i++)
		if(V[k][i]!=V[k-1][i])
			{cr=1; break;}

		k++;


	}while(cr==1);

	k--;


	for(i=0;i<20;i++)
			L[i]=0;



	r=0;
	i=in;
	j=0;
		L[r++]=i+1;
		

		for(;i!=fin;)
		{
			if (i==j) j++; 
			if(V[k][i]-A[i][j]==V[k][j])
				{L[r++]=j+1; i=j; j=0; }
			else
			j++; 

		}
		L[r]=V[k][in]-V[k][fin];

	

	printf("\r\n Drumul este : ");

	for(i=0;L[i+1]!=0;i++)
	{
	printf("%d",L[i]);
	if(L[i+2]!=0) printf("->");
	}

	printf("\r\n Lungimea drumului : ");
	printf("%d",L[i]);
	
	goto p1;


}
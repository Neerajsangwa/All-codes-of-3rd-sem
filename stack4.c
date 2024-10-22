#include<stdio.h>
#include<math.h>
void th(int n , char from , char to , char aux)
{
	if ( n == 1)
	{
		printf("Move the disk 1 from %c to %c .\n", from , to);
		return ;
	}
	th ( n-1 , from , aux  , to );
	
	printf ( "move the disk %d from %c to %c \n", n , from , to );
	
	th(n-1 , aux , to , from);
}
int main()
{
	int n  ;
	 printf("Enter the number of disks :");
	 scanf("%d", &n);
	 th ( n,'A' , 'C' , 'B');
	 printf("\n");
	 int k = pow(2 , n) -1 ;
	 printf("Total number of moves : %d", k);
	 
	 return 0;
}

WITHOUT RECURSION 



#include<stdio.h>
int fact_loop(int num); //function declaration

//int fact_loop(int ); YES allowed

int main()
{
int num;
int result;
printf("Enter the number :");
scanf("%d", &num);
result=fact_loop(num); //function call (actual argument)
printf("Result =%d \n", result);
return 0;
}

int fact_loop(int n)
{
int i, ans =1;
for(i=1;i<=n;i++)
{
ans =ans*i;//1 2 6 24

}



WITH RECURSION 

  #include<stdio.h>

int fact_rec(int num); //function declaration

int main()
{
int num;

int result;

printf("Enter the number :");

scanf("%d", &num);

result = fact_rec(num); //function call

printf("Result =%d \n",result);

return 0;

}
int fact_rec(int num)

{


return ans;
}

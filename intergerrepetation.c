/******************************************************************************
 Given three integers x,y and z you need to find the all the possible combination of numbers having 4 at most x times, having 5 at most y times and having 6 at most z times as a digit.
 Example:-
input x=1,y=1,z=1
output

4
5
6
45
54
56
65
46
64
456
465
546
564
645
654


*******************************************************************************/

#include <stdio.h>
#include <math.h>
#define BASE 10
int main()
{
    int x,y,z,j,t;
    long long num, n;
    int i, lastDigit;
    int freq[BASE];
    printf("Enter frequncy of x y and  z");
    scanf("%d %d %d", &x,&y,&z);
    t=x+y+z;

    for(j=1;j<(6*pow(10,t));j++)
    {
    /* Input number from user */
   // printf("Enter any number: ");
    //scanf("%lld", &num);
    
    /* Initialize frequency array with 0 */
    for(i=0; i<BASE; i++)
    {
        freq[i] = -10;
       // printf("%d",freq[i]);
    }

    /* Copy the value of 'num' to 'n' */
    num = j;
    n = num; 

    /* Run till 'n' is not equal to zero */
    while(n != 0)
    {
        /* Get last digit */
        lastDigit = n % 10;

        /* Remove last digit */
        n /= 10;

        /* Increment frequency array */
        if(lastDigit==4 || lastDigit==5 || lastDigit==6)
        {
                if(freq[lastDigit]==-10)
                    freq[lastDigit] = -1;
                freq[lastDigit]++;
        }
        else
        {
                num=-1;
                break;
        }
    }
    if(freq[4] ==(x-1) && freq[5]==-10 && freq[6] == -10 && num>0)
        printf(" %d\n",num);
    if(freq[5] ==(y-1) && freq[4]==-10 && freq[6] == -10 && num>0)
        printf(" %d\n",num);
    if(freq[6] ==(z-1) && freq[5]==-10 && freq[4] == -10 && num>0)
        printf(" %d\n",num);
    if(freq[4] ==(x-1) && freq[5]==(y-1) && freq[6]==-10 && num>0)
        printf(" %d\n",num);
    if(freq[5] ==(y-1) && freq[6]==(z-1) && freq[4]==-10 && num>0)
        printf(" %d\n",num);
    if(freq[6] ==(z-1) && freq[4]==(x-1) && freq[5]==-10 && num>0)
        printf(" %d\n",num);
    if(freq[4]==(x-1) && freq[5]==(y-1) && freq[6]==(z-1) && num>0)
        printf(" %d\n",num);
    }
        
    
    return 0;
}

#include <stdio.h>

int count (int i) ;

int main(void)
{

do {
count(0);
}
while(!kbhit());
printf("count called %d times", count (1));
return 0;
}

int count (int i)
{
static int c=0;

if(i) return c;
else c++;
return 0;
}
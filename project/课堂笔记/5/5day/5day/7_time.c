#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{   
    struct tm *pt;
    time_t tm1, tm2;
    tm1 = time(&tm2);
    printf("%ld %ld \n", tm1, tm2);

    printf("%s", ctime(&tm1));
    printf("%s", ctime(&tm2));

    pt = localtime(&tm1);
    printf("%4d-%02d-%2d %02d:%02d:%02d 星期%d\n",
      pt->tm_year+1900, pt->tm_mon+1, pt->tm_mday,
      pt->tm_hour, pt->tm_min, pt->tm_sec, pt->tm_wday);

    
    return 0;


}

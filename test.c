#include <wiringPi.h>
#include <wiringSerial.h>
#include <stdio.h>
#include <unistd.h>

#define COMPORT "/dev/serial0"
#define COUNT 10
int main(void)
{
	  int fd;
	    if(wiringPiSetupSys() < 0) 
		      {
			            printf("init sys fail\n");
				          return 1;
					    }
	      if((fd = serialOpen(COMPORT,115200)) < 0 ) 
		        {
				      printf("open serial fail\n");
				            return 1;
					      }
	       int count = 0;
	        while( count < COUNT)
			 {
				    serialPuts(fd,"123");
				       sleep(1);
				          count ++;
					   }
		serialClose(fd);
}

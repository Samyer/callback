#include<stdio.h>
#include "callback.h"
void register_alarm(alarm a){
	int index=0;
	while(alarm_list[index]!=NULL)
		index++;
   if(index<MAX_ALARMS)
   {
	   alarm_list[index++] = a;
   }
   else
   {
	   alarm_list[MAX_ALARMS-1]=a;
   }
}

int hit_alarm(int index){
   if ( index < 0 || index >= MAX_ALARMS)
      return 1;
  if(alarm_list[index]!=NULL)
  {
	  (*alarm_list[index])(index);
   return 0;
  }
  else
	  return 1;
}
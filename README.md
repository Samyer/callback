# callback函数
#C 语言中经常使用函数指针来实现函数的回调，callback 操作在 Linux C 程序开发中非常常见。
#本挑战中包含一个 callback 的实现，但使用中我们发现存在一些 BUG，请直接在源文件中调试并修复 BUG，使其可以正常使用。

#两个关键函数的作用：
register_alarm(alarm)：注册新的 alarm 到 alarm_list 中
hit_alarm(index)：触发 alarm_list 中指定 index 的 alarm
修复 BUG 之后，仍然需要在代码中补充两个异常处理：
在 register_alarm(alarm) 中，如果注册的 alarm 数量超过了 alarm_list 容量，register_alarm(index) 不应该报错，继续执行。
在 hit_alarm(index) 中，如果对应的 alarm_list[index] 没有任何 alarm 注册，hit_alarm(index) 需要返回 1（return 1;）。

#源代码
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

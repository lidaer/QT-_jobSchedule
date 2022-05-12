#ifndef JOBSCHEDULE_H
#define JOBSCHEDULE_H
#include"pcb.h"
#include<QString>

class jobSchedule
{
public:

    pcb *jobHead;

    jobSchedule();
    int getJobLength();
    void addJob(string name,int arrive,int service);
    pcb *getRandomJob();   //获取一个随机字母
    bool addRandJobs();        //随机生成一个进程
    void initFlag();       //将flag标记都置为0
    void clear();          //清空进程
};

#endif // JOBSCHEDULE_H

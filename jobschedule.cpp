#include "jobschedule.h"
#include<QDateTime>
#include<QString>


jobSchedule::jobSchedule()
{
    jobHead=new pcb;
    jobHead->next=nullptr;
}

int jobSchedule::getJobLength(){
    pcb* p=new pcb;
    p->next=nullptr;
    p=jobHead->next;
    int n=0;
    while(p){
        n++;
        p=p->next;
    }
    return n;
}

//添加一个进程
void jobSchedule::addJob(string name,int arrive,int service){

    pcb *p=new pcb;
    p=jobHead->next;
    while(p->next) p=p->next;  //找到尾结点
    pcb *q=new pcb;
    q->next=nullptr;
    q->name=name;
    q->arrive=arrive;
    q->service=service;
    //尾插
    q->next=p->next;
    p->next=q;
}

//随机获取一个进程
pcb *jobSchedule::getRandomJob()
{
    qsrand(QDateTime::currentMSecsSinceEpoch());//为随机值设定一个seed

    const char chrs[] = "abcdefghijklmnopqrstuvwxyz";
    int chrs_size = sizeof(chrs);
    int randomx = 0;

    randomx= rand() % (chrs_size - 1);
    char ch= chrs[randomx];

    QString Qstr(ch);

    pcb *p=new pcb;
    p->next=nullptr;
    p->name=Qstr.toStdString();  //取随机生成的字母作为进程名

    //检测是否存在同名的进程名，若存在则返回空指针
    pcb *q=new pcb;
    q=jobHead->next;
    while(q){
        if(q->name==Qstr.toStdString()) return nullptr;
        q=q->next;
    }
    delete q;

    p->arrive=rand()%100;   //取0到100的随机数作为进程到达时间
    p->service=rand()%99+1;   //取1到100的随机数作为进程服务时间
    return p;
}

//随机添加五个进程
bool jobSchedule::addRandJobs(){
    int i=1;
    while(i<=5){
        pcb *q=new pcb;
        q->next=nullptr;
        q=getRandomJob();
        if(q!=nullptr){
            q->next=jobHead->next;
            jobHead->next=q;          //头插
            i++;
        }
        q=nullptr;
        delete q;
    }

}

void jobSchedule::initFlag(){
    pcb *p=new pcb;
    p=jobHead->next;
    while(p){
        p->flag=0;
        p=p->next;
    }
}

void jobSchedule::clear(){
    pcb *p=jobHead->next;
    pcb *q;
    while(p!=nullptr){
        q=p->next;
        delete p;
        p=q;
    }
    jobHead->next=nullptr;
}



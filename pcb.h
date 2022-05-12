#ifndef PCB_H
#define PCB_H

#include<iostream>
#include<string>
using namespace std;

struct pcb
{
    string name; //名称
    int service;    //服务时间
    int finish;    //结束时间
    int arrive;  //到达时间
    float response;   //响应比
    int turnaround;      //周转时间
    float weightedturnaround;   //带权周转时间
    bool flag=0;         //是否已服务的标记
    pcb* next;
};


#endif // PCB_H

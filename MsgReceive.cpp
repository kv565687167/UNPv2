/*
 * MsgReceive.cpp
 *
 *  Created on: 2013-7-8
 *      Author: root
 */
#include <sys/stat.h>
#include <fcntl.h>
#include <mqueue.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
	mqd_t mqd;
	struct mq_attr attr;
	char* buff;
	uint32_t prio;
	ssize_t n;
	mqd=mq_open("/a",O_RDONLY);
	mq_getattr(mqd,&attr);
	buff=(char*)malloc(attr.mq_msgsize);
	n=mq_receive(mqd,buff,attr.mq_msgsize,&prio);
	printf("read %ld bytes,priority =%u\n",(long)n,prio);
}




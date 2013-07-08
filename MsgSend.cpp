/*
 * MsgSend.cpp
 *
 *  Created on: 2013-7-8
 *      Author: root
 */
#include <sys/stat.h>
#include <fcntl.h>
#include <mqueue.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	mqd_t mqd;
	struct mq_attr attr;
	int result;
	void* ptr;
	mqd=mq_open("/a",O_CREAT|O_EXCL,NULL,NULL);
	if(mqd==-1)
		mqd=mq_open("/a",O_WRONLY);
	else
		printf("success\n");
	mq_getattr(mqd,&attr);
	ptr=calloc(10,sizeof(char));
	result=mq_send(mqd,(char*)ptr,10,10);
	if(result==-1)
		perror("error1:");
	else
		printf("success1\n");

}





/****************************************************************
    > File Name: save_info.c
    > Author: bigh
    > Mail: hanleisky@gmail.com 
    > Created Time: Thu 09 May 2013 09:08:16 PM CST
 ******************************************************************/


#include"common.h"

extern stu_node_t *stu_head;

save_stu_info()
{	
	char c,cc;
	FILE *fp =  NULL;
	stu_node_t *p = NULL;

	system("clear");
	printf("\n\n\n\n\t\t**************Save data************\n\n\n\n");
	printf("\n\n\t\tSave your data?(y/n) :");

	//get user's choise
	scanf("%c",&c);
	getchar();

	//to save
	if(c == 'y')
	{
		//open file in writable mode
		fp = fopen("stu_db","w");	

		if(fp == NULL)
		{
			printf("fopen error\n");
			exit(-1);
		}

		//write link to file
		for(p = stu_head; p!=NULL; p=p->next)
		{

			fprintf(fp,"%d %s %s %d %d %d %d %d %d %d\n",p->stu.id,p->stu.name,p->stu.passwd,p->stu.age,p->stu.grade,p->stu.score.math,p->stu.score.c,p->stu.score.chinese,p->stu.score.ave,p->stu.score.rank);

		}
		
		fclose(fp);


		printf("\n\t\tSaved,exiting\n\n\n\n");
			//system("clear");
		exit(-1);
	}

	//to not save
	else
	{
		printf("\n\n\t\tData not saved, your sure?(y/n) :");
		scanf("%c",&cc);
		getchar();

		//make sure to save or not
		if(c == 'y')
		{
			//system("clear");
			exit(-1);
		}

			//get back to save
		else
			save_stu_info;
	}
	
}

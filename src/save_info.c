/****************************************************************
    > File Name: save_info.c
    > Author: bigh
    > Mail: hanleisky@gmail.com 
    > Created Time: Thu 09 May 2013 09:08:16 PM CST
 ******************************************************************/


#include"common.h"

extern stu_node_t *stu_head;
extern tch_node_t *tch_head;

void save_info()
{	
	char c;
	FILE *sfp =  NULL;
	FILE *tfp = NULL;
	stu_node_t *sp = NULL;
	tch_node_t *tp = NULL;


	if(stu_head!=NULL || tch_head!=NULL)
	{

		c = meanu_save_info();	
			//to save
		if(c == 'y')
		{
			//open file in writable mode
			sfp = fopen("stu_db","w");	
			tfp = fopen("tch_db","w");

			if(sfp == NULL || tfp == NULL)
			{
				printf("fopen error\n");
				exit(-1);
			}

			//write student's info to file
			for(sp = stu_head; sp!=NULL; sp=sp->next)
			{

				fprintf(sfp,"%d %s %s %d %d %d %d %d %d %d\n",sp->stu.id,sp->stu.name,sp->stu.passwd,sp->stu.age,sp->stu.grade,sp->stu.score.math,sp->stu.score.c,sp->stu.score.chinese,sp->stu.score.ave,sp->stu.score.rank);

			}

			for(tp= tch_head; tp!=NULL; tp=tp->next)
			{
				fprintf(tfp,"%d %s %s %d\n",tp->tch.id,tp->tch.name,tp->tch.passwd,tp->tch.grade);

			}
			
			fclose(sfp);
			fclose(tfp);


			printf("\n\t\tSaved,exiting\n\n\n\n\n\n\n\n");
				//system("clear");
			return;
			//exit(-1);
		}

		//to not save
		else
		{
			printf("\n\t\tNote saved,exiting\n\n\n\n\n\n\n\n");
				
			//system("clear");
			exit(-1);
		}


	}
	
}

#include"common.h"

extern stu_node_t *stu_head;
extern tch_node_t *tch_head;



int stu_login()
{

	//cause of selected student login,so load the students' info
	load_stu_info();

	int flag = 0;
	int get_id;
	char get_passwd[32];

	//mark the logging_in student's info and return it 
	stu_node_t *p = NULL;

	//get id
	printf("\nId:");
	scanf("%d",&get_id);
	getchar();

	//get passwd
	printf("\nPassword:");
	scanf("%s",get_passwd);
	getchar();

	//compare get_id get_passwd to current ones
	for(p=stu_head; p!=NULL; p=p->next)
	{
		if((p->stu.id - get_id)==0 && strcmp(p->stu.passwd,get_passwd)==0)
		{
			flag = 1;
			break;
		}
	}


	if(flag)
	{ 
		printf("login successfull\n");

		//jumt to manager func
		stu_manager(p);

	}
	else
	{
		static int error_count=0;
		error_count++;
		printf("error,re-input please\n");
		
		//count how many errors have been made
		if(error_count >= 3)
		{
			printf("3 error token,exiting\n");
			return;
		}


		//re load this func to login
		flag = stu_login();
			
	}



}


int tch_login()
{

	//cause of selected teacher's login,so load the teachers' info
	load_tch_info();
	load_stu_info();

	int flag = 0;
	int get_id;
	char get_passwd[32];

	//mark the logging_in student's info and pass it next 
	tch_node_t *p = NULL;

	//get id
	printf("\nId:");
	scanf("%d",&get_id);
	getchar();

	//get passwd
	printf("\nPassword:");
	scanf("%s",get_passwd);
	getchar();

	//compare get_id get_passwd to current ones
	for(p=tch_head; p!=NULL; p=p->next)
	{
		if((p->tch.id - get_id)==0 && strcmp(p->tch.passwd,get_passwd)==0)
		{
			flag = 1;
			break;
		}
	}


	if(flag)
	{ 
		printf("login successfull\n");

		//jumt to manager func
		tch_manager(p);

	}
	else
	{
		static int error_count=0;
		error_count++;
		printf("error,re-input please\n");
		
		//count how many errors have been made
		if(error_count >= 3)
		{
			printf("3 error token,exiting\n");
			return;
		}


		//re load this func to login
		flag = tch_login();
			
	}



}



void show_about()
{
		system("clear");
		printf("\n\n\n\n\t\t******************About us*****************\n\n\n\n");
		printf("\t\t\t\tThis is MIS\n");
		printf("\n\n\n\n\n\n\n");
		getchar();
		return;

	
}


void login()
{
	int select_num;
	while(1)
	{
		system("clear");
		printf("\n\n\n\n\t\t******************Welcome to MIS*****************\n\n\n\n");
		printf("\t\t\t\t1.Students\n");
		printf("\t\t\t\t2.Teachers\n");
		printf("\t\t\t\t3.ADMIN\n\n\n"); 
		printf("\n\t\t\t\t0.Exit\n");
		printf("\n\n\n\n\t\t********************11.About*********************\n");

		//record user's select
		printf("\n\n\n\n:");
		scanf("%d",&select_num);
		getchar();

		switch (select_num)
		{
			case 1:
				stu_login();
				break;
			case 2:
				tch_login();
				break;
#if 0
			case 3:
				admin_login();
				break;
#endif

			case 11:
				show_about();
				break;
			case 0:
				return;
				break;
			default:
				printf("\nerror\n");
				login();
			
		}
	}

}



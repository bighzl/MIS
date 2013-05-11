#include"common.h"
#include"teacher.h"

extern stu_node_t *stu_head; 
extern tch_node_t *tch_head; 


void show_tch_info(tch_node_t *node) 
{ 
	int select_num; 
	system("clear"); 

	printf("\n\n\n\n\t\t**************Your information******************\n\n\n\n"); 
	printf("\n\n\t\tid\tname\tage\n\n\n"); 
	printf("\t\t%d\t%s\t%d\n",node->tch.id,node->tch.name,node->tch.age); 

#if 0 
	getchar(); 
	return; 
#endif

	printf("\n\n\n\t\t\t\t0.Back\n\n\n\n"); 
	printf("\t\t:");	
	scanf("%d",&select_num); 
	getchar(); 

	if(select_num == 0) 
		return; 
	else
		show_tch_info(node);


}



void edit_p_score()
{
	int select_num;
	stu_node_t *p = NULL;

	while(1)
	{

		system("clear");
		printf("\n\n\n\n\t\t**************Edit person scores******************\n\n\n\n");

		printf("\n\n\t\t\t\tid\tname\t\t\n\n\n");

		for(p = stu_head; p!=NULL; p=p->next)
		{
			printf("\t\t\t\t%d\t%-12s\n",p->stu.id,p->stu.name);
		}
		printf("\t\t\t\t");


		printf("input the id you wanna edit,or 0 for Back :");

		scanf("%d",&select_num);
		getchar();

		if(select_num == 0)
			return;

		for(p = stu_head; p!=NULL; p=p->next)
		{
			if(p->stu.id == select_num)
				break;
		}


		if(p == NULL)
			edit_p_score();
		printf("\t\t\t\tnew math score:");	
		scanf("%d",&p->stu.score.math);

		printf("\t\t\t\tnew math score:");	
		scanf("%d",&p->stu.score.c);

		printf("\t\t\t\tnew math score:");	
		scanf("%d",&p->stu.score.chinese);

		printf("\tEdit done!");
		return;

	}

}

void edit_c_score()
{
	int select_num;
	stu_node_t *p = NULL;

	while(1)
	{

		system("clear");
		printf("\n\n\n\n\t\t**************Edit course scores******************\n\n\n\n");

		printf("\n\n\n\t\t\t\t1.math\n\n\n\n");
		printf("\n\n\n\t\t\t\t2.c\n\n\n\n");
		printf("\n\n\n\t\t\t\t3.chinese\n\n\n\n");

		printf("\n\n\n\t\t\t\t0.Back\n\n\n\n");

		printf("\t\t :");

		scanf("%d",&select_num);
		getchar();

		switch (select_num)
		{
			case 1:
				for(p = stu_head; p!=NULL; p=p->next)
				{
					printf("\t\t\t\t%d's new math score:",p->stu.id);
					scanf("%d",&p->stu.score.math);
				}
			//	return;
				break;
			case 2:
				for(p = stu_head; p!=NULL; p=p->next)
				{
					printf("\t\t\t\t%d's new c score:",p->stu.id);
					scanf("%d",&p->stu.score.c);
				}
				return;
				break;
			case 3:
				for(p = stu_head; p!=NULL; p=p->next)
				{
					printf("\t\t\t\t%d's new chinese score:",p->stu.id);
					scanf("%d",&p->stu.score.chinese);
				}
				return;
				break;
			case 0:
				return;
				break;
		}

	}

}
#if 0
			printf("\t\tnew math score:");	
			scanf("%d",&p->stu.score.math);

			printf("\t\tnew math score:");	
			scanf("%d",&p->stu.score.c);

			printf("\t\tnew math score:");	
			scanf("%d",&p->stu.score.chinese);

			printf("\t\tEdit done!");
			return;
#endif

void edit_score()
{
	int select_num;

	while(1)
	{

		system("clear");
		printf("\n\n\n\n\t\t**************Edit scores******************\n\n\n\n");
		printf("\t\t\t\t1.Edit single Student scores\n");
		printf("\t\t\t\t2.Edit single course score\n");
		printf("\n\n\n\t\t\t\t0.Back\n\n\n\n");

		printf("\t\t:");	
		scanf("%d",&select_num);
		getchar();

#if 0
		printf("\n\n\n\n\t\t**************Edit scores******************\n\n\n\n");
		printf("\t\t\t\t1.Edit math score\n");
		printf("\t\t\t\t2.Edit c score\n");
		printf("\t\t\t\t3.Edit chinese score\n");
		printf("\n\n\n\t\t\t\t0.Back\n\n\n\n");

#endif

		switch (select_num)
		{
			case 1:
				edit_p_score();
				break;
			case 2:
				edit_c_score();
				break;
			case 0:
				return;
				break;
		}

	}
}

void tch_show_score(tch_node_t *node,int mode)
{

	int select_num;
	stu_node_t *p = NULL;

	//int count to count numbers to printed info
	int count=0;
	//sum to rec single course's total score;
	int sum=0;
	//ave to record single course's ave score;
	float ave=0;

	while(1)
	{
		system("clear");
		printf("\n\n\n\n\t\t**************Your scores******************\n\n\n\n");



		switch (mode)
		{
			case 2:

				//printf all  student's socre
				printf("\n\n\t\tid\tname\t\tmath\tc\tchinese\taverage\trank\n\n\n");
				for(p = stu_head; p!=NULL; p=p->next)
				{
					printf("\t\t%d\t%-12s\t%d\t%d\t%d\t%d\t%d\n",p->stu.id,p->stu.name,p->stu.score.math,p->stu.score.c,p->stu.score.chinese,p->stu.score.ave,p->stu.score.rank);

				}

				break;
			case 3:
				//printf all  student's socre
				printf("\n\n\t\tid\tname\t\tmath\n\n\n");
				for(p = stu_head; p!=NULL; p=p->next)
				{
					printf("\t\t%d\t%-12s\t%d\n",p->stu.id,p->stu.name,p->stu.score.math);
					count++;
					sum += (p->stu.score.math);

				}

				printf("\n\n\n");
				//count ave
				ave = (float)sum/count;
				printf("\t\t\tave");
				printf("\t\t%.2f",ave);	
				
				break;
			case 4:
				//printf all  student's socre
				printf("\n\n\t\tid\tname\t\tc\n\n\n");
				for(p = stu_head; p!=NULL; p=p->next)
				{
					printf("\t\t%d\t%-12s\t%d\n",p->stu.id,p->stu.name,p->stu.score.c);
					count++;
					sum += (p->stu.score.c);
				}

				printf("\n\n\n");
				//count ave
				ave = (float)sum/count;
				printf("\t\t\tave");
				printf("\t\t%.2f",ave);	

				break;
			case 5:
				//printf all  student's socre
				printf("\n\n\t\tid\tname\t\tchinese\n\n\n");
				for(p = stu_head; p!=NULL; p=p->next)
				{
					printf("\t\t%d\t%-12s\t%d\n",p->stu.id,p->stu.name,p->stu.score.chinese);
					count++;
					sum += (p->stu.score.chinese);
				}

				printf("\n\n\n");
				//count ave
				ave = (float)sum/count;
				printf("\t\t\tave");
				printf("\t\t%.2f",ave);	

				break;
		}



		printf("\n\n\n\n\n\t\t\t\t1.Edit\n\n\n\n");
		printf("\n\n\n\n\n\t\t\t\t0.Back\n\n\n\n");
		printf("\t\t:");	

		scanf("%d",&select_num);
		getchar();

		if(select_num == 0)
			return;
		else if(select_num == 1)
		{
			edit_score();
		}
		else
			tch_show_score(node,mode);


	}


}

void tch_reset_passwd(tch_node_t *node)
{
	char old_passwd[32];	
	char new_passwd[32];
	char new_passwd2[32];

	system("clear");
	printf("\n\n\n\n\t\t**************Reset Passwd************\n\n\n\n");

	printf("\t\tinput your old password:");
	scanf("%s",old_passwd);
	getchar();

	//compare the input passwd and current passwd
	if(strcmp(node->tch.passwd,old_passwd)!=0)
	{
		printf("\n\npassword error");
		tch_reset_passwd(node);
		return;
		//return is needed,in case of times of circle input;
	}

	printf("\n\n\t\tinput your new password:");
	scanf("%s",new_passwd);
	getchar();

	printf("\n\n\t\tRe-input your new password:");
	scanf("%s",new_passwd2);
	getchar();
	
	//compare two input new passwd
	if(strcmp(new_passwd,new_passwd2)!=0)
	{
		printf("\n\nnew password not the same");
		tch_reset_passwd(node);
		return;
		//same as the previous one
	}

	//set new passwd
	strcpy(node->tch.passwd,new_passwd);
	printf("your new passwd is : %s",new_passwd);


}






void tch_manager(tch_node_t *node)
{
	int select_num;
	while(1)
	{
		system("clear");
		printf("\n\n\n\n\t\t**************Welcome aboard****************\n\n\n\n");
		printf("\t\t\t\t1.Check your infomation\n");
		printf("\t\t\t\t2.Check class's score by id\n");
		printf("\t\t\t\t3.Check math score\n");
		printf("\t\t\t\t4.Check C score\n");
		printf("\t\t\t\t5.Check chinese score\n");
		printf("\t\t\t\t6.Edit students' score\n");
		printf("\t\t\t\t7.Reset your password\n\n\n");
		printf("\t\t\t\t0.Back\n\n\n\n");
		
		printf("\t\t:");
		scanf("%d",&select_num);
		getchar();

		switch(select_num)
		{
			case 1:
				show_tch_info(node);
				break;
			case 2:
				tch_show_score(node,2);
				break;
			case 3:
				tch_show_score(node,3);
				break;
			case 4:
				tch_show_score(node,4);
				break;
			case 5:
				tch_show_score(node,5);
				break;
			case 6:
				edit_score();
				break;
			case 7:
				tch_reset_passwd(node);
				break;
			case 0:
				return;
				break;

		}

	}
}

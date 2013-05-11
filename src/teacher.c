#include"common.h"
#include"teacher.h"

extern stu_node_t *stu_head; 
extern tch_node_t *tch_head; 


void show_tch_info(tch_node_t *node) 
{ 
	int select_num; 
	system("clear"); 

	printf("\n\n\n\n\t\t**************Your information******************\n\n\n\n"); 
	printf("\n\n\t\tid\tname\tgrade\n\n\n"); 
	printf("\t\t%d\t%s\t%d\n",node->tch.id,node->tch.name,node->tch.grade); 

#if 0 
	getchar(); 
	return; 
#endif

	printf("\n\n\n\t\t0.Back\n\n"); 
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
		select_num = meanu_edit_p_score();

		if(select_num == 0)
			return;

		for(p = stu_head; p!=NULL; p=p->next)
		{
			if(p->stu.id == select_num)
				break;
		}


		if(p == NULL)
			edit_p_score();
		printf("\t\tnew math score:");	
		scanf("%d",&p->stu.score.math);

		printf("\t\tnew c score:");	
		scanf("%d",&p->stu.score.c);

		printf("\t\tnew chinese score:");	
		scanf("%d",&p->stu.score.chinese);

		printf("\t\tEdit done!");
		return;

	}

}

void edit_c_score()
{
	int select_num;
	stu_node_t *p = NULL;

	while(1)
	{
		select_num = meanu_edit_c_score();

		switch (select_num)
		{
			case 1:
				for(p = stu_head; p!=NULL; p=p->next)
				{
					printf("\t\t%d's new math score:",p->stu.id);
					scanf("%d",&p->stu.score.math);
				}
			//	return;
				break;
			case 2:
				for(p = stu_head; p!=NULL; p=p->next)
				{
					printf("\t\t%d's new c score:",p->stu.id);
					scanf("%d",&p->stu.score.c);
				}
				return;
				break;
			case 3:
				for(p = stu_head; p!=NULL; p=p->next)
				{
					printf("\t\t%d's new chinese score:",p->stu.id);
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



void edit_score()
{
	int select_num;

	while(1)
	{
		select_num = meanu_edit_score();
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
				//printf student's math socre
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
				printf("\t\tave");
				printf("\t\t\t%.2f",ave);	
				
				break;
			case 4:
				//printf student's c socre
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
				printf("\t\tave");
				printf("\t\t\t%.2f",ave);	

				break;
			case 5:
				//printf student's chinese socre
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
				printf("\t\tave");
				printf("\t\t\t%.2f",ave);	

				break;
		}



		printf("\n\n\t\t1.Edit");
		printf("\n\n\t\t0.Back");
		printf("\n\n\t\t:");	

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
		printf("\n\n\t\tpassword error");
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
		printf("\n\n\t\tnew password not the same");
		tch_reset_passwd(node);
		return;
		//same as the previous one
	}

	//set new passwd
	strcpy(node->tch.passwd,new_passwd);
	printf("\n\n\t\tyour new passwd is : %s",new_passwd);


}






void tch_manager(tch_node_t *node)
{
	int select_num;
	while(1)
	{
		select_num = meanu_tch_manager();
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

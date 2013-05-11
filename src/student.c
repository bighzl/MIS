#include"common.h"
#include"student.h"

extern stu_node_t *stu_head;
extern tch_node_t *tch_head;

void show_stu_info(stu_node_t *node)
{
	int select_num;
	
	system("clear");
	printf("\n\n\n\n\t\t**************Your information******************\n\n\n\n");
	printf("\n\n\t\tid\tname\tage\tgrade\n\n\n");
	printf("\t\t%d\t%s\t%d\t%d\n",node->stu.id,node->stu.name,node->stu.age,node->stu.grade);


	printf("\n\n\n\t\t\t\t0.Back\n\n\n\n");
	
	printf("\t\t:");	
	scanf("%d",&select_num);
	getchar();

	if(select_num == 0)
		return;
	else
		show_stu_info(node);




}
void show_score(stu_node_t *node)
{

	int select_num;

	system("clear");
	printf("\n\n\n\n\t\t**************Your scores******************\n\n\n\n");

	printf("\n\n\t\tmath\tc\tchinese\taverage\trank\n\n\n");
	printf("\t\t%d\t%d\t%d\t%d\t%d\n",node->stu.score.math,node->stu.score.c,node->stu.score.chinese,node->stu.score.ave,node->stu.score.rank);

	printf("\n\n\n\t\t\t\t0.Back\n\n\n\n");
	printf("\t\t:");	
	scanf("%d",&select_num);
	getchar();

	if(select_num == 0)
		return;
	else
		show_score(node);



}

void stu_reset_passwd(stu_node_t *node)
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
	if(strcmp(node->stu.passwd,old_passwd)!=0)
	{
		printf("\n\npassword error");
		stu_reset_passwd(node);
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
		stu_reset_passwd(node);
		return;
		//same as the previous one
	}

	//set new passwd
	strcpy(node->stu.passwd,new_passwd);
	printf("your new passwd is : %s",new_passwd);


}



void stu_manager(stu_node_t *node)
{
	int select_num;
	while(1)
	{
		system("clear");
		printf("\n\n\n\n\t\t**************Welcome aboard****************\n\n\n\n");
		printf("\t\t\t\t1.Check your infomation\n");
		printf("\t\t\t\t2.Check your score\n");
		printf("\t\t\t\t3.Reset your password\n\n\n");
		printf("\t\t\t\t0.Back\n\n\n\n");
		
		printf("\t\t:");
		scanf("%d",&select_num);
		getchar();

		switch(select_num)
		{
			case 1:
				show_stu_info(node);
				break;
			case 2:
				show_score(node);
				break;
			case 3:
				stu_reset_passwd(node);
				break;
			case 0:
				return;
				break;

		}

	}
}




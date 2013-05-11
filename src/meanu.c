#include"common.h"

extern stu_node_t *stu_head; 
extern tch_node_t *tch_head; 


/*********UI func**************/

void clear_meanu()
{
	system("clear");
	printf("\n\n\n\n\t\t******************Welcome to MIS*****************\n\n\n\n");
}

int meanu_main_login()
{
	int select_num;

	system("clear");
	printf("\n\n\n\n\t\t******************Welcome to MIS*****************\n\n\n\n");
	printf("\t\t1.Students\n\n");
	printf("\t\t2.Teachers\n\n");
	printf("\t\t3.ADMIN\n\n\n"); 
	printf("\t\t0.Exit\n");
	printf("\n\n\n\n\t\t********************11.About*********************\n");

	//record user's select
	printf("\n\n\n\t\t:");
	scanf("%d",&select_num);
	getchar();

	return select_num;
}


char meanu_save_info()
{
	char c;
	system("clear");
	printf("\n\n\n\n\t\t**************Save data************\n\n\n\n");
	printf("\n\n\t\tSave your data?(y/n) :");

	//get user's choise
	scanf("%c",&c);
	getchar();
	return c;


}


int meanu_stu_manager()
{
	int select_num;

	system("clear");
	printf("\n\n\n\n\t\t**************Welcome aboard****************\n\n\n\n");
	printf("\t\t1.Check your infomation\n\n");
	printf("\t\t2.Check your score\n\n");
	printf("\t\t3.Reset your password\n\n\n");
	printf("\t\t0.Back\n\n\n");
	
	//get user's choise and return it
	printf("\t\t:");
	scanf("%d",&select_num);
	getchar();

	return select_num;

}


int meanu_tch_manager()
{
	int select_num;

	system("clear");
	printf("\n\n\n\n\t\t**************Welcome aboard****************\n\n\n\n");
	printf("\t\t1.Check your infomation\n\n");
	printf("\t\t2.Check class's score by id\n\n");
	printf("\t\t3.Check math score\n\n");
	printf("\t\t4.Check C score\n\n");
	printf("\t\t5.Check chinese score\n\n");
	printf("\t\t6.Edit students' score\n\n");
	printf("\t\t7.Reset your password\n\n\n");
	printf("\t\t0.Back\n\n\n");
	
	//get user's choise,return it 
	printf("\t\t:");
	scanf("%d",&select_num);
	getchar();
	return select_num;

}


int meanu_edit_score()
{
	int select_num;

	system("clear");
	printf("\n\n\n\n\t\t**************Edit scores******************\n\n\n\n");
	printf("\t\t1.Edit single Student scores\n\n");
	printf("\t\t2.Edit single course score\n\n");
	printf("\n\n\t\t0.Back\n\n\n");

	printf("\t\t:");	
	scanf("%d",&select_num);
	getchar();

	return select_num;
#if 0
	printf("\n\n\n\n\t\t**************Edit scores******************\n\n\n\n");
	printf("\t\t\t\t1.Edit math score\n");
	printf("\t\t\t\t2.Edit c score\n");
	printf("\t\t\t\t3.Edit chinese score\n");
	printf("\n\n\n\t\t\t\t0.Back\n\n\n\n");

#endif


}


int meanu_edit_c_score()
{
	int select_num;

	system("clear");
	printf("\n\n\n\n\t\t**************Edit course scores******************\n\n\n\n");

	printf("\t\t1.math\n\n");
	printf("\t\t2.c\n\n");
	printf("\t\t3.chinese\n\n");

	printf("\n\t\t0.Back\n\n\n");

	printf("\t\t :");

	scanf("%d",&select_num);
	getchar();



	return select_num;
}


int meanu_edit_p_score()
{
	int select_num;	
	stu_node_t *p = NULL;

	system("clear");
	printf("\n\n\n\n\t\t**************Edit person scores******************\n\n\n\n");

	printf("\n\n\t\tid\tname\n\n");

	for(p = stu_head; p!=NULL; p=p->next)
	{
		printf("\t\t%d\t%-12s\n",p->stu.id,p->stu.name);
	}


	printf("\n\t\tinput the id you wanna edit,or 0 for Back :");

	scanf("%d",&select_num);
	getchar();

	return select_num;

}


int meanu_admin_manager()
{
	int select_num;

	system("clear");
	printf("\n\n\n\n\t\t***************Welcome Aboard*****************\n\n\n\n");

	printf("\t\t1.Check my infomation\n\n");
	printf("\t\t2.Edit students' info\n\n");
	printf("\t\t3.Edit teachers' info\n\n\n");
	printf("\t\t4.Reset my password\n\n");
	printf("\t\t0.Back\n\n\n");

	//get user's choise and return it
	printf("\t\t:");
	scanf("%d",&select_num);
	return select_num;
	


}



int meanu_edit_stu_info()
{
	int select_num;

	system("clear");
	printf("\n\n\n\n\t\t***************Edit Student Info*****************\n\n\n\n");

	printf("\t\t1.Add a student\n\n");
	printf("\t\t2.Del a student\n\n");
	printf("\t\t3.Edit student's profile\n\n\n");
	printf("\t\t0.Back\n\n\n");

	//get user's choise and return it
	printf("\t\t:");
	scanf("%d",&select_num);

	return select_num;

}
	


int meanu_edit_tch_info()
{
	int select_num;

	system("clear");
	printf("\n\n\n\n\t\t***************Edit Teacher Info*****************\n\n\n\n");

	printf("\t\t1.Add a teacher\n\n");
	printf("\t\t2.Del a teacher\n\n");
	printf("\t\t3.Edit teacher's profile\n\n\n");
	printf("\t\t0.Back\n\n\n");

	//get user's choise and return it
	printf("\t\t:");
	scanf("%d",&select_num);

	return select_num;

}
	


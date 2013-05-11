#include"common.h"

extern stu_node_t *stu_head;
extern tch_node_t *tch_head;

show_admin_info()
{
	clear_meanu();
	printf("\t\t################ You are Administrator ################");
	printf("\n\n\n\n\t\t");
	getchar();
	return;
}


void add_stu()
{
	stu_node_t node;

	printf();


	//*******use the func in load_info.c:8 **************//
	insert_stu_node(node);

}

void del_stu()
{

}

void edit_stu()
{
}

void edit_stu_info()
{
	int select_num;	
	while(1)
	{
		select_num = meanu_edit_stu_info();
		
		switch(select_num)
		{
			case 1:
				add_stu();
				break;

			case 2:
				del_stu();
				break;

			case 3:
				edit_stu();
				break;

			case 0:
				return;
				break;
			default:
				edit_stu_info();

		}

	}
}


void add_tch()
{
}

void del_tch()
{
}

void edit_tch()
{
}


void edit_tch_info()
{
	int select_num;	
	while(1)
	{
		select_num = meanu_edit_tch_info();
		
		switch(select_num)
		{
			case 1:
				add_tch();
				break;

			case 2:
				del_tch();
				break;

			case 3:
				edit_tch();
				break;

			case 0:
				return;
				break;
			
			default:
				edit_tch_info();

		}

	}

}



void admin_manager()
{
	int select_num;
	while(1)
	{
		select_num = meanu_admin_manager();

		switch(select_num)
		{

			case 1:
				show_admin_info();
				break;

			case 2:
				edit_stu_info();	
				break;

			case 3:
				edit_tch_info();
				break;

			case 4:
//				admin_reset_passwd();
				break;

			case 0:
				return;
				break;
		}
	}
}

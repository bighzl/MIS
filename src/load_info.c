#include"common.h"
#include"student.h"
#include"teacher.h"

extern stu_node_t *stu_head;
extern tch_node_t *tch_head;

void insert_stu_node(stu_node_t node)
{

	stu_node_t *to_add = NULL;
	to_add = (stu_node_t *)malloc(sizeof(stu_node_t));
	if(to_add == NULL)
	{
		printf("malloc error\n");
		exit(-1);
	}
	//struct whole copy
	*to_add = node;


	//make node's pointer to NULL
	to_add->pre = NULL;
	to_add->next = NULL;


	
	static stu_node_t *tail = NULL;
	//get_node_info(&node);

	//insert to link
	if(stu_head == NULL)
	{
		stu_head = to_add;
		tail = to_add;
	}
	else
	{
		tail->next = to_add;
		to_add->pre = tail;
		tail = to_add;
	}
	//for testing whether the info be read or not
//	printf("%d\n",tail->stu.id);

}



#if 0
void print_link(stu_node_t *head)
{
	stu_node_t *p = NULL;
	p = head;
	while(p != NULL)
	{
		printf("%s\n",p->stu.name);
		p = p->next;
		
	}

}

#endif 


void load_stu_info()
{
	int re;
//	int count=0;

	FILE *fp = NULL;

	//creat a node of stu
	stu_node_t node;
#if 0
	node = (stu_node_t *)malloc(sizeof(stu_node_t));
	if(node == NULL)
	{
		printf("malloc error\n");
		exit(-1);
	}
	//make node's pointer to NULL
	node->pre = NULL;
	node->next = NULL;


	
#endif

	//read infomation
	fp = fopen("stu_db","r");
	if(fp == NULL)
	{
		printf("fopen error\n");
		exit(-1);
	}
	while(1)
	{
		/*
		re = fscanf(fp,"%d %s %s",&node->stu.id,node->stu.name,node->stu.passwd);
		*/
		re = fscanf(fp,"%d %s %s %d %d %d %d %d %d %d",&node.stu.id,node.stu.name,node.stu.passwd,&node.stu.age,&node.stu.grade,&node.stu.score.math,&node.stu.score.c,&node.stu.score.chinese,&node.stu.score.ave,&node.stu.score.rank);

		//insert this node to link

		if(re <= 0)
			break;
//		count++;
		insert_stu_node(node);
	}
	fclose(fp);

//	print_link(stu_head);


}

void insert_tch_node(tch_node_t node)
{

#if 0
	//for debug
	getchar();

#endif




	tch_node_t *to_add = NULL;
	//malloc RAM for to_add
	to_add = (tch_node_t *)malloc(sizeof(tch_node_t));
	if(to_add == NULL)
	{
		printf("malloc error\n");
		exit(-1);
	}
	//struct whole copy
	*to_add = node;		

	//	*to_add = node;

	/* have a problem here 
	 *gcc give a notice that imcompatible types when assigning
	 *to type  tch_node_t from type int
	 */


	//make node's pointer to NULL
	to_add->pre = NULL;
	to_add->next = NULL;


	
	static tch_node_t *tail = NULL;
	//get_node_info(&node);

	//insert to link
	if(tch_head == NULL)
	{
		tch_head = to_add;
		tail = to_add;
	}
	else
	{
		tail->next = to_add;
		to_add->pre = tail;
		tail = to_add;
	}
	//for testing whether the info be read or not
	//printf("%d\n",tail->tch.id);


}

void load_tch_info()
{
	int re;
//	int count=0;

	FILE *fp = NULL;

	//creat a node of tch
	tch_node_t node;

	//read infomation
	fp = fopen("tch_db","r");
	if(fp == NULL)
	{
		printf("fopen error\n");
		exit(-1);
	}
	while(1)
	{


		//read it to node
		re = fscanf(fp,"%d %s %s %d",&node.tch.id,node.tch.name,node.tch.passwd,&node.tch.age);


		//insert this node to link

		if(re <= 0)
			break;
//		count++;
		insert_tch_node(node);
	}
	fclose(fp);

//	print_link(tch_head);


}

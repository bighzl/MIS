#include"common.h"

stu_node_t *stu_head=NULL;
tch_node_t *tch_head=NULL;

int main()
{
	//meanu()
	//****in meanu.c*******//
	load_stu_info();
	load_tch_info();

	login();

	save_info();

	return 0;
}

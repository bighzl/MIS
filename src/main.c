#include"common.h"

stu_node_t *stu_head=NULL;
tch_node_t *tch_head=NULL;

int main()
{
	login();

	save_stu_info();
	//save_tch_info();

	return 0;
}

#ifndef __STU_H__
#define __STU_H__
#include"common.h"



typedef struct stu_score
{
	int math;
	int c;
	int chinese;
	int ave;
	int rank;
}stu_score_t;


typedef struct student
{
	int id;
	char name[128];
	char passwd[32];
	int age;
	int grade;


	//how to handle this?
	stu_score_t score;

}stu_t;




#endif

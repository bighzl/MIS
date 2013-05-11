#ifndef __COMMON_H__
#define __COMMON_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"student.h"
#include"teacher.h"

typedef struct stu_node
{
	stu_t stu;
	struct stu_node *pre;
	struct stu_node *next;
}stu_node_t;


typedef struct tch_node
{
	tch_t tch;
	struct tch_node *pre;
	struct tch_node *next;
}tch_node_t;

#endif


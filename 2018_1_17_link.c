#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//void front();
//void back();

struct Stu {
	//学号
	char id[9];
	//姓名
	char name[13];
	//性别
	char sex;
	//年龄
 	int age;
	struct Stu *next;
};

struct Stu *insertnode(struct Stu *, struct Stu *);
void printLink(struct Stu *);
void setStu(struct Stu *, char*, char*, char, int);
void printStu(const struct Stu *);

int main() {
	struct Stu *head = NULL;
	struct Stu *pnew = NULL;
	char temp_id[9];
	char temp_name[13];
	char temp_sex;
	int temp_age;
	int sel;

	//.运算符 成员运算符
	//创建成员
	while(1) {
		printf("是否创建成员（1.创建0.退出）");
		scanf("%d", &sel);
		if(0 == sel) {
			break;
		}
		printf("请输入学号:");
		scanf("%s", temp_id);
		printf("请输入姓名:");
		scanf("%s", temp_name);
		printf("请输入性别:");
		scanf(" %c", &temp_sex);
		printf("请输入年龄:");
		scanf("%d", &temp_age);
		pnew = (struct Stu *)malloc(sizeof(struct Stu));
		setStu(pnew, temp_id, temp_name, temp_sex, temp_age);

		//有序插入
		head = insertnode(head,pnew);
	}

	//输出结构体变量
	printLink(head);	

	return 0;
}

void printLink(struct Stu *head) {
	struct Stu *pnew = head;
	while(pnew != NULL) {
		printStu(pnew);
		pnew = pnew->next;
	}
}

struct Stu *insertnode(struct Stu *head, struct Stu *pnew) {
	struct Stu *p1 = head;
	struct Stu *p2 = head;

	while(p1 != NULL&&strcmp(pnew->id,p1->id)>0) {
		p2 = p1;
		p1 = p1->next;
	}

	if(p1==p2) {
		head = pnew;
	}
	else {
		p2->next = pnew;
	}
	pnew->next = p1;

	return head;
}

void setStu(struct Stu *p, char *id, char *name, char sex, int age) {
	strcpy((*p).id, id);
	strcpy((*p).name, name);
	(*p).sex = sex;
	(*p).age = age;
}

void printStu(const struct Stu *s) {
	printf("学号:%s  姓名:%s  性别:%c  年龄:%d\n", (*s).id, (*s).name, (*s).sex, (*s).age);
}
	//后插
	/*p = head;
	while(p != NULL&&p->next != NULL) {
		p = p->next;

	}
	if(p == NULL) {
		head = pnew;
	}
	else {
		p->next = pnew;
	}
	pnew->next = NULL;*/
	//向前插入
	//(*pnew).next = head;
	//pnew->next = head;
	//head = pnew;

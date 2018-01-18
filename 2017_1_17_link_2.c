#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Stu {
	char id[9];
	char name[13];
	char sex;
	int age;
	struct Stu *next;
};

void setStu(struct Stu *, char *, char *, char, int);
struct Stu *insertNode(struct Stu *,struct Stu *);
void printLink(struct Stu *);
void printStu(struct Stu*);

int main() {
	struct Stu *pnew = NULL;
	struct Stu *head = NULL;
	char temp_id[9];
	char temp_name[13];
	char temp_sex;
	int temp_age;
	int sel;

	while(1) {
		printf("�Ƿ�����Ա(1.�� 0.��):");
		scanf("%d", &sel);
		if(0 == sel) {
			break;
		}
		printf("������ѧ��:");
		scanf("%s", temp_id);
		printf("����������:");
		scanf("%s", temp_name);
		printf("�������Ա�:");
		scanf(" %c", &temp_sex);
		printf("����������:");
		scanf("%d", &temp_age);
		pnew = (struct Stu *)malloc(sizeof(struct Stu));
		setStu(pnew, temp_id, temp_name, temp_sex, temp_age);

		head = insertNode(head, pnew);
	}

	printLink(head);

	return 0;
}

void setStu(struct Stu *p, char *id, char *name, char sex, int age) {
	strcpy(p->id, id);
	strcpy(p->name, name);
	p->sex = sex;
	p->age = age;
}

struct Stu *insertNode(struct Stu *head,struct Stu *pnew) {
	struct Stu *p1 = head;
	struct Stu *p2 = head;

	while(p1 != NULL&&strcmp(pnew->id, p1->id)>0) {
		p2 = p1;
		p1 = p1->next;
	}
	if(p1 == p2) {
		head = pnew;
	}
	else {
		p2->next = pnew;
	}
	pnew->next = p1;

	return head;
}

void printLink(struct Stu *head) {
	struct Stu *pnew = head;
	while(pnew != NULL) {
		printStu(pnew);
		pnew = pnew->next;
	}
}

void printStu(struct Stu *p) {
	printf("ѧ��:%s ����:%s �Ա�:%c ����:%d\n", p->id, p->name, p->sex, p->age);
}
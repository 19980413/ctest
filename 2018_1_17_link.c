#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//void front();
//void back();

struct Stu {
	//ѧ��
	char id[9];
	//����
	char name[13];
	//�Ա�
	char sex;
	//����
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

	//.����� ��Ա�����
	//������Ա
	while(1) {
		printf("�Ƿ񴴽���Ա��1.����0.�˳���");
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

		//�������
		head = insertnode(head,pnew);
	}

	//����ṹ�����
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
	printf("ѧ��:%s  ����:%s  �Ա�:%c  ����:%d\n", (*s).id, (*s).name, (*s).sex, (*s).age);
}
	//���
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
	//��ǰ����
	//(*pnew).next = head;
	//pnew->next = head;
	//head = pnew;

#include<stdio.h>
#include<stdlib.h>
#include<io.h>
#include"Snake.h"

int a[10];

void PrintAchievement()
{
	PrintWelcome();
	Color(3);
	setpos(57, 10);
	printf("��   ��");
	setpos(44, 12);
	printf("�Ѿ���ɵĳɾͻ�����ɫչʾ");
	setpos(44, 14);
	printf("δ��ɵĳɾͻ��Ժ�ɫչʾ");
	setpos(40, 18);
	Color(a[0]);
	printf("����ר��(�������ը���Ҵ��)");
	setpos(40, 20);
	Color(a[1]);
	printf("ҩ��(����ʮ�������Ҵ��)");
	setpos(40, 22);
	Color(a[2]);
	printf("�����ױȵĴ�˵(���ֲ���ʳ�����)");
	setpos(55, 26);
	Color(3);
	printf("��ESC�˳�");
	setpos(0, 50);
}

void SaveAchievement()
{
	FILE *fp;
	int i;
	fp = fopen("Achievement", "w");
	for (i = 0; i < 10; i++)
		fprintf(fp, "%d\r", a[i]);
	fclose(fp);
}

void ReadAchievement()
{
	FILE *fp;
	int i;
	if (access("Achievement", 0) != 0)
	{
		fp = fopen("Achievement", "w+");
		for (i = 0; i < 10; i++)
			fprintf(fp, "12\r");
		fclose(fp);
	}
	fp = fopen("Achievement", "r");
	for (i = 0; i < 10; i++)
		fscanf(fp,"%d", &a[i]);
	fclose(fp);
}

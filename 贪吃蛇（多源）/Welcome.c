#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<mmsystem.h>
#include"Snake.h"
#pragma comment(lib,"winmm.lib")

extern char name[100];
extern int Chapter;
extern int ReadGameFlag;

void PrintWelcome()
{
	Color(11);
	int i;
	for (i = 10; i <= 110; i += 2)
	{
		setpos(i, 5);
		printf(WELCOME);
		setpos(i, 37);
		printf(WELCOME);
	}
	for (i = 6; i <= 36; i++)
	{
		setpos(10, i);
		printf(WELCOME);
		setpos(110, i);
		printf(WELCOME);

	}
	Color(16);
}

void WelcomePlayer1()
{
	PrintWelcome();
	Color(3);
	setpos(47, 10);
	printf("��ӭ�����ߡ�������Ԫ Ver 6.0 �汾");
	setpos(53, 13);
	printf("���������������");
	setpos(50, 25);
	printf("���س�ȷ�ϲ�������Ϸ");
	Color(14);
	setpos(88, 35);
	printf("Created by Louis296");
	InputName();
	Color(16);
	setpos(0, 38);
}

int WelcomePlayer2(snake* p2,rank* p)
{
	PlaySound(TEXT("main.wav"), NULL, SND_ASYNC | SND_LOOP | SND_NODEFAULT);
    Start:PrintWelcome();
    int select,flag;
	Color(3);
	setpos(14, 7);
	printf("��ӭ���");
	Color(14);
	printf(" %s", name);
	Color(3);
	setpos(55, 10);
	printf("�ߡ�������Ԫ");
	setpos(49, 15);
	printf("1,��ʼ��Ϸ");
	setpos(49, 17);
	printf("2,���а�");
	setpos(49, 19);
	printf("3,�ɾ�");
	setpos(49, 21);
	printf("0,�˳���Ϸ");
	setpos(49, 28);
	printf("����ѡ�����:");
	Color(14);
	setpos(100, 33);
	printf("Ver 6.0");
	setpos(88, 35);
	printf("Created by Louis296");
	setpos(63, 28);
	scanf("%d", &select);
	setpos(0, 50);
	Color(16);
	switch (select)
	{
	case 1:
		system("cls");
		if (WelcomePlayer2_2(p2))
		{
			system("cls");
			goto Start;
		}
		else
			flag = 0;
		break;
	case 2:
		system("cls");
		PrintRankList(p);
		while (1)
			if (GetAsyncKeyState(VK_ESCAPE))
				break;
		system("cls");
		goto Start;
	case 3:
		system("cls");
		PrintAchievement();
		while (1)
			if (GetAsyncKeyState(VK_ESCAPE))
				break;
		system("cls");
		goto Start;
	case 0:
		flag = 1;
		break;
	default:
		system("cls");
		goto Start;
	}
	if (flag == 1)
		return 0;
	else
		return 1;
}

int WelcomePlayer2_2(snake* p2)
{
	Start: PrintWelcome();
	int select;
	Color(3);
	setpos(14, 7);
	printf("��ӭ���");
	Color(14);
	printf(" %s", name);
	Color(3);
	setpos(55, 10);
	printf("�ߡ�������Ԫ");
	setpos(49, 15);
	printf("1,����Ϸ");
	setpos(49, 17);
	printf("2,��ȡ��Ϸ");
	setpos(49, 19);
	printf("3,ѡ��ؿ�");
	setpos(49, 21);
	printf("0,����");
	setpos(49, 28);
	printf("����ѡ�����:");
	Color(14);
	setpos(100, 33);
	printf("Ver 6.0");
	setpos(88, 35);
	printf("Created by Louis296");
	setpos(63, 28);
	scanf("%d", &select);
	setpos(0, 50);
	Color(16);
	switch (select)
	{
	case 1:
		Chapter = 1;
		return 0;
	case 2:
		if (ReadSave(p2))
		{
			ReadGameFlag = 1;
			return 0;
		}
		else
			system("cls");
			goto Start;
	case 3:
		Color(3);
		setpos(47, 30);
		printf("����ѡ��ؿ���1-4����");
		scanf("%d", &Chapter);
		Color(16);
		return 0;
	case 0:
		return 1;
	default:
		system("cls");
		goto Start;
	}
}

void InputName()
{
	char* find;
	setpos(54, 15);
	fgets(name, 100, stdin);
	find = strchr(name, '\n');
	if (find != NULL)
		*find = '\0';
}

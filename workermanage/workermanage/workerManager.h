#pragma once//��ֹͷ�ļ��ظ�����
#include<iostream>
using namespace std;
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define FILENAME "empFile.txt"
class WorkerManager{
public:
	//��¼ְ������
	int m_EmpNum;
	//ְ������ָ��
	Worker** m_EmpArray;
	//�ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;
	WorkerManager();
	//ͳ���ļ��е�����
	int get_EmpNum();
	//��ʼ��Ա��
	void init_Emp();
	//չʾ�˵�
	void Show_Menu();
	//���ְ��
	void Add_Emp();
	//�����ļ�
	void save();
	//��ʾְ��
	void Show_Emp();
	//ɾ��ְ��
	void Del_Emp();
	//�ж�ְ���Ƿ����
	int IsExist(int id);
	//�޸�ְ��
	void Mod_Emp();
	//����ְ��
	void Find_Emp();
	//����
	void Sort_Emp();
	//����ļ�
	void Clean_File();
	//�˳�ϵͳ
	void ExitSystem();
	~WorkerManager();
	
};
#pragma once
#include<iostream>
using namespace std;
#include"identity.h"
#include<string>
#include"orderFile.h"
#include<vector>
class Teacher :public Identity {
public:
	//Ĭ�Ϲ���
	Teacher();
	//�вι���
	Teacher(int empId, string name, string pwd);
	//�˵�����  �����д��麯�����������д�������޷�ʵ��������
	virtual void openMenu();
	//�鿴����ԤԼ
	void showAllOrder();
	//���ԤԼ
	void validOrder();
	//ְ����
	int m_EmpId;
};
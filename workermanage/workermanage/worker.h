#pragma once
#include<iostream>
using namespace std;
#include<string>
//ְ��������
class Worker {
public:
	int m_Id;//Ա�����
	string m_Name;//����
	int m_DeptId;//���ű��
	//��ʾ������Ϣ
	virtual	void showInfo() = 0;
	//��ȡ��λ����
	virtual string getDeptName() = 0;
};
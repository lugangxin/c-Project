#pragma once
#include<iostream>
using namespace std;
#include<map>
#include<fstream>
#include"globalFile.h"
#include<string>
class OrderFile {
public:
	//���캯��
	OrderFile();
	//����ԤԼ��¼
	void updateOrder();
	//��¼ԤԼ����
	int m_Size;
	//��¼����ԤԼ������
	map<int, map<string, string>>m_orderData;

};
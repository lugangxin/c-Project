#pragma once
#include<iostream>
using namespace std;
#include"identity.h"
#include<string>
#include"orderFile.h"
#include<vector>
class Teacher :public Identity {
public:
	//默认构造
	Teacher();
	//有参构造
	Teacher(int empId, string name, string pwd);
	//菜单界面  父类有纯虚函数子类必须重写，否则无法实例化对象
	virtual void openMenu();
	//查看所有预约
	void showAllOrder();
	//审核预约
	void validOrder();
	//职工号
	int m_EmpId;
};
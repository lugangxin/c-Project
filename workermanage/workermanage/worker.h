#pragma once
#include<iostream>
using namespace std;
#include<string>
//职工抽象类
class Worker {
public:
	int m_Id;//员工编号
	string m_Name;//姓名
	int m_DeptId;//部门编号
	//显示个人信息
	virtual	void showInfo() = 0;
	//获取岗位名称
	virtual string getDeptName() = 0;
};
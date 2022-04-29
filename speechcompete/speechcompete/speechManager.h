#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include"speaker.h"
#include<algorithm>
#include<deque>
#include<functional>
#include<numeric>
#include<string>
#include<fstream>
//设计演讲管理类
class SpeechManager 
{
public:
	//构造
	SpeechManager();
	//初始化属性
	void initSpeech();
	//创建选手
	void createSpeaker();
	//菜单
	void show_Menu();
	//开始比赛  比赛整个流程控制函数
	void startSpeech();
	//抽签
	void speechDraw();
	//比赛
	void speechContest();
	//显示得分
	void showScore();
	//保存记录
	void saveRecord();
	//读取记录
	void loadRecord();
	//显示往届记录
	void showRecord();
	//判断文件是否为空
	bool fileIsEmpty;
	//存放往届记录的容器
	map<int, vector<string>>m_Record;
	//清空记录
	void clearRecord();
	//退出
	void exitSystem();
	//析构
	~SpeechManager();
	//成员属性
	//保存第一轮比赛选手编号容器
	vector<int>v1;
	//第一轮晋级选手编号
	vector<int>v2;
	//前三名
	vector<int>vVictory;
	//编号及对应具体选手
	map<int, Speaker>m_Speaker;
	//比赛轮数
	int m_Index;
};
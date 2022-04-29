#include<iostream>
using namespace std;
#include"speechManager.h"
#include<string>
#include<ctime>
int main() {
	//随机数种子
	srand((unsigned int)time(NULL));
	//创建管理类的对象
	SpeechManager sm;
	//测试创建选手
	/*for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end();it++) {
		cout << "选手编号：" << it->first << "姓名：" << it->second.m_Name << "得分：" << it->second.m_Score[0] << endl;
	}*/
	int choice = 0;//存取用户输入
	while (true)
	{
		sm.show_Menu();
		cout << "请输入您的选择：" << endl;
		cin >> choice;
		switch (choice) {
		case 1://开始比赛
			sm.startSpeech();
			break;
		case 2://查看往届比赛记录
			sm.showRecord();
			break;
		case 3://清空比赛记录
			sm.clearRecord();
			break;
		case 0://退出系统
			sm.exitSystem();
			break;
		}
	}
	system("pause");
	return 0;
}
#include<iostream>
using namespace std;
#include"speechManager.h"
#include<string>
#include<ctime>
int main() {
	//���������
	srand((unsigned int)time(NULL));
	//����������Ķ���
	SpeechManager sm;
	//���Դ���ѡ��
	/*for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end();it++) {
		cout << "ѡ�ֱ�ţ�" << it->first << "������" << it->second.m_Name << "�÷֣�" << it->second.m_Score[0] << endl;
	}*/
	int choice = 0;//��ȡ�û�����
	while (true)
	{
		sm.show_Menu();
		cout << "����������ѡ��" << endl;
		cin >> choice;
		switch (choice) {
		case 1://��ʼ����
			sm.startSpeech();
			break;
		case 2://�鿴���������¼
			sm.showRecord();
			break;
		case 3://��ձ�����¼
			sm.clearRecord();
			break;
		case 0://�˳�ϵͳ
			sm.exitSystem();
			break;
		}
	}
	system("pause");
	return 0;
}
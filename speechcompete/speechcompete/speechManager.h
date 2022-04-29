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
//����ݽ�������
class SpeechManager 
{
public:
	//����
	SpeechManager();
	//��ʼ������
	void initSpeech();
	//����ѡ��
	void createSpeaker();
	//�˵�
	void show_Menu();
	//��ʼ����  �����������̿��ƺ���
	void startSpeech();
	//��ǩ
	void speechDraw();
	//����
	void speechContest();
	//��ʾ�÷�
	void showScore();
	//�����¼
	void saveRecord();
	//��ȡ��¼
	void loadRecord();
	//��ʾ�����¼
	void showRecord();
	//�ж��ļ��Ƿ�Ϊ��
	bool fileIsEmpty;
	//��������¼������
	map<int, vector<string>>m_Record;
	//��ռ�¼
	void clearRecord();
	//�˳�
	void exitSystem();
	//����
	~SpeechManager();
	//��Ա����
	//�����һ�ֱ���ѡ�ֱ������
	vector<int>v1;
	//��һ�ֽ���ѡ�ֱ��
	vector<int>v2;
	//ǰ����
	vector<int>vVictory;
	//��ż���Ӧ����ѡ��
	map<int, Speaker>m_Speaker;
	//��������
	int m_Index;
};
#include<iostream>
using namespace std;
#include"identity.h"
#include<fstream>
#include<string>
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"
//�����ʦ�Ӳ˵�����
void teacherMenu(Identity* &teacher) {//����ָ�����
	while (true) {
		//������ʦ�Ӳ˵�
		teacher->openMenu();
		//������ָ��תΪ����ָ�룬���������������ӿ�
		Teacher* tea = (Teacher*)teacher;
		int select = 0;
		cin >> select;
		if (select == 1) {
			
			cout << "�鿴����ԤԼ" << endl;
			tea->showAllOrder();
		}
		else if (select == 2) {
			
			cout << "���ԤԼ" << endl;
			tea->validOrder();
		}
		else {
			delete teacher;//���ٶ�������
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//����ѧ���Ӳ˵�����
void studentMenu(Identity* & student) {//����ָ�����
	while (true) {
		//����ѧ���Ӳ˵�
		student->openMenu();
		//������ָ��תΪ����ָ�룬���������������ӿ�
		Student* stu = (Student*)student;
		int select = 0;
		cin >> select;
		if (select == 1) {
			//����ԤԼ
			cout << "����ԤԼ" << endl;
			stu->applyOrder();
		}
		else if (select == 2) {
			//�鿴����ԤԼ
			cout << "�鿴����ԤԼ" << endl;
			stu->showMyOrder();
		}
		else if (select == 3) {
			//�鿴������ԤԼ
			cout << "�鿴������ԤԼ" << endl;
			stu->showAllOrder();
		}
		else if (select == 4) {
			//ȡ��ԤԼ
			cout << "ȡ��ԤԼ" << endl;
			stu->cancelOrder();
		}
		else {
			delete student;//���ٶ�������
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls"); 
			return;
		}
	}
}
//�������Ա�Ӳ˵�����
void managerMenu(Identity* &manager) {//����ָ�����
	while (true) {
		//���ù���Ա�Ӳ˵�
		manager->openMenu();
		//������ָ��תΪ����ָ�룬���������������ӿ�
		Manager* man = (Manager*)manager;
		int select = 0;
		cin >> select;
		if (select==1) {
			//����˺�
			cout << "����˺�" << endl;
			man->addPerson();
		}
		else if (select==2) {
			//�鿴�˺�
			cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select==3) {
			//�鿴����
			cout << "�鿴����" << endl;
			man->showComputer();
		}
		else if (select==4) {
			//���ԤԼ
			cout << "���ԤԼ" << endl;
			man->clearFile();
		}
		else {
			delete manager;//���ٶ�������
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//��¼  ����1�������ļ�����  ����2�������������
void LoginIn(string fileName,int type) {
	//����ָ�룬����ָ���������
	Identity * person = NULL;
	//���ļ�
	ifstream ifs;
	ifs.open(fileName,ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	//׼�������û���Ϣ
	int id = 0;
	string name;
	string pwd;
	//�ж����
	if (type==1) {//ѧ��
		cout << "������ѧ�ţ�" << endl;
		cin >> id;
	
	}
	else if (type==2) {
		cout << "������ְ���ţ�" << endl;
		cin >> id;
	}
	cout << "�������û�����" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;
	if (type==1) {
		//ѧ�������֤
		int fId;//���ļ��л�ȡ��id
		string fName;
		string fPwd;
		while (ifs>>fId&&ifs>>fName&&ifs>>fPwd) {
			/*cout << fId << endl;
			cout << fName<< endl;
			cout << fPwd << endl;
			cout <<  endl;*/
			//���û��������Ϣ�Ա�
			if(fId==id&&fName==name&&fPwd==pwd){
				cout << "ѧ����֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Student(id,name,pwd);
				//����ѧ���Ӳ˵�
				studentMenu(person);
				return;
			}
		}
	}
	else if (type==2) {
		//��ʦ�����֤
		int fId;//���ļ��л�ȡ��id
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {			
			//���û��������Ϣ�Ա�
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "��ʦ��֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//�����ʦ�Ӳ˵�
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type==3) {
		//����Ա�����֤
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd) {
			//���û��������Ϣ�Ա�
			if (fName == name && fPwd == pwd) {
				cout << "����Ա��֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//�������Ա�Ӳ˵�
				managerMenu(person);
				return;
			}
		}
	}
	cout << "��֤��¼ʧ�ܣ�" << endl;
	system("pause");
	system("cls");
	return;
}
int main() {
	int select = 0;//�����û���ѡ��
	while (true)
	{
		cout << "===============��ӭ��������ԤԼϵͳ==================" << endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t----------------------------\n";
		cout << "\t\t|      1.ѧ������          |\n";
		cout << "\t\t|                          |\n";
		cout << "\t\t|      2.��    ʦ          |\n";
		cout << "\t\t|                          |\n";
		cout << "\t\t|      3.�� �� Ա          |\n";
		cout << "\t\t|                          |\n";
		cout << "\t\t|      0.��    ��          |\n";
		cout << "\t\t|                          |\n";
		cout << "\t\t----------------------------\n";
		cout << "��������ѡ��";
		cin >> select;
		switch (select)
		{
		case 1://ѧ��
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://��ʦ
			LoginIn(TEACHER_FILE,2);
			break;
		case 3://����Ա
			LoginIn(ADMIN_FILE,3);
			break;
		case 0://�˳�
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			break;
		}
	}
	
	system("pause");
	return 0;
}
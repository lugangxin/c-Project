#include<iostream>
using namespace std;
#include<string>
#define MAX 1000
//��ϵ��
struct Person {
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;

};
//ͨѶ¼
struct Addressbooks { 
	struct Person personArray[MAX];
	int m_Size;
};
//�����ϵ��
void addPerson(struct Addressbooks* abs) {
	//���ж��Ƿ���
	if (abs->m_Size==MAX) {
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else {
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		int sex=0;
		cout << "�������Ա�" << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;		
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}
		int age=0;
		cout << "���������䣺" << endl;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		string phone;
		cout << "������绰��" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		string addr;
		cout << "�������ַ��" << endl;
		cin >> addr;
		abs->personArray[abs->m_Size].m_Addr = addr;
		//����ͨѶ¼����
		abs->m_Size++;
		cout << "��ӳɹ�" << endl;
		system("pause");//�밴���������
		system("cls");//����
	}
}
//��ʾ��ϵ��
void showPerson(struct Addressbooks * abs) {
	//�ж����˷�
	if (abs->m_Size==0) {
		cout << "ͨѶ¼Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size;i++) {
			cout << "������" << abs->personArray[i].m_Name <<"\t";
			cout << "�Ա�" <<(abs->personArray[i].m_Sex==1 ?"��":"Ů")<< "\t";
			cout << "���䣺" << abs->personArray[i].m_Age << "\t";
			cout << "�绰��" << abs->personArray[i].m_Phone << "\t";
			cout << "��ַ��" << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");//�밴���������
	system("cls");//����
}
//�����ϵ���Ƿ���� �����ڷ���λ��
int isExist(struct Addressbooks* abs,string name) {
	for (int i = 0; i < abs->m_Size;i++) {
		if (abs->personArray[i].m_Name==name) {
			return i;
		}		
	}
	return -1;
}
//ɾ����ϵ�ˣ���������
void deletePerson(struct Addressbooks* abs) {
	cout << "������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	int ret=isExist(abs, name);
	if (ret!=-1) {
		for (int i = ret; i < abs->m_Size;i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout<<"ɾ���ɹ�" <<endl;
	}else{
		cout << "û�д���" << endl;
	}
	system("pause");//�밴���������
	system("cls");//����
}
//������ϵ��
void findPerson(struct Addressbooks* abs) {
	cout << "������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << "������" << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա�" << abs->personArray[ret].m_Sex << "\t";
		cout << "���䣺" << abs->personArray[ret].m_Age << "\t";
		cout << "�绰��" << abs->personArray[ret].m_Phone << "\t";
		cout << "��ַ��" << abs->personArray[ret].m_Addr << "\t";

	}
	else {
		cout << "û�д���" << endl;
	}
	system("pause");//�밴���������
	system("cls");//����
}
//�޸���ϵ��
void modifyPerson(struct Addressbooks* abs) {
	cout << "������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		int sex = 0;
		cout << "�������Ա�" << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}
		int age = 0;
		cout << "���������䣺" << endl;
		cin >> age;
		abs->personArray[ret].m_Age = age;
		string phone;
		cout << "������绰��" << endl;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		string addr;
		cout << "�������ַ��" << endl;
		cin >> addr;
		abs->personArray[ret].m_Addr = addr;
		cout << "�޸ĳɹ�" << endl;
	}
	else {
		cout << "û�д���" << endl;
	}
	system("pause");//�밴���������
	system("cls");//����
}
//���ͨѶ¼ �߼������
void clearPerson(struct Addressbooks* abs) {
	abs->m_Size = 0;
	cout << "ͨѶ¼�����" << endl;
	system("pause");//�밴���������
	system("cls");//����
}
//�˵�
void showMenu() {
	cout << "*************************" << endl;
	cout << "***** 1�������ϵ�� *****" << endl;
	cout << "***** 2����ʾ��ϵ�� *****" << endl;
	cout << "***** 3��ɾ����ϵ�� *****" << endl;
	cout << "***** 4��������ϵ�� *****" << endl;
	cout << "***** 5���޸���ϵ�� *****" << endl;
	cout << "***** 6�������ϵ�� *****" << endl;
	cout << "***** 0���˳�ͨѶ¼ *****" << endl;
	cout << "*************************" << endl;
}
int main() {
	//����ͨѶ¼�ṹ�����
	struct Addressbooks abs;
	abs.m_Size = 0;
	int select = 0;
	while (true) {
		showMenu();
		cin >> select;
		switch (select) {
		case 1://���
			addPerson(&abs);//��ַ���ݿ�������ʵ��
			break;
		case 2://��ʾ
			showPerson(&abs);
			break;
		case 3://ɾ��
			deletePerson(&abs);
			break;
		case 4://����
			findPerson(&abs);
			break;
		case 5://�޸�
			modifyPerson(&abs);
			break;
		case 6://���
			clearPerson(&abs);
			break;
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
	
}
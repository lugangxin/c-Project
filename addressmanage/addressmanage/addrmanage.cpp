#include<iostream>
using namespace std;
#include<string>
#define MAX 1000
//联系人
struct Person {
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;

};
//通讯录
struct Addressbooks { 
	struct Person personArray[MAX];
	int m_Size;
};
//添加联系人
void addPerson(struct Addressbooks* abs) {
	//先判断是否满
	if (abs->m_Size==MAX) {
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else {
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		int sex=0;
		cout << "请输入性别：" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;		
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		int age=0;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		string phone;
		cout << "请输入电话：" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		string addr;
		cout << "请输入地址：" << endl;
		cin >> addr;
		abs->personArray[abs->m_Size].m_Addr = addr;
		//更新通讯录人数
		abs->m_Size++;
		cout << "添加成功" << endl;
		system("pause");//请按任意键继续
		system("cls");//清屏
	}
}
//显示联系人
void showPerson(struct Addressbooks * abs) {
	//判断有人否
	if (abs->m_Size==0) {
		cout << "通讯录为空" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size;i++) {
			cout << "姓名：" << abs->personArray[i].m_Name <<"\t";
			cout << "性别：" <<(abs->personArray[i].m_Sex==1 ?"男":"女")<< "\t";
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "电话：" << abs->personArray[i].m_Phone << "\t";
			cout << "地址：" << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");//请按任意键继续
	system("cls");//清屏
}
//检测联系人是否存在 若存在返回位置
int isExist(struct Addressbooks* abs,string name) {
	for (int i = 0; i < abs->m_Size;i++) {
		if (abs->personArray[i].m_Name==name) {
			return i;
		}		
	}
	return -1;
}
//删除联系人（按姓名）
void deletePerson(struct Addressbooks* abs) {
	cout << "请输入要删除的联系人" << endl;
	string name;
	cin >> name;
	int ret=isExist(abs, name);
	if (ret!=-1) {
		for (int i = ret; i < abs->m_Size;i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout<<"删除成功" <<endl;
	}else{
		cout << "没有此人" << endl;
	}
	system("pause");//请按任意键继续
	system("cls");//清屏
}
//查找联系人
void findPerson(struct Addressbooks* abs) {
	cout << "请输入要查找的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
		cout << "性别：" << abs->personArray[ret].m_Sex << "\t";
		cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
		cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
		cout << "地址：" << abs->personArray[ret].m_Addr << "\t";

	}
	else {
		cout << "没有此人" << endl;
	}
	system("pause");//请按任意键继续
	system("cls");//清屏
}
//修改联系人
void modifyPerson(struct Addressbooks* abs) {
	cout << "请输入要修改的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		int sex = 0;
		cout << "请输入性别：" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		int age = 0;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->personArray[ret].m_Age = age;
		string phone;
		cout << "请输入电话：" << endl;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		string addr;
		cout << "请输入地址：" << endl;
		cin >> addr;
		abs->personArray[ret].m_Addr = addr;
		cout << "修改成功" << endl;
	}
	else {
		cout << "没有此人" << endl;
	}
	system("pause");//请按任意键继续
	system("cls");//清屏
}
//清空通讯录 逻辑上清空
void clearPerson(struct Addressbooks* abs) {
	abs->m_Size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");//请按任意键继续
	system("cls");//清屏
}
//菜单
void showMenu() {
	cout << "*************************" << endl;
	cout << "***** 1、添加联系人 *****" << endl;
	cout << "***** 2、显示联系人 *****" << endl;
	cout << "***** 3、删除联系人 *****" << endl;
	cout << "***** 4、查找联系人 *****" << endl;
	cout << "***** 5、修改联系人 *****" << endl;
	cout << "***** 6、清空联系人 *****" << endl;
	cout << "***** 0、退出通讯录 *****" << endl;
	cout << "*************************" << endl;
}
int main() {
	//创建通讯录结构体变量
	struct Addressbooks abs;
	abs.m_Size = 0;
	int select = 0;
	while (true) {
		showMenu();
		cin >> select;
		switch (select) {
		case 1://添加
			addPerson(&abs);//地址传递可以修饰实参
			break;
		case 2://显示
			showPerson(&abs);
			break;
		case 3://删除
			deletePerson(&abs);
			break;
		case 4://查找
			findPerson(&abs);
			break;
		case 5://修改
			modifyPerson(&abs);
			break;
		case 6://清空
			clearPerson(&abs);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
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
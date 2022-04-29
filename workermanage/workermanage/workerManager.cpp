#include"workerManager.h"
WorkerManager::WorkerManager() {
	//文件不存在
	ifstream ifs;
	ifs.open(FILENAME,ios::in);//输入--读文件
	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		//初始化属性
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件存在
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "文件为空" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件存在有数据
	int num = this->get_EmpNum();
	cout << "职工人数为" <<num<< endl;
	this->m_EmpNum = num;
	//开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//将文件中的数据存到数组中
	this->init_Emp();
	//测试
	/*for (int i = 0; i < this->m_EmpNum;i++) {
		cout << "职工编号：" << this->m_EmpArray[i]->m_Id
			<< " 姓名：" << this->m_EmpArray[i]->m_Name
			<< " 部门编号：" << this->m_EmpArray[i]->m_DeptId << endl;
	}*/
}
//统计文件中的人数
int WorkerManager::get_EmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//输入--读文件
	int id;
	string name;
	int did;
	int num = 0;
	while (ifs>>id&&ifs>>name&&ifs>>did) {
		//统计人数
		num++;
	}
	return num;
}
//初始化员工
void WorkerManager::init_Emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//输入--读文件
	int id;
	string name;
	int did;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did) {
		Worker* worker = NULL;
		if (did==1) {
			worker = new Employee(id,name,did);
		}
		else if (did == 1) {
			worker = new Manager(id, name, did);
		}
		else {
			worker = new Boss(id, name, did);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}
//展示菜单
void WorkerManager::Show_Menu() {
	cout << "***************************" << endl;
	cout << "***欢迎使用职工管理系统！***" << endl;
	cout << "***** 0、退出管理系统 *****" << endl;
	cout << "***** 1、增加职工信息 *****" << endl;
	cout << "***** 2、显示职工信息 *****" << endl;
	cout << "***** 3、删除离职职工 *****" << endl;
	cout << "***** 4、修改职工信息 *****" << endl;
	cout << "***** 5、查找职工信息 *****" << endl;
	cout << "***** 6、按照编号排序 *****" << endl;
	cout << "***** 7、清空所有文档 *****" << endl;
	cout << "***************************" << endl;
}
//添加职工
void WorkerManager::Add_Emp() {
	cout << "请输入添加职工数量" << endl;
	int addNum = 0;//保存用户输入数量
	cin >> addNum;
	if (addNum>0) {
		//计算添加新空间大小
		int newSize = this->m_EmpNum + addNum;
		//开辟新空间
		Worker** newSpace=new Worker* [newSize];
		//将原来空间的数据拷贝到新空间
		if (this->m_EmpArray!=NULL) {
			for (int i = 0; i < this->m_EmpNum;i++) {
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//添加新数据
		for (int i = 0; i < addNum; i++) {
			int id;
			string name;
			int dSelect;//部门选择
			cout << "请输入第" <<i+1<<"个新职工编号："<< endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工姓名：" << endl;
			cin >> name;
			cout << "请选择该职工岗位：" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch(dSelect) {
				case 1:
					worker = new Employee(id,name,1);
					break;
				case 2:
					worker = new Manager(id, name, 2);
					break;
				case 3:
					worker = new Boss(id, name, 3);
					break;
				default:
					break;
			}
			//将创建的职工指针保存到数组
			newSpace[this->m_EmpNum + i] = worker;

		}
		//释放原有的空间
		delete[] this->m_EmpArray;
		//更新空间指向
		this->m_EmpArray = newSpace;
		//更新职工人数
		this->m_EmpNum = newSize;
		//置文件非空
		this->m_FileIsEmpty = false;
		cout << "成功添加" <<addNum <<"名新职工"<<endl;
		//成功添加后保存到文件中
		this->save();
	}
	else {
		cout << "输入数据有误" << endl;
	}
	system("pause");
	system("cls");
}
//保存文件
void WorkerManager::save() {
	ofstream ofs;
	ofs.open(FILENAME,ios::out);//输出对应写文件
	for (int i = 0; i < this->m_EmpNum;i++) {
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;

	}
	ofs.close();
}
//显示职工
void WorkerManager::Show_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		for (int i = 0; i < this->m_EmpNum;i++) {
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}
//删除职工
void WorkerManager::Del_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空！" << endl;
	}
	else {
		//按职工编号删除
		cout << "请输入想要删除的职工编号：" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		if (index!=-1) {
			//数据前移
			for (int i = index; i < this->m_EmpNum - 1;i++) {
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			//同步更新到文件中
			this->save();
			cout << "删除成功！" << endl;
		}
		else {
			cout << "删除失败，未找到该职工" << endl;
		}

	}
	system("pause");
	system("cls");
}
//判断职工是否存在
int WorkerManager::IsExist(int id) {
	int index = -1;
	for (int i = 0; i < m_EmpNum;i++) {
		if (this->m_EmpArray[i]->m_Id==id) {
			//找到职工
			index = i;
			break;
		}
	}
	return index;
}
//修改职工
void WorkerManager::Mod_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空！" << endl;
	}
	else {
		cout << "请输入想要修改的职工编号：" << endl;
		int id;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret!=-1) {
			delete this->m_EmpArray[ret];
			int newId = 0;
			string newName = "";
			int dSelect = 0;
			cout << "查到" << id<<"号职工，请输入新的职工号"<<endl;
			cin >> newId;
			cout << "请输入新的姓名" << endl;
			cin >> newName;
			cout << "请输入新的岗位" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect) {
			case 1:
				worker = new Employee(newId,newName,dSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, dSelect);
				break;
			default:
				break;
			}
			//更新数据到数组
			this->m_EmpArray[ret] = worker;
			cout << "修改成功" << endl;
			this->save();

		}
		else {
			cout << "修改失败，查无此人" << endl;
		}
	}
	system("pause");
	system("cls");
}
//查找职工
void WorkerManager::Find_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空！" << endl;
	}
	else {
		cout << "请输入查找的方式：" << endl;
		cout << "1.按职工编号查找：" << endl;
		cout << "2.按职工姓名查找：" << endl;
		int select = 0;
		cin >> select;
		if (select==1) {
			int id;
			cout << "请输入查找的职工编号" << endl;
			cin >> id;
			int ret = IsExist(id);
			if (ret!=-1) {
				cout << "查找成功，该职工信息为：" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else {
				cout << "查找失败，没有此人" << endl;
			}
		}
		else if (select==2) {
			string name;
			cout << "请输入查找的职工姓名" << endl;
			cin >> name;
			//加入判断是否查到的标志
			bool flag = false;
			for (int i = 0; i < m_EmpNum;i++) {
				if (this->m_EmpArray[i]->m_Name==name) {
					cout << "查找成功，职工编号为" <<this->m_EmpArray[i]->m_Id<<"的职工信息如下："<<endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if (flag==false) {
				cout << "查找失败，没有此人" << endl;
			}
		}
		else {
			cout << "输入信息有误，请重新输入" << endl;
		}
	}
	system("pause");
	system("cls");
}
//排序
void WorkerManager::Sort_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空！" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "请选择排序方式" << endl;
		cout << "1.按职工编号升序" << endl;
		cout << "2.按职工编号降序" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < m_EmpNum;i++) {
			int minOrMax = i;
			for (int j = i+1; j < this->m_EmpNum;j++) {
				if (select == 1) {
					if (this->m_EmpArray[minOrMax]->m_Id>this->m_EmpArray[j]->m_Id) {
						minOrMax = j;
					}
				}
				else {
					if (this->m_EmpArray[minOrMax]->m_Id< this->m_EmpArray[j]->m_Id) {
						minOrMax = j;
					}
				}
			
			}
			if (i!=minOrMax) {
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}
		}
		cout << "排序成功，结果为" << endl;
		this->save();
		this->Show_Emp();
	}
}
//清空文件
void WorkerManager::Clean_File() {
	cout << "确定清空？" << endl;
	cout << "1.确定" << endl;
	cout << "2.返回" << endl;
	int select = 0;
	cin >> select;
	if (select==1) {
		ofstream ofs(FILENAME, ios::trunc);//删除文件后重新创建
		ofs.close();
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				if (this->m_EmpArray[i] != NULL) {
					delete this->m_EmpArray[i];
				}
			}
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");
}
//退出系统
void WorkerManager::ExitSystem() {
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}
WorkerManager::~WorkerManager() {
	if(this->m_EmpArray!=NULL){
		for (int i = 0; i < this->m_EmpNum;i++) {
			if (this->m_EmpArray[i]!=NULL) {
				delete this->m_EmpArray[i];
			}
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}
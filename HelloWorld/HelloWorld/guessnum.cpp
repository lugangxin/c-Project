#include<iostream>
using namespace std;
#include<ctime>
int main() {
	
	//�������������
	srand((unsigned int)time(NULL));
	int r,num,i=0;
	r = rand() % 100 + 1;
	cout << "��ӭ�ٻ�ʦ������Ϸ���磬����1-100����һ����Ҫ�µ����֣�������5�λ��ᣡ" << endl;
	while (i<5) {
		cin >> num;
		if (num > r) {
			cout << "������������������룡" << endl;
		}
		else if (num<r) {
			cout << "�������С�����������룡" << endl;
		}
		else{
			cout << "��ϲ��¶��ˣ�" << endl;
			break;
		}
		i++;
	}
	if (i>=5) {
		cout << "����5�λ��ᣬ������û�в³���������ʧ�ܣ�" << endl;
	}

	system("pause");
	return 0;
}
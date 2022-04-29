#include<iostream>
using namespace std;
#include<ctime>
int main() {
	
	//生成随机数种子
	srand((unsigned int)time(NULL));
	int r,num,i=0;
	r = rand() % 100 + 1;
	cout << "欢迎召唤师来到游戏世界，请在1-100间挑一个你要猜的数字，您共有5次机会！" << endl;
	while (i<5) {
		cin >> num;
		if (num > r) {
			cout << "输入的数大，请重新输入！" << endl;
		}
		else if (num<r) {
			cout << "输入的数小，请重新输入！" << endl;
		}
		else{
			cout << "恭喜你猜对了！" << endl;
			break;
		}
		i++;
	}
	if (i>=5) {
		cout << "经过5次机会，您还是没有猜出来，闯关失败！" << endl;
	}

	system("pause");
	return 0;
}
#include <iostream>
#include <string>
#define MAX 1000 //通讯录最大容量暂定1000

using namespace std;

/*
整体架构：实现：菜单、退出、添加联系人、显示联系人、删除联系人、查找联系人、
修改联系人、清空联系人功能
*/

/*
添加联系人功能的具体实现：
设计联系人结构体、设计通讯录结构体、main函数中创建通讯录、封装添加联系人的函数、
测试添加联系人的功能
*/
//联系人结构体
struct Person {
	//姓名
	string m_Name;
	//性别 1 男 2女
	int m_Sex;
	//年龄
	int m_Age;
	//电话
	string m_Phone;
	//住址
	string m_Addr;
};

//通讯录结构体
struct Addressbooks {
	//联系人的数组
	struct Person personArray[MAX];
	//当前联系人个数
	int m_Size;
};

//1、添加联系人
void addPerson(Addressbooks *abs)
 {
	//判断通讯录是否满
	if (abs->m_Size == MAX) {
		cout << "通讯录已满，无法添加" << endl;
	}
	else {
		//添加联系人

		//姓名
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//性别
		cout << "请输入性别" << endl;
		cout << "1——男" << endl;
		cout << "2——女" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;//如果输入对了，则结束这层while循环，否则一直循环直到输入正确为止
			}
			else {
				cout << "输入有误，请重新输入！" << endl;
			}
		}

		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		while (true) {
			cin >> age;
			if (age>=0 &&age<=150) {
				abs->personArray[abs->m_Size].m_Age = age;
				break;//如果输入对了，则结束这层while循环，否则一直循环直到输入正确为止
			}
			else {
				cout << "输入有误，请重新输入！" << endl;
			}
		}
		//电话
		cout << "请输入电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//住址
		cout << "请输入家庭字符：" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;
		 //更新通讯录的人数
		abs->m_Size++;

		cout << "添加成功" << endl;

		system("pause");//请按任意键介绍
		system("cls");//清屏操作

	}
}

//2、显示联系人
void showPerson(Addressbooks *abs) {
	//判断通讯录中人数是否为0
	if (abs->m_Size == 0) {
		cout << "当前记录为空" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "姓名：" << abs->personArray[i].m_Name << "\t";
			cout << "性别：" <<(abs->personArray[i].m_Sex==1? "男":"女") << "\t";
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "电话：" << abs->personArray[i].m_Phone << "\t";
			cout << "住址：" << abs->personArray[i].m_Addr<< endl;
		}
	}
	system("pause");//按任意键继续
	system("cls");//屏幕清零
}

//3、删除联系人
//3.1封装一个函数，用于检测联系人是否存在，存在返回索引，不存在返回-1
int isExist(Addressbooks *abs, string name) {
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArray[i].m_Name == name) {
			return i;
		}
		return -1;
	}
}
//3、删除联系人
void deletePreson(Addressbooks *abs) {
	cout << "请输入您要删除的联系人" << endl;
	string name;
	cin >> name;

	int ret=isExist(abs,name);
	if (ret != -1) {
		//查到该人，删除
		for (int i = ret; i < abs->m_Size; i++) {
			abs->personArray[i] = abs->personArray[i + 1];//数据前移
		}
		abs->m_Size--;//更新人数；
		cout << "删除成功" << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//4、查找联系人
void findPerson(Addressbooks *abs) {
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;
	//判断联系人是否存在
	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
		cout << "性别：" << abs->personArray[ret].m_Sex << "\t";
		cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
		cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
		cout << "住址：" << abs->personArray[ret].m_Addr << endl;
	}else {
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");
}

//5、修改联系人
void modifyPerson(Addressbooks *abs) {
	cout << "请输入您要修改的联系人" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1) {
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		//性别
		int sex;
		cout << "请输入性别" << endl;
		cout << "1——男" << endl;
		cout << "2——女" << endl;
		cin >> sex;
		abs->personArray[ret].m_Sex = sex;
		//年龄
		int age;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->personArray[ret].m_Age = age;
		//电话
		string phone;
		cout << "请输入电话：" << endl;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		//住址
		string address;
		cout << "请输入住址：" << endl;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

		cout << "修改成功" << endl;
	}
	else {
		cout << "您要修改的联系人不存在" << endl;
	}

	system("pause");
	system("cls");
}

//6、情况联系人
void cleanPerson(Addressbooks *abs) {
	abs->m_Size = 0;//做逻辑上的清空
	cout << "通讯录已清空" << endl;

	system("pause");
	system("cls");
}

//菜单界面
void showMenu() {
	cout << "1、添加联系人" << endl;
	cout << "2、显示联系人" << endl;
	cout << "3、删除联系人" << endl;
	cout << "4、查找联系人" << endl;
	cout << "5、修改联系人" << endl;
	cout << "6、清空联系人" << endl;
	cout << "0、退出通讯录" << endl;
}

int main() {

	Addressbooks abs;//创建通讯录结构体变量
	abs.m_Size = 0;

	int select = 0;//创建用户选择输入的变量

	while (true) {
		//调用菜单
		showMenu();

		cin >> select;
		switch (select) {
		case 1://1、添加联系人
			addPerson(&abs);
			break;
		case 2://2、显示联系人
			showPerson(&abs);
			break;
		case 3://3、删除联系人
			deletePreson(&abs);
			break;
		case 4://4、查找联系人
			findPerson(&abs);
			break;
		case 5://5、修改联系人
			modifyPerson(&abs);
			break;
		case 6://6、清空联系人
			cleanPerson(&abs);
			break;
		case 0://0、退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;//直接退出整个通讯录管理系统
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}
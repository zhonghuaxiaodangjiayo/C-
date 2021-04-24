#include <iostream>
#include <string>
#define MAX 1000 //ͨѶ¼��������ݶ�1000

using namespace std;

/*
����ܹ���ʵ�֣��˵����˳��������ϵ�ˡ���ʾ��ϵ�ˡ�ɾ����ϵ�ˡ�������ϵ�ˡ�
�޸���ϵ�ˡ������ϵ�˹���
*/

/*
�����ϵ�˹��ܵľ���ʵ�֣�
�����ϵ�˽ṹ�塢���ͨѶ¼�ṹ�塢main�����д���ͨѶ¼����װ�����ϵ�˵ĺ�����
���������ϵ�˵Ĺ���
*/
//��ϵ�˽ṹ��
struct Person {
	//����
	string m_Name;
	//�Ա� 1 �� 2Ů
	int m_Sex;
	//����
	int m_Age;
	//�绰
	string m_Phone;
	//סַ
	string m_Addr;
};

//ͨѶ¼�ṹ��
struct Addressbooks {
	//��ϵ�˵�����
	struct Person personArray[MAX];
	//��ǰ��ϵ�˸���
	int m_Size;
};

//1�������ϵ��
void addPerson(Addressbooks *abs)
 {
	//�ж�ͨѶ¼�Ƿ���
	if (abs->m_Size == MAX) {
		cout << "ͨѶ¼�������޷����" << endl;
	}
	else {
		//�����ϵ��

		//����
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1������" << endl;
		cout << "2����Ů" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;//���������ˣ���������whileѭ��������һֱѭ��ֱ��������ȷΪֹ
			}
			else {
				cout << "�����������������룡" << endl;
			}
		}

		//����
		cout << "���������䣺" << endl;
		int age = 0;
		while (true) {
			cin >> age;
			if (age>=0 &&age<=150) {
				abs->personArray[abs->m_Size].m_Age = age;
				break;//���������ˣ���������whileѭ��������һֱѭ��ֱ��������ȷΪֹ
			}
			else {
				cout << "�����������������룡" << endl;
			}
		}
		//�绰
		cout << "������绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//סַ
		cout << "�������ͥ�ַ���" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;
		 //����ͨѶ¼������
		abs->m_Size++;

		cout << "��ӳɹ�" << endl;

		system("pause");//�밴���������
		system("cls");//��������

	}
}

//2����ʾ��ϵ��
void showPerson(Addressbooks *abs) {
	//�ж�ͨѶ¼�������Ƿ�Ϊ0
	if (abs->m_Size == 0) {
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "������" << abs->personArray[i].m_Name << "\t";
			cout << "�Ա�" <<(abs->personArray[i].m_Sex==1? "��":"Ů") << "\t";
			cout << "���䣺" << abs->personArray[i].m_Age << "\t";
			cout << "�绰��" << abs->personArray[i].m_Phone << "\t";
			cout << "סַ��" << abs->personArray[i].m_Addr<< endl;
		}
	}
	system("pause");//�����������
	system("cls");//��Ļ����
}

//3��ɾ����ϵ��
//3.1��װһ�����������ڼ����ϵ���Ƿ���ڣ����ڷ��������������ڷ���-1
int isExist(Addressbooks *abs, string name) {
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArray[i].m_Name == name) {
			return i;
		}
		return -1;
	}
}
//3��ɾ����ϵ��
void deletePreson(Addressbooks *abs) {
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;

	int ret=isExist(abs,name);
	if (ret != -1) {
		//�鵽���ˣ�ɾ��
		for (int i = ret; i < abs->m_Size; i++) {
			abs->personArray[i] = abs->personArray[i + 1];//����ǰ��
		}
		abs->m_Size--;//����������
		cout << "ɾ���ɹ�" << endl;
	}
	else {
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

//4��������ϵ��
void findPerson(Addressbooks *abs) {
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	//�ж���ϵ���Ƿ����
	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << "������" << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա�" << abs->personArray[ret].m_Sex << "\t";
		cout << "���䣺" << abs->personArray[ret].m_Age << "\t";
		cout << "�绰��" << abs->personArray[ret].m_Phone << "\t";
		cout << "סַ��" << abs->personArray[ret].m_Addr << endl;
	}else {
		cout << "���޴���" << endl;
	}

	system("pause");
	system("cls");
}

//5���޸���ϵ��
void modifyPerson(Addressbooks *abs) {
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1) {
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		//�Ա�
		int sex;
		cout << "�������Ա�" << endl;
		cout << "1������" << endl;
		cout << "2����Ů" << endl;
		cin >> sex;
		abs->personArray[ret].m_Sex = sex;
		//����
		int age;
		cout << "���������䣺" << endl;
		cin >> age;
		abs->personArray[ret].m_Age = age;
		//�绰
		string phone;
		cout << "������绰��" << endl;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		//סַ
		string address;
		cout << "������סַ��" << endl;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

		cout << "�޸ĳɹ�" << endl;
	}
	else {
		cout << "��Ҫ�޸ĵ���ϵ�˲�����" << endl;
	}

	system("pause");
	system("cls");
}

//6�������ϵ��
void cleanPerson(Addressbooks *abs) {
	abs->m_Size = 0;//���߼��ϵ����
	cout << "ͨѶ¼�����" << endl;

	system("pause");
	system("cls");
}

//�˵�����
void showMenu() {
	cout << "1�������ϵ��" << endl;
	cout << "2����ʾ��ϵ��" << endl;
	cout << "3��ɾ����ϵ��" << endl;
	cout << "4��������ϵ��" << endl;
	cout << "5���޸���ϵ��" << endl;
	cout << "6�������ϵ��" << endl;
	cout << "0���˳�ͨѶ¼" << endl;
}

int main() {

	Addressbooks abs;//����ͨѶ¼�ṹ�����
	abs.m_Size = 0;

	int select = 0;//�����û�ѡ������ı���

	while (true) {
		//���ò˵�
		showMenu();

		cin >> select;
		switch (select) {
		case 1://1�������ϵ��
			addPerson(&abs);
			break;
		case 2://2����ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3://3��ɾ����ϵ��
			deletePreson(&abs);
			break;
		case 4://4��������ϵ��
			findPerson(&abs);
			break;
		case 5://5���޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6://6�������ϵ��
			cleanPerson(&abs);
			break;
		case 0://0���˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;//ֱ���˳�����ͨѶ¼����ϵͳ
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}
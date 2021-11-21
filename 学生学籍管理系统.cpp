#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;
class Student        //ѧ����
{
public:
	//���º��������Student���е�˽�г�Ա���������Ϊ��Ԫ����
	friend void Delete();
	friend void Recompose();
	friend void Find();
	friend void Count();
	friend void PutOutFile();
	friend void PutInFlie();

	void setStu()
	{
		cin >> Number >> Name >>Gender >> Age >> Class >> Major >> Department;
	}
	void showStu()
	{
		cout << Number <<'\t' << Name << '\t' << Gender << '\t'
			<< Age << '\t' << Class << '\t' <<'\t'<< Major << '\t'
			<< '\t' << Department << endl;
	}
private:
	string Number;        //ѧ��
	string Name;          //����
	string Gender;        //�Ա�
	int Age;              //����
	string Class;         //���
	string Major;         //רҵ����
	string Department;    //ϵ��
};



vector<Student> stu;       //��vector����������ѧ������
int total = 0;              //¼���ѧ������



void Input()           //¼����Ϣ����
{
	int n;          //Ҫ¼����Ϣ��ѧ������
	cout << "ִ�С�¼��ѧ����Ϣ������---------->������Ҫ¼����Ϣ��ѧ��������";
	cin >> n;
	cout << "����������ѧ����ѧ�š��������Ա����䡢��š�רҵ���ơ�ϵ��" << endl;
	for (int i = 0; i < n; i++)
	{
		Student S;
		S.setStu();
		stu.push_back(S);    //�������ѧ����Ϣ����vector<Student>������
	}
	total += n;
}



void Delete()          //ɾ����Ϣ����
{
	cout << "ִ�С�ɾ��ѧ����Ϣ������---------->������Ҫɾ��ѧ����ѧ�ţ�";
	string num;
	cin >> num;
	//�õ�������������������Ԫ�أ����ڲ��Һ�ɾ��
	vector<Student>::iterator it = stu.begin();
	for (; it != stu.end(); it++)
	{
		if ((*it).Number == num)
		{
			stu.erase(it);    //ɾ��������itָ���ѧ����Ϣ
			total--;       //ɾ��һ��ѧ������Ϣ��ϵͳ��¼ѧ����������һ
			cout << "--------->ѧ��Ϊ" << num << "��ѧ������Ϣ��ɾ����" << endl;
			return;
		}
	}
	cout << "--------->δ�ҵ�ѧ��Ϊ" << num << "��ѧ��������ѧ���Ƿ��������" << endl;
}



void Recompose()           //�޸�ѧ����Ϣ
{
    cout<< "ִ�С��޸�ѧ����Ϣ������---------->������Ҫ�޸�ѧ����ԭѧ�ţ�";
	string num;
	cin >> num;
	//�õ�������������������Ԫ�أ����ڲ��Һ�ɾ��
	vector<Student>::iterator it = stu.begin();
	for (; it != stu.end(); it++)
	{
		if ((*it).Number == num)
		{
			cout << "���������޸ĺ��ѧ����ѧ�š��������Ա����䡢��š�רҵ���ơ�ϵ��" << endl;
			(*it).setStu();    //���ó�Ա�������¸���ѧ�������Ը�ֵ
			cout << "--------->ԭѧ��Ϊ"<<num<<"��ѧ������Ϣ���޸ģ�" << endl;
			return;
		}
	}
	cout << "--------->δ�ҵ�ѧ��Ϊ" << num << "��ѧ��������ѧ���Ƿ��������" << endl;
}



void Find()               //��ѯѧ������Ϣ
{
	cout  << "=========��a����ѧ�Ų�ѯ����ѧ����Ϣ" << endl;
	cout  << "=========��b����������ѯ����ѧ����Ϣ" << endl;
	cout  << "=========��c�����Ա��ѯѧ����Ϣ" << endl;
	cout  << "=========��d������Ų�ѯѧ����Ϣ" << endl;
	cout  << "=========>������������ѡ���ѯ���";
	char x;
	cin >> x;
	switch (x)
	{
	case 'a':
	{
		cout << "��ѡ�񡰰�ѧ�Ų�ѯ����ѧ����Ϣ��---------->�������ѧ����ѧ�ţ�";
		string num;
		cin >> num;
		vector<Student>::iterator it = stu.begin();
		cout << "--------->��ѧ���Ļ�����Ϣ���£�" << endl;
		for (; it != stu.end(); it++)
		{
			if ((*it).Number == num)
			{
				(*it).showStu();
				break;
			}
		}
		if (it == stu.end())
			cout << "--------->δ��ѯ��ѧ��Ϊ" << num << "��ѧ��" << endl;
	}break;
	case 'b':
	{
		int flag=0;        //����ѯ�����ѧ������flag=1
		cout << "��ѡ�񡰰�������ѯ����ѧ����Ϣ��---------->�������ѧ����������";
		string name;
		cin >> name;
		vector<Student>::iterator it = stu.begin();
		cout << "--------->��ѧ���Ļ�����Ϣ���£�" << endl;
		for (; it != stu.end(); it++)
		{
			if ((*it).Name == name)
			{
				(*it).showStu();
				//���ǵ�ѧ�����ܳ���ͬ��������˴�����break����˳�ѭ��
				flag = 1;
			}
		}
		if (flag != 1)
			cout << "--------->δ��ѯ��Ϊ����Ϊ��" << name << "��ѧ��" << endl;
	}break;
	case 'c':
	{
		cout << "��ѡ�񡰰��Ա��ѯѧ����Ϣ��---------->������Ҫ��ѯѧ�����Ա�";
		string gender;
		cin >> gender;
		vector<Student>::iterator it = stu.begin();
		cout <<"--------->"<< gender << "��ѧ������Ϣ���£�" << endl;
		for (; it != stu.end(); it++)
		{
			if ((*it).Gender == gender)
			{
				(*it).showStu();
			}
		}
	}break;
	case 'd':
	{
		cout << "��ѡ�񡰰���Ų�ѯѧ����Ϣ��---------->������Ҫ��ѯѧ���İ�ţ�";
		string class2;
		cin >> class2;
		vector<Student>::iterator it = stu.begin();
		cout << "--------->" << class2 << "��ѧ������Ϣ���£�" << endl;

		for (; it != stu.end(); it++)
		{
			if ((*it).Class == class2)
			{
				(*it).showStu();
			}
		}
	}break;
	}
}



void Count()         //ͳ��ѧ����Ϣ
{
	cout  << "=========��a�����Ա�ͳ��ѧ������" << endl;
	cout  << "=========��b�������ͳ��ѧ������" << endl;
	cout  << "=========��c��������ͳ��ѧ������" << endl;
	cout  << "=========��d����ϵ��ͳ��ѧ������" << endl;
	cout  << "========>������������ѡ��ͳ�����";
	char x;
	cin >> x;
	switch (x)
	{
	case 'a':
	{
		cout << "��ѡ�񡰰��Ա�ͳ��ѧ��������---------->������Ҫͳ�Ƶ�ѧ�����Ա�";
		string gender;
		cin >> gender;
		int totalA = 0;
		vector<Student>::iterator it = stu.begin();
		for (; it != stu.end(); it++)
		{
			if ((*it).Gender == gender)
			{
				totalA++;
			}
		}
		cout << "--------->" << gender << "��ѧ������" << totalA << "��" << endl;
	}break;
	case 'b':
	{
		cout << "��ѡ�񡰰����ͳ��ѧ��������---------->������Ҫͳ�Ƶ�ѧ���İ�ţ�";
		string class2;
		cin >> class2;
		int totalB = 0;
		vector<Student>::iterator it = stu.begin();
		for (; it != stu.end(); it++)
		{
			if ((*it).Class == class2)
			{
				totalB++;
			}
		}
		cout << "--------->" << class2 << "��ѧ������" << totalB << "��" << endl;
	}break;
	case 'c':
	{
		cout << "��ѡ�񡰰�����ͳ��ѧ��������---------->������Ҫͳ�Ƶ�ѧ�������䣺";
		int age;
		cin >> age;
		int totalC = 0;
		vector<Student>::iterator it = stu.begin();
		for (; it != stu.end(); it++)
		{
			if ((*it).Age == age)
			{
				totalC++;
			}
		}
		cout << "--------->" << "����Ϊ"<<age << "���ѧ������" << totalC << "��" << endl;
	}break;
	case 'd':
	{
		cout << "��ѡ�񡰰�ϵ��ͳ��ѧ��������---------->������Ҫͳ�Ƶ�ѧ����ϵ��";
		string dep;
		cin >> dep;
		int totalD = 0;
		vector<Student>::iterator it = stu.begin();
		for (; it != stu.end(); it++)
		{
			if ((*it).Department == dep)
			{
				totalD++;
			}
		}
		cout << "--------->" <<dep << "��ѧ������" << totalD << "��" << endl;
	}break;
}
}


//ɾ���ļ��еĵ�һ�У�ѧ��	����	�Ա�	����	���	רҵ	ϵ��
//ɾ�����к������ȷ�ذ�����д�뵽Student���vector������
void DeleteFirstLine()
{
	//���ļ��е���������д������vec��
	vector<string> vec;
	string strLine;   //��¼�ļ���ÿһ��
	ifstream inFile("ѧ��ѧ����Ϣ.txt", ios::in);
	while (inFile)
	{
		getline(inFile, strLine);   //���ж�ȡ�ļ����ݵ�strLine��
		vec.push_back(strLine);     //����ȡ��һ�����ݷ���������
	}
	inFile.close();

	//ɾ����һ��
	vec.erase(vec.begin());

	//��ʣ�����������д�ص��ļ���
	ofstream outFile("ѧ��ѧ����Ϣ.txt", ios::out);
	vector<string>::const_iterator it = vec.begin();
	for (; it != vec.end(); it++)
	{
		//���н�vec�����е�����д���ļ���
		outFile.write((*it).c_str(), (*it).size());
		outFile << endl;
	}
	outFile.close();          //�ر��ļ�
}



void PutOutFile()        //��ȡ�ļ��е����ݣ������뵽vector<Student>������
{
	ifstream ifs;          //����������
	//���ļ������ж��Ƿ�򿪳ɹ�
	ifs.open("ѧ��ѧ����Ϣ.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}

	string number, name, gender;
	int age;
	string class1, major, dep;
	//���ϱ������ڴ���ļ�ÿһ�ж�Ӧ��ѧ����Ϣ���ݣ��Ա����ļ��е�ÿһ�����ݴ���һ��ѧ������󣬲���ŵ�stu������

	while (ifs >> number >> name >> gender >> age >> class1 >> major >> dep)
	{
		Student s;
		s.Number = number;
		s.Name = name;
		s.Gender = gender;
		s.Age = age;
		s.Class = class1;
		s.Major = major;
		s.Department = dep;
		stu.push_back(s);
		total++;        //ÿ����һ��ѧ������󲢴�������stu�У���ѧ��������һ
	}
	ifs.close();          //�ر��ļ�
}



void PutInFlie()          //��ѧ����Ϣ�洢��д�룩���ļ���
{
	//��Student�������г�Ա��Ϣ�洢��д�룩���ļ���
	ofstream ofs;       //����������
	//�״�Ĭ�ϴ���һ��"ѧ��ѧ����Ϣ.txt"�ļ����뱾��Ŀͬ���ļ�����
	ofs.open("ѧ��ѧ����Ϣ.txt", ios::out);
	//��ѧ����Ϣ����д���ļ���
	ofs << "ѧ��" << '\t' << "����" << '\t' << "�Ա�" << '\t' << "����" << '\t'
		<< "���" << '\t' << '\t' << "רҵ" << '\t' << '\t' << '\t' << "ϵ��"<<endl;
	for (int i = 0; i < total; i++)
	{
		ofs << stu[i].Number << '\t' << stu[i].Name << '\t' << stu[i].Gender
			<< '\t' << stu[i].Age << '\t' << stu[i].Class
			<< '\t' << '\t' << stu[i].Major << '\t' << '\t' << '\t' << stu[i].Department << endl;
	}
	ofs.close();      //�ر��ļ�
}



int main()
{
	DeleteFirstLine();   //���ļ��е�һ�У�ѧ��  ����  �Ա�  ����  ���  רҵ  ϵ��ɾ��
	PutOutFile();         //ɾ���ļ���һ�к󣬽��ļ��е�ѧ����Ϣ����ѧ�����vector������

	/*���Խ��ļ��е����ݵ��������������Ч��
	for (int i = 0; i < total; i++)
	{
		stu[i].showStu();
	}
	*/

	cout << "==========================ѧ��ѧ������ϵͳ==========================" << endl;
	int x=0;         //��¼�û�ѡ���ܵ����
	while (x != 6)   //���û�û��ѡ���˳�ϵͳ����ÿִ����һ�����ܺ�������ʾ�˵����û�ѡ��
	{
		cout << endl << endl;
		cout << "|-------------------------------�˵�-------------------------------|" << endl;
		cout << "|======================��1��ѧ��������Ϣ��¼��=====================|" << endl;
		cout << "|======================��2��ѧ��������Ϣ��ɾ��=====================|" << endl;
		cout << "|======================��3��ѧ��������Ϣ���޸�=====================|" << endl;
		cout << "|======================��4��ѧ��������Ϣ�Ĳ�ѯ=====================|" << endl;
		cout << "|======================��5��ѧ��������Ϣ��ͳ��=====================|" << endl;
		cout << "|======================     ��6���˳�ϵͳ     =====================|" << endl;
		cout << "|------------------------------------------------------------------|" << endl;
		cout << "������������ѡ����Ҫִ�еĹ��ܣ�";
		cin >> x;     //�û����ݲ˵����빦�ܶ�Ӧ���
		if (x == 6)
		{
			cout << "***************ѧ��ѧ������ϵͳ���˳���";
			break;
		}
		switch (x)
		{
		case 1:
		{
			Input();
			cout << "����ɡ�¼��ѧ����Ϣ������������س���������...";
			getchar();
			getchar();
		} break;

		case 2:
		{
		    Delete();
			cout << "����ɡ�ɾ��ѧ����Ϣ������������س���������...";
			getchar();
			getchar();
		}break;

		case 3:
		{
			Recompose();
			cout << "����ɡ��޸�ѧ����Ϣ������������س���������...";
			getchar();
			getchar();
		}break;

		case 4:
		{
			Find();
			cout << "����ɡ���ѯѧ����Ϣ������������س���������...";
			getchar();
			getchar();
		}break;

		case 5:
		{
			Count();
			cout << "����ɡ�ͳ��ѧ����Ϣ������������س���������...";
			getchar();
			getchar();
		}break;

		}
	}
	PutInFlie();      //��ѧ����Ϣ�洢��д�룩���ļ���
	return 0;
}

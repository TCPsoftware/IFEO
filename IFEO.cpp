#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
void end(bool);
void read();
void add(string str);
	ifstream fin;
	string s;
int main(){
	string ss="ʹ��ǰ�����Ƿ��ѹ���ԱȨ�����У�����һ�����޷����룡\n\n��ر�����ɱ����������̨���̣������ܾ����ʣ�\n\n����ʱ����ÿһ�ε�ȷ����ť���鿴��ʾ���Ƿ�ɹ�����\n\n��ȷ�ϴ˳������Թ���ԱȨ��ִ�еģ�������ǣ���㡰�񡱽���ִ��\n���Թ���ԱȨ����������\n\n\n\n"; 
	int re = MessageBox(NULL,ss.c_str(),"��ʾ", MB_ICONINFORMATION|MB_YESNO);
	if(re == 7){
		end(false);
		exit(0);
	}
//	system("del gmon.out /s /q");
	fin.open("ifeo.txt");
	if( (bool)(fin>>s) == false){
		string sss="��⵽��û�б�дIFEO.txt\n\n�뽫Ҫӳ��ٳֵĳ�������д����Ŀ¼��IFEO.txt��\n\nÿ��һ������Ҫ����ո���У�\n\nȻ�������д˳���\n\n��д��ȥ����Щ���򽫲�������\n\n���棬����ȷд���ļ�������д�ļ������ܻ����ϵͳ���⣡����\n\n";
		MessageBox(NULL,sss.c_str(),"δ�ҵ�IFEO.txt", MB_ICONSTOP);
		fin.close();
		end(false);
	}
	else{
		add(s);
		read();
		fin.close();
		end(true);
	}
	return 0;
}
void read(){
	while( (bool)(fin>>s) != false){
		add(s);
	}
};
void add(string str){
	ofstream fout;
	string comm = "IFEO-"+str+".reg";
	fout.open(comm.c_str());
	fout<<"Windows Registry Editor Version 5.00"<<endl;
	fout<<endl;
	fout<<"[HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\"+str+"]"<<endl;
	fout<<"@=\"\""<<endl;
	fout<<"\"Debugger\"=\"cmd /c exit\""<<endl<<endl;
	fout.close();
	string comm1;
	comm1 = "regedit "+comm;
	system(comm1.c_str());
	string comm2;
	comm2 = "del "+comm+" /s /q";
	system(comm2.c_str());
};
void end(bool flag){
	ofstream fout;
	if(flag){
		cout<<"\n\n\n���в����Ѿ���ɣ�\n\n";
		system("pause");
	}
	else{
		cout<<"\n\n\n����ʧ��\n\n"; 
		system("pause");
	}
	fout.open("TEMP_RUN.bat");
	fout<<"timeout 3 & del gmon.out /q /s & del TEMP_RUN.bat & exit /q /s"<<endl;
//	fout<<"del TEMP_RUN.bat /q /s"<<endl;
//	fout<<"exit"<<endl;
	fout.close();

	system("cmd /c start TEMP_RUN.bat");
//	system("del gmon.out /s /q");
};

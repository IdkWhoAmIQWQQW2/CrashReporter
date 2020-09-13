/*
*GTPS Auto Restarter & Crash Reporter by Kaan#7777 (github.com/zKaan)
*Please don't sell this application, this application is FREE.
*Please don't change owner name to your name.
*/


#include <iostream>
#include <fstream>
#include <windows.h>
#include <time.h>
#include <string>
#include <ctime>

#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

using namespace std;

int main()
{
	int number;
	system("color 0b");
	system("title GTPS Crash Reporter and Auto Restarter");
	cout << "\t \t GTPS Crash Reporter & Auto Restarter by Kaan#7777" << endl;
	cout << "\t \t Check my repos at github.com/zKaan." << endl;
	cout << "\n \n \t \t Welcome to Crash Reporter & Auto Restarter." << endl;
	cout << "\t \t This application will open automatically if your server.exe is shut down." << endl;
	cout << "\t \t This application will keep crash logs in crashlogs.txt." << endl;
	cout << "\t \t Close your gtps.exe and rename to server and run this application" << endl;
	cout << "\n \t \t Enter 1 if you already did all : ";
	cin >> number;

	if (number != 1) {

		system("cls");
		cout << "You have to enter 1 if you want to run Crash Reporter & Auto Restarter!" << endl;
		system("pause");
	}
	if (number == 1) {

		cout << "\n \n \t \t Exe will open in 2 seconds!" << endl;

		ofstream CrasherZ("crashlogs.txt", ios::app);
		CrasherZ << "\n[RESTART] Crash Reporter & Auto Restarter Re-Opened!" << endl;
		CrasherZ.close();

		while (true)
		{
			system("start /wait server.exe"); // if your gtps.exe's name isn't server, change here to your server name
			time_t _tm = time(NULL);
			struct tm* curtime = localtime(&_tm);
			string GetTimeCr = asctime(curtime);
			ofstream LogsCR;
			LogsCR.open("crashlogs.txt", ios::app);
			LogsCR << "[CRASH] Exe re-opened at " << GetTimeCr;
			LogsCR.close();
			system("color 04");
			cout << "[WARNING]\t \t Exe re-opened at : " << GetTimeCr << endl;
		}
	}
}

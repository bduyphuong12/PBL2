#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

//Ham thay doi kich co cua khung cmd voi tham so truyen vao la chieu cao, chieu rong
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

// ham to mau
void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

// ham dich chuyen con tro den toa do x y
void gotoxy(int x,int y)
{    
	HANDLE hConsoleOutput;    
	COORD Cursor_an_Pos = {x-1,y-1};   
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);    
	SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}

// ham xoa man hinh
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

// ham lay key tu ban phim
/* GetAsyncKeyState(VK_ESCAPE) => bat su kien him Esc */ 

// ham tu viet	
void ToMau(int x, int y, char *a, int color) // x y la toa do con tro can nhay den de viet, a la chuoi can truyen vao, color la mau can truyen vao
{
	gotoxy(x, y);
	textcolor(color);
	cout << a;
	textcolor(7);
}

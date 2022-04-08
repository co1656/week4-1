#pragma once
#include <iostream>
#include <Windows.h>
#include <chrono>
#include <thread>


using namespace std;

namespace MuSeoun_Engine
{
	class MGameLoop
	{
	private:
		bool _isGameRunning;

	public:
		MGameLoop() 
		{
			_isGameRunning = false; 
		}
		~MGameLoop() {}

		void Run()
		{
			_isGameRunning = true;

			initialize();

			while (_isGameRunning)
			{
				Input();
				Update();
				Render();
			}

			Release();
		}

		void Stop()
		{
			_isGameRunning = false;
		}


	private :

		int playerCoordX, playerCoordY;
		bool isKeyPressed;

		void initialize()
		{
			playerCoordX = 0;
			playerCoordY = 0;

			isKeyPressed = false;

			SetCursorState(false);
		}

		void Input()
		{
			if (GetAsyncKeyState(VK_SPACE) == -0x8000 || GetAsyncKeyState(VK_SPACE) == -0x8001)
			{
				
		    }
			else
			{
				
			}
		}
		void Update()
		{
			
		}
		void Render()
		{
			chrono::system_clock::time_point startRenderTimePonit = chrono::system_clock::now();
			//system("cls");
			cout << "Rendering...";

			chrono::duration<double> renderDuration = chrono::system_clock::now() - startRenderTimePonit;
			cout << "Rendering speed : " << renderDuration.count() << "sec" << endl;

			int remainingFrameTime = 100 - (int)(renderDuration.count() * 1000.0);
			
			if (remainingFrameTime > 0)
				this_thread::sleep_for(chrono::milliseconds(remainingFrameTime));
			
		}

		void Release(){}

	private: //게임사용함수 

		void MoveCursor(short x, short y)
		{
			COORD position = {  x , y };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
		}

		void SetCursorState(bool isActive)
		{
			CONSOLE_CURSOR_INFO consoleCursorinfo;
			consoleCursorinfo.bVisible = isActive;
			consoleCursorinfo.dwSize = 1;

			SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleCursorinfo);
		}
	};
}
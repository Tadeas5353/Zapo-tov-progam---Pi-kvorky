#include <iostream>
#include <vector>
#include <clocale>
#include <windows.h>
#include <windows.graphics.h>
#include "Window.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	Window window;

	if (!window.Create(hInstance, nCmdShow)) {
		return 0;
	}

	MSG msg = {};
	while (GetMessage(&msg, nullptr, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}
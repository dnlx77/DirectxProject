#include <Windows.h>

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	const auto pClassName = "Prova";
	WNDCLASSEX wc = { 0 };
	
	wc.cbClsExtra = 0;
	wc.cbSize = sizeof(wc);
	wc.lpfnWndProc = DefWindowProc;
	wc.hInstance = hInstance;
	wc.hCursor = nullptr;
	wc.lpszClassName = pClassName;
	wc.hIcon = nullptr;
	wc.style = CS_OWNDC;
	wc.cbWndExtra = 0;
	wc.hbrBackground = nullptr;

	RegisterClassEx(&wc);



	return 0;
}
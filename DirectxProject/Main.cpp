#include <Windows.h>

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	/* Creazione della windows class*/

	const auto pClassName = "Prova";  // Nome della classe
	WNDCLASSEX wc = { 0 };

	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = pClassName;
	wc.hIconSm = nullptr;

	RegisterClassEx(&wc);

	const auto pWindowName = "Prima finestra";

	/* Creazione della finestra*/

	HWND hWnd = CreateWindowExA(
		0,
		pClassName,
		pWindowName,
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		200, 200, 640, 480,
		nullptr,
		nullptr,
		hInstance,
		nullptr
	);

	MSG msg;

	ShowWindow(hWnd, SW_SHOW);

	/* Gestione dei messaggi*/
	
	BOOL bRet;

	while (bRet = GetMessage(&msg, nullptr, 0, 0) >= 0) {
		
		if (bRet == 0)
			return WPARAM(msg.wParam);
		else {
			TranslateMessage(&msg);
			DispatchMessageA(&msg);
		}
	}

	return 0;

}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {

	switch (msg) {
		case WM_CLOSE:
			PostQuitMessage(1);
			break;

		case WM_QUIT:
			return WPARAM(wParam);
	}

	return DefWindowProc (hWnd, msg, wParam, lParam);
}

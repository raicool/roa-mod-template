#include "callback.h"

void wndproc(
	const HWND hWnd,
	UINT& uMsg,
	WPARAM& wParam,
	LPARAM& lParam
)
{
	// This callback is ran before WndProc is processed for the main Rivals of Aether executable thread
	// Editing uMsg, wParam, or lParam will also edit the values passed to the main thread

	if (uMsg == WM_KEYDOWN && wParam == VK_ESCAPE)
	{
		__debugbreak();
	}

	return;
}


void present(
	ID3D11RenderTargetView* render_target,
	IDXGISwapChain* swapchain,
	ID3D11Device* d3d_device,
	ID3D11DeviceContext* d3d_device_context
)
{
	// This callback is ran before IDXGISwapChain::Present is called for the main Rivals of Aether executable thread
	// Editing any values pointed to by the function parameter will also edit the values passed to the main thread

	return;
}
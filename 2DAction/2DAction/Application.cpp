#include "Application.h"
#include <DxLib.h>
#include "Scene/SceneController.h"
#include "Common/Geometry.h"

namespace
{
	bool _isExit = false;
	Size wsize = { 1024,768 };
}

Application& Application::Instance()
{
	static Application instance;
	return instance;
}

Application::Application()
{
}

Application::~Application()
{
}

bool Application::Initialize(void)
{
	DxLib::SetGraphMode(wsize.w, wsize.h, 32);
	DxLib::ChangeWindowMode(true);
	DxLib::SetWindowText("1916047_‹gŒ´«Žj");
	if (DxLib_Init()) 
	{
		return false;
	}
	sceneController_.reset(new SceneController());

	DxLib::SetDrawScreen(DX_SCREEN_BACK);
	return true;
}

void Application::Run(void)
{
	while (DxLib::ProcessMessage() == 0) 
	{
		DxLib::ClsDrawScreen();
		sceneController_->Update();
		sceneController_->Draw(); 
		DxLib::ScreenFlip();

		if (_isExit) break;
	}
}

void Application::Terminate(void)
{
	DxLib_End();
}

void Application::Exit(void)
{
	_isExit = true;
}

const Viewport& Application::GetViewport() const
{
	return viewport_;
}

Size Viewport::GetSize() const
{
	return wsize;
}

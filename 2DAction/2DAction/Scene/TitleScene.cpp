#include "TitleScene.h"
#include <DxLib.h>
#include <string>
#include <cassert>
#include "../Application.h"
#include "../Common/Geometry.h"
#include "SceneController.h"

using namespace std;

namespace
{
	constexpr uint32_t blink_interval_normal = 45;		// 通常時のStart文字の点滅間隔
	constexpr uint32_t blink_interval_fast = 5;			// 高速点滅時のStart文字の点滅間隔
	constexpr uint32_t fade_interval = 45;				// フェードの時間
	unsigned int blinkInterval_ = blink_interval_normal;
	unsigned int waitTimer_;
	unsigned int blinkTimer_;
	
	int frame_;
}


TitleScene::TitleScene(SceneController& c) :
	Scene(c),
	updater_(&TitleScene::FadeinUpdate),
	drawer_(&TitleScene::FadeDraw)
{
	waitTimer_ = 0;
	blinkInterval_ = blink_interval_normal;

	frame_ = 0;
}

void TitleScene::FadeinUpdate()
{
	if (++waitTimer_ == fade_interval)
	{
		updater_ = &TitleScene::NormalUpdate;
		drawer_ = &TitleScene::NormalDraw;
	}
}

void TitleScene::NormalUpdate()
{
	/*if (CheckHitKey(KEY_INPUT_RETURN))
	{
		updater_ = &TitleScene::BlinkUpdate;
		blinkInterval_ = blink_interval_fast;
		waitTimer_ = 30;
	}*/
}

void TitleScene::BlinkUpdate()
{
	if (--waitTimer_ == 0)
	{
		updater_ = &TitleScene::FadeoutUpdate;
		waitTimer_ = fade_interval;
		drawer_ = &TitleScene::FadeDraw;
	}
}

void TitleScene::FadeoutUpdate()
{
	if (--waitTimer_ == 0)
	{
	}
}

void TitleScene::NormalDraw()
{
	
}

void TitleScene::FadeDraw()
{
	NormalDraw();

	auto blendparam = 255 * (static_cast<float>(fade_interval - waitTimer_) /static_cast<float>(fade_interval));
	SetDrawBlendMode(DX_BLENDMODE_MULA, static_cast<int>(blendparam));

	// フェード用の矩形描画
	const auto& vsize = Application::Instance().GetViewport().GetSize();
	DrawBox(0, 0, vsize.w, vsize.h, 0x000000, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void TitleScene::Update()
{
	(this->*updater_)();
	frame_++;
}

void TitleScene::Draw()
{

	(this->*drawer_)();

}

TitleScene::~TitleScene()
{
}

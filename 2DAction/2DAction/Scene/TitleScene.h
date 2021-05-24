#pragma once
#include "Scene.h"

class SceneController;

class TitleScene :
	public Scene
{
	friend SceneController;
private:
	TitleScene(SceneController& c);

	using UpdateFunctionTitle = void(TitleScene::*)();
	using DrawFunctionTitle = void(TitleScene::*)();

	UpdateFunctionTitle updater_;
	DrawFunctionTitle drawer_;

	// メンバ関数ポインタ用
	// Update系

	/// <summary>
	/// 遷移してきたときにフェードインする状態のアップデート関数
	/// </summary>
	void FadeinUpdate();

	/// <summary>
	/// ボタン入力待ち状態のアップデート関数
	/// </summary>
	void NormalUpdate();

	/// <summary>
	/// ボタンが入力された後,「Start」文字を高速点滅させる状態の
	/// アップデート関数
	/// </summary>
	void BlinkUpdate();

	/// <summary>
	/// 高速点滅が終わり、フェードアウトする状態のアップデート関数
	/// </summary>
	/// <param name=""></param>
	void FadeoutUpdate();

	// Draw系

	/// <summary>
	/// 特にエフェクトのない通常の状態の描画関数
	/// </summary>
	void NormalDraw();

	/// <summary>
	/// フェードしているときの描画関数
	/// </summary>
	void FadeDraw();
public:
	void Update() override;
	void Draw() override;
	~TitleScene();
};


#pragma once
#include <memory>
#include <deque>
#include <functional>

class Scene;
class Application;

class SceneController
{
	friend Application;
private:
	std::deque<std::shared_ptr<Scene>> scene_;
	SceneController();
	std::function<void(void)> postDrawExecuter_;
public:
	/// <summary>
	/// シーンの切り替えを行う
	/// </summary>
	/// <param name="scene">新しく切り替えるシーン</param>
	/// <attention>前のシーンは呼出し語に削除される為、
	/// この関数の呼び出し元が削除対象だった場合には、
	/// この関数の呼び出し後に処理を行ってはならない</attention>
	void ChangeScene(Scene* scene);

	/// <summary>
	/// シーンスタックを全削除し、新しいシーンに切り替える
	/// </summary>
	/// <param name="scene">新しく切り替えるシーン</param>
	/// <attention>前のシーンは呼出し語に削除される為、
	/// この関数の呼び出し元が削除対象だった場合には、
	/// この関数の呼び出し後に処理を行ってはならない</attention>
	void CleanChangeScene(Scene* scene);

	/// <summary>
	/// シーンをシーンスタックに積む
	/// </summary>
	/// <param name="scene">積むシーン</param>
	void PushScene(Scene* scene);

	/// <summary>
	/// シーンをシーンスタックから削除する
	/// </summary>
	void PopScene();

	/// <summary>
	/// シーンスタックの先頭のシーンの更新を行う
	/// </summary>
	void Update();

	/// <summary>
	/// シーンスタックにあるシーンをすべて描画する
	/// </summary>
	void Draw();

	~SceneController();
};
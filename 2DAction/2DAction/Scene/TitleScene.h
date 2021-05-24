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

	// �����o�֐��|�C���^�p
	// Update�n

	/// <summary>
	/// �J�ڂ��Ă����Ƃ��Ƀt�F�[�h�C�������Ԃ̃A�b�v�f�[�g�֐�
	/// </summary>
	void FadeinUpdate();

	/// <summary>
	/// �{�^�����͑҂���Ԃ̃A�b�v�f�[�g�֐�
	/// </summary>
	void NormalUpdate();

	/// <summary>
	/// �{�^�������͂��ꂽ��,�uStart�v�����������_�ł������Ԃ�
	/// �A�b�v�f�[�g�֐�
	/// </summary>
	void BlinkUpdate();

	/// <summary>
	/// �����_�ł��I���A�t�F�[�h�A�E�g�����Ԃ̃A�b�v�f�[�g�֐�
	/// </summary>
	/// <param name=""></param>
	void FadeoutUpdate();

	// Draw�n

	/// <summary>
	/// ���ɃG�t�F�N�g�̂Ȃ��ʏ�̏�Ԃ̕`��֐�
	/// </summary>
	void NormalDraw();

	/// <summary>
	/// �t�F�[�h���Ă���Ƃ��̕`��֐�
	/// </summary>
	void FadeDraw();
public:
	void Update() override;
	void Draw() override;
	~TitleScene();
};


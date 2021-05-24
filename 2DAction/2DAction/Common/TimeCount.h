#pragma once
#include <chrono>

// �v���O�����N������̎��Ԃ��v������N���X
// �O�t���[������̌o�ߎ��Ԃ��L������
class TimeCount
{
private:
	// �����֎~
	TimeCount();

	// �R�s�[�A����֎~
	TimeCount(const TimeCount&) = delete;
	void operator=(const TimeCount&) = delete;

	std::chrono::high_resolution_clock::time_point timePoint_;
	float nowCount_;
	float deltaTime_;

	float GetCount_();
	float GetDeltaTime_();
	void Update_();
	static TimeCount& Instance();

public:

	/// <summary>
	/// �Q�[�����N�����Ă���̎��Ԃ�Ԃ�
	/// </summary>
	/// <returns></returns>
	static float GetCount();

	/// <summary>
	/// �O�t���[������̌o�ߎ��Ԃ�Ԃ�
	/// </summary>
	/// <returns>�O�t���[������̌o�ߎ��ԁi1�b�𒴂�����0��Ԃ��j</returns>
	static float GetDeltaTime();
	static void Update();
	~TimeCount();
};


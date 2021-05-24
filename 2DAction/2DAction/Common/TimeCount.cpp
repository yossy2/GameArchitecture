#include "TimeCount.h"
#include <DxLib.h>

using namespace std::chrono;

TimeCount::TimeCount() :nowCount_(0),deltaTime_(0)
{
	timePoint_ = high_resolution_clock::now();
}

float TimeCount::GetCount_()
{
	return nowCount_;
}

float TimeCount::GetDeltaTime_()
{
	return deltaTime_;
}

void TimeCount::Update_()
{
	auto now = high_resolution_clock::now();

	microseconds micro = duration_cast<microseconds>(now - timePoint_);

	deltaTime_ = static_cast<float>(micro.count()) / 1000000.0f;
	//if (deltaTime_ > 1.0) deltaTime_ = 0;
	timePoint_ = now;
	nowCount_ += deltaTime_;
}

TimeCount& TimeCount::Instance()
{
	static TimeCount instance;
	return instance;
}

float TimeCount::GetCount()
{
	return Instance().GetCount_();
}

float TimeCount::GetDeltaTime()
{
	return Instance().GetDeltaTime_();
}

void TimeCount::Update()
{
	Instance().Update_();
}

TimeCount::~TimeCount()
{
}

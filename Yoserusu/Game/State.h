#ifndef INCLUDE_GAME_STATE_H_
#define INCLUDE_GAME_STATE_H_

#include "Game/Timer.h"
#include "Game/ArmLeft.h"
#include "Game/ArmRight.h"
#include "Mashiro/Graphics/Bitmap.h"

class Ball;
class Wall;
class BackGround;
class LockOn;

//ゲームプレイ本体
class State{
public:
	State();
	~State();

	void update();
	void draw();
	void init();
	bool timeUp() const;
	bool countDown() const;
	bool targetCheck() const;
private:
	Ball* ball;
	Wall* wall;
	Timer* timer;
	ArmLeft* lArm;
	ArmRight* rArm;
	BackGround* mBack;
	LockOn* mLockOn;

};

#endif
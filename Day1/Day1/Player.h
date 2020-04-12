#pragma once
#include <iostream>
#include "PlayerState.h"

using namespace std;

class PlayerState;

class Player
{
private:
	PlayerState *state;

public:
	Player();
	
	void SetState(PlayerState *state);
	void Move();
	void Eat();
	void Attack();
	void Idle();
};
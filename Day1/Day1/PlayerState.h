#pragma once

#include "Player.h"

using namespace std;

class PlayerState
{
public:
	virtual void Move(Player *player) = 0;
	virtual void Eat(Player *player) = 0;
	virtual void Attack(Player *player) = 0;
	virtual void Idle(Player *player) = 0;

protected:
	void SetPlayerState(Player *player, PlayerState *state)
	{
		player->SetState(state);
	}
};

class MoveState : public PlayerState
{
private:
	static MoveState *instance;

public:
	static MoveState *GetInstance();

	virtual void Move(Player *player);
	virtual void Eat(Player *player);
	virtual void Attack(Player *player);
	virtual void Idle(Player *player);
};

class IdleState : public PlayerState
{
private:
	static IdleState *instance;

public:
	static IdleState *GetInstance();

	virtual void Move(Player *player);
	virtual void Eat(Player *player);
	virtual void Attack(Player *player);
	virtual void Idle(Player *player);
};

class BattleState : public PlayerState
{
private:
	static BattleState *instance;

public:
	static BattleState *GetInstance();

	virtual void Move(Player *player);
	virtual void Eat(Player *player);
	virtual void Attack(Player *player);
	virtual void Idle(Player *player);
};

class HungryState : public PlayerState
{
private:
	static HungryState *instance;

public:
	static HungryState *GetInstance();

	virtual void Move(Player *player);
	virtual void Eat(Player *player);
	virtual void Attack(Player *player);
	virtual void Idle(Player *player);
};

class DeadState : public PlayerState
{
private:
	static DeadState *instance;

public:
	static DeadState *GetInstance();

	virtual void Move(Player *player);
	virtual void Eat(Player *player);
	virtual void Attack(Player *player);
	virtual void Idle(Player *player);
};
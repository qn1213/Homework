#include "PlayerState.h"

MoveState *MoveState::instance;
IdleState *IdleState::instance;
BattleState *BattleState::instance;
HungryState *HungryState::instance;
DeadState *DeadState::instance;


///////////////////////////////////////////////////////////////////

MoveState *MoveState::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new MoveState();
	}
	return instance;
}

void MoveState::Move(Player *player)
{
	cout << "걷는 상태 -> 걷는중!!!" << endl;
}

void MoveState::Eat(Player *player)
{
	cout << "걷는 상태 -> 먹는중!!!" << endl;
}

void MoveState::Attack(Player *player)
{
	cout << "걷는 상태 -> 공격중!!!" << endl;

	SetPlayerState(player, BattleState::GetInstance());
}

void MoveState::Idle(Player *player)
{
	cout << "걷는 상태 -> 쉬는중!!" << endl;

	SetPlayerState(player, IdleState::GetInstance());
}

///////////////////////////////////////////////////////////////////

IdleState *IdleState::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new IdleState();
	}
	return instance;
}

void IdleState::Move(Player *player)
{
	cout << "쉬는 상태 -> 걷는중!!!" << endl;
	SetPlayerState(player, MoveState::GetInstance());
}

void IdleState::Eat(Player *player)
{
	cout << "쉬는 상태 -> 먹는중!!!" << endl;
}

void IdleState::Attack(Player *player)
{
	cout << "쉬는 상태 -> 공격중!!!" << endl;
	SetPlayerState(player, BattleState::GetInstance());
}

void IdleState::Idle(Player *player)
{
	cout << "쉬는 상태 -> 쉬는중!!!" << endl;
}

///////////////////////////////////////////////////////////////////

BattleState *BattleState::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new BattleState();
	}
	return instance;
}

void BattleState::Move(Player *player)
{
	cout << "전투 상태 -> 걷는중!!!" << endl;
}

void BattleState::Eat(Player *player)
{
	cout << "전투 상태 -> 먹는중!!!" << endl;
}

void BattleState::Attack(Player *player)
{
	cout << "전투 상태 -> 공격중!!!" << endl;
	SetPlayerState(player, HungryState::GetInstance());
}

void BattleState::Idle(Player *player)
{
	cout << "전투 상태 -> 쉬는중!!!" << endl;
}

///////////////////////////////////////////////////////////////////

HungryState *HungryState::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new HungryState();
	}
	return instance;
}

void HungryState::Move(Player *player)
{
	cout << "배고픔 상태 -> 걷는중!!!" << endl;
}

void HungryState::Eat(Player *player)
{
	cout << "배고픔 상태 -> 먹는중!!!" << endl;
	SetPlayerState(player, IdleState::GetInstance());
}

void HungryState::Attack(Player *player)
{
	cout << "배고픔 상태 -> 공격중!!!" << endl;

	SetPlayerState(player, DeadState::GetInstance());
}

void HungryState::Idle(Player *player)
{
	cout << "배고픔 상태 -> 쉬는중!!" << endl;
}

///////////////////////////////////////////////////////////////////

DeadState *DeadState::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new DeadState();
	}
	return instance;
}

void DeadState::Move(Player *player)
{
	cout << "사망 상태 -> 걷는중!!!" << endl;
}

void DeadState::Eat(Player *player)
{
	cout << "사망 상태 -> 먹는중!!!" << endl;
}

void DeadState::Attack(Player *player)
{
	cout << "사망 상태 -> 공격중!!!" << endl;

}

void DeadState::Idle(Player *player)
{
	cout << "사망 상태 -> 쉬는중!!" << endl;
}
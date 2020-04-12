#include "Player.h"



Player::Player()
{
	state = IdleState::GetInstance();
}

void Player::SetState(PlayerState *state)
{
	this->state = state;
}

void Player::Move()
{
	state->Move(this);
}

void Player::Eat()
{
	state->Eat(this);
}

void Player::Attack()
{
	state->Attack(this);
}

void Player::Idle()
{
	state->Idle(this);
}
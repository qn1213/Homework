#include "Player.h"

int main()
{
	Player *player = new Player();

	player->Move();
	player->Move();
	player->Attack();
	player->Move();
	player->Attack();
	player->Eat();
	player->Move();
	player->Attack();
	player->Attack();
	player->Attack();
	player->Idle();

	delete player;
	return 0;
}
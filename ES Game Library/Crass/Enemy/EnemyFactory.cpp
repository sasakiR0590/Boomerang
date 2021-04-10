#include "EnemyFactory.h"

EnemyFactory::EnemyFactory() {

}

EnemyFactory::~EnemyFactory() {

}

EnemyBase* EnemyFactory::Create(string tag, Vector3 _position, Vector3 speed, int hp)
{
	EnemyBase* enemy_factory = CreateProduct(tag, _position);
	enemy_factory->Initialize(_position, speed, hp);
	return enemy_factory;
}

EnemyBase* EnemyFactory::CreateProduct(string tag, Vector3 _position) {
	if (tag == "move_enemy") { return new Enemy; }
	if (tag	== "stop_enemy") { return new StopEnemy; }
}
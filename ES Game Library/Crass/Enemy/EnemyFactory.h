#pragma once

#include "../../ESGLib.h"
#include"EnemyBase.h"
#include "StopEnemy.h"
#include"Enemy.h"

class EnemyFactory {
public:
	EnemyFactory::EnemyFactory();
	EnemyFactory::~EnemyFactory();

	EnemyBase* Create(string tag, Vector3 _position, Vector3 speed, int hp);
	EnemyBase* CreateProduct(string tag,Vector3 _position);
private:

};
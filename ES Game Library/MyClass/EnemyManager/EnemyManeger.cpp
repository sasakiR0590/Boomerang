#include"EnemyManeger.h"
#include"EnemyFactory/EnemyBase/EnemyBase.h"
#include <fstream>
#include"../EffectManager/EffectManager.h"
#include "../Data/WordsTable.h"
EnemyManager::EnemyManager()
{
	_enemy = {};
	
}

EnemyManager::~EnemyManager()
{
	//範囲for文
	for (auto& enemy : _enemy) {
		 delete enemy;
	}
}

bool EnemyManager::Initialize()
{
	for (int i = 0; i < ENEMY_NUM; ++i) {
		appear_pos [i] = Vector3_Zero;
		tag[i]         = INT_MAX;
		appear_time[i] = INT_MAX;
		appear_flag[i] = false;
	}

	LoadCSV();
	return true;
}

int EnemyManager::Update(PlayerManager* playermanager)
{
	_playermanager = playermanager;
	if(_frame < GAME_FRAME && _timemanager.StartFlag())
	   _frame++;
	else {
		_frame = 0;
		_time++;
	}

	if (_time > appear_time[count] && count < ENEMY_NUM) {
			Generate(_playermanager);
			count++;
	}

	auto itr = _enemy.begin();
	while (itr != _enemy.end()) {
		//Updateでreturnされた値 LIVING・・生きてる DEATH・・消去
			if ((*itr)->Update(_playermanager) == LIVING && (*itr)->AutoDead() == LIVING)
				itr++;
			else
			{
				//要素数が DEATH なら消去
				//itrの値の場所を削除しその場所から監視再開
				EffectManager::Instance().Create(EffectTag::EXPLOSION, (*itr)->GetPosition());
				itr = _enemy.erase(itr);
			}
	}

	return 0;
}

void EnemyManager::Draw()
{
	for (auto& enemy : _enemy) {
		enemy->Draw();
	}
}

void EnemyManager::Generate(PlayerManager* player_manager)
{
	unique_ptr<EnemyFactory> factory = std::make_unique<EnemyFactory>();

	if (!appear_flag[count])
	{
		_enemy.push_back(factory->Create(tag[count], appear_pos[count], player_manager));
		appear_flag[count] = true;
	}

}

void EnemyManager::OnCollisionEnter(EnemyBase* enemy)
{
	enemy->Damage();
	EffectManager::Instance().Create(EffectTag::HIT, _playermanager->GetBoomerang().GetCollision()->GetPosition());
}

void EnemyManager::LoadCSV() {
	std::ifstream pos_time_infile("csvFile/Enemy/EnemyPosition_AppearTime.txt");

	std::string dummy_line;
	
	//1～3行を読み飛ばし
	for (int i = 0; i < DUMMYLINENUM; i++) {
		getline(pos_time_infile, dummy_line);
	}
	
	//データ読み込み
	for (int i = 0; i < ENEMY_NUM; ++i) {
		pos_time_infile >> tag[i] >> appear_pos[i].x >> appear_pos[i].y >> appear_pos[i].z >> appear_time[i];
	}
}
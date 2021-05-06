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
	if(_frame < 60)
	   _frame++;
	else {
		_frame = 0;
		_time++;
	}

	if (_time > appear_time[count] && count < ENEMY_NUM) {
		Generate(playermanager);
		count++;
	}

	auto itr = _enemy.begin();
	while (itr != _enemy.end()) {

		//Updateでreturnされた値 0・・生きてる 1・・消去
			if ((*itr)->Update(playermanager) == LIVING && (*itr)->AutoDead() == LIVING)
				itr++;
			else
			{//要素数が 1 なら消去
				//itrの値を変更して値を一つ進める
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
	EffectManager::Instance().Create(EffectTag::HIT, enemy->GetPosition());
}

void EnemyManager::LoadCSV() {
	std::ifstream pos_time_infile("csvFile/Enemy/EnemyPosition_AppearTime.txt");

	std::string dummy_line;
	
	//1〜3行を読み飛ばし
	for (int i = 0; i < DUMMYLINENUM; i++) {
		getline(pos_time_infile, dummy_line);
	}
	
	//データ読み込み
	for (int i = 0; i < ENEMY_NUM; ++i) {
		pos_time_infile >> tag[i] >> appear_pos[i].x >> appear_pos[i].y >> appear_pos[i].z >> appear_time[i];
	}
}
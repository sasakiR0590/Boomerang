#include"EnemyManeger.h"
#include"EnemyBase.h"
#include <fstream>
#include"../EffectManager/EffectManager.h"
EnemyManager::EnemyManager()
{
	_enemy = {};
	
}

EnemyManager::~EnemyManager()
{
	//�͈�for��
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

int EnemyManager::Update()
{
	_time++;

	if (_time > appear_time[count] && count < ENEMY_NUM) {
		Generate();
		count++;
	}

	auto itr = _enemy.begin();
	while (itr != _enemy.end()) {

		//Update��return���ꂽ�l 0�E�E�����Ă� 1�E�E����
			if ((*itr)->Update() == LIVING)
				itr++;
			else
				//�v�f���� 1 �Ȃ����
				//itr�̒l��ύX���Ēl����i�߂�
				itr = _enemy.erase(itr);
	}
	return 0;
}

void EnemyManager::Draw()
{
	for (auto& enemy : _enemy) {
		enemy->Draw();
	}
}

void EnemyManager::Generate()
{
	unique_ptr<EnemyFactory> factory = std::make_unique<EnemyFactory>();

	if (!appear_flag[count])
	{		
		switch (tag[count])
		{
		case MOVE_ENEMY:
			_enemy.push_back(factory->Create("move_enemy", appear_pos[count]));
			appear_flag[count] = true;
			break;
		case STOP_ENEMY:
			_enemy.push_back(factory->Create("stop_enemy", appear_pos[count]));
			appear_flag[count] = true;
			break;

		}
	}

}

void EnemyManager::OnCollisionEnter(EnemyBase* enemy)
{
	enemy->Damage();
	EffectManager::Instance().Create("debug", enemy->GetPosition());
}

void EnemyManager::LoadCSV() {
	std::ifstream pos_time_infile("csvFile/Enemy/EnemyPosition_AppearTime.txt");

	std::string dummy_line;
	
	//1�E2�s��
	getline(pos_time_infile, dummy_line);
	getline(pos_time_infile, dummy_line);
	
	//�f�[�^�ǂݍ���
	for (int i = 0; i < ENEMY_NUM; ++i) {
		pos_time_infile >> tag[i] >> appear_pos[i].x >> appear_pos[i].y >> appear_pos[i].z >> appear_time[i];
	}
}
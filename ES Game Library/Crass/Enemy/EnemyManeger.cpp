#include"EnemyManeger.h"
#include"EnemyBase.h"
#include <fstream>

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
	_moveenemy_speed = Vector3_Zero;
	_moveenemy_hp    = 0;
	_stopenemy_speed = Vector3_Zero;
	_stopenemy_hp    = 0;

	for (int i = 0; i < ENEMY_NUM; ++i) {
		appear_pos [i] = Vector3_Zero;
		tag[i]         = INT_MAX;
		appear_time[i] = INT_MAX;
		appear_flag[i] = false;
	}

	LoadCSV();
	LoadPosition_AppearTimeCSV();
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
			_enemy.push_back(factory->Create("move_enemy", appear_pos[count], _moveenemy_speed, _moveenemy_hp));
			appear_flag[count] = true;
			break;
		case STOP_ENEMY:
			_enemy.push_back(factory->Create("stop_enemy", appear_pos[count], _stopenemy_speed, _stopenemy_hp));
			appear_flag[count] = true;
			break;

		}
	}

}

void EnemyManager::OnCollisionEnter(EnemyBase* enemy)
{
	enemy->Damage();
}

void EnemyManager::LoadCSV()
{
	std::ifstream moveenemy_infile("csvFile/Enemy/EnemyStatus.csv");
	std::ifstream stopenemy_infile("csvFile/Enemy/StopEnemyStatus.csv");

	std::string filename;
	TCHAR t_filename[256];

	std::string dummy_line;
	char conma;

	//!�����G�̃X�e�[�^�X�ǂݍ���
	//��s��
	getline(moveenemy_infile, dummy_line);
	//��s��
	getline(moveenemy_infile, dummy_line);
    //�O�s��
	moveenemy_infile >> _moveenemy_speed.x >> conma >> _moveenemy_speed.y >> conma >> _moveenemy_speed.z >> conma >> _moveenemy_hp;

	//!�����Ȃ��G�̃X�e�[�^�X�ǂݍ���
	//��s��
	getline(stopenemy_infile, dummy_line);
	//��s��
	getline(stopenemy_infile, dummy_line);
	//�O�s��
	stopenemy_infile >> _stopenemy_hp;
}

void EnemyManager::LoadPosition_AppearTimeCSV() {
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
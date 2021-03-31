#include "EffectManager.h"
EffectManager::EffectManager()
{
	_hit_effect.reset(new ParticleSystem);
}

EffectManager::~EffectManager()
{
}

bool EffectManager::Initialize()
{
	EFFEKSEER hit = Effekseer.CreateEffectFromFile(_T("Effect/damage_effect01/damege_0127.efk"));
	_hit_effect->RegisterParticle(hit);
	_hit_effect->SetNomalEffect();

	return true;
}

int EffectManager::Update()
{
	return 0;
}

void EffectManager::Draw()
{
	auto itr = _effect.begin();
	while (itr != _effect.end()) {

		//Update��return���ꂽ�l 0�E�E�����Ă� 1�E�E����
		if (!(*itr)->GetPlayEnd())
		{
			itr->get()->Draw();
			itr++;
		}
		else
			//�v�f���� 1 �Ȃ����
			//itr�̒l��ύX���Ēl����i�߂�
			itr = _effect.erase(itr);
	}
}

void EffectManager::Create(string tag, Vector3 pos)
{
	if (tag == HITEFFECT) _effect.push_back(_hit_effect);
	auto&& effect = _effect.back();
	effect.get()->SetPosition(pos);
}

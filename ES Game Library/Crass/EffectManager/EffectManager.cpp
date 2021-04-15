#include "EffectManager.h"
EffectManager::EffectManager()
{
	_hit_effect.reset(new ParticleSystem);
}

EffectManager::~EffectManager()
{
	_hit_effect.reset();
}

bool EffectManager::Initialize()
{
	Effekseer.Attach(GraphicsDevice, 8192);
	auto&& hit = Effekseer.CreateEffectFromFile(_T("Effect/damage_effect01/damege_0127.efk"));
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
	_hit_effect->Draw();
}

void EffectManager::Create(string tag, Vector3 pos)
{
	if (tag == HITEFFECT) _hit_effect->Play();
	//ParticleSystem* effect = _effect.back().get();
	//effect->SetPosition(pos);
}

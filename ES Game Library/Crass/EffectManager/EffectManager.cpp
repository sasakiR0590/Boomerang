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

		//Updateでreturnされた値 0・・生きてる 1・・消去
		if (!(*itr)->GetPlayEnd())
		{
			itr->get()->Draw();
			itr++;
		}
		else
			//要素数が 1 なら消去
			//itrの値を変更して値を一つ進める
			itr = _effect.erase(itr);
	}
}

void EffectManager::Create(string tag, Vector3 pos)
{
	if (tag == HITEFFECT) _effect.push_back(_hit_effect);
	auto&& effect = _effect.back();
	effect.get()->SetPosition(pos);
}

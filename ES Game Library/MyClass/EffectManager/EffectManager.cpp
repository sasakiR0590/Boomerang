#include "EffectManager.h"
#include "../Data/WordsTable.h"
#include"../Data/MyAlgorithm.h"

EffectManager::EffectManager()
{
	
}

EffectManager::~EffectManager()
{
}

bool EffectManager::Initialize()
{
	ParticleSystem* hiteffect = new ParticleSystem;
	_effect.insert(std::make_pair(EffectTag::HIT, std::move(SetEffectInit("Effect/hiteffect/hit_effect.efk", 0.5f, 0.1f))));
	_effect.insert(std::make_pair(EffectTag::EXPLOSION, std::move(SetEffectInit("Effect/explosion/explosion.efk", 0.1f, 0.3f))));
	return true;
}

int EffectManager::Update()
{
	return 0;
}

void EffectManager::Draw()
{
}

void EffectManager::Create(string tag, Vector3 pos)
{
	_effect.at(tag)->Play();
	_effect.at(tag)->SetPosition(pos);
	_effect.at(tag)->Draw();
}

ParticleSystem* EffectManager::SetEffectInit(string filename, float speed, float scale)
{
	auto&& particle = Effekseer.CreateEffectFromFile(ConvertStringFileName(filename));
	ParticleSystem* effect = new ParticleSystem;
	effect->RegisterParticle(particle);
	effect->SetSpeed(speed);
	effect->SetScale(scale);
	return effect;
}

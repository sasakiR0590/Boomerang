#include "EffectManager.h"
#include "../Data/WordsTable.h"
#include <codecvt>
EffectManager::EffectManager()
{
	
}

EffectManager::~EffectManager()
{
}

bool EffectManager::Initialize()
{
	Effekseer.Attach(GraphicsDevice, 8192);
	ParticleSystem* hiteffect = new ParticleSystem;
	_effect.insert(std::make_pair(EffectTag::HIT, std::move(SetEffectInit("Effect/hiteffect/hit_effect.efk", 1.0f, 0.1f))));
	_effect.insert(std::make_pair(EffectTag::EXPLOSION, std::move(SetEffectInit("Effect/explosion/explosion.efk", 1.0f, 0.1f))));
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
	auto filepath = std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(filename);
	auto&& particle = Effekseer.CreateEffectFromFile(filepath.c_str());
	ParticleSystem* effect = new ParticleSystem;
	effect->RegisterParticle(particle);
	effect->SetSpeed(speed);
	effect->SetScale(scale);
	return effect;
}

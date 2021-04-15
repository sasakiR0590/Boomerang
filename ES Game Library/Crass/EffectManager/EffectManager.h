#pragma once


#include"../../ESGLib.h"
#include"../ParticleSystem/Particle.h"
class EffectManager{
public:
    EffectManager::EffectManager();
    EffectManager::~EffectManager();
    bool   Initialize();
    int    Update();
    void   Draw();
    void Create(string tag, Vector3 pos);
    //! �V���O���g���I�u�W�F�N�g�𑼂ŌĂяo�����̋L�q
    static EffectManager& Instance() {
        static EffectManager instance;
        return instance;
    };
private:
    std::list<std::unique_ptr<ParticleSystem>> _effect;
    std::unique_ptr<ParticleSystem>       _hit_effect;
    string HITEFFECT = "HitEffect";
};
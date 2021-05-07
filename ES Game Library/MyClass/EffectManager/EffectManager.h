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
    std::map<string, ParticleSystem*> _effect;
    ParticleSystem* SetEffectInit(string filename,float speed,float scale);
};
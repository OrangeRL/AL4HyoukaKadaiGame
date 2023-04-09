#include "DustParticleManager.h"
using namespace std;

void DustParticleManager::CreateParticle(ViewProjection* viewProjection, XMMATRIX* matProjection, Vector3 beginPos, Vector3 scale)
{
	particles.emplace_back(new DustParticle);
	particles.back()->Initialize(viewProjection, matProjection, beginPos);
	//particles.back()->SetScale(scale);
}

DustParticleManager::DustParticleManager()
{
}

DustParticleManager::~DustParticleManager()
{
	particles.clear();
}

void DustParticleManager::Initialize(ViewProjection* viewProjection, XMMATRIX* matProjection)
{
	for (unique_ptr<DustParticle>& particle : particles)
	{

	}
}

void DustParticleManager::Update(ViewProjection* viewProjection, XMMATRIX* matProjection, Vector3 beginPos, Vector3 scale)
{
	particles.remove_if([](std::unique_ptr<DustParticle>& particle) {
		return particle->IsDead();
		});

	if (particles.size() <= LIMIT)
	{
		CreateParticle(viewProjection, matProjection, beginPos, scale);
	}

	for (unique_ptr<DustParticle>& particle : particles)
	{
		particle->Update(beginPos);
	}
}

void DustParticleManager::Draw()
{
	for (unique_ptr<DustParticle>& particle : particles)
	{
		particle->Draw();
	}
}

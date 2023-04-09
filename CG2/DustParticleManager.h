#pragma once
#include "DustParticle.h"
#include <list>
#include <memory>

class DustParticleManager
{
public:
	DustParticleManager();
	~DustParticleManager();

	void Initialize(ViewProjection* viewProjection, XMMATRIX* matProjection);
	void Update(ViewProjection* viewProjection, XMMATRIX* matProjection, Vector3 beginPos, Vector3 scale = { 0.5f,0.5f,0.5f });
	void Draw();

	void CreateParticle(ViewProjection* viewProjection, XMMATRIX* matProjection, Vector3 beginPos, Vector3 scale);

	const std::list<std::unique_ptr<DustParticle>>& GetParticle() {
		return particles;
	};

	static const int LIMIT = 5;

private:
	std::list<std::unique_ptr<DustParticle>> particles;
};
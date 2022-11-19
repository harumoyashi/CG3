#include "Emitter.h"

Emitter::~Emitter()
{
	delete particle;
}

void Emitter::Initialize()
{
	particle = ParticleManager::Create();
	particle->SetBillboard(false);
}

void Emitter::Update()
{
	//X,Y,Z全てランダムに分布
	XMFLOAT3 pos{};
	pos.x = position.x + (float)rand() / RAND_MAX * md_pos - md_pos / 2.0f;
	pos.y = position.y + (float)rand() / RAND_MAX * md_pos - md_pos / 2.0f;
	pos.z = position.z + (float)rand() / RAND_MAX * md_pos - md_pos / 2.0f;

	//X,Y,Z全てランダムに分布
	XMFLOAT3 vel{};
	vel.x = /*(float)rand() / RAND_MAX * md_vel - md_vel / 2.0f*/0.0f;
	vel.y = /*(float)rand() / RAND_MAX * md_vel - md_vel / 2.0f*/0.0f;
	vel.z = /*(float)rand() / RAND_MAX * md_vel - md_vel / 2.0f*/0.0f;

	//重力に見立ててYのみ[-0.001f,0]ランダムに分布
	XMFLOAT3 acc{};
	acc.y = -(float)rand() / RAND_MAX * rnd_acc;
	//追加
	float r = (float)rand() / RAND_MAX * 1.0f;
	float g = (float)rand() / RAND_MAX * 1.0f;
	float b = (float)rand() / RAND_MAX * 1.0f;
	particle->Add(120, pos, vel, acc, 0.0f, 3.0f, { r,g,b,1.0f });
	particle->SetIsDark(true);

	particle->Update();
}

void Emitter::Draw(ID3D12GraphicsCommandList* cmdList)
{
	// 3Dオブジェクト描画前処理
	ParticleManager::PreDraw(cmdList);
	// 3Dオブクジェクトの描画
	particle->Draw();
	// 3Dオブジェクト描画後処理
	ParticleManager::PostDraw();
}

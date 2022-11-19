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
	//X,Y,Z�S�ă����_���ɕ��z
	XMFLOAT3 pos{};
	pos.x = position.x + (float)rand() / RAND_MAX * md_pos - md_pos / 2.0f;
	pos.y = position.y + (float)rand() / RAND_MAX * md_pos - md_pos / 2.0f;
	pos.z = position.z + (float)rand() / RAND_MAX * md_pos - md_pos / 2.0f;

	//X,Y,Z�S�ă����_���ɕ��z
	XMFLOAT3 vel{};
	vel.x = /*(float)rand() / RAND_MAX * md_vel - md_vel / 2.0f*/0.0f;
	vel.y = /*(float)rand() / RAND_MAX * md_vel - md_vel / 2.0f*/0.0f;
	vel.z = /*(float)rand() / RAND_MAX * md_vel - md_vel / 2.0f*/0.0f;

	//�d�͂Ɍ����Ă�Y�̂�[-0.001f,0]�����_���ɕ��z
	XMFLOAT3 acc{};
	acc.y = -(float)rand() / RAND_MAX * rnd_acc;
	//�ǉ�
	float r = (float)rand() / RAND_MAX * 1.0f;
	float g = (float)rand() / RAND_MAX * 1.0f;
	float b = (float)rand() / RAND_MAX * 1.0f;
	particle->Add(120, pos, vel, acc, 0.0f, 3.0f, { r,g,b,1.0f });
	particle->SetIsDark(true);

	particle->Update();
}

void Emitter::Draw(ID3D12GraphicsCommandList* cmdList)
{
	// 3D�I�u�W�F�N�g�`��O����
	ParticleManager::PreDraw(cmdList);
	// 3D�I�u�N�W�F�N�g�̕`��
	particle->Draw();
	// 3D�I�u�W�F�N�g�`��㏈��
	ParticleManager::PostDraw();
}

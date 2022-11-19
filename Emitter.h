#pragma once
#include "ParticleManager.h"
#include "Input.h"

class Emitter
{
private:
// Microsoft::WRL::Çè»ó™
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;
	// DirectX::Çè»ó™
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMMATRIX = DirectX::XMMATRIX;

	ParticleManager* particle = {};

	const float md_pos = 10.0f;
	const float md_vel = 10.0f;
	const float rnd_acc = 0.001f;

public:
	XMFLOAT3 position = {0,0,0};

public:
	~Emitter();

	void Initialize();
	void Update();
	void Draw(ID3D12GraphicsCommandList* cmdList);
};
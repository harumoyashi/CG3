#include "BasicShaderHeader.hlsli"

struct GSOutput
{
	float4 svpos : SV_POSITION;	//システム用頂点座標
    float3 normal : NORMAL;		//法線ベクトル
    float2 uv : TEXCOORD;		//uv値
};

[maxvertexcount(3)]
void main(
	triangle VSOutput input[3] : SV_POSITION, 
	inout TriangleStream< GSOutput > output
)
{
	for (uint i = 0; i < 3; i++)
	{
		GSOutput element;
		element.svpos = input[i].svpos;
		element.normal = input[i].normal;
		element.uv = input[i].uv;
		output.Append(element);
	}
}
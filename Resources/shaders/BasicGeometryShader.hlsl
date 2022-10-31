#include "BasicShaderHeader.hlsli"

[maxvertexcount(6)]
void main(
	triangle VSOutput input[3] : SV_POSITION, 
	inout TriangleStream< GSOutput > output
)
{
	for (uint i = 0; i < 3; i++)
	{
        GSOutput element; //出力用頂点データ
        element.svpos = input[i].svpos; //頂点座標をコピー
        element.normal = input[i].normal; //法線をコピー
        element.uv = input[i].uv; //UVをコピー
		//頂点を1つ出力(出力リストに追加)
        output.Append(element);
    }
    output.RestartStrip();
    
    for (uint i = 0; i < 3; i++)
    {
        GSOutput element; //出力用頂点データ
        element.svpos = input[i].svpos + float4(10.0f,0.0f,0.0f,0.0f); //頂点座標をコピー
        element.normal = input[i].normal; //法線をコピー
        element.uv = input[i].uv * 5.0f; //UVをコピー
		//頂点を1つ出力(出力リストに追加)
        output.Append(element);
    }
}
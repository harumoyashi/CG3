#include "BasicShaderHeader.hlsli"

[maxvertexcount(3)]
void main(
	point VSOutput input[1] : SV_POSITION,
	inout TriangleStream<GSOutput> output
)
{
    GSOutput element; //出力用頂点データ
    //共通
    element.normal = input[0].normal; //法線をコピー
   
    //1点目
    element.svpos = input[0].svpos; //頂点座標をコピー
    element.uv = input[0].uv; //UVをコピー
    output.Append(element);
    //2点目
    element.svpos = input[0].svpos + float4(10.0f, 10.0f, 0, 0); //頂点座標をコピー
    element.uv = input[0].uv + float2(1,1); //UVをコピー
    output.Append(element);
    //3点目
    element.svpos = input[0].svpos + float4(10.0f, 0, 0, 0); //頂点座標をコピー
    element.uv = input[0].uv + float2(1, 0); //UVをコピー
    output.Append(element);
}
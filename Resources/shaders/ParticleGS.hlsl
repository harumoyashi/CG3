#include "Particle.hlsli"

//四角形の頂点数
static const uint vnum = 4;

//センターからのオフセット
static const float4 offset_array[vnum] =
{
    float4(-1.5f, -1.5f, 0, 0), //左下
    float4(-1.5f, +1.5f, 0, 0), //左上
    float4(+1.5f, -1.5f, 0, 0), //右下
    float4(+1.5f, +1.5f, 0, 0), //右上
};

//左下が0,0　右下が1,1
static const float2 uv_array[vnum] =
{
    float2(0, 1),   //左下
    float2(0, 0),   //左上
    float2(1, 1),   //右下
    float2(1, 0),   //右上
};

[maxvertexcount(vnum)]
void main(
	point VSOutput input[1] : SV_POSITION,
	inout TriangleStream<GSOutput> output
)
{
    GSOutput element; //出力用頂点データ
   
    for (uint i = 0; i < vnum; i++)
    {
        //ワールド座標ベースでずらす
        float4 offset = mul(matBillboard, offset_array[i]);
        //オフセット分ずらす(ワールド座標)
        element.svpos = input[0].pos + offset;
        
        //ビュー、射影変換
        element.svpos = mul(mat,element.svpos);
        element.uv = uv_array[i];
        output.Append(element);      
    }
}
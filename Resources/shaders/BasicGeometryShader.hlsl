#include "BasicShaderHeader.hlsli"

[maxvertexcount(3)]
void main(
	point VSOutput input[1] : SV_POSITION,
	inout TriangleStream<GSOutput> output
)
{
    GSOutput element; //�o�͗p���_�f�[�^
    //����
    element.normal = input[0].normal; //�@�����R�s�[
   
    //1�_��
    element.svpos = input[0].svpos; //���_���W���R�s�[
    element.uv = input[0].uv; //UV���R�s�[
    output.Append(element);
    //2�_��
    element.svpos = input[0].svpos + float4(10.0f, 10.0f, 0, 0); //���_���W���R�s�[
    element.uv = input[0].uv + float2(1,1); //UV���R�s�[
    output.Append(element);
    //3�_��
    element.svpos = input[0].svpos + float4(10.0f, 0, 0, 0); //���_���W���R�s�[
    element.uv = input[0].uv + float2(1, 0); //UV���R�s�[
    output.Append(element);
}
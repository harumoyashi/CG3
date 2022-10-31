#include "BasicShaderHeader.hlsli"

[maxvertexcount(6)]
void main(
	triangle VSOutput input[3] : SV_POSITION, 
	inout TriangleStream< GSOutput > output
)
{
	for (uint i = 0; i < 3; i++)
	{
        GSOutput element; //�o�͗p���_�f�[�^
        element.svpos = input[i].svpos; //���_���W���R�s�[
        element.normal = input[i].normal; //�@�����R�s�[
        element.uv = input[i].uv; //UV���R�s�[
		//���_��1�o��(�o�̓��X�g�ɒǉ�)
        output.Append(element);
    }
    output.RestartStrip();
    
    for (uint i = 0; i < 3; i++)
    {
        GSOutput element; //�o�͗p���_�f�[�^
        element.svpos = input[i].svpos + float4(10.0f,0.0f,0.0f,0.0f); //���_���W���R�s�[
        element.normal = input[i].normal; //�@�����R�s�[
        element.uv = input[i].uv * 5.0f; //UV���R�s�[
		//���_��1�o��(�o�̓��X�g�ɒǉ�)
        output.Append(element);
    }
}
struct VSInput
{
    float3 position : POSITION;
    float2 texCoord : TEXCOORD;
    float3 normal : NORMAL;
};

cbuffer Transform : register(b0)
{
    matrix world;
};

cbuffer Camera : register(b1)
{
    matrix camera;
};

struct VSOutput
{
    float4 position : SV_POSITION;
    float2 texCoord : TEXCOORD;
    float3 normal : NORMAL;
};

VSOutput main(VSInput input)
{
    VSOutput output;
    //output.position = float4(input.position, 1);
    output.position = mul(float4(input.position, 1), world);
    output.position = mul(output.position, camera);
    output.texCoord = input.texCoord;
    
    output.normal = mul(input.normal, (float3x3)world);

    return output;
}
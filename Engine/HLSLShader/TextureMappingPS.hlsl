struct VSOutput
{
    float4 position : SV_POSITION;
    float2 texCoord : TEXCOORD;
    float3 normal : NORMAL;
};

Texture2D map;
SamplerState mapSampler;

float4 main(VSOutput input) : SV_TARGET
{
    float4 diffuseMapColor = map.Sample(mapSampler, input.texCoord);
    
    // light direction.
    float3 lightDir = normalize(float3(500.0f, 500.0f, -500.0f));
    
    // NdotL.
    float NdotL = dot(normalize(input.normal), lightDir);
    
    //return float4(1.0f, 1.0f, 0.0f, 1.0f);
    return diffuseMapColor * NdotL;
}
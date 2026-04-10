#pragma once

#include "Texture.h"
#include <vector>

namespace Craft
{
	class CRAFT_API CubemapTexture : public Texture
	{
	public:
		CubemapTexture();
		CubemapTexture(const std::string& path);
		~CubemapTexture() = default;

	protected:
		virtual void LoadTexture(const std::string& path) override;
		virtual void CreateSRVAndSampler() override;

	private:
		// 6장 이미지 배열.
		std::vector<byte*> images;
	};
}
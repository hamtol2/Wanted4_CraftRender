#pragma once

#include "Core/Common.h"
#include <memory>
#include <unordered_map>
#include <string>

namespace Craft
{
	class Texture;
	class CubemapTexture;

	class CRAFT_API TextureLoader
	{
	public:
		TextureLoader();
		~TextureLoader() = default;

		void Load(
			const std::string& name,
			std::weak_ptr<Texture>& outTexture);

		// Å¥ºê¸Ê ·Îµå ÇÔ¼ö.
		void LoadCubemap(
			const std::string& path,
			std::weak_ptr<CubemapTexture>& outTexture
		);

		static TextureLoader& Get();

	private:

		static TextureLoader* instance;

		std::unordered_map<
			std::string,
			std::shared_ptr<Texture>> textureMap;

		// Å¥ºê¸Ê °ü¸®¿ë ¸Ê.
		std::unordered_map<
			std::string,
			std::shared_ptr<CubemapTexture>> cubemapTextureMap;
	};
}
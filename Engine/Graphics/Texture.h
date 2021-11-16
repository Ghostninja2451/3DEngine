#pragma once
#include "Resource/Resource.h"
#include"Math/MathTypes.h"
#include <SDL.h>


namespace henry
{
	class Renderer;
	class Texture : public Resource
	{
	public:
		Texture() {}
		Texture(Renderer* renderer);

		bool Load(const std::string& name, void* data = nullptr) override;

		glm::vec2 GetSize() const;

		friend class Renderer;

		bool Create(SDL_Surface* surface);


	private:
		SDL_Texture* texture{ nullptr };
		SDL_Renderer* renderer{ nullptr };
	};

}
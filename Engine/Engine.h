#pragma once

#define REGISTER_CLASS(class) henry::ObjectFactory::Instance().Register<class>(#class);
#define CREATE_ENGINE_OBJECT(class) henry::ObjectFactory::Instance().Create<henry::class>(#class);


//core
#include"Core/Utilities.h"
#include"Core/FileSystem.h"
#include "Core/Timer.h"
#include"Core/Json.h"
#include"Core/Serializable.h"

//framework
#include"FrameWork/EventSystem.h"
#include"Framework/Singleton.h"
#include"Framework/Factory.h"

//Math
#include"Math/Random.h"
#include"Math/MathUtils.h"
#include"Math/Transform.h"
#include"Math/MathTypes.h"

//#include"Graphics/Shape.h"
#include"Object/Actor.h"
#include"Object/Scene.h"

//component
#include"Component/PhysicsComponent.h"
#include"Component/AudioComponent.h"
#include"Component/CameraComponent.h"
#include"Component/MeshComponent.h"
#include"Component/ModelComponent.h"
#include"Component/LightComponent.h"

#include"Component/FreeCameraControler.h"

//inputsystem
#include"Input/InputSystem.h"

//Graphic
#include"Graphics/Renderer.h"
#include"Graphics/Texture.h"
#include"Graphics/Program.h"
#include"Graphics/Shader.h"
#include"Graphics/Material.h"
#include"Graphics/VertexBuffer.h"

//Audio
#include"Audio/AudioSystem.h"


//resource
#include "Resource/ResourceSystem.h"

#define NOMINMAX

#include <vector>
#include <memory>
#include<algorithm>


namespace henry
{
	using ObjectFactory = Singleton<Factory<std::string, Object>>;
	
	class Engine
	{
	public:
		void Startup();
		void Shutdown();

		void Update();
		void Draw(Renderer* renderer);

		template<typename T>
		T* Get();

	public:
		FrameTimer time;

	private:
		std::vector<std::unique_ptr<System>> systems;

	};

	template<typename T>
	inline T* Engine::Get()
	{
		for (auto& system : systems)
		{
			if (dynamic_cast<T*>(system.get())) return dynamic_cast<T*>(system.get());
		}
		
		return nullptr;
	}
}
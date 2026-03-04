#include "Core/Engine.h"
#include "Level/TriangleDemoLevel.h"

using namespace Craft;

// 엔진 실행 함수.
void LaunchEngineStartup(HINSTANCE instance)
{
	Engine engine;
	engine.Initialize(instance);
	engine.AddNewLevel<TriangleDemoLevel>();
	engine.Run();
}

int main()
{
	LaunchEngineStartup(GetModuleHandle(nullptr));
}
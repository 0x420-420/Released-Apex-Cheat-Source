#pragma once
#include <wtypes.h>

namespace variables {
	HANDLE Process = { };
	uintptr_t ModuleBase = { };
	uintptr_t PID = { };

	uintptr_t EntityList = { };
	uintptr_t LocalPlayer = { };

	uintptr_t BaseEntity = { };
	uintptr_t Entity_Handle = { };

	uintptr_t derefent = { };
	uintptr_t Health = { };

	uintptr_t Shield = { };
	uintptr_t EntName = { };
}
struct Vector3 {

	float x, y, z;
};
namespace TerryFosterSettings
{

	float R = {};
	float G = {};
	float B = {};
	bool HealthBased = { false };
	bool ShieldBased = { false };
	bool StaticGlow = { true };



}
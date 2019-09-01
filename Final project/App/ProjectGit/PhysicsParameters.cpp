/*

Name: Kirsty McEwan

Student ID: B00188061

I declare that the following code was produced by Kirsty McEwan, Lauren McNally, Matthew McMahon Wood as a group assignment for the Game Physics module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/
#include <iostream>
#include "PhysicsParameters.h"
#include "Utils.h"
#include <float.h>
vec2 PhysicsParameters::GetResultantForce()
{
	return ForceAccum;
}

void PhysicsParameters::ClearAccumulator()
{
	ForceAccum = vec2(0);
}

void PhysicsParameters::AddForce(const vec2 & force)
{
	ForceAccum = force + ForceAccum;					//Adds new force to current force
}

void PhysicsParameters::SetInverseMass(float mass)
{
	if (mass != 0)
		InverseMass = 1.0f / mass;
	else
		InverseMass = INFINITY;
}

void PhysicsParameters::SetRestitution(float restit)
{
	Restitution = Utils::clamp(restit);					//Keeps the value between 0 and 1. If value > 1 then value = 1. If valve < 0, then value = 0
}

void PhysicsParameters::SetVelocity(vec2 vel)
{
	Velocity = vel;
}

float PhysicsParameters::GetInverseMass()
{
	return InverseMass;
}

float PhysicsParameters::GetMass()
{
	return 1.0f / InverseMass;							//Retruns original mass
}

float PhysicsParameters::GetRestitution()
{
	return Restitution;
}

vec2 PhysicsParameters::GetVelocity()
{
	return Velocity;
}

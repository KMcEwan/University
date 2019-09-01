/*

Name: Kirsty McEwan

Student ID: B00188061

I declare that the following code was produced by Kirsty McEwan, Lauren McNally, Matthew McMahon Wood as a group assignment for the Game Physics module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/
#pragma once
#include <glm\glm.hpp>
#include "Transform.h"

struct PhysicsParameters		//Data structure to pass data, position, velocity, acceleration etc
{
private:
	float InverseMass;
	float Restitution;			//The bounce of an object 
	vec2 ForceAccum;

public:
	Transform transform;
	vec2 Velocity;
	vec2 Acceleration;
	vec2 GetResultantForce();

	void ClearAccumulator();
	void AddForce(const vec2& force);
	void SetInverseMass(float mass);
	void SetRestitution(float restit);
	void SetVelocity(vec2 vel);

	float GetInverseMass();
	float GetMass();
	float GetRestitution();
	vec2 GetVelocity();

	PhysicsParameters(float mass, vec2 pos, vec2 vel, float restit = 0)												//Constructor
		: Velocity(vel), Restitution(restit), ForceAccum(vec2(0)), Acceleration(vec2(0)), InverseMass(INFINITY)		//Initaliser 
	{
		SetInverseMass(mass);
		transform.Translate(pos);
	}

	virtual ~PhysicsParameters() {}																					//Deconstructor
};
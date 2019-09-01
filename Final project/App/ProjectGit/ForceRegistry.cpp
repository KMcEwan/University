/*

Name: Kirsty McEwan

Student ID: B00188061

I declare that the following code was produced by Kirsty McEwan, Lauren McNally, Matthew McMahon Wood as a group assignment for the Game Physics module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/
#include "ForceRegistry.h"

void ForceRegistry::Add(PhysicsEntity* obj, Force* ForceType)					//Registers the force to the object passed in. Object = (PhysicsEntity* obj). force = the force being passed in, ie - gravity. Use ie - ForceRegistry->add(ball, gravity)
{
	ForceRegistration ForceReg;													//Create new ForceRegistration called fr 
	ForceReg.force = ForceType;													//ForceReg = force passed in
	ForceReg.Parameters = obj->GetParameters();									//Set the Parameters of the new ForceRegistration (ForceReg) = to the parameters of the object being passed in
	registrations.push_back(ForceReg);											// Push ForceReg to vector
}

void ForceRegistry::Remove(PhysicsEntity * obj, Force * ForceType)				//Moves through vector for specific pair of PhysicsEntity-Force and erases it from the vector
{
	for (vector<ForceRegistration>::iterator it = registrations.begin();
											 it < registrations.end();
											 it++)
	{
		if (it->Parameters == obj->GetParameters())
		{
			registrations.erase(it);
			break;
		}
	}
}

void ForceRegistry::Clear()														//Clears the ForceAccum
{
	for (vector<ForceRegistration>::iterator it = registrations.begin();
											 it < registrations.end();
											 it++)
	{
		it->Parameters->ClearAccumulator();										//Resets the forces on the object, for the next frames forces computations (Parameter is a pointer to PhysicsParameter, which has the ClearAccumulator method)
	}
}

void ForceRegistry::updateForces(float dt)
{
	for (vector<ForceRegistration>::iterator it = registrations.begin(); it < registrations.end(); ++it)
	{
		it->force->updateForce(it->Parameters, dt);
	}
}

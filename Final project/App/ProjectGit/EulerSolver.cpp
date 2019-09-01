/*

Name: Kirsty McEwan

Student ID: B00188061

I declare that the following code was produced by Kirsty McEwan, Lauren McNally, Matthew McMahon Wood as a group assignment for the Game Physics module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/
#include "EulerSolver.h"

void EulerSolver::solver(PhysicsParameters * Parameters, float dt)
{
	Parameters->transform.Translate(dt * Parameters->Velocity);
	Parameters->Velocity += dt * Parameters->Acceleration;
	Parameters->Acceleration = Parameters->GetResultantForce() * Parameters->GetInverseMass();
}

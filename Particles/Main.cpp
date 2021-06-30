#include "FountainParticleSystem.h"
#include "GravityModifier.h"
#include "ForceModifier.h"
#include "PlaneCollisionModifier.h"
#include "Timer.h"
#include <iostream>

/*_______________________________________________________________________

  This program demonstrates how to use the Particle System API. it 
  includes the following:

  1) Examples of how Modifiers are added to the particle system.
  2) Initialization of a particle system.
  3) Running the particle simulation.
_______________________________________________________________________*/

namespace
{
    const float simulationTime = 3.f;
}

int main()
{
    std::cout << "Particle System API Test\n";

    const Plane3 ground(Vector3(-5.f, 0.f,-5.f), Vector3(-5.f, 0.f, 5.f), Vector3( 5.f, 0.f,-5.f));

    std::cout << "\nInitializing Modifiers.";

    GravityModifier gravity;
    gravity.SetGravity(2.f);

    ForceModifier force;
    force.SetForce(Vector3(-2.5f, -6.f, 0.f));

    PlaneCollisionModifier collision;
    collision.SetPlane3(ground);

    std::cout << "\nInitializing Particle System.\n";

    FountainParticleSystem fountain;

    fountain.SetMaxParticles(500);
    fountain.SetNumToRelease(20);
    fountain.SetReleaseInterval(0.05f);
    fountain.SetLifeCycle(3.f);
    fountain.SetPosition(Vector3(2.f, 0.f, 0.f));
    fountain.SetParticleVelocity(Vector3(3.f, 9.f, 0.f));
    fountain.SetVelocityFactor(0.f);

    fountain.AddModifier(&gravity);
    fountain.AddModifier(&force);
    fountain.AddModifier(&collision);

    fountain.Initialize();
    fountain.SetActive(true);

    std::cout << "\nSimulating for " << simulationTime << " seconds...";

    Timer timer;
    float accumulatedTime = 0.f;
    
    while(accumulatedTime <= simulationTime)
    {
        timer.Tick();

        const float delta = timer.GetElapsedTime();

        fountain.Update(delta);
        accumulatedTime += delta;
    }

    std::cout << "\nSimulation finished.\n";

    std::cout << "\nPress Enter to exit: ";
    std::cin.get();

    return 0;
}
#pragma once

/*
Systems are where most of the logic in an ECS based design should be.
*/
class SystemBase
{
public:
	virtual ~SystemBase() {};

	/*
	This can be used for to copy over components to an internal structure to 
	prevent direct use of external components. Provides better encapsulation at 
	the cost of extra copies. This will be run every loop.
	*/
	virtual void Reload() {};

	/*
	This is where the system should do the majority of its work on various 
	components
	*/
	virtual void Run() = 0;

	/*
	This method should be used to clean up any components that were marked for 
	delete. It can also be used to swap buffers and other tasks that should be 
	run after all systems are done running
	*/
	virtual void Clean() = 0;
};
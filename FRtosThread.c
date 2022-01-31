// ----------------------------------------------------------------------------
/**
 * @file        FRtosThread.c
 * @author
 * @date
 * @brief
 * @copyright
 * (c) Copyright Schlumberger Technology Corp., unpublished work, created 2020.
 * This computer program includes confidential, proprietary information and is a
 * trade secret of Schlumberger Technology Corp. All use, disclosure, and/or
 * reproduction is prohibited unless authorized in writing.
 * All Rights Reserved.
**/
// ----------------------------------------------------------------------------
// Include section
#include "FRtosThread.h"
#include "Container.h"

uint8_t  convertPriority(uint16_t priority) 
{
    /* Map threadX priority to FreeRTOS priority.
	 * In ThreadX priority range is  0-31 where 31 is lowest
	 * In FreeRTOS priority range is 0-31 where 0 would be lowest*/
	return (31U - (uint8_t)priority);
}

uint16_t convertStackSize(uint32_t stackSizeInBytes)
{
    return (uint16_t)(stackSizeInBytes >> 2);
}

void Thread_Construct(thread_t threads)
{
    	/* Create a container to store threads's context, if it is not existed yet*/
	if (threads == NULL)
	{
		threads = new Container<FRtosThread>(MAX_NUMBER_OF_THREADS);
		if (threads == NULL)
		{
			throw Exception("Thread list creation failed");
		}
	}

	/* Append the run object to this thread object*/
    taskParameters.taskObj    = this;
    this->runObj = &run;

	/* Append this thread into thread container, and assign this thread Id received from thread container*/
	id = threads->add(*this);
	if (id >= MAX_NUMBER_OF_THREADS)
	{
		throw Exception("Thread container is full");
	}

	/* Assign priority*/
	SLB_INT08U prio = convertPriority(priority);
	
    /* convert stack size from bytes to words*/
    SLB_INT16U stackSizeInWords = convertStackSize(stackSizeInBytes);
	
	
   /* Call FreeRTOS thread creation function*/
    BaseType_t taskCreatedOk = xTaskCreate( &dispatcher,
    										const_cast<char *>(name),
											static_cast<SLB_INT16U>(stackSizeInWords),
											&taskParameters,
											static_cast<UBaseType_t>(prio),
											NULL);

    /* Check return status, if an error clean-up and throw exception */
    if (taskCreatedOk != pdPASS)
    {
        throw Exception("Error creating thread", taskCreatedOk);
    }
}

uint8_t Thread_GetId(thread_t thread)
{
    return 0;
}

void Thread_Destroy(thread_t thread)
{
}

// ----------------------------------------------------------------------------
// End of file
// ----------------------------------------------------------------------------
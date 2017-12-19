// Fill out your copyright notice in the Description page of Project Settings.

#include "FSMBase.h"
#include "FSMStateBase.h"


// Sets default values for this component's properties
UFSMBase::UFSMBase()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	pCurrentState = NULL;
	pPrevState = NULL;

	// ...
}


// Called when the game starts
void UFSMBase::BeginPlay()
{
	Super::BeginPlay();


	// ...
	
}


// Called every frame
void UFSMBase::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (pCurrentState)

		pCurrentState->OnUpdate(DeltaTime);
	

	// ...
}

bool UFSMBase::AddState(UFSMStateBase * pState)
{
	if (pState->GetIndex()==invalidState)
	{
		return false;
	}
	int stateIndex = pState->GetIndex();
	if (statesMap.Find(pState->GetIndex())!=NULL)
	{
		return false;
	}
	statesMap.Add(pState->GetIndex(), pState);
	return true;
}

void UFSMBase::RemoveSate(int stateIndex)
{
	if (pCurrentState!=NULL&&pCurrentState->GetIndex()==stateIndex)
	
		ChangeState(invalidState);
		UFSMStateBase **pState = statesMap.Find(stateIndex);
		if (*pState==NULL)
		
			return;
		
		statesMap.Remove(stateIndex);
}

void UFSMBase::RemoveAllSate()
{
	pCurrentState = NULL;
	pPrevState = NULL;
	statesMap.Reset();
}


bool UFSMBase::ChangeState(int stateIndex)
{
	if (pCurrentState)
	{
		if (pCurrentState->GetIndex() == stateIndex)
			return false;
		else
			pCurrentState->OnExit();
	}
	pPrevState = pCurrentState;
	if (stateIndex ==invalidState)
	{
		pCurrentState = NULL;
	}
	else
		pCurrentState = GetState(stateIndex);
	if (pCurrentState)
	{
		pCurrentState->OnEnter();
	}
	else
		return false;

	return  true;
}
UFSMStateBase * UFSMBase::GetState(int stateIndx)
{
	if (stateIndx==invalidState)
	{
		return NULL;

	}
	UFSMStateBase **pState = statesMap.Find(stateIndx);
	if (*pState==NULL)
	{
		return NULL;
	}
	return *pState;
}



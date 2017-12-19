// Fill out your copyright notice in the Description page of Project Settings.

#include "NewObjectFromClass.h"

UObject * UNewObjectFromClass::NewObjectFormBlueprint(UObject * owner, UClass * UC)
{
	return NewObject<UObject>(owner, UC);
}

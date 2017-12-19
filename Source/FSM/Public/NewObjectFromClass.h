// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "NewObjectFromClass.generated.h"

/**
 * 
 */
UCLASS()
class FSM_API UNewObjectFromClass : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Create Object From Class", CompactNodeTitle = "Create", Keyworld = "new create blurprint"), Category = Game)
		static UObject* NewObjectFormBlueprint(UObject *owner, UClass *UC);
	
};

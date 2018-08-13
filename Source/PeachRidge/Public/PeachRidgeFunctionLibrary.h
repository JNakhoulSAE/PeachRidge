// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PeachRidgeFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class PEACHRIDGE_API UPeachRidgeFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

		UFUNCTION(BlueprintCallable, Category = "Custom Functions")
		static void GetLookAt(FVector origin, FVector location);
	
	
};

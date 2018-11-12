// Fill out your copyright notice in the Description page of Project Settings.

#include "PeachRidgeFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/UObjectIterator.h"
#include "Engine/GameEngine.h"
#include "Components/BillboardComponent.h"

void UPeachRidgeFunctionLibrary::TakePhoto(TArray<AActor*> speciesArray, TArray<FString> scannableSpecies, TArray<FString> scannedSpecies) {

	bool canStartScanning = false;

	// Get Player Controller
	TObjectIterator<APlayerController> controller;
	if (!controller) return;

	// Camera Fade (Flash)
	APlayerCameraManager* cameraManager = UGameplayStatics::GetPlayerCameraManager(controller->_getUObject(), 0);

	cameraManager->StartCameraFade(0.5, 0, 0.5, FLinearColor::White, false, true);

	// Check for valid selected species
	for (int i = 0; i < 2; i++)
	{
		if (speciesArray.IsValidIndex(i)) {
			canStartScanning = true;
		}
	}

	if (canStartScanning) {

		speciesArray.Reserve(speciesArray.Num());
		for (int i = 0; i < speciesArray.Num(); ++i)
		{
			if (speciesArray.IsValidIndex(i)) {

				// Adding species to list of all scanned species
				AActor* species = speciesArray[i];

				scannableSpecies.Reserve(scannableSpecies.Num());
				for (int i = 0; i < scannableSpecies.Num(); ++i)
				{
					if (species->GetActorLabel().Contains(scannableSpecies[i])) {
						if (GEngine) {
							GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Purple, "Scanned " + scannableSpecies[i]);
						}

						scannedSpecies.AddUnique(scannableSpecies[i]);
					}
				}

				// Clear billboard component

			}
		}

		canStartScanning = false;
	}
	else {
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Purple, "No species to scan.");
		}
	}
}
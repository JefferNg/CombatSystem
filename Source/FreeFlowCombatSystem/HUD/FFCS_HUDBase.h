// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "FFCS_HUDBase.generated.h"

/**
 * 
 */
UCLASS()
class FREEFLOWCOMBATSYSTEM_API AFFCS_HUDBase : public AHUD
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "HUD")
	void SetupHUD();
};

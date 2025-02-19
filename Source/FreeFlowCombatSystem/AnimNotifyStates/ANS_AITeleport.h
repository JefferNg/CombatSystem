// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "ANS_AITeleport.generated.h"

/**
 * 
 */
UCLASS()
class FREEFLOWCOMBATSYSTEM_API UANS_AITeleport : public UAnimNotifyState
{
	GENERATED_BODY()

public:
	virtual void NotifyTick(USkeletalMeshComponent * MeshComp, UAnimSequenceBase * Animation, float FrameDeltaTime, const FAnimNotifyEventReference& EventReference) override;

public:
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly)
	float Offset = 50.0f;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly)
	float InterpSpeed = 5.0f;
};

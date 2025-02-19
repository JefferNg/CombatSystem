// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "ANS_AIAttackCollision.generated.h"

/**
 * 
 */
UCLASS()
class FREEFLOWCOMBATSYSTEM_API UANS_AIAttackCollision : public UAnimNotifyState
{
	GENERATED_BODY()

public:
	virtual void NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime, const FAnimNotifyEventReference& EventReference) override;
	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference) override;

	UFUNCTION()
	void DoCollisionCheck(USkeletalMeshComponent* MeshComp);

public:
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Settings")
	bool DoAttackOnce;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Settings")
	float Radius;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Settings")
	FName StartSocket;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Settings")
	FName EndSocket;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Settings")
	FGameplayTag HitCollisionExclusionTag;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Settings")
	FGameplayTag FinisherTag;

private:
	UPROPERTY()
	bool AttackOnceTrigger = false;

	UPROPERTY(EditInstanceOnly, Category="Settings")
	bool Debug = false;
	
};

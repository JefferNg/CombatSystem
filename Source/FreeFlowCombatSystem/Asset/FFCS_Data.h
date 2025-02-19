// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FFCS_Data.generated.h"

UENUM(BlueprintType)
enum EAttackHitDirection : uint8
{
	Fwd UMETA(DisplayName = "Forward"),
	Bwd UMETA(DisplayName = "Backward"),
	Lt UMETA(DisplayName = "Left"),
	Rt UMETA(DisplayName = "Right")
};

UENUM(BlueprintType)
enum EAIStates : uint8
{
	GetInRange,
	GetBack,
	Wait,
	LookForWeapons,
	Strafe,
	Attack
};

USTRUCT(BlueprintType)
struct FPlayerAttackAnimData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UAnimMontage* AttackMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float PlayRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Offset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Damage;

	FPlayerAttackAnimData() {
		PlayRate = 1.0f;
		Offset = 100.0f;
		Damage = 10.0f;
	}
};

USTRUCT(BlueprintType)
struct FFinisherAnimData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UAnimMontage* FinisherMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UAnimMontage* HitMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float PlayRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Offset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Damage;

	FFinisherAnimData() {
		PlayRate = 1.0f;
		Offset = 100.0f;
		Damage = 10.0f;
	}
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "FreeFlowCombatSystem/Asset/FFCS_Data.h"
#include "AC_FFCC_Base.generated.h"


UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FREEFLOWCOMBATSYSTEM_API UAC_FFCC_Base : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAC_FFCC_Base();
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable) //BIE allows definition in blueprint without c++
	EAttackHitDirection HitDirection(AActor* Instigator);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void PlayHitMontage(EAttackHitDirection HitDirection);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetCurrentEnemy(AActor* EnemyRef);

	UFUNCTION(BlueprintImplementableEvent, BlueprintPure, BlueprintCallable)
	AActor* GetCurrentEnemy();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetCounterEnemy(AActor* EnemyRef);

	UFUNCTION(BlueprintImplementableEvent, BlueprintPure, BlueprintCallable)
	AActor* GetCounterEnemy();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetTag(const FGameplayTag& Tag);

	UFUNCTION(BlueprintImplementableEvent, BlueprintPure, BlueprintCallable)
	FGameplayTag GetTag();

	//UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Counter")
	//void PlayCounterMontage();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Counter")
	void ComboCounter();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Counter")
	void ResetComboCounter();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Counter")
	void SetFinisherAnims(const FFinisherAnimData NewFinisherData);

	UFUNCTION(BlueprintImplementableEvent, BlueprintPure, BlueprintCallable)
	FFinisherAnimData GetFinisherAnims();

	UFUNCTION(BlueprintImplementableEvent, BlueprintPure, BlueprintCallable)
	FPlayerAttackAnimData GetAttackAnims();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Counter")
	void SetAttackAnims(const FPlayerAttackAnimData& NewAttackAnim);

	UFUNCTION(BlueprintImplementableEvent, BlueprintPure, BlueprintCallable)
	FFinisherAnimData GetCounterAnims();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Counter")
	void SetCounterAnims(const FFinisherAnimData& NewCounterAnim);

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Finisher", meta=(AllowPrivateAccess=true))
	FFinisherAnimData FinisherAnims;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Finisher", meta=(AllowPrivateAccess=true))
	FPlayerAttackAnimData AttackAnims;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Finisher", meta=(AllowPrivateAccess=true))
	FFinisherAnimData CounterAnims;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Finisher", meta=(AllowPrivateAccess=true))
	TArray<FFinisherAnimData> FinisherAnimSets;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Finisher", meta=(AllowPrivateAccess=true))
	TArray<FFinisherAnimData> CounterAnimSets;
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combo")
	int Counter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Timer Handler")
	FTimerHandle ComboCounter_Timer;

/*
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	*/

		
};

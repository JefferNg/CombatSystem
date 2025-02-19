// Fill out your copyright notice in the Description page of Project Settings.


#include "AC_EnemyComp_Base.h"

// Sets default values for this component's properties
UAC_EnemyComp_Base::UAC_EnemyComp_Base()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	MaxHealth = 100.0f;
	CurrentHealth = MaxHealth;
}


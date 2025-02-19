// Fill out your copyright notice in the Description page of Project Settings.


#include "ANS_AITeleport.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "GameFramework/Character.h"
#include "Kismet/KismetMathLibrary.h"

// refer to AC_EnemyComp GetEnemyTeleportLocation blueprint
void UANS_AITeleport::NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime,
                                 const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyTick(MeshComp, Animation, FrameDeltaTime, EventReference);

	AActor* Owner = MeshComp->GetOwner();
	// valid check
	if (Owner)
	{
		// get owner->get blackboard in blueprint
		const UBlackboardComponent* BlackboardComp = UAIBlueprintHelperLibrary::GetBlackboard(Owner);
		// valid check
		if (BlackboardComp)
		{
			// gets literal blackboard name
			const FName KeyName = FName("TargetActor");

			UObject* Value = BlackboardComp->GetValueAsObject(KeyName);
			// valid check
			if (Value)
			{
				// cast to character
				ACharacter* Player = Cast<ACharacter>(Value);

				if (Player)
				{
					FVector StartLoc =  Owner->GetActorLocation();
					FVector PlayerLoc = Player->GetActorLocation();

					FVector Direction = (StartLoc - PlayerLoc).GetSafeNormal();
					FVector TeleportLoc = PlayerLoc + (Direction * Offset);

					FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(StartLoc, PlayerLoc);

					FVector InterpLoc = FMath::VInterpTo(StartLoc, TeleportLoc, FrameDeltaTime, InterpSpeed);

					Owner->SetActorLocationAndRotation(InterpLoc, LookAtRotation);
				}
			}
		}
	}
}

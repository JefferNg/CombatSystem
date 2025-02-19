// Fill out your copyright notice in the Description page of Project Settings.


#include "ANS_PlayerTeleport.h"

#include "FreeFlowCombatSystem/ActorComponent/AC_FFCC_Base.h"
#include "FreeFlowCombatSystem/Character/FFCC_CharacterBase.h"
#include "Kismet/KismetMathLibrary.h"


void UANS_PlayerTeleport::NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
                                     float FrameDeltaTime, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyTick(MeshComp, Animation, FrameDeltaTime, EventReference);

	if (MeshComp->GetOwner())
	{
		UAC_FFCC_Base* FFCC = Cast<UAC_FFCC_Base>(MeshComp->GetOwner()->GetComponentByClass(UAC_FFCC_Base::StaticClass()));
		if (FFCC)
		{
			if (FFCC->GetCounterEnemy())
			{
				FVector StartLoc = MeshComp->GetOwner()->GetActorLocation();
				FVector EndLoc = FFCC->GetCounterEnemy()->GetActorLocation();
				FVector Dir = (StartLoc - EndLoc).GetSafeNormal();
				FVector TeleportLoc = EndLoc + (Dir * Offset);
				FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(StartLoc, EndLoc);
				FVector InterpLoc = FMath::VInterpTo(StartLoc, TeleportLoc, FrameDeltaTime, InterpSpeed);
				FFCC->GetCounterEnemy()->SetActorRotation(UKismetMathLibrary::FindLookAtRotation(EndLoc, StartLoc));
				MeshComp->GetOwner()->SetActorLocationAndRotation(InterpLoc, LookAtRotation);
			}
		}
	}
}

void UANS_PlayerTeleport::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
	const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyEnd(MeshComp, Animation, EventReference);

	if (MeshComp->GetOwner())
	{
		AFFCC_CharacterBase* Character = Cast<AFFCC_CharacterBase>(MeshComp->GetOwner());
		if (Character)
		{
			Character->DashCounterMontage();
		}
	}
}

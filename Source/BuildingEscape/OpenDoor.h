// Copyright Steven Garcia 2019

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Components/PrimitiveComponent.h"
#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOpenRequest);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintAssignable)
	FOnOpenRequest OnOpenRequest;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	float OpenAngle = 90.0f;
	UPROPERTY(EditAnywhere)
	float CloseAngle = 0.0f;
	UPROPERTY(EditAnywhere)
	float DoorCloseDelay = 1.f;
	UPROPERTY(EditAnywhere)
	float TriggerMass = 50.0f;
	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate = nullptr;
	AActor* Owner = nullptr;

	float LastDoorOpenTime;

	void OpenDoor();
	void CloseDoor();

	float GetTotalMassOfActorsOnPlate();
};
